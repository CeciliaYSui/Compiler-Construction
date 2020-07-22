/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ADDITION = 258,
     SUBTRACTION = 259,
     MULTIPLICATION = 260,
     DIVISION = 261,
     MODULUS = 262,
     LESSTHAN = 263,
     GREATERTHAN = 264,
     LESSOREQUAL = 265,
     GREATEROREQUAL = 266,
     EQUAL = 267,
     NOTEQUAL = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     LPARENTH = 272,
     RPARENTH = 273,
     LBRACKET = 274,
     RBRACKET = 275,
     SEMICOLON = 276,
     COLON = 277,
     COMMA = 278,
     ASSIGN = 279,
     CARRIAGERETURN = 280,
     MAIN = 281,
     END = 282,
     EXIT = 283,
     IF = 284,
     ELSE = 285,
     WHILE = 286,
     TO = 287,
     COUNTING = 288,
     UPWARD = 289,
     DOWNWARD = 290,
     REAL = 291,
     INTEGER = 292,
     DATA = 293,
     ALGORITHM = 294,
     READ = 295,
     PRINT = 296,
     VARIABLE = 297,
     STRING = 298,
     INTCONSTANT = 299,
     REALCONSTANT = 300
   };
#endif
/* Tokens.  */
#define ADDITION 258
#define SUBTRACTION 259
#define MULTIPLICATION 260
#define DIVISION 261
#define MODULUS 262
#define LESSTHAN 263
#define GREATERTHAN 264
#define LESSOREQUAL 265
#define GREATEROREQUAL 266
#define EQUAL 267
#define NOTEQUAL 268
#define AND 269
#define OR 270
#define NOT 271
#define LPARENTH 272
#define RPARENTH 273
#define LBRACKET 274
#define RBRACKET 275
#define SEMICOLON 276
#define COLON 277
#define COMMA 278
#define ASSIGN 279
#define CARRIAGERETURN 280
#define MAIN 281
#define END 282
#define EXIT 283
#define IF 284
#define ELSE 285
#define WHILE 286
#define TO 287
#define COUNTING 288
#define UPWARD 289
#define DOWNWARD 290
#define REAL 291
#define INTEGER 292
#define DATA 293
#define ALGORITHM 294
#define READ 295
#define PRINT 296
#define VARIABLE 297
#define STRING 298
#define INTCONSTANT 299
#define REALCONSTANT 300




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

