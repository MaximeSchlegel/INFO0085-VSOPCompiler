%{
    #include <map>
    #include <stack>
    #include <string>
    #include <utility>

    #include "Parser.h"
    #include "../../exception/Exception.h"


    extern std::map<std::string, int> reservedId;
    extern std::string filename;

    std::string strBuffer;
    std::pair<int,int> strStartPosition;
    std::stack<std::pair<int, int>> openedCommentsPosition;


    #define YY_USER_ACTION \
            yylloc.first_line = yylloc.last_line; \
            yylloc.first_column = yylloc.last_column; \
            for(int i = 0; yytext[i] != '\0'; i++) { \
                if(yytext[i] == '\n') { \
                    yylloc.last_line++; \
                    yylloc.last_column = 1; \
                } \
                else { \
                    yylloc.last_column++; \
                } \
            }

%}

%option noyywrap

%x INLINECOMMENT MULTILINECOMMENT STR

space           \x20
tab             \x09
lf              \x0A
ff              \x0B
cr              \x0C
whitespace      {space}|{tab}
ignored-char    {whitespace}|{lf}|{ff}|{cr}

bin-digit          0|1
digit              {bin-digit}|[2-9]
hex-digit          {digit}|[a-fA-F]
bin-literal        0b{bin-digit}+
digit-literal      {digit}+
hex-literal        0x{hex-digit}+
integer-literal    {digit-literal}|{hex-literal}|{bin-literal}

lowercase-letter    [a-z]
uppercase-letter    [A-Z]
letter              {lowercase-letter}|{uppercase-letter}

typeId      {uppercase-letter}({letter}|{digit}|_)*
objectId    {lowercase-letter}({letter}|{digit}|_)*



%%
"//"                  { BEGIN(INLINECOMMENT); }
<INLINECOMMENT>.*    {  }
<INLINECOMMENT>\n    { BEGIN(INITIAL); }


<INITIAL,MULTILINECOMMENT>"(*"    { openedCommentsPosition.emplace(yylloc.first_line, yylloc.first_column);
                                    BEGIN(MULTILINECOMMENT);
                                  }
<MULTILINECOMMENT>"*)"            { yylloc.first_line = openedCommentsPosition.top().first;
                                    yylloc.first_column = openedCommentsPosition.top().second;
                                    openedCommentsPosition.pop();
                                    if (openedCommentsPosition.empty()) {
                                      BEGIN(INITIAL);
                                    }
                                  }
<MULTILINECOMMENT>([^*(])+        {  }
<MULTILINECOMMENT>"("             {  }
<MULTILINECOMMENT>\*              {  }
<MULTILINECOMMENT><<EOF>>         { yylloc.first_line = openedCommentsPosition.top().first;
                                    yylloc.first_column = openedCommentsPosition.top().second;
                                    yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                                "unexpected end-of-file in comment");
                                    return ERROR;
                                  }


\x22                           { strStartPosition = std::pair<int , int>(yylloc.first_line, yylloc.first_column);
                                 strBuffer = yytext;
                                 BEGIN(STR);
                               }
<STR>\x22                      { strBuffer += yytext;
                                 yylval.strValue = new std::string(strBuffer);
                                 BEGIN(INITIAL);
                                 yylloc.first_line = strStartPosition.first;
                                 yylloc.first_column = strStartPosition.second;
                                 return STRLITERAL;
                               }
<STR>\x5C\x0A([ '\x09'])*      {  }
<STR>\x5Cb                     { strBuffer += "\\x08"; }
<STR>\x5Ct                     { strBuffer += "\\x09"; }
<STR>\x5Cn                     { strBuffer += "\\x0a"; }
<STR>\x5Cr                     { strBuffer += "\\x0d"; }
<STR>\x5C\x22                  { strBuffer += 92;
                                 strBuffer += 34;
                               }
<STR>\x5C\x5C                  { strBuffer += 92;
                                 strBuffer += 92;
                               }
<STR>\x5Cx({hex-digit}{2})     { std::string s = yytext; s = s.erase(0,2);
                                 int intLit = std::stoi(s, 0, 16);
                                 if (intLit < 32 or intLit == 127) {
                                   strBuffer += "\\x" + s;
                                 }
                                 else {
                                   strBuffer += intLit;
                                 }
                               }
<STR>\x5C                      { yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                            "invalid escaped sequence");
                                 return ERROR;
                               }
<STR>\x00                      { yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                            "null char in string");
                                 return ERROR;
                               }
<STR>\x0A                      { yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                            "feed line in string");
                                 return ERROR;
                               }
<STR><<EOF>>                   { yylloc.first_line = strStartPosition.first;
                                 yylloc.first_column = strStartPosition.second;
                                 yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                            "unexpected end-of-file in string");
                                 return ERROR;
                               }
<STR>.                         { strBuffer += yytext; }


{bin-literal}                             { std::string s = yytext; s = s.erase(0,2);
                                              int intLit = std::stoi(s, 0, 2);
                                              yylval.intValue = intLit;
                                              return INTLITERAL;
                                          }

{digit-literal}                           { int intLit = std::stoi(yytext, 0, 10);
                                            yylval.intValue = intLit;
                                            return INTLITERAL;
                                          }
{hex-literal}                             { std::string s = yytext; s = s.erase(0,2);
                                            int intLit = std::stoi(s, 0, 16);
                                            yylval.intValue = intLit;
                                            return INTLITERAL;
                                          }

{integer-literal}({objectId}|{typeId})    { yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                                    "missing whitespace between integer and identifier");
                                            return ERROR;
                                          }
"0b"{ignored-char}                        { yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                                        "incomplete binary integer literal");
                                            return ERROR;
                                          }
"0x"{ignored-char}                        { yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                                        "incomplete hexadecimal integer literal");
                                            return ERROR;
                                          }


{typeId}    { yylval.strValue = new std::string(yytext);
              return TYPEID;
            }


{objectId}    { std::map<std::string, int>::iterator isReserved;
                isReserved = reservedId.find(yytext);
                if (isReserved != reservedId.end()) {
                  return isReserved->second;
                } else {
                  yylval.strValue = new std::string(yytext);
                  return OBJECTID;
                }
              }


"{"    { return LBRACE; }
"}"    { return RBRACE; }
"("    { return LPAR; }
")"    { return RPAR; }
":"    { return COLON; }
";"    { return SEMICOLON; }
","    { return COMMA; }
"+"    { return PLUS; }
"-"    { return MINUS; }
"*"    { return TIMES; }
"/"    { return DIV; }
"^"    { return POW; }
"."    { return DOT; }
"="    { return EQUAL; }
"<"    { return LOWER; }
"<="   { return LOWEREQUAL; }
"<-"   { return ASSIGN; }


{ignored-char}+    {  }
<<EOF>>            { return END; }
.                  { yylval.lerror = new LexerException(filename, yylloc.first_line, yylloc.first_column,
                                                "invalid character");
                     return ERROR;
                   }



%%