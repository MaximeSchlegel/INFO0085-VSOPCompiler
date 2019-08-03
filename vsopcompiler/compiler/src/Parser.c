/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compiler/vsop_parser.y" /* yacc.c:337  */

    #include "../../ast_node/ASTNode.h"
    #include "../../exception/Exception.h"

    extern Node* astResult;
    extern std::string filename;

    extern int yyparse(void);
    extern int yylex();
    void yyerror(const char *s) {  };
    extern int yywrap(void) { return 1; };

#line 83 "compiler/src/Parser.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.h".  */
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
#line 13 "compiler/vsop_parser.y" /* yacc.c:352  */

	#include "../../ast_node/ASTNode.h"
	#include "../../exception/Exception.h"

#line 121 "compiler/src/Parser.c" /* yacc.c:352  */

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
#line 18 "compiler/vsop_parser.y" /* yacc.c:352  */

	int intValue;
  	std::string *strValue;
  	Node *astNode;
  	std::vector<Node *> *nodeVector;
  	std::pair<std::vector<Node *> *, std::vector<Node *> *> *nodeVectorPair;
	LexerException *lerror;

#line 188 "compiler/src/Parser.c" /* yacc.c:352  */
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



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

#define YYUNDEFTOK  2
#define YYMAXUTOK   300

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    75,    77,    79,    81,    87,    91,    95,
      99,   107,   112,   116,   122,   126,   134,   136,   142,   152,
     156,   164,   171,   173,   177,   183,   190,   195,   202,   206,
     210,   214,   218,   222,   226,   230,   234,   238,   242,   246,
     250,   254,   258,   262,   266,   270,   274,   280,   284,   288,
     292,   294,   296,   300,   305,   307,   311
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "\"end-of-file\"", "BOOL",
  "INT32", "STRING", "UNIT", "TYPEID", "TRUE", "FALSE", "INTLITERAL",
  "STRLITERAL", "AND", "NOT", "CLASS", "DO", "ELSE", "EXTENDS", "IF", "IN",
  "ISNULL", "LET", "NEW", "THEN", "WHILE", "OBJECTID", "LBRACE", "RBRACE",
  "LPAR", "RPAR", "COLON", "SEMICOLON", "COMMA", "PLUS", "MINUS", "TIMES",
  "DIV", "POW", "DOT", "EQUAL", "LOWER", "LOWEREQUAL", "ASSIGN", "NEG",
  "$accept", "type", "literal", "program", "class", "class_body", "field",
  "method", "formals", "formal", "block", "expr", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    12,    14,   -35,   -16,   -35,   -35,   -35,    22,   -35,
       4,   -23,   -35,    19,   -35,   -35,   -35,    40,    18,   134,
     -35,     9,    -8,   -35,   -35,   -35,   -35,   -35,   -35,   -22,
     134,    23,    18,   -35,   180,   -35,   134,   -35,   -35,   -35,
     -35,   -35,   180,   180,   180,    44,    70,   180,   -25,   180,
     158,   180,   -35,    21,    54,   182,    52,    45,    41,   -35,
      64,   180,   180,    -9,   112,   -35,    82,    45,   180,   -35,
     180,   180,   180,   180,   180,    53,   180,   180,   180,   180,
     180,   134,   180,   112,    16,   112,   -35,   180,   -35,   182,
     137,   137,    45,    45,    45,    56,   191,   191,   191,     0,
      94,   -19,   112,   -35,   180,   112,   180,   -35,   180,   180,
     180,   112,    34,   112,   112,   124,   -35,   180,   112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    11,     0,     1,    13,    12,     0,    16,
       0,     0,    16,     0,    14,    17,    18,     0,    22,     0,
      15,     0,     0,    23,     2,     3,     4,     5,     6,     0,
       0,     0,     0,    19,     0,    25,     0,    24,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    50,     0,     0,    43,     0,    45,     0,    48,
       0,    54,     0,     0,    26,    52,     0,    44,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,    33,    53,     0,    51,    34,
      38,    39,    40,    41,    42,     0,    35,    36,    37,     0,
      28,     0,    30,    46,     0,    27,    54,    21,     0,     0,
       0,    56,     0,    29,    31,     0,    47,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -29,   -35,   -35,    95,    86,   -35,   -35,   -35,    77,
      31,   -34,     5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    29,    52,     2,     3,    11,    15,    16,    22,    23,
      63,    64,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      53,    35,   109,     8,    13,    61,    14,    54,    55,    56,
      57,    33,     9,    60,     5,     1,    66,    67,     6,    62,
      86,     4,    34,    31,    87,   110,    32,    83,    85,   107,
       1,    10,    12,    87,    89,    68,    90,    91,    92,    93,
      94,    30,    96,    97,    98,    21,   100,   103,   102,    18,
     104,    19,   101,   105,    69,    36,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   116,    68,    13,   104,    20,
     111,    58,    83,    81,   113,   114,   115,    80,    68,    59,
      95,    82,    79,   118,    74,    75,   106,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    68,     7,    17,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    68,    37,
      99,   112,   108,    88,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    68,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    68,    24,
      25,    26,    27,    28,     0,   117,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    38,    39,
      40,    41,     0,    42,    72,    73,    74,    75,    43,     0,
      44,    45,    46,     0,    47,    48,    49,     0,    50,    65,
      38,    39,    40,    41,    51,    42,     0,     0,     0,     0,
      43,     0,    44,    45,    46,     0,    47,    48,    49,     0,
      50,     0,     0,     0,     0,     0,    51,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1
};