/*
 * ========================================================================
 * Author ---------------- Cecilia Y. Sui
 * Course ---------------- Compiler Construction
 * Filename -------------- parser.y
 * Date of Submission ---- December 3, 2019
 * Assignment ------------ Checkpoint #8 
 * Description ----------- Fully implemented parser 
 *
 * Warning --------------- Modulus operator not working
 * ----------------------- Counting loops not working 
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "AST.h" 
#include "ST.h"

int yyerror();
int yylex();
int yyparse(); 

Type currType; 
Node *root; 



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 32 "parser.y"
{
   int intval; 
   float realval; 
   char *sval;
   Node *node; 
}
/* Line 193 of yacc.c.  */
#line 222 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 235 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    11,    15,    18,    20,    23,    28,    30,
      32,    34,    38,    39,    41,    46,    50,    53,    54,    56,
      58,    60,    62,    64,    66,    68,    70,    72,    77,    85,
      96,   104,   116,   128,   131,   135,   139,   141,   145,   147,
     149,   151,   153,   156,   160,   164,   166,   170,   174,   178,
     182,   186,   190,   192,   196,   200,   203,   205,   209,   213,
     217,   219,   223,   225,   227,   229,   231
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    26,    21,    48,    54,    27,    26,    21,
      -1,    38,    22,    49,    -1,    38,    22,    -1,    50,    -1,
      50,    49,    -1,    51,    22,    52,    21,    -1,    36,    -1,
      37,    -1,    53,    -1,    53,    23,    52,    -1,    -1,    42,
      -1,    42,    19,    44,    20,    -1,    39,    22,    55,    -1,
      56,    55,    -1,    -1,    57,    -1,    61,    -1,    62,    -1,
      58,    -1,    59,    -1,    60,    -1,    64,    -1,    65,    -1,
      63,    -1,    74,    24,    68,    21,    -1,    29,    68,    21,
      55,    27,    29,    21,    -1,    29,    68,    21,    55,    30,
      21,    55,    27,    29,    21,    -1,    31,    68,    21,    55,
      27,    31,    21,    -1,    33,    74,    34,    68,    32,    68,
      21,    55,    27,    33,    21,    -1,    33,    74,    35,    68,
      32,    68,    21,    55,    27,    33,    21,    -1,    28,    21,
      -1,    40,    74,    21,    -1,    41,    66,    21,    -1,    67,
      -1,    67,    23,    66,    -1,    68,    -1,    43,    -1,    25,
      -1,    69,    -1,    16,    68,    -1,    69,    14,    68,    -1,
      69,    15,    68,    -1,    70,    -1,    69,     8,    70,    -1,
      69,     9,    70,    -1,    69,    10,    70,    -1,    69,    11,
      70,    -1,    69,    12,    70,    -1,    69,    13,    70,    -1,
      71,    -1,    70,     3,    71,    -1,    70,     4,    71,    -1,
       4,    71,    -1,    72,    -1,    71,     5,    72,    -1,    71,
       6,    72,    -1,    71,     7,    72,    -1,    73,    -1,    17,
      68,    18,    -1,    74,    -1,    44,    -1,    45,    -1,    42,
      -1,    42,    19,    68,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   122,   123,   126,   127,   130,   132,   133,
     136,   137,   138,   141,   149,   159,   164,   166,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   180,   187,   193,
     200,   206,   215,   226,   230,   235,   240,   241,   245,   246,
     249,   255,   256,   259,   263,   269,   270,   274,   278,   282,
     286,   290,   296,   297,   301,   305,   310,   311,   315,   319,
     325,   326,   329,   330,   334,   340,   343
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADDITION", "SUBTRACTION",
  "MULTIPLICATION", "DIVISION", "MODULUS", "LESSTHAN", "GREATERTHAN",
  "LESSOREQUAL", "GREATEROREQUAL", "EQUAL", "NOTEQUAL", "AND", "OR", "NOT",
  "LPARENTH", "RPARENTH", "LBRACKET", "RBRACKET", "SEMICOLON", "COLON",
  "COMMA", "ASSIGN", "CARRIAGERETURN", "MAIN", "END", "EXIT", "IF", "ELSE",
  "WHILE", "TO", "COUNTING", "UPWARD", "DOWNWARD", "REAL", "INTEGER",
  "DATA", "ALGORITHM", "READ", "PRINT", "VARIABLE", "STRING",
  "INTCONSTANT", "REALCONSTANT", "$accept", "program", "data",
  "fulldeclaration", "declaration", "datatype", "varlist", "item",
  "algorithm", "body", "statement", "assignment", "ifstatement", "ifesle",
  "whileloop", "countup", "countdown", "exit", "read", "print",
  "printlist", "printitem", "fullexpression", "comparison", "expression",
  "term", "factor", "atom", "variable", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    52,    53,    53,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    71,
      72,    72,    73,    73,    73,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     3,     2,     1,     2,     4,     1,     1,
       1,     3,     0,     1,     4,     3,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     7,    10,
       7,    11,    11,     2,     3,     3,     1,     3,     1,     1,
       1,     1,     2,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     2,     1,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     0,     0,
       8,     9,     3,     5,     0,    17,     0,     6,    12,     0,
       0,     0,     0,     0,     0,    65,    15,    17,    18,    21,
      22,    23,    19,    20,    26,    24,    25,     0,     0,    13,
       0,    10,    33,     0,     0,     0,    63,    64,     0,    41,
      45,    52,    56,    60,    62,     0,     0,     0,    40,    39,
       0,    36,    38,     0,    16,     0,     2,     0,     7,    12,
      55,    42,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,     0,
      34,    35,     0,     0,     0,     0,    11,    61,     0,    46,
      47,    48,    49,    50,    51,    43,    44,    53,    54,    57,
      58,    59,     0,     0,     0,    37,    66,    27,    14,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,    28,
       0,    30,    17,    17,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    31,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,    12,    13,    14,    40,    41,     9,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      60,    61,    62,    49,    50,    51,    52,    53,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int8 yypact[] =
{
     -22,    -8,    35,     8,   -65,    31,    24,    12,    44,    40,
     -65,   -65,   -65,    12,    46,    51,    45,   -65,    32,    52,
      15,    15,    33,    33,    -2,    57,   -65,    51,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,    59,    60,    66,
      65,    64,   -65,    -6,    15,    15,   -65,   -65,    67,   111,
      47,    11,   -65,   -65,   -65,    68,    21,    69,   -65,   -65,
      73,    72,   -65,    15,   -65,    15,   -65,    53,   -65,    32,
      11,   -65,    78,    51,    20,    20,    20,    20,    20,    20,
      15,    15,    -6,    -6,    -6,    -6,    -6,    51,    15,    15,
     -65,   -65,    -2,    80,    77,    81,   -65,   -65,   -24,    47,
      47,    47,    47,    47,    47,   -65,   -65,    11,    11,   -65,
     -65,   -65,    75,    71,    76,   -65,   -65,   -65,   -65,    84,
      83,    74,    15,    15,    88,    51,    93,    94,    95,   -65,
     100,   -65,    51,    51,    99,   102,   103,   110,   101,   104,
     -65,   112,   114,   -65,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   119,   -65,   -65,    70,   -65,   -65,   -26,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
      48,   -65,   -11,   -65,   -49,   -38,   -64,   -65,   -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      37,    64,    43,   119,     1,    70,   120,    56,    57,    48,
      55,    45,    37,     3,    44,    45,    84,    85,    86,    43,
     109,   110,   111,    58,    43,    99,   100,   101,   102,   103,
     104,    44,    45,    71,    72,     4,    25,    45,    46,    47,
      25,    59,    46,    47,   107,   108,     5,    98,    10,    11,
      82,    83,    93,     7,    94,    88,    89,    25,    37,    46,
      47,   112,    25,     8,    46,    47,    15,    16,    18,   105,
     106,    38,    37,    42,    39,    25,    63,   113,   114,    19,
      20,    66,    21,    65,    22,    67,    68,    69,    73,    87,
      90,    23,    24,    25,    91,    92,    97,    95,   117,   130,
     116,   118,   121,   122,   125,   126,   135,   136,   123,   129,
      37,   127,   128,   124,   131,   132,   133,    37,    37,    74,
      75,    76,    77,    78,    79,    80,    81,   134,   137,   138,
     139,   140,    17,   143,   141,   144,     0,   142,     0,    96,
     115
};

