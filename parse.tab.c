/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parse.y"

/* Parser for gnbasic
   Copyright (C) 1998 James Bowman

This file is part of gnbasic.

gnbasic is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

gnbasic is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with gnbasic; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#define YYDEBUG 1

#include "t1.h"

extern int yyparse();

static double errline;

void yyerror(const char *message)
{
  fprintf(stderr, "Syntax error at line %g\n", errline);
  exit(1);
}

int yylex(void);

static statement_t *mkstatement(int t)
{
  statement_t *news = (statement_t *)malloc(sizeof(*news));
  news->type = t;
  return news;
}

static expression_t *mkexpression(expression_type_t t)
{
  expression_t *news = (expression_t *)malloc(sizeof(*news));
  news->type = t;
  return news;
}

static expression_t *mkop(int arity, int o)
{
  expression_t *news = mkexpression(op);
  news->parms.op.o = o;
  news->parms.op.arity = arity;
  return news;
}

/************************************************************************/


/* Line 371 of yacc.c  */
#line 131 "parse.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     FLOATLIT = 259,
     INTLIT = 260,
     STRING = 261,
     STRLIT = 262,
     IDENTIFIER = 263,
     SGN = 264,
     LEFT = 265,
     RIGHT = 266,
     MID = 267,
     _ABS = 268,
     VAL = 269,
     LOG = 270,
     EXP = 271,
     AND = 272,
     ATN = 273,
     COS = 274,
     DATA = 275,
     DIM = 276,
     END = 277,
     FOR = 278,
     GOSUB = 279,
     GOTO = 280,
     IF = 281,
     INPUT = 282,
     INT = 283,
     LET = 284,
     NEXT = 285,
     NOT = 286,
     OR = 287,
     PRINT = 288,
     READ = 289,
     RETURN = 290,
     SIN = 291,
     SQR = 292,
     STEP = 293,
     THEN = 294,
     TO = 295,
     USING = 296,
     RUN = 297,
     LIST = 298,
     CLEAR = 299,
     SAVE = 300,
     LOAD = 301,
     NL = 302,
     CMP_LE = 303,
     CMP_GE = 304,
     CMP_NE = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 66 "parse.y"

  double d;
  int i;
  GString *s;
  GList *l;
  statement_t *statement;
  expression_t *expression;
  variable_t *variable;