static const yytype_int8 yycheck[] =
{
      34,    30,    21,    19,    27,    30,    29,    36,    42,    43,
      44,    33,    28,    47,     0,    16,    50,    51,     4,    44,
      29,     9,    44,    31,    33,    44,    34,    61,    62,    29,
      16,     9,    28,    33,    68,    14,    70,    71,    72,    73,
      74,    32,    76,    77,    78,    27,    80,    31,    82,    30,
      34,    32,    81,    87,    33,    32,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    31,    14,    27,    34,    29,
     104,    27,   106,    32,   108,   109,   110,    25,    14,     9,
      27,    17,    28,   117,    39,    40,    30,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    14,     2,    12,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    14,    32,
      79,   106,    18,    31,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    14,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    14,     5,
       6,     7,     8,     9,    -1,    21,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    10,    11,
      12,    13,    -1,    15,    37,    38,    39,    40,    20,    -1,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    31,
      10,    11,    12,    13,    36,    15,    -1,    -1,    -1,    -1,
      20,    -1,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    35,    36,    37,    38,
      39,    40,    41,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    49,    50,     9,     0,     4,    50,    19,    28,
       9,    51,    28,    27,    29,    52,    53,    51,    30,    32,
      29,    27,    54,    55,     5,     6,     7,     8,     9,    47,
      32,    31,    34,    33,    44,    47,    32,    55,    10,    11,
      12,    13,    15,    20,    22,    23,    24,    26,    27,    28,
      30,    36,    48,    57,    47,    57,    57,    57,    27,     9,
      57,    30,    44,    56,    57,    31,    57,    57,    14,    33,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    28,
      25,    32,    17,    57,    58,    57,    29,    33,    31,    57,
      57,    57,    57,    57,    57,    27,    57,    57,    57,    56,
      57,    47,    57,    31,    34,    57,    30,    29,    18,    21,
      44,    57,    58,    57,    57,    57,    31,    21,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    47,    48,    48,    48,
      48,    49,    49,    49,    50,    50,    51,    51,    51,    52,
      52,    53,    54,    54,    54,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     5,     7,     0,     2,     2,     4,
       6,     9,     0,     1,     3,     3,     1,     3,     4,     6,
       4,     6,     8,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     4,     6,     2,     1,
       1,     3,     2,     3,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 73 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[0]);
                (yyval.strValue) = new std::string("bool"); }
