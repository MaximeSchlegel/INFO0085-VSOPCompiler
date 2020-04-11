%{
    #include "../../ast_node/ASTNode.h"
    #include "../../exception/Exception.h"

    extern Node* astResult;
    extern std::string filename;

    extern int yyparse(void);
    extern int yylex();
    void yyerror(const char *s) {  };
    extern int yywrap(void) { return 1; };
%}
%code requires {
	#include "../../ast_node/ASTNode.h"
	#include "../../exception/Exception.h"
}

%union {
	int intValue;
  	std::string *strValue;
  	Node *astNode;
  	std::vector<Node *> *nodeVector;
  	std::pair<std::vector<Node *> *, std::vector<Node *> *> *nodeVectorPair;
	ExceptionHolder *lerror;
}

//Terminal
%token <lerror> ERROR				     	// lexical error token
%token END "end-of-file"
%token BOOL INT32 STRING UNIT
%token <strValue> TYPEID	    		     	//  user-defined type
%token TRUE FALSE
%token <intValue> INTLITERAL
%token <strValue> STRLITERAL
%token AND NOT
%token CLASS DO ELSE EXTENDS IF IN ISNULL LET NEW
%token THEN WHILE
%token <strValue> OBJECTID         	    		//  user-defined object
%token LBRACE RBRACE LPAR RPAR COLON SEMICOLON
%token COMMA PLUS MINUS TIMES DIV POW DOT EQUAL
%token LOWER LOWEREQUAL ASSIGN

//Nonterminal
%type <strValue> type
%type <nodeVector> formals args
%type <nodeVectorPair> class_body
%type <astNode> program class field method
%type <astNode> formal block expr literal

//Precedence
%nonassoc THEN
%nonassoc ELSE
%nonassoc DO IN
%right ASSIGN
%left AND
%right NOT
%nonassoc LOWER LOWEREQUAL EQUAL
%left PLUS MINUS
%left TIMES DIV
%left ISNULL NEG
%right POW
%left DOT
%nonassoc LPAR RPAR
%nonassoc LBRACE RBRACE

//start state
%start program



%%
type:
    BOOL      { @$ = @1;
                $$ = new std::string("bool"); }
  | INT32     { @$ = @1;
                $$ = new std::string("int32"); }
  | STRING    { @$ = @1;
                $$ = new std::string("string"); }
  | UNIT      { @$ = @1;
                $$ = new std::string("unit"); }
  | TYPEID    { @$ = @1;
                $$ = $1; }
  ;


literal:
    TRUE          { BoolLiteralNode* ltr = new BoolLiteralNode(true);
    		    ltr->setPosition(filename, @1.first_line, @1.first_column);
                    @$ = @1;
                    $$ = ltr; }
  | FALSE         { BoolLiteralNode* ltr = new BoolLiteralNode(false);
    		    ltr->setPosition(filename, @1.first_line, @1.first_column);
                    @$ = @1;
                    $$ = ltr; }
  | INTLITERAL    { IntLiteralNode* ltr = new IntLiteralNode($1);
    		    ltr->setPosition(filename, @1.first_line, @1.first_column);
                    @$ = @1;
                    $$ = ltr; }
  | STRLITERAL    { StrLiteralNode* ltr = new StrLiteralNode($1);
    		    ltr->setPosition(filename, @1.first_line, @1.first_column);
                    @$ = @1;
                    $$ = ltr; }
  ;


program:
    class           { ProgramNode* prg = new ProgramNode();
    		      prg->setPosition(filename, @1.first_line, @1.first_column);
                      prg->addClass($1);
                      @$ = @1;
                      $$ = prg; }
  | program class   { ProgramNode* prg = (ProgramNode*) $1;
  		      prg->addClass($2);
                      @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                      $$ = $1; }
  | program END     { $$ = $1; astResult = $1;
  		      YYACCEPT; }
  ;


class:
  CLASS TYPEID LBRACE class_body RBRACE                     { ClassNode* cls = new ClassNode($2, new std::string("Object"), $4);
  							      cls->setPosition(filename, @1.first_line, @1.first_column);
                                                              @$ = @1; @$.last_line = @5.last_line; @$.last_column = @5.last_column;
                                                              $$ = cls; }
  | CLASS TYPEID EXTENDS TYPEID LBRACE class_body RBRACE    { ClassNode* cls = new ClassNode($2, $4, $6);
  							      cls->setPosition(filename, @1.first_line, @1.first_column);
                                                              @$ = @1; @$.last_line = @7.last_line; @$.last_column = @7.last_column;
                                                              $$ = cls; }
  ;


class_body:
    /*empty*/            { std::pair<std::vector<Node *> *, std::vector<Node *> *> *bdy = new std::pair<std::vector<Node *> *, std::vector<Node *> *>(nullptr, nullptr);
     			   $$ = bdy; }
  | class_body field     { if (!$1->first) {
  			     $1->first = new std::vector<Node *>();
  			   }
  			   $1->first->push_back($2);
  			   @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                           $$ = $1; }
  | class_body method    { if (!$1->second) {
  			     $1->second = new std::vector<Node *>();
  			   }
  			   $1->second->push_back($2);
  			   @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                           $$ = $1; }
  ;


field:
    OBJECTID COLON type SEMICOLON                { FieldNode* fld = new FieldNode($1, $3);
                                                   fld->setPosition(filename, @1.first_line, @1.first_column);
                                                   @$ = @1; @$.last_line = @4.last_line; @$.last_column = @4.last_column;
                                                   $$ = fld;}
  | OBJECTID COLON type ASSIGN expr SEMICOLON    { FieldNode* fld = new FieldNode($1, $3, $5);
                                                   fld->setPosition(filename, @1.first_line, @1.first_column);
                                                   @$ = @1; @$.last_line = @6.last_line; @$.last_column = @6.last_column;
                                                   $$ = fld; }
  ;