static const yytype_int16 yycheck[] =
{
      15,    27,     4,    27,    26,    43,    30,    22,    23,    20,
      21,    17,    27,    21,    16,    17,     5,     6,     7,     4,
      84,    85,    86,    25,     4,    74,    75,    76,    77,    78,
      79,    16,    17,    44,    45,     0,    42,    17,    44,    45,
      42,    43,    44,    45,    82,    83,    38,    73,    36,    37,
       3,     4,    63,    22,    65,    34,    35,    42,    73,    44,
      45,    87,    42,    39,    44,    45,    22,    27,    22,    80,
      81,    26,    87,    21,    42,    42,    19,    88,    89,    28,
      29,    21,    31,    24,    33,    19,    21,    23,    21,    21,
      21,    40,    41,    42,    21,    23,    18,    44,    21,   125,
      20,    20,    27,    32,    21,    31,   132,   133,    32,    21,
     125,   122,   123,    29,    21,    21,    21,   132,   133,     8,
       9,    10,    11,    12,    13,    14,    15,    27,    29,    27,
      27,    21,    13,    21,    33,    21,    -1,    33,    -1,    69,
      92
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    47,    21,     0,    38,    48,    22,    39,    54,
      36,    37,    49,    50,    51,    22,    27,    49,    22,    28,
      29,    31,    33,    40,    41,    42,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    74,    26,    42,
      52,    53,    21,     4,    16,    17,    44,    45,    68,    69,
      70,    71,    72,    73,    74,    68,    74,    74,    25,    43,
      66,    67,    68,    19,    55,    24,    21,    19,    21,    23,
      71,    68,    68,    21,     8,     9,    10,    11,    12,    13,
      14,    15,     3,     4,     5,     6,     7,    21,    34,    35,
      21,    21,    23,    68,    68,    44,    52,    18,    55,    70,
      70,    70,    70,    70,    70,    68,    68,    71,    71,    72,
      72,    72,    55,    68,    68,    66,    20,    21,    20,    27,
      30,    27,    32,    32,    29,    21,    31,    68,    68,    21,
      55,    21,    21,    21,    27,    55,    55,    29,    27,    27,
      21,    33,    33,    21,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 117 "parser.y"
    { root = (yyvsp[(4) - (7)].node); }
    break;

  case 8:
#line 132 "parser.y"
    { currType = TYPE_REAL; }
    break;

  case 9:
#line 133 "parser.y"
    { currType = TYPE_INT; }
    break;

  case 13:
#line 141 "parser.y"
    { if (STLookup((yyvsp[(1) - (1)].sval))!=NULL) { 
                                 yyerror("Duplicate Declaration! "); 
                                 YYERROR; 
                            }
                            else {
                                 STInsert(currType, (yyvsp[(1) - (1)].sval), 1, 0); 
                                 } 
                           }
    break;

  case 14:
#line 149 "parser.y"
    { if (STLookup((yyvsp[(1) - (4)].sval)) != NULL) {
                                                               yyerror("Duplicate Declaration! ");
                                                               YYERROR; 
                                                         }
                                                         else {STInsert(currType, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].intval), 1);}
                                                         }
    break;

  case 15:
#line 159 "parser.y"
    { (yyval.node) = (yyvsp[(3) - (3)].node); 
                                        STInsert(TYPE_INT, "$aMod", 1, 0); 
                                        STInsert(TYPE_INT, "$bMod", 1, 0); }
    break;

  case 16:
#line 164 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); 
                                  (yyval.node)->next = (yyvsp[(2) - (2)].node); }
    break;

  case 17:
#line 166 "parser.y"
    {(yyval.node) = NULL; }
    break;

  case 18:
#line 169 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 19:
#line 170 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 20:
#line 171 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 21:
#line 172 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 22:
#line 173 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 23:
#line 174 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 24:
#line 175 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 25:
#line 176 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 26:
#line 177 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 27:
#line 180 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                            (yyval.node)->left = (yyvsp[(1) - (4)].node); 
                                                            (yyval.node)->right = (yyvsp[(3) - (4)].node); 
                                                            (yyval.node)->kind = ASSIGNMENT_OP; }
    break;

  case 28:
#line 187 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                                     (yyval.node)->left = (yyvsp[(2) - (7)].node); 
                                                                     (yyval.node)->right = (yyvsp[(4) - (7)].node); 
                                                                     (yyval.node)->kind = IF_OP;}
    break;

  case 29:
#line 193 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                                                         (yyval.node)->left = (yyvsp[(2) - (10)].node); 
                                                                                         (yyval.node)->right = (yyvsp[(4) - (10)].node); 
                                                                                         (yyval.node)->ifelse = (yyvsp[(7) - (10)].node); 
                                                                                         (yyval.node)->kind = IFELSE_OP;}
    break;

  case 30:
#line 200 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                                           (yyval.node)->left = (yyvsp[(2) - (7)].node); 
                                                                           (yyval.node)->right = (yyvsp[(4) - (7)].node); 
                                                                           (yyval.node)->kind = WHILE_OP;}
    break;

  case 31:
#line 206 "parser.y"
    { 
                           (yyval.node) = (Node *)malloc(sizeof(Node)); 
                           (yyval.node)->left = (yyvsp[(2) - (11)].node); 
                           (yyval.node)->cnt1 = (yyvsp[(4) - (11)].node); 
                           (yyval.node)->cnt2 = (yyvsp[(6) - (11)].node); 
                           (yyval.node)->right = (yyvsp[(8) - (11)].node); 
                           (yyval.node)->kind = COUNTUP_OP; }
    break;

  case 32:
#line 215 "parser.y"
    {
                           (yyval.node) = (Node *)malloc(sizeof(Node)); 
                           (yyval.node)->left = (yyvsp[(2) - (11)].node); 
                           (yyval.node)->cnt1 = (yyvsp[(4) - (11)].node); 
                           (yyval.node)->cnt2 = (yyvsp[(6) - (11)].node); 
                           (yyval.node)->right = (yyvsp[(8) - (11)].node); 
                           (yyval.node)->kind = COUNTDOWN_OP; }
    break;

  case 33:
#line 226 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                  (yyval.node)->kind = EXIT_OP; }
    break;

  case 34:
#line 230 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                           (yyval.node)->left = (yyvsp[(2) - (3)].node); 
                                           (yyval.node)->kind = READ_OP; }
    break;

  case 35:
#line 235 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                             (yyval.node)->left = (yyvsp[(2) - (3)].node); 
                                             (yyval.node)->kind = PRINT_OP; }
    break;

  case 36:
#line 240 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:
#line 241 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); 
                                             (yyval.node)->next = (yyvsp[(3) - (3)].node); }
    break;

  case 38:
#line 245 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:
#line 246 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                          (yyval.node)->sval = (yyvsp[(1) - (1)].sval); 
                          (yyval.node)->kind = LITERAL_STRING; }
    break;

  case 40:
#line 249 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                  (yyval.node)->kind = NEWLINE_OP; }
    break;

  case 41:
