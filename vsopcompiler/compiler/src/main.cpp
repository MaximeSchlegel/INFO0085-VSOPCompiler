#include <iostream>
#include <map>
#include <stack>

#include "../../ast_node/ASTNode.h"
#include "../../debugger/Debugger.h"
#include "../../exception/Exception.h"
#include "../../symbol_table/SymbolTable.h"

#include "Lexer.h"
#include "Parser.h"
#include "ASTProcessor.h"


bool extended = false;
std::string filename = "";
std::map<std::string, int> reservedId = {{"bool", BOOL}, {"int32", INT32},{"string", STRING},{"unit", UNIT},
                                         {"and", AND},{"not", NOT},{"class", CLASS},{"do", DO},{"else", ELSE},
                                         {"extends", EXTENDS},{"false", FALSE},{"if", IF},{"in", IN},{"isnull", ISNULL},
                                         {"let", LET},{"new", NEW},{"then", THEN},{"true", TRUE},{"while", WHILE}};
ProgramNode *astResult;
Debugger *debugger;


void displayToken (int token) {
    if (token == ERROR) {
        std::cerr << *yylval.lerror << std::endl;
        return;
    }

    if (token == END) {
        return;
    }

    //display the standard tokens
    std::cout << yylloc.first_line << "," << yylloc.first_column << ",";
    switch (token) {
        case BOOL: std::cout << "bool"; break;
        case INT32: std::cout << "int32"; break;
        case STRING: std::cout << "string"; break;
        case UNIT: std::cout << "unit"; break;
        case TYPEID: std::cout << "type-identifier," << *yylval.strValue; break;
        case INTLITERAL: std::cout << "integer-literal," << yylval.intValue; break;
        case STRLITERAL: std::cout << "string-literal," << *yylval.strValue; break;
        case AND: std::cout << "and"; break;
        case NOT: std::cout << "not"; break;
        case CLASS: std::cout << "class"; break;
        case DO: std::cout << "do"; break;
        case ELSE: std::cout << "else"; break;
        case EXTENDS: std::cout << "extends"; break;
        case FALSE: std::cout << "false"; break;
        case IF: std::cout << "if"; break;
        case IN: std::cout << "in"; break;
        case ISNULL: std::cout << "isnull"; break;
        case LET: std::cout << "let"; break;
        case NEW: std::cout << "new"; break;
        case THEN: std::cout << "then"; break;
        case TRUE: std::cout << "true"; break;
        case WHILE: std::cout << "while"; break;
        case OBJECTID: std::cout << "object-identifier," << *yylval.strValue; break;
        case LBRACE: std::cout << "lbrace"; break;
        case RBRACE: std::cout << "rbrace"; break;
        case LPAR: std::cout << "lpar"; break;
        case RPAR: std::cout << "rpar"; break;
        case COLON: std::cout << "colon"; break;
        case SEMICOLON: std::cout << "semicolon"; break;
        case COMMA: std::cout << "comma"; break;
        case PLUS: std::cout << "plus"; break;
        case MINUS: std::cout << "minus"; break;
        case TIMES: std::cout << "times"; break;
        case DIV: std::cout << "div"; break;
        case POW: std::cout << "pow"; break;
        case DOT: std::cout << "dot"; break;
        case EQUAL: std::cout << "equal"; break;
        case LOWER: std::cout << "lower"; break;
        case LOWEREQUAL: std::cout << "lower-equal"; break;
        case ASSIGN: std::cout << "assign"; break;
        default: std::cout << "unknown token"; break;
    }
    std::cout << std::endl;
}


int main(int argc, char *argv[]) {
//    //define the basic reserved identifier
//    reservedId.emplace("bool", BOOL);
//    reservedId.emplace("int32", INT32);
//    reservedId.emplace("string", STRING);
//    reservedId.emplace("unit", UNIT);
//    reservedId.emplace("and", AND);
//    reservedId.emplace("not", NOT);
//    reservedId.emplace("class", CLASS);
//    reservedId.emplace("do", DO);
//    reservedId.emplace("else", ELSE);
//    reservedId.emplace("extends", EXTENDS);
//    reservedId.emplace("false", FALSE);
//    reservedId.emplace("if", IF);
//    reservedId.emplace("in", IN);
//    reservedId.emplace("isnull", ISNULL);
//    reservedId.emplace("let", LET);
//    reservedId.emplace("new", NEW);
//    reservedId.emplace("then", THEN);
//    reservedId.emplace("true", TRUE);
//    reservedId.emplace("while", WHILE);

    bool lex = false, parse = false, check = false, llvm = false, debug = false;
    std::string optionStr;

    for (int i = 0; i < argc; ++i) {
        // determine the option used
        std::map<std::string, int> optionMap = {{"-lex", 1}, {"-parse", 2}, {"-check", 3}, {"-llvm", 4}, {"-ext", 5}, {"-g", 6}};
        optionStr = std::string(argv[i]);
        std::map<std::string, int>::iterator optionIt = optionMap.find(optionStr);
        int option = optionIt != optionMap.end() ? optionIt->second : 0;

        switch (option) {
            case 1: lex = true; break;
            case 2: parse = true; break;
            case 3: check = true; break;
            case 4: llvm = true; break;
            case 5: extended = true; break;
            case 6: debug = true; break;
            default: filename = optionStr; break;
        }
    }

    if ((lex && (parse || check || llvm)) || (parse && (check || llvm)) || (check && llvm)) {
        std::cerr << "error: invalid option combination" << std::endl;
        return -1;
    }

    if (filename != "") {
        yyin = fopen(filename.c_str(), "r");
        if (!yyin) {
            std::cerr << "error : can't access file -- " << filename << std::endl;
            return -1;
        }
    }

    if(debug) {
        debugger = new Debugger(true);
    } else {
        debugger = new Debugger(false);
    }

    if(extended) {
        debugger->print("Extended detected");

        /* do things to support extend vsop */
    }

    if (lex) {
        debugger->print("Lexing ...");

        int token;
        do {
            token = yylex();
            displayToken(token);
        } while (token != END and token != ERROR);

        debugger->print("Lexing ended");

        fclose(yyin);
        return token == ERROR ? -1 : 0;
    }

    if (parse) {
        debugger->print("Parsing ...");

        if (yyparse() == 1) {
            std::cerr << filename << ":" << yylloc.first_line << ":" << yylloc.first_column << ": syntax error";

            fclose(yyin);
            return -1;
        } else {
            debugger->print("Parsing ended");

            std::cout << *astResult << std::endl;

            fclose(yyin);
            return 0;
        }
    }

    if(check) {
        debugger->print("Checking ...");

        if (yyparse() == 1) {
            std::cerr << filename << ":" << yylloc.first_line << ":" << yylloc.first_column << ": syntax error";

            fclose(yyin);
            return -1;
        } else {
            ASTProcessor *ast_processor = new ASTProcessor(astResult);

            try {
                debugger->print("Parsing ended");

                ast_processor->check();
                debugger->print("Checking ended");

                std::cout << *astResult << std::endl;

                fclose(yyin);
                return 0;
            } catch (const ASTProcessorException &e) {
                std::cerr << e << std::endl;

                fclose(yyin);
                return -1;
            }
        }
    }

    if (llvm) {
        debugger->print("Generating LLVM code");

        std::cerr << "LLVM intermediate representation not implemented" << std::endl;
        return -1;
    }

    std::cerr << "error: can't resolve passed arguments" << std::endl;
    return -1;
}