/* Line 387 of yacc.c  */
#line 235 "parse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 263 "parse.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      63,    64,    60,    58,    55,    59,     2,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    54,
      56,    53,    57,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    62,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    15,    19,    21,
      24,    26,    29,    32,    35,    37,    41,    42,    45,    48,
      50,    57,    66,    69,    72,    75,    80,    85,    88,    91,
      97,   100,   102,   106,   107,   109,   113,   115,   117,   119,
     121,   125,   127,   129,   131,   135,   137,   139,   141,   143,
     145,   147,   149,   153,   155,   157,   159,   163,   165,   167,
     169,   171,   174,   176,   178,   180,   185,   192,   201,   203,
     205,   207,   209,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   229,   231,   233,   237,   239,   244,   246,   250,
     252
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    66,    51,    67,    -1,    66,
       1,    51,    -1,    -1,    -1,     3,    68,    69,    -1,    42,
      -1,    42,     3,    -1,    43,    -1,    43,     3,    -1,    46,
       6,    -1,    45,     6,    -1,    70,    -1,    70,    52,    69,
      -1,    -1,    20,    90,    -1,    21,    91,    -1,    22,    -1,
      23,    89,    53,    73,    40,    73,    -1,    23,    89,    53,
      73,    40,    73,    38,    73,    -1,    24,    73,    -1,    25,
      73,    -1,    27,    71,    -1,    26,    73,    39,     3,    -1,
      26,    73,    39,    69,    -1,    30,    89,    -1,    33,    71,
      -1,    33,    41,    73,    54,    71,    -1,    34,    91,    -1,
      35,    -1,    89,    53,    73,    -1,    -1,    73,    -1,    73,
      72,    71,    -1,    55,    -1,    54,    -1,    74,    -1,    76,
      -1,    74,    75,    76,    -1,    17,    -1,    32,    -1,    78,
      -1,    76,    77,    78,    -1,    53,    -1,    56,    -1,    57,
      -1,    50,    -1,    48,    -1,    49,    -1,    80,    -1,    78,
      79,    80,    -1,    58,    -1,    59,    -1,    82,    -1,    80,
      81,    82,    -1,    60,    -1,    61,    -1,    62,    -1,    84,
      -1,    83,    84,    -1,    59,    -1,    31,    -1,    88,    -1,
      85,    63,    73,    64,    -1,    86,    63,    73,    55,    73,
      64,    -1,    87,    63,    73,    55,    73,    55,    73,    64,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    18,
      -1,    19,    -1,    36,    -1,    37,    -1,    28,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,     3,    -1,     6,
      -1,    89,    -1,    63,    73,    64,    -1,     8,    -1,     8,
      63,    90,    64,    -1,    73,    -1,    90,    55,    73,    -1,
      89,    -1,    91,    55,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   141,   143,   148,   151,   151,   156,   158,
     160,   162,   164,   166,   170,   175,   183,   187,   194,   201,
     207,   217,   227,   234,   241,   248,   257,   266,   273,   281,
     289,   296,   302,   312,   316,   325,   336,   341,   347,   350,
     352,   361,   362,   365,   367,   376,   377,   378,   379,   380,
     381,   384,   386,   395,   396,   399,   401,   410,   411,   412,
     415,   417,   425,   426,   430,   432,   439,   447,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   468,   469,
     472,   476,   483,   490,   497,   504,   512,   521,   526,   533,
     538
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "FLOATLIT", "INTLIT", "STRING",
  "STRLIT", "IDENTIFIER", "SGN", "LEFT", "RIGHT", "MID", "_ABS", "VAL",
  "LOG", "EXP", "AND", "ATN", "COS", "DATA", "DIM", "END", "FOR", "GOSUB",
  "GOTO", "IF", "INPUT", "INT", "LET", "NEXT", "NOT", "OR", "PRINT",
  "READ", "RETURN", "SIN", "SQR", "STEP", "THEN", "TO", "USING", "RUN",
  "LIST", "CLEAR", "SAVE", "LOAD", "NL", "CMP_LE", "CMP_GE", "CMP_NE",
  "'\\n'", "':'", "'='", "';'", "','", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'^'", "'('", "')'", "$accept", "program", "line", "$@1",
  "statements", "statement", "printlist", "printsep", "expression",
  "expression0", "e0op", "expression1", "e1op", "expression2", "e2op",
  "expression3", "e3op", "expression4", "e4op", "expression5", "e5op1",
  "e5op2", "e5op3", "expression6", "variable", "exprlist", "varlist", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    10,    58,    61,    59,    44,    60,    62,    43,    45,
      42,    47,    94,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    67,    68,    67,    67,    67,
      67,    67,    67,    67,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      87,    88,    88,    88,    88,    89,    89,    90,    90,    91,
      91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     0,     3,     1,     2,
       1,     2,     2,     2,     1,     3,     0,     2,     2,     1,
       6,     8,     2,     2,     2,     4,     4,     2,     2,     5,
       2,     1,     3,     0,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     4,     6,     8,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     1,     3,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     6,     8,    10,     0,     0,     0,     2,    16,     9,
      11,    13,    12,     1,     0,     5,    85,     0,     0,    19,
       0,     0,     0,     0,    33,     0,    33,     0,    31,     7,
      14,     0,     4,     3,     0,    81,    82,    77,    78,    79,
      80,    68,    69,    70,    71,    72,    73,    76,    63,    74,
      75,    62,     0,    87,    38,    39,    43,    51,    55,     0,
      60,     0,     0,     0,    64,    83,    17,    89,    18,     0,
      22,    23,     0,    24,    34,    27,     0,    28,    30,    16,
       0,     0,     0,    41,    42,     0,    49,    50,    48,    45,
      46,    47,     0,    53,    54,     0,    57,    58,    59,     0,
      61,     0,     0,     0,     0,     0,     0,    16,    37,    36,
      33,     0,    15,    32,    86,    84,    40,    44,    52,    56,
       0,     0,     0,    88,    90,     0,    25,    26,    35,    33,
      65,     0,     0,     0,    29,     0,     0,    20,    66,     0,
       0,     0,    21,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    29,    30,    73,   110,    74,    54,
      85,    55,    92,    56,    95,    57,    99,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
      12,   -71,     9,    11,    10,    24,     2,   -71,   196,   -71,
     -71,   -71,   -71,   -71,   -20,    12,   -29,   118,    30,   -71,
      30,   118,   118,   118,   118,    30,    33,    30,   -71,   -71,
     -12,    -3,   -71,   -71,   118,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   118,   -71,    -9,   -24,   -37,     5,   -71,   150,
     -71,    -1,     8,    13,   -71,   -71,     1,   -71,    18,     7,
     -71,   -71,    29,   -71,   -27,   -71,   118,   -71,    18,   196,
     118,   -45,    14,   -71,   -71,   118,   -71,   -71,   -71,   -71,
     -71,   -71,   118,   -71,   -71,   118,   -71,   -71,   -71,   118,
     -71,   118,   118,   118,   118,    30,   118,   168,   -71,   -71,
     118,    21,   -71,   -71,   -71,   -71,   -24,   -37,     5,   -71,
      15,    22,    25,   -71,   -71,    41,   -71,   -71,   -71,   118,
     -71,   118,   118,   118,   -71,    19,    27,    50,   -71,   118,
     118,    26,   -71,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,    78,   -71,   -70,   -71,   -19,   -71,   -17,   -71,
     -71,    16,   -71,     3,   -71,     4,   -71,    -5,   -71,    38,
     -71,   -71,   -71,   -71,    -7,    68,    76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      53,    31,    13,    14,    70,    71,    72,    77,    83,   112,
     104,    67,     9,    69,    10,     1,    11,    53,    75,   114,
      67,    93,    94,    84,    86,    87,    88,   108,   109,    89,
      12,    32,    90,    91,    34,    82,    35,   127,    16,    36,
      79,    16,    37,    38,    39,    40,    41,    42,    43,    44,
      80,    45,    46,    15,     2,     3,   104,     4,     5,   111,
     106,    47,   101,   113,    48,    96,    97,    98,   107,    49,
      50,   102,    31,   105,    76,   129,   103,   131,   115,   130,
     132,   133,   139,   138,   120,   121,   122,   123,   140,   125,
     143,   128,    51,    33,   119,   117,    52,   100,   124,   118,
      31,   116,    81,    78,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,   135,   136,   137,     0,     0,     0,
       0,    35,   141,   142,    36,     0,    16,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,    48,
       0,     0,     0,    35,    49,    50,    36,     0,    16,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
       0,   126,     0,     0,     0,     0,    16,    51,    47,     0,
       0,    52,     0,     0,     0,     0,    49,    50,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,    25,     0,
       0,    26,    27,    28,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,    25,     0,     0,    26,
      27,    28
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      17,     8,     0,     1,    21,    22,    23,    26,    17,    79,
      55,    18,     3,    20,     3,     3,     6,    34,    25,    64,
      27,    58,    59,    32,    48,    49,    50,    54,    55,    53,
       6,    51,    56,    57,    63,    52,     3,   107,     8,     6,
      52,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      53,    18,    19,    51,    42,    43,    55,    45,    46,    76,
      53,    28,    63,    80,    31,    60,    61,    62,    39,    36,
      37,    63,    79,    55,    41,    54,    63,    55,    64,    64,
      55,    40,    55,    64,   101,   102,   103,   104,    38,   106,
      64,   110,    59,    15,    99,    92,    63,    59,   105,    95,
     107,    85,    34,    27,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,     3,   139,   140,     6,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    31,
      -1,    -1,    -1,     3,    36,    37,     6,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      -1,     3,    -1,    -1,    -1,    -1,     8,    59,    28,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    36,    37,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    43,    45,    46,    66,    67,    68,     3,
       3,     6,     6,     0,     1,    51,     8,    20,    21,    22,
      23,    24,    25,    26,    27,    30,    33,    34,    35,    69,
      70,    89,    51,    67,    63,     3,     6,     9,    10,    11,
      12,    13,    14,    15,    16,    18,    19,    28,    31,    36,
      37,    59,    63,    73,    74,    76,    78,    80,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    89,    91,    89,
      73,    73,    73,    71,    73,    89,    41,    71,    91,    52,
      53,    90,    73,    17,    32,    75,    48,    49,    50,    53,
      56,    57,    77,    58,    59,    79,    60,    61,    62,    81,
      84,    63,    63,    63,    55,    55,    53,    39,    54,    55,
      72,    73,    69,    73,    64,    64,    76,    78,    80,    82,
      73,    73,    73,    73,    89,    73,     3,    69,    71,    54,
      64,    55,    55,    40,    71,    73,    73,    73,    64,    55,
      38,    73,    73,    64
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
        case 5:
