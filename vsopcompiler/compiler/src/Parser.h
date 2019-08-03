/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_COMPILER_SRC_PARSER_H_INCLUDED
# define YY_YY_COMPILER_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 13 "compiler/vsop_parser.y" /* yacc.c:1921  */

	#include "../../ast_node/ASTNode.h"
	#include "../../exception/Exception.h"

#line 53 "compiler/src/Parser.h" /* yacc.c:1921  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERROR = 258,
    END = 259,
    BOOL = 260,
    INT32 = 261,
    STRING = 262,
    UNIT = 263,
    TYPEID = 264,
    TRUE = 265,
    FALSE = 266,
    INTLITERAL = 267,
    STRLITERAL = 268,
    AND = 269,
    NOT = 270,
    CLASS = 271,
    DO = 272,
    ELSE = 273,
    EXTENDS = 274,
    IF = 275,
    IN = 276,
    ISNULL = 277,
    LET = 278,
    NEW = 279,
    THEN = 280,
    WHILE = 281,
    OBJECTID = 282,
    LBRACE = 283,
    RBRACE = 284,
    LPAR = 285,
    RPAR = 286,
    COLON = 287,
    SEMICOLON = 288,
    COMMA = 289,
    PLUS = 290,
    MINUS = 291,
    TIMES = 292,
    DIV = 293,
    POW = 294,
    DOT = 295,
    EQUAL = 296,
    LOWER = 297,
    LOWEREQUAL = 298,
    ASSIGN = 299,
    NEG = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "compiler/vsop_parser.y" /* yacc.c:1921  */

	int intValue;
  	std::string *strValue;
  	Node *astNode;
  	std::vector<Node *> *nodeVector;
  	std::pair<std::vector<Node *> *, std::vector<Node *> *> *nodeVectorPair;
	LexerException *lerror;

#line 120 "compiler/src/Parser.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_COMPILER_SRC_PARSER_H_INCLUDED  */