method:
    OBJECTID LPAR formals RPAR COLON type LBRACE block RBRACE    { MethodNode* mtd = new MethodNode($1, $6, $3, $8);
    								   mtd->setPosition(filename, @1.first_line, @1.first_column);
                                                                   @$ = @1; @$.last_line = @9.last_line; @$.last_column = @9.last_column;
                                                                   $$ = mtd; }
  ;

formals:
    /*empty*/               { std::vector<Node *> *fmls = nullptr;
     			      $$ = fmls; }
  | formal		    { std::vector<Node *> *fmls = new std::vector<Node *>();
                              fmls->push_back($1);
                              @$ = @1;
                              $$ = fmls; }
  | formals COMMA formal    { $1->push_back($3);
                              @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                              $$ = $1; }
  ;

formal:
    OBJECTID COLON type    { FormalNode* fml = new FormalNode($1, $3);
                             fml->setPosition(filename, @1.first_line, @1.first_column);
                             @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                             $$ = fml; }
  ;

block:		//put the L/RBARCE in the parent rule
    expr                    { BlockNode* blk = new BlockNode();
                              blk->setPosition(filename, @1.first_line, @1.first_column);
                              blk->addExpr($1);
                              @$ = @1;
                              $$ = blk; }
  | block SEMICOLON expr    { BlockNode* blk = (BlockNode*) $1;
  			      blk->addExpr($3);
                              @$ = @1; @$.last_line = @3.last_line; @$.last_column = @1.last_column;
                              $$ = blk;}
  ;

expr:
    IF expr THEN expr                              { IfNode* expr = new IfNode($2, $4);
    						     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @4.last_line; @$.last_column = @4.last_column;
                                                     $$ = expr; }
  | IF expr THEN expr ELSE expr                    { IfNode* expr = new IfNode($2, $4, $6);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @6.last_line; @$.last_column = @6.last_column;
                                                     $$ = expr; }
  | WHILE expr DO expr                             { WhileNode* expr = new WhileNode($2, $4);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @4.last_line; @$.last_column = @4.last_column;
                                                     $$ = expr; }
  | LET OBJECTID COLON type IN expr                { LetNode* expr = new LetNode($2, $4, $6);
                                                     expr->setPosition(filename, @1.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @6.last_line; @$.last_column = @6.last_column;
                                                     $$ = expr; }
  | LET OBJECTID COLON type ASSIGN expr IN expr    { LetNode* expr = new LetNode($2, $4, $6, $8);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @8.last_line; @$.last_column = @8.last_column;
                                                     $$ = expr; }
  | OBJECTID ASSIGN expr                           { AssignNode* expr = new AssignNode($1, $3);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr AND expr                                  { AndNode* expr = new AndNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr EQUAL expr                                { EqualNode* expr = new EqualNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr LOWER expr                                { LowerNode* expr = new LowerNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr LOWEREQUAL expr                           { LowerEqualNode* expr = new LowerEqualNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr PLUS expr                                 { PlusNode* expr = new PlusNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr MINUS expr                                { MinusNode* expr = new MinusNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr TIMES expr                                { TimesNode* expr = new TimesNode($1, $3);
  						     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr DIV expr                                  { DivNode* expr = new DivNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | expr POW expr                                  { PowNode* expr = new PowNode($1, $3);
                                                     expr->setPosition(filename, @2.first_line, @2.first_column);
                                                     @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = expr; }
  | NOT expr                                       { NotNode* expr = new NotNode($2);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                                                     $$ = expr; }
  | MINUS expr  %prec NEG                          { NegNode* expr = new NegNode($2);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                                                     $$ = expr; }
  | ISNULL expr                                    { IsNullNode* expr = new IsNullNode($2);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                                                     $$ = expr; }
  | OBJECTID LPAR args RPAR                        { ObjectNode* obj = new ObjectNode(new std::string("self"));
                                                     obj->setPosition(filename, @1.first_line, @1.first_column);
  						     CallNode* expr = new CallNode($1, obj, $3);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @4.last_line; @$.last_column = @4.last_column;
                                                     $$ = expr; }
  | expr DOT OBJECTID LPAR args RPAR               { CallNode* expr = new CallNode($3, $1, $5);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @4.last_line; @$.last_column = @4.last_column;
                                                     $$ = expr; }
  | NEW TYPEID                                     { NewNode* expr = new NewNode($2);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                                                     $$ = expr; }
  | OBJECTID                                       { ObjectNode* expr = new ObjectNode($1);
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1;
                                                     $$ = expr; }
  | literal                                        { @$ = @1;
                                                     $$ = $1; }
  | LPAR expr RPAR                                 { @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = $2; }
  | LPAR RPAR                                      { UnitNode* expr = new UnitNode();
                                                     expr->setPosition(filename, @1.first_line, @1.first_column);
                                                     @$ = @1; @$.last_line = @2.last_line; @$.last_column = @2.last_column;
                                                     $$ = expr; }
  | LBRACE block RBRACE                            { @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                                                     $$ = $2; }
  ;

args:
    /*empty*/          { std::vector<Node *> *args = nullptr;
     			 $$ = args; }
  | expr               { std::vector<Node *> *args = new std::vector<Node *>();
  			 args->push_back($1);
  			 @$ = @1;
                         $$ = args; }
  | args COMMA expr    { $1->push_back($3);
  			 @$ = @1; @$.last_line = @3.last_line; @$.last_column = @3.last_column;
                         $$ = $1; }
  ;


%%