#line 255 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 42:
#line 256 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                      (yyval.node)->left = (yyvsp[(2) - (2)].node); 
                                      (yyval.node)->kind = NOT_OP; }
    break;

  case 43:
#line 259 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                                 (yyval.node)->left = (yyvsp[(3) - (3)].node);
                                                 (yyval.node)->right = (yyvsp[(1) - (3)].node); 
                                                 (yyval.node)->kind = AND_OP; }
    break;

  case 44:
#line 263 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                                (yyval.node)->left = (yyvsp[(3) - (3)].node); 
                                                (yyval.node)->right = (yyvsp[(1) - (3)].node); 
                                                (yyval.node)->kind = OR_OP; }
    break;

  case 45:
#line 269 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 46:
#line 270 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                                  (yyval.node)->left = (yyvsp[(1) - (3)].node);  
                                                  (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                                  (yyval.node)->kind = LESS_OP; }
    break;

  case 47:
#line 274 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                     (yyval.node)->left = (yyvsp[(1) - (3)].node);  
                                                     (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                                     (yyval.node)->kind = GREATER_OP; }
    break;

  case 48:
#line 278 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                     (yyval.node)->left = (yyvsp[(1) - (3)].node);  
                                                     (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                                     (yyval.node)->kind = LESSOREQUAL_OP; }
    break;

  case 49:
#line 282 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                        (yyval.node)->left = (yyvsp[(1) - (3)].node);  
                                                        (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                                        (yyval.node)->kind = GREATEROREQUAL_OP; }
    break;

  case 50:
#line 286 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                               (yyval.node)->left = (yyvsp[(1) - (3)].node);  
                                               (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                               (yyval.node)->kind = EQUAL_OP; }
    break;

  case 51:
#line 290 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                                  (yyval.node)->left = (yyvsp[(1) - (3)].node);  
                                                  (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                                  (yyval.node)->kind = NOTEQUAL_OP; }
    break;

  case 52:
#line 296 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 53:
#line 297 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                            (yyval.node)->left = (yyvsp[(1) - (3)].node); 
                                            (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                            (yyval.node)->kind = ADDITION_OP; }
    break;

  case 54:
#line 301 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                               (yyval.node)->left = (yyvsp[(1) - (3)].node); 
                                               (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                               (yyval.node)->kind = SUBTRACTION_OP; }
    break;

  case 55:
#line 305 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                    (yyval.node)->left = (yyvsp[(2) - (2)].node); 
                                    (yyval.node)->kind = UMINUS_OP; }
    break;

  case 56:
#line 310 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:
#line 311 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                              (yyval.node)->left = (yyvsp[(1) - (3)].node); 
                                              (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                              (yyval.node)->kind = MULTIPLICATION_OP; }
    break;

  case 58:
#line 315 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                        (yyval.node)->left = (yyvsp[(1) - (3)].node); 
                                        (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                        (yyval.node)->kind = DIVISION_OP; }
    break;

  case 59:
#line 319 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                       (yyval.node)->left = (yyvsp[(1) - (3)].node); 
                                       (yyval.node)->right = (yyvsp[(3) - (3)].node); 
                                       (yyval.node)->kind = MODULUS_OP; }
    break;

  case 60:
#line 325 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 61:
#line 326 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 62:
#line 329 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 63:
#line 330 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                               (yyval.node)->intval = (yyvsp[(1) - (1)].intval); 
                               (yyval.node)->kind = LITERAL_INT; 
                               (yyval.node)->dtype = TYPE_INT; }
    break;

  case 64:
#line 334 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                                (yyval.node)->realval = (yyvsp[(1) - (1)].realval); 
                                (yyval.node)->kind = LITERAL_REAL; 
                                (yyval.node)->dtype = TYPE_REAL; }
    break;

  case 65:
#line 340 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node));
                            (yyval.node)->sval = (yyvsp[(1) - (1)].sval); 
                            (yyval.node)->kind = VARIABLE_OP; }
    break;

  case 66:
#line 343 "parser.y"
    { (yyval.node) = (Node *)malloc(sizeof(Node)); 
                                                             (yyval.node)->sval = (yyvsp[(1) - (4)].sval); 
                                                             (yyval.node)->left = (yyvsp[(3) - (4)].node); 
                                                             (yyval.node)->kind = VARIABLE_OP; }
    break;


/* Line 1267 of yacc.c.  */
#line 1943 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 350 "parser.y"


int yyerror(const char * msg) {
   printf("%s \n", msg); 
   printf("Called yyerror()\n");
   return  0;
}