/* Line 1787 of yacc.c  */
#line 148 "parse.y"
    {
        }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 151 "parse.y"
    { errline = (yyvsp[(1) - (1)].d); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 152 "parse.y"
    {
	  is.line[(int)(yyvsp[(1) - (3)].d)] = (yyvsp[(3) - (3)].l);
	}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 156 "parse.y"
    { }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 158 "parse.y"
    { }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 160 "parse.y"
    { }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 162 "parse.y"
    { }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 164 "parse.y"
    { }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 166 "parse.y"
    { }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 171 "parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].statement));
        }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 176 "parse.y"
    {
	  (yyval.l) = g_list_prepend((yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].statement));
        }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 183 "parse.y"
    {
	  (yyval.statement) = NULL;
	}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 188 "parse.y"
    {
	  statement_t *news = mkstatement(DATA);
	  news->parms.data = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = news;
	}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 195 "parse.y"
    {
	  statement_t *news = mkstatement(DIM);
	  news->parms.dim = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = news;
	}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 202 "parse.y"
    {
	  statement_t *news = mkstatement(END);
	  (yyval.statement) = news;
	}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 208 "parse.y"
    {
	  statement_t *news = mkstatement(FOR);
	  news->parms._for.v = (yyvsp[(2) - (6)].variable);
	  news->parms._for.begin = (yyvsp[(4) - (6)].expression);
	  news->parms._for.end = (yyvsp[(6) - (6)].expression);
	  news->parms._for.step = NULL;
	  (yyval.statement) = news;
	}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 218 "parse.y"
    {
	  statement_t *news = mkstatement(FOR);
	  news->parms._for.v = (yyvsp[(2) - (8)].variable);
	  news->parms._for.begin = (yyvsp[(4) - (8)].expression);
	  news->parms._for.end = (yyvsp[(6) - (8)].expression);
	  news->parms._for.step = (yyvsp[(8) - (8)].expression);
	  (yyval.statement) = news;
	}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 228 "parse.y"
    {
	  statement_t *news = mkstatement(GOSUB);
	  news->parms.gosub = (yyvsp[(2) - (2)].expression);
	  (yyval.statement) = news;
	}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 235 "parse.y"
    {
	  statement_t *news = mkstatement(GOTO);
	  news->parms._goto = (yyvsp[(2) - (2)].expression);
	  (yyval.statement) = news;
	}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 242 "parse.y"
    {
	  statement_t *news = mkstatement(INPUT);
	  news->parms.input = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = news;
	}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 249 "parse.y"
    {
	  statement_t *news = mkstatement(IF);
	  news->parms._if.cond = (yyvsp[(2) - (4)].expression);
	  news->parms._if.thene = NULL;
	  news->parms._if.thenl = (yyvsp[(4) - (4)].d);
	  (yyval.statement) = news;
	}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 258 "parse.y"
    {
	  statement_t *news = mkstatement(IF);
	  news->parms._if.cond = (yyvsp[(2) - (4)].expression);
	  news->parms._if.thene = (yyvsp[(4) - (4)].l);
	  news->parms._if.thenl = 0;
	  (yyval.statement) = news;
	}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 267 "parse.y"
    {
	  statement_t *news = mkstatement(NEXT);
	  news->parms.next = (yyvsp[(2) - (2)].variable);
	  (yyval.statement) = news;
	}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 274 "parse.y"
    {
	  statement_t *news = mkstatement(PRINT);
	  news->parms.print.usingwhich = NULL;
	  news->parms.print.l = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = news;
	}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 282 "parse.y"
    {
	  statement_t *news = mkstatement(PRINT);
	  news->parms.print.usingwhich = (yyvsp[(3) - (5)].expression);
	  news->parms.print.l = (yyvsp[(5) - (5)].l);
	  (yyval.statement) = news;
	}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 290 "parse.y"
    {
	  statement_t *news = mkstatement(READ);
	  news->parms.read = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = news;
	}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 297 "parse.y"
    {
	  statement_t *news = mkstatement(RETURN);
	  (yyval.statement) = news;
	}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 303 "parse.y"
    {
	  statement_t *news = mkstatement(LET);
	  news->parms.let.lvalue = (yyvsp[(1) - (3)].variable);
	  news->parms.let.e = (yyvsp[(3) - (3)].expression);
	  (yyval.statement) = news;
        }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 312 "parse.y"
    {
	  (yyval.l) = NULL;
        }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 317 "parse.y"
    {
	  printitem_t *news = (printitem_t *)malloc(sizeof(*news));

	  news->e = (yyvsp[(1) - (1)].expression);
	  news->sep = 0;
	  (yyval.l) = g_list_prepend(NULL, news);
	}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 326 "parse.y"
    {
	  printitem_t *news = (printitem_t *)malloc(sizeof(*news));

	  news->e = (yyvsp[(1) - (3)].expression);
	  news->sep = (yyvsp[(2) - (3)].i);
	  (yyval.l) = g_list_prepend((yyvsp[(3) - (3)].l), news);
	}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 337 "parse.y"
    {
	  (yyval.i) = ',';
	}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 342 "parse.y"
    {
	  (yyval.i) = ';';
	}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 353 "parse.y"
    {
	  expression_t *news = mkop(2, (yyvsp[(2) - (3)].i));
	  news->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  news->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = news;
	}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 361 "parse.y"
    { (yyval.i) = AND; }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 362 "parse.y"
    { (yyval.i) = OR;  }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 368 "parse.y"
    {
	  expression_t *news = mkop(2, (yyvsp[(2) - (3)].i));
	  news->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  news->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = news;
	}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 376 "parse.y"
    { (yyval.i) = '='; }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 377 "parse.y"
    { (yyval.i) = '<'; }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 378 "parse.y"
    { (yyval.i) = '>'; }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 379 "parse.y"
    { (yyval.i) = CMP_NE; }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 380 "parse.y"
    { (yyval.i) = CMP_LE; }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 381 "parse.y"
    { (yyval.i) = CMP_GE; }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 387 "parse.y"
    {
	  expression_t *news = mkop(2, (yyvsp[(2) - (3)].i));
	  news->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  news->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = news;
	}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 395 "parse.y"
    { (yyval.i) = '+'; }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 396 "parse.y"
    { (yyval.i) = '-'; }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 402 "parse.y"
    {
	  expression_t *news = mkop(2, (yyvsp[(2) - (3)].i));
	  news->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  news->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = news;
	}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 410 "parse.y"
    { (yyval.i) = '*'; }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 411 "parse.y"
    { (yyval.i) = '/'; }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 412 "parse.y"
    { (yyval.i) = '^'; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 418 "parse.y"
    {
	  expression_t *news = mkop(1, (yyvsp[(1) - (2)].i));
	  news->parms.op.p[0] = (yyvsp[(2) - (2)].expression);
	  (yyval.expression) = news;
        }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 425 "parse.y"
    { (yyval.i) = '-'; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 426 "parse.y"
    { (yyval.i) = NOT; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 433 "parse.y"
    {
	  expression_t *news = mkop(1, (yyvsp[(1) - (4)].i));
	  news->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
	  (yyval.expression) = news;
        }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 440 "parse.y"
    {
	  expression_t *news = mkop(2, (yyvsp[(1) - (6)].i));
	  news->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
	  news->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
	  (yyval.expression) = news;
        }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 448 "parse.y"
    {
	  expression_t *news = mkop(3, (yyvsp[(1) - (8)].i));
	  news->parms.op.p[0] = (yyvsp[(3) - (8)].expression);
	  news->parms.op.p[1] = (yyvsp[(5) - (8)].expression);
	  (yyval.expression) = news;
        }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 456 "parse.y"
    { (yyval.i) = _ABS; }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 457 "parse.y"
    { (yyval.i) = VAL; }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 458 "parse.y"
    { (yyval.i) = LOG; }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 459 "parse.y"
    { (yyval.i) = EXP; }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 460 "parse.y"
    { (yyval.i) = ATN; }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 461 "parse.y"
    { (yyval.i) = COS; }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 462 "parse.y"
    { (yyval.i) = SIN; }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 463 "parse.y"
    { (yyval.i) = SQR; }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 464 "parse.y"
    { (yyval.i) = INT; }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 465 "parse.y"
    { (yyval.i) = SGN; }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 468 "parse.y"
    { (yyval.i) = LEFT; }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 469 "parse.y"
    { (yyval.i) = RIGHT; }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 472 "parse.y"
    { (yyval.i) = MID; }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 477 "parse.y"
    {
	  expression_t *news = mkexpression(number);
	  news->parms.number = (yyvsp[(1) - (1)].d);
	  (yyval.expression) = news;
	}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 484 "parse.y"
    {
	  expression_t *news = mkexpression(string);
	  news->parms.string = (yyvsp[(1) - (1)].s);
	  (yyval.expression) = news;
	}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 491 "parse.y"
    {
	  expression_t *news = mkexpression(variable);
	  news->parms.variable = (yyvsp[(1) - (1)].variable);
	  (yyval.expression) = news;
        }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 498 "parse.y"
    {
	  (yyval.expression) = (yyvsp[(2) - (3)].expression);
        }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 505 "parse.y"
    {
	  variable_t *news = (variable_t *)malloc(sizeof(*news));
	  news->name = (yyvsp[(1) - (1)].s);
	  news->sub = NULL;
	  (yyval.variable) = news;
        }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 513 "parse.y"
    {
	  variable_t *news = (variable_t *)malloc(sizeof(*news));
	  news->name = (yyvsp[(1) - (4)].s);
	  news->sub = (yyvsp[(3) - (4)].l);
	  (yyval.variable) = news;
        }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 522 "parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].expression));
        }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 527 "parse.y"
    {
	  (yyval.l) = g_list_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].expression));
        }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 534 "parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].variable));
        }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 539 "parse.y"
    {
	  (yyval.l) = g_list_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].variable));
        }
    break;


/* Line 1787 of yacc.c  */
#line 2258 "parse.tab.c"
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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2050 of yacc.c  */
#line 544 "parse.y"