#line 1490 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 3:
#line 75 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[0]);
                (yyval.strValue) = new std::string("int32"); }
#line 1497 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 4:
#line 77 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[0]);
                (yyval.strValue) = new std::string("string"); }
#line 1504 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 5:
#line 79 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[0]);
                (yyval.strValue) = new std::string("unit"); }
#line 1511 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 81 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[0]);
                (yyval.strValue) = (yyvsp[0].strValue); }
#line 1518 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 7:
#line 87 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { BoolLiteralNode* ltr = new BoolLiteralNode(true);
    		    ltr->setPosition(filename, (yylsp[0]).first_line, (yylsp[0]).first_column);
                    (yyloc) = (yylsp[0]);
                    (yyval.astNode) = ltr; }
#line 1527 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 8:
#line 91 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { BoolLiteralNode* ltr = new BoolLiteralNode(false);
    		    ltr->setPosition(filename, (yylsp[0]).first_line, (yylsp[0]).first_column);
                    (yyloc) = (yylsp[0]);
                    (yyval.astNode) = ltr; }
#line 1536 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 95 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { IntLiteralNode* ltr = new IntLiteralNode((yyvsp[0].intValue));
    		    ltr->setPosition(filename, (yylsp[0]).first_line, (yylsp[0]).first_column);
                    (yyloc) = (yylsp[0]);
                    (yyval.astNode) = ltr; }
#line 1545 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 99 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { StrLiteralNode* ltr = new StrLiteralNode((yyvsp[0].strValue));
    		    ltr->setPosition(filename, (yylsp[0]).first_line, (yylsp[0]).first_column);
                    (yyloc) = (yylsp[0]);
                    (yyval.astNode) = ltr; }
#line 1554 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 107 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { ProgramNode* prg = new ProgramNode();
    		      prg->setPosition(filename, (yylsp[0]).first_line, (yylsp[0]).first_column);
                      prg->addClass((yyvsp[0].astNode));
                      (yyloc) = (yylsp[0]);
                      (yyval.astNode) = prg; }
#line 1564 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 112 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { ProgramNode* prg = (ProgramNode*) (yyvsp[-1].astNode);
  		      prg->addClass((yyvsp[0].astNode));
                      (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                      (yyval.astNode) = (yyvsp[-1].astNode); }
#line 1573 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 116 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyval.astNode) = (yyvsp[-1].astNode); astResult = (yyvsp[-1].astNode);
  		      YYACCEPT; }
#line 1580 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 122 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { ClassNode* cls = new ClassNode((yyvsp[-3].strValue), new std::string("Object"), (yyvsp[-1].nodeVectorPair));
  							      cls->setPosition(filename, (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                              (yyloc) = (yylsp[-4]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                              (yyval.astNode) = cls; }
#line 1589 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 126 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { ClassNode* cls = new ClassNode((yyvsp[-5].strValue), (yyvsp[-3].strValue), (yyvsp[-1].nodeVectorPair));
  							      cls->setPosition(filename, (yylsp[-6]).first_line, (yylsp[-6]).first_column);
                                                              (yyloc) = (yylsp[-6]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                              (yyval.astNode) = cls; }
#line 1598 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 134 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { std::pair<std::vector<Node *> *, std::vector<Node *> *> *bdy = new std::pair<std::vector<Node *> *, std::vector<Node *> *>(nullptr, nullptr);
     			   (yyval.nodeVectorPair) = bdy; }
#line 1605 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 136 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { if (!(yyvsp[-1].nodeVectorPair)->first) {
  			     (yyvsp[-1].nodeVectorPair)->first = new std::vector<Node *>();
  			   }
  			   (yyvsp[-1].nodeVectorPair)->first->push_back((yyvsp[0].astNode));
  			   (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                           (yyval.nodeVectorPair) = (yyvsp[-1].nodeVectorPair); }
#line 1616 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 142 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { if (!(yyvsp[-1].nodeVectorPair)->second) {
  			     (yyvsp[-1].nodeVectorPair)->second = new std::vector<Node *>();
  			   }
  			   (yyvsp[-1].nodeVectorPair)->second->push_back((yyvsp[0].astNode));
  			   (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                           (yyval.nodeVectorPair) = (yyvsp[-1].nodeVectorPair); }
#line 1627 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 152 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { FieldNode* fld = new FieldNode((yyvsp[-3].strValue), (yyvsp[-1].strValue));
                                                   fld->setPosition(filename, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                   (yyloc) = (yylsp[-3]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                   (yyval.astNode) = fld;}
#line 1636 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 156 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { FieldNode* fld = new FieldNode((yyvsp[-5].strValue), (yyvsp[-3].strValue), (yyvsp[-1].astNode));
                                                   fld->setPosition(filename, (yylsp[-5]).first_line, (yylsp[-5]).first_column);
                                                   (yyloc) = (yylsp[-5]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                   (yyval.astNode) = fld; }
#line 1645 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 21:
#line 164 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { MethodNode* mtd = new MethodNode((yyvsp[-8].strValue), (yyvsp[-3].strValue), (yyvsp[-6].nodeVector), (yyvsp[-1].astNode));
    								   mtd->setPosition(filename, (yylsp[-8]).first_line, (yylsp[-8]).first_column);
                                                                   (yyloc) = (yylsp[-8]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                                   (yyval.astNode) = mtd; }
#line 1654 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 171 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { std::vector<Node *> *fmls = nullptr;
     			      (yyval.nodeVector) = fmls; }
#line 1661 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 173 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { std::vector<Node *> *fmls = new std::vector<Node *>();
                              fmls->push_back((yyvsp[0].astNode));
                              (yyloc) = (yylsp[0]);
                              (yyval.nodeVector) = fmls; }
#line 1670 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 177 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyvsp[-2].nodeVector)->push_back((yyvsp[0].astNode));
                              (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                              (yyval.nodeVector) = (yyvsp[-2].nodeVector); }
#line 1678 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 183 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { FormalNode* fml = new FormalNode((yyvsp[-2].strValue), (yyvsp[0].strValue));
                             fml->setPosition(filename, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                             (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                             (yyval.astNode) = fml; }
#line 1687 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 190 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { BlockNode* blk = new BlockNode();
                              blk->setPosition(filename, (yylsp[0]).first_line, (yylsp[0]).first_column);
                              blk->addExpr((yyvsp[0].astNode));
                              (yyloc) = (yylsp[0]);
                              (yyval.astNode) = blk; }
#line 1697 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 27:
#line 195 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { BlockNode* blk = (BlockNode*) (yyvsp[-2].astNode);
  			      blk->addExpr((yyvsp[0].astNode));
                              (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[-2]).last_column;
                              (yyval.astNode) = blk;}
#line 1706 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 28:
#line 202 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { IfNode* expr = new IfNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
    						     expr->setPosition(filename, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                     (yyloc) = (yylsp[-3]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1715 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 29:
#line 206 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { IfNode* expr = new IfNode((yyvsp[-4].astNode), (yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-5]).first_line, (yylsp[-5]).first_column);
                                                     (yyloc) = (yylsp[-5]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1724 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 210 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { WhileNode* expr = new WhileNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                     (yyloc) = (yylsp[-3]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1733 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 214 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { LetNode* expr = new LetNode((yyvsp[-4].strValue), (yyvsp[-2].strValue), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-5]).first_line, (yylsp[-4]).first_column);
                                                     (yyloc) = (yylsp[-5]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1742 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 218 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { LetNode* expr = new LetNode((yyvsp[-6].strValue), (yyvsp[-4].strValue), (yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-7]).first_line, (yylsp[-7]).first_column);
                                                     (yyloc) = (yylsp[-7]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1751 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 222 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { AssignNode* expr = new AssignNode((yyvsp[-2].strValue), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1760 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 226 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { AndNode* expr = new AndNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1769 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 230 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { EqualNode* expr = new EqualNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1778 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 234 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { LowerNode* expr = new LowerNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1787 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 238 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { LowerEqualNode* expr = new LowerEqualNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1796 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 242 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { PlusNode* expr = new PlusNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1805 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 39:
#line 246 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { MinusNode* expr = new MinusNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1814 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 250 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { TimesNode* expr = new TimesNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
  						     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1823 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 254 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { DivNode* expr = new DivNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1832 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 258 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { PowNode* expr = new PowNode((yyvsp[-2].astNode), (yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1841 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 262 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { NotNode* expr = new NotNode((yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1850 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 44:
#line 266 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { NegNode* expr = new NegNode((yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1859 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 45:
#line 270 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { IsNullNode* expr = new IsNullNode((yyvsp[0].astNode));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1868 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 46:
#line 274 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { ObjectNode* obj = new ObjectNode(new std::string("self"));
                                                     obj->setPosition(filename, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
  						     CallNode* expr = new CallNode((yyvsp[-3].strValue), obj, (yyvsp[-1].nodeVector));
                                                     expr->setPosition(filename, (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                     (yyloc) = (yylsp[-3]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1879 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 47:
#line 280 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { CallNode* expr = new CallNode((yyvsp[-3].strValue), (yyvsp[-5].astNode), (yyvsp[-1].nodeVector));
                                                     expr->setPosition(filename, (yylsp[-5]).first_line, (yylsp[-5]).first_column);
                                                     (yyloc) = (yylsp[-5]); (yyloc).last_line = (yylsp[-2]).last_line; (yyloc).last_column = (yylsp[-2]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1888 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 48:
#line 284 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { NewNode* expr = new NewNode((yyvsp[0].strValue));
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1897 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 49:
#line 288 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { ObjectNode* expr = new ObjectNode((yyvsp[0].strValue));
                                                     expr->setPosition(filename, (yylsp[0]).first_line, (yylsp[0]).first_column);
                                                     (yyloc) = (yylsp[0]);
                                                     (yyval.astNode) = expr; }
#line 1906 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 292 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[0]);
                                                     (yyval.astNode) = (yyvsp[0].astNode); }
#line 1913 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 294 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = (yyvsp[-1].astNode); }
#line 1920 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 52:
#line 296 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { UnitNode* expr = new UnitNode();
                                                     expr->setPosition(filename, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                     (yyloc) = (yylsp[-1]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = expr; }
#line 1929 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 53:
#line 300 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                                                     (yyval.astNode) = (yyvsp[-1].astNode); }
#line 1936 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 54:
#line 305 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { std::vector<Node *> *args = nullptr;
     			 (yyval.nodeVector) = args; }
#line 1943 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 55:
#line 307 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { std::vector<Node *> *args = new std::vector<Node *>();
  			 args->push_back((yyvsp[0].astNode));
  			 (yyloc) = (yylsp[0]);
                         (yyval.nodeVector) = args; }
#line 1952 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;

  case 56:
#line 311 "compiler/vsop_parser.y" /* yacc.c:1652  */
    { (yyvsp[-2].nodeVector)->push_back((yyvsp[0].astNode));
  			 (yyloc) = (yylsp[-2]); (yyloc).last_line = (yylsp[0]).last_line; (yyloc).last_column = (yylsp[0]).last_column;
                         (yyval.nodeVector) = (yyvsp[-2].nodeVector); }
#line 1960 "compiler/src/Parser.c" /* yacc.c:1652  */
    break;


#line 1964 "compiler/src/Parser.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 317 "compiler/vsop_parser.y" /* yacc.c:1918  */
