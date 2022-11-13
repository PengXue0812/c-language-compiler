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
     ASSIGN_OP = 258,
     OR = 259,
     AND = 260,
     SINGLAND = 261,
     NE_OP = 262,
     EQ_OP = 263,
     LE_OP = 264,
     GE_OP = 265,
     LT_OP = 266,
     GT_OP = 267,
     PRINTF = 268,
     SCANF = 269,
     IDENTIFIER = 270,
     CONST = 271,
     LOWER_THAN_ELSE = 272,
     WHILE = 273,
     FOR = 274,
     BREAK = 275,
     CONTINUE = 276,
     IF = 277,
     ELSE = 278,
     RETURN = 279,
     VOID = 280,
     S_QUO = 281,
     D_QUO = 282,
     INT = 283,
     COMMA = 284,
     SEMI = 285
   };
#endif
/* Tokens.  */
#define ASSIGN_OP 258
#define OR 259
#define AND 260
#define SINGLAND 261
#define NE_OP 262
#define EQ_OP 263
#define LE_OP 264
#define GE_OP 265
#define LT_OP 266
#define GT_OP 267
#define PRINTF 268
#define SCANF 269
#define IDENTIFIER 270
#define CONST 271
#define LOWER_THAN_ELSE 272
#define WHILE 273
#define FOR 274
#define BREAK 275
#define CONTINUE 276
#define IF 277
#define ELSE 278
#define RETURN 279
#define VOID 280
#define S_QUO 281
#define D_QUO 282
#define INT 283
#define COMMA 284
#define SEMI 285




/* Copy the first part of user declarations.  */
#line 1 "c_compiler.y"

#include <stdio.h>
#include <string.h>
#include "Node/BaseNode.h"
#include "Node/BTNode.h"
AST::BaseNode* root;
extern int yylex(void); 

extern int yyparse(void); 

int yywrap()
{
    return 1;
}
void yyerror(const char *s)
{
	printf("[error] %s\n", s);
}

int main()
{
	yyparse();
	return 0;
}


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
#line 28 "c_compiler.y"
{
    char* num;
    AST::BaseNode *ast;
    char *str;
}
/* Line 193 of yacc.c.  */
#line 188 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 201 "y.tab.c"

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   726

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,     2,     2,    17,     2,     2,
      19,    20,    15,    13,     2,    14,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    14,    18,    22,    24,
      28,    33,    38,    41,    43,    47,    49,    51,    54,    58,
      63,    67,    69,    72,    78,    83,    87,    91,    93,    97,
     100,   102,   105,   108,   110,   114,   117,   123,   131,   137,
     144,   152,   160,   168,   178,   187,   196,   205,   208,   211,
     219,   225,   231,   233,   237,   239,   243,   245,   247,   249,
     251,   255,   259,   263,   267,   271,   275,   279,   282,   286,
     290,   293,   297,   301,   305,   309,   313,   317,   321,   326,
     330,   333,   338,   341,   343,   347,   349
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    46,    -1,    45,    46,    -1,
      49,    56,    40,    -1,    49,    50,    53,    -1,    49,    50,
      40,    -1,    25,    -1,    25,    21,    22,    -1,    25,    21,
      26,    22,    -1,    25,    21,    59,    22,    -1,    15,    25,
      -1,    26,    -1,    48,    39,    26,    -1,    38,    -1,    35,
      -1,    38,    15,    -1,    25,    19,    20,    -1,    25,    19,
      51,    20,    -1,    51,    39,    52,    -1,    52,    -1,    49,
      25,    -1,    49,    25,    21,    26,    22,    -1,    49,    25,
      21,    22,    -1,    49,     6,    25,    -1,    49,    15,    25,
      -1,    49,    -1,    41,    54,    42,    -1,    54,    55,    -1,
      55,    -1,    59,    40,    -1,    56,    40,    -1,    53,    -1,
      34,    59,    40,    -1,    34,    40,    -1,    32,    19,    59,
      20,    55,    -1,    32,    19,    59,    20,    55,    33,    55,
      -1,    28,    19,    59,    20,    55,    -1,    29,    19,    40,
      40,    20,    55,    -1,    29,    19,    58,    40,    40,    20,
      55,    -1,    29,    19,    40,    59,    40,    20,    55,    -1,
      29,    19,    40,    40,    59,    20,    55,    -1,    29,    19,
      58,    40,    59,    40,    59,    20,    55,    -1,    29,    19,
      58,    40,    59,    40,    20,    55,    -1,    29,    19,    58,
      40,    40,    59,    20,    55,    -1,    29,    19,    40,    59,
      40,    59,    20,    55,    -1,    30,    40,    -1,    31,    40,
      -1,    23,    19,    37,    59,    37,    20,    40,    -1,    23,
      19,    59,    20,    40,    -1,    24,    19,    25,    20,    40,
      -1,    57,    -1,    57,    39,    56,    -1,    47,    -1,    47,
       3,    59,    -1,    56,    -1,    59,    -1,    26,    -1,    61,
      -1,    59,     3,    59,    -1,    59,    13,    59,    -1,    59,
      14,    59,    -1,    59,    15,    59,    -1,    59,    16,    59,
      -1,    59,    17,    59,    -1,    19,    59,    20,    -1,    14,
      59,    -1,    59,     5,    59,    -1,    59,     4,    59,    -1,
      18,    59,    -1,    41,    48,    42,    -1,    59,     8,    59,
      -1,    59,     7,    59,    -1,    59,    12,    59,    -1,    59,
      11,    59,    -1,    59,    10,    59,    -1,    59,     9,    59,
      -1,    25,    19,    60,    20,    -1,    25,    19,    20,    -1,
      15,    25,    -1,    25,    21,    59,    22,    -1,     6,    25,
      -1,    59,    -1,    60,    39,    59,    -1,    25,    -1,    61,
      25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    86,    93,   103,   111,   120,   126,   134,
     142,   154,   162,   172,   180,   191,   197,   203,   211,   219,
     230,   237,   244,   252,   262,   270,   278,   286,   294,   301,
     309,   316,   323,   330,   337,   343,   348,   355,   362,   369,
     375,   382,   389,   396,   405,   413,   421,   429,   434,   439,
     445,   451,   473,   479,   490,   497,   506,   512,   521,   528,
     534,   541,   548,   555,   562,   569,   576,   582,   588,   595,
     602,   608,   614,   621,   628,   635,   642,   649,   656,   664,
     670,   677,   685,   694,   700,   709,   714
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN_OP", "OR", "AND", "SINGLAND",
  "NE_OP", "EQ_OP", "LE_OP", "GE_OP", "LT_OP", "GT_OP", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'('", "')'", "'['", "']'", "PRINTF",
  "SCANF", "IDENTIFIER", "CONST", "LOWER_THAN_ELSE", "WHILE", "FOR",
  "BREAK", "CONTINUE", "IF", "ELSE", "RETURN", "VOID", "S_QUO", "D_QUO",
  "INT", "COMMA", "SEMI", "'{'", "'}'", "$accept", "program", "blocks",
  "block", "variable", "consts", "descriptor", "function", "params",
  "param", "body", "statements", "statement", "declares", "declarevars",
  "forstart", "expression", "arguments", "identifiers", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    43,    45,    42,    47,    37,    33,    40,
      41,    91,    93,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     3,     3,     1,     3,
       4,     4,     2,     1,     3,     1,     1,     2,     3,     4,
       3,     1,     2,     5,     4,     3,     3,     1,     3,     2,
       1,     2,     2,     1,     3,     2,     5,     7,     5,     6,
       7,     7,     7,     9,     8,     8,     8,     2,     2,     7,
       5,     5,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     4,     2,     1,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    15,     0,     2,     3,     0,    17,     1,     4,
       0,     8,    54,     0,     0,    52,    12,     0,     0,     0,
       7,     0,     6,     5,     0,    18,    27,     0,    21,     0,
       0,     0,     0,     0,     9,    85,    58,     0,     0,    59,
      58,    55,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,    33,     0,    30,     0,     0,     8,    53,
       0,     0,    22,    19,     0,    82,    67,    80,    70,     0,
       0,     0,    10,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      86,    80,     0,     0,     0,     0,     0,    47,    48,     0,
      35,     0,    58,    28,    29,    32,    31,    25,    26,     0,
      20,    66,    79,    83,     0,     0,     0,    71,    60,    69,
      68,    73,    72,    77,    76,    75,    74,    61,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,    56,     0,
      57,     0,    34,    24,     0,    78,     0,    81,    14,     0,
       0,     0,    81,     0,     0,     0,     0,     0,    23,    84,
       0,    50,    51,    38,     0,     0,     0,     0,     0,    36,
       0,    39,     0,     0,     0,     0,     0,     0,     0,    49,
      42,    41,     0,    40,     0,     0,     0,    37,    46,    45,
      44,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    74,     6,    13,    27,    28,
      53,    54,    55,    56,    15,   139,    57,   114,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -53
static const yytype_int16 yypact[] =
{
     -27,   -53,    -5,    75,   -27,   -53,    -9,   -53,   -53,   -53,
      55,    92,    95,    66,    70,    78,   -53,    62,    77,   440,
     -53,   210,   -53,   -53,    -8,   -53,    79,    17,   -53,   100,
     440,   102,   440,   440,   -53,   103,   107,   105,   491,   109,
     -53,   687,   110,   118,   131,    69,   132,   133,   113,   114,
     136,   252,   231,   -53,   181,   -53,   134,    15,   165,   -53,
     163,   164,   169,   -53,   -27,   -53,   130,   -53,   -53,   543,
     269,   440,   -53,   -53,    45,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   -53,
     -53,    10,   290,   166,    77,   440,   307,   -53,   -53,   440,
     -53,    31,    47,   -53,   -53,   -53,   -53,   -53,   -53,   -17,
     -53,   -53,   -53,   687,    34,   511,   171,   -53,   687,   700,
     460,   709,   709,   127,   127,   127,   127,   130,   130,   -53,
     -53,   -53,   440,   561,   172,   527,   579,   324,   -53,   154,
     687,   597,   -53,   -53,   176,   -53,   440,   -53,   -53,   475,
     161,   162,    76,   210,   348,   153,   365,   210,   -53,   687,
     183,   -53,   -53,   -53,   210,   615,   382,   406,   168,   184,
     174,   -53,   210,   210,   633,   210,   651,   423,   210,   -53,
     -53,   -53,   210,   -53,   210,   210,   669,   -53,   -53,   -53,
     -53,   210,   -53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,   -53,   214,   -53,   -53,   -13,   -53,   -53,   155,
     207,   -53,   -52,    -3,   -53,   -53,   -18,   -53,   -53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -14
static const yytype_int16 yytable[] =
{
      38,    41,   104,    14,    26,   143,    10,    10,     1,   144,
       7,     2,    66,   -12,    68,    69,    11,    58,    75,    76,
      77,    59,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   101,    75,    76,    77,    63,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   -12,
     -12,    26,   113,   115,   145,   106,    64,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   142,    -8,   146,   133,     8,   135,   136,   140,   -11,
      16,   141,    25,    29,   116,    60,   -13,   117,    70,   -13,
      94,    30,    31,   138,    61,    32,    33,     1,    19,    34,
       2,   163,    35,    36,    62,   169,    20,    21,    -8,    -8,
      23,    17,   171,    18,   149,   -11,   -11,    24,    37,   155,
     180,   181,    70,   183,    71,    65,   187,    67,   159,    72,
     188,    73,   189,   190,    90,    91,   165,    92,   168,   192,
      84,    85,    86,    87,    88,    86,    87,    88,   174,   176,
      93,    95,    96,    97,    98,    99,    75,    76,    77,   186,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    75,    76,    77,   105,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    18,    29,   107,   108,
     109,   134,   151,   166,   156,    30,    42,   148,   158,    32,
      33,   161,   162,   170,    43,    44,    45,    40,   177,    46,
      47,    48,    49,    50,   179,    51,    29,   178,     9,   110,
      22,     0,    52,   103,    30,    42,     0,     0,    32,    33,
       0,     0,     0,    43,    44,    45,    40,    29,    46,    47,
      48,    49,    50,     0,    51,    30,    42,     0,     0,    32,
      33,    52,     0,     0,    43,    44,    45,   102,    29,    46,
      47,    48,    49,    50,     0,    51,    30,    31,     0,     0,
      32,    33,    52,     0,     0,    29,     0,    35,    40,     0,
       0,     0,     0,    30,    31,     0,     0,    32,    33,   112,
       0,     0,   100,    37,    35,    40,    29,     0,     0,     0,
       0,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      37,     0,     0,    29,     0,    35,    40,     0,     0,     0,
       0,    30,    42,     0,     0,    32,    33,   132,     0,     0,
      29,    37,    45,    40,     0,     0,     0,     0,    30,    31,
       0,     0,    32,    33,     0,     0,     0,   137,    37,    35,
      40,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,    30,    31,   154,    37,    32,    33,   164,     0,
       0,    29,     0,    35,    40,     0,     0,     0,     0,    30,
      31,     0,     0,    32,    33,     0,     0,     0,    29,    37,
      35,    40,     0,     0,     0,     0,    30,    31,     0,     0,
      32,    33,   173,     0,     0,   167,    37,    35,    40,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
      30,    31,     0,    37,    32,    33,   175,     0,     0,    29,
       0,    35,    40,     0,     0,     0,     0,    30,    31,     0,
       0,    32,    33,   185,     0,     0,    29,    37,    35,    40,
       0,     0,     0,     0,    30,    31,     0,     0,    32,    33,
       0,     0,     0,     0,    37,    35,    40,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    75,    76,
      77,    37,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,   160,    89,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
      75,    76,    77,   147,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,    75,    76,    77,   152,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,   111,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,   150,    75,    76,    77,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,   153,
      75,    76,    77,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,   157,    75,    76,
      77,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,   172,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,   182,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,   184,    75,    76,    77,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,   191,
      75,    76,    77,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    77,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    80,    81,
      82,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      18,    19,    54,     6,    17,    22,    15,    15,    35,    26,
      15,    38,    30,     3,    32,    33,    25,    25,     3,     4,
       5,    24,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    51,     3,     4,     5,    20,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    39,
      40,    64,    70,    71,    20,    40,    39,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    40,     3,    39,    92,     0,    94,    95,    96,     3,
      25,    99,    20,     6,    39,     6,    39,    42,    19,    42,
      21,    14,    15,    96,    15,    18,    19,    35,     3,    22,
      38,   153,    25,    26,    25,   157,    40,    41,    39,    40,
      40,    19,   164,    21,   132,    39,    40,    39,    41,   137,
     172,   173,    19,   175,    21,    25,   178,    25,   146,    22,
     182,    26,   184,   185,    25,    25,   154,    19,   156,   191,
      13,    14,    15,    16,    17,    15,    16,    17,   166,   167,
      19,    19,    19,    40,    40,    19,     3,     4,     5,   177,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     3,     4,     5,    40,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    21,     6,    25,    25,
      21,    25,    20,    40,    40,    14,    15,    26,    22,    18,
      19,    40,    40,    20,    23,    24,    25,    26,    40,    28,
      29,    30,    31,    32,    40,    34,     6,    33,     4,    64,
      13,    -1,    41,    42,    14,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,     6,    28,    29,
      30,    31,    32,    -1,    34,    14,    15,    -1,    -1,    18,
      19,    41,    -1,    -1,    23,    24,    25,    26,     6,    28,
      29,    30,    31,    32,    -1,    34,    14,    15,    -1,    -1,
      18,    19,    41,    -1,    -1,     6,    -1,    25,    26,    -1,
      -1,    -1,    -1,    14,    15,    -1,    -1,    18,    19,    20,
      -1,    -1,    40,    41,    25,    26,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    18,    19,
      41,    -1,    -1,     6,    -1,    25,    26,    -1,    -1,    -1,
      -1,    14,    15,    -1,    -1,    18,    19,    37,    -1,    -1,
       6,    41,    25,    26,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    40,    41,    25,
      26,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    40,    41,    18,    19,    20,    -1,
      -1,     6,    -1,    25,    26,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,     6,    41,
      25,    26,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      18,    19,    20,    -1,    -1,    40,    41,    25,    26,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    41,    18,    19,    20,    -1,    -1,     6,
      -1,    25,    26,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    18,    19,    20,    -1,    -1,     6,    41,    25,    26,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    41,    25,    26,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     3,     4,
       5,    41,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    37,    22,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
       3,     4,     5,    22,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,     3,     4,     5,    22,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     9,    10,
      11,    12,    13,    14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    38,    44,    45,    46,    49,    15,     0,    46,
      15,    25,    47,    50,    56,    57,    25,    19,    21,     3,
      40,    41,    53,    40,    39,    20,    49,    51,    52,     6,
      14,    15,    18,    19,    22,    25,    26,    41,    59,    61,
      26,    59,    15,    23,    24,    25,    28,    29,    30,    31,
      32,    34,    41,    53,    54,    55,    56,    59,    25,    56,
       6,    15,    25,    20,    39,    25,    59,    25,    59,    59,
      19,    21,    22,    26,    48,     3,     4,     5,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    22,
      25,    25,    19,    19,    21,    19,    19,    40,    40,    19,
      40,    59,    26,    42,    55,    40,    40,    25,    25,    21,
      52,    20,    20,    59,    60,    59,    39,    42,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    37,    59,    25,    59,    59,    40,    56,    58,
      59,    59,    40,    22,    26,    20,    39,    22,    26,    59,
      20,    20,    22,    20,    40,    59,    40,    20,    22,    59,
      37,    40,    40,    55,    20,    59,    40,    40,    59,    55,
      20,    55,    20,    20,    59,    20,    59,    40,    33,    40,
      55,    55,    20,    55,    20,    20,    59,    55,    55,    55,
      55,    20,    55
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
#line 75 "c_compiler.y"
    {
        root = new AST::BaseNode("program",AST::NodeType::ROOT);
        // root->addChildNode(new AST::BaseNode("test"));
        root->addChildNode((yyvsp[(1) - (1)].ast));
        BTTree<AST::BaseNode> printer(root, &AST::BaseNode::getAllChildrenNode,
                        &AST::BaseNode::getStringContent);
        printer.print();

    }
    break;

  case 3:
#line 87 "c_compiler.y"
    {
        // printf("blocks->block");
        AST::BaseNode *node = new AST::BaseNode("a_Block",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 4:
#line 94 "c_compiler.y"
    {
        // printf("blocks->blocks block");
        AST::BaseNode *node =new AST::BaseNode("Blocks",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(1) - (2)].ast));
        node->addChildNode((yyvsp[(2) - (2)].ast));
        (yyval.ast) = node;
    }
    break;

  case 5:
#line 104 "c_compiler.y"
    {
        // printf("block->descriptor declares SEMI");
        AST::BaseNode *node =new AST::BaseNode("Def_Variable_Block",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 6:
#line 112 "c_compiler.y"
    {
        // printf("block->descriptor function body");
        AST::BaseNode * node = new AST::BaseNode("Def_Function_Block_WithBody",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(2) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 7:
#line 121 "c_compiler.y"
    {
        // printf("block->descriptor function 'SEMI'");
        AST::BaseNode * node = new AST::BaseNode("Def_Function_Block_WithoutBody",AST::NodeType::DEFINITION);
    }
    break;

  case 8:
#line 127 "c_compiler.y"
    {   
        // printf("variable->IDENTIFIER");
        AST::BaseNode * node = new AST::BaseNode("Def_Identifier",AST::NodeType::DEFINITION);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[(1) - (1)].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
    break;

  case 9:
#line 135 "c_compiler.y"
    {
        // printf("variable->IDENTIFIER '[' ']'");
        AST::BaseNode * node = new AST::BaseNode("Def_array[]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[(1) - (3)].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
    break;

  case 10:
#line 143 "c_compiler.y"
    {
        // printf("variable->IDENTIFIER '[' CONST ']'");
        AST::BaseNode * node = new AST::BaseNode("Def_array[Const]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[(1) - (4)].str),AST::NodeType::ID);
        // AST::BaseNode * const_node = new AST::BaseNode($3,AST::NodeType::ID);

        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[(3) - (4)].num), AST::NodeType::CONST_INT);
        node->addChildNode(var_node);
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
    break;

  case 11:
#line 155 "c_compiler.y"
    {
        // printf("variable->IDENTIFIER '[' expression ']'");
        AST::BaseNode * node = new AST::BaseNode("Def_array[expression]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[(1) - (4)].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        node->addChildNode((yyvsp[(3) - (4)].ast));
    }
    break;

  case 12:
#line 163 "c_compiler.y"
    {
        // printf("variable->'*' IDENTIFIER");
        AST::BaseNode * node = new AST::BaseNode("Def_*Identifier",AST::NodeType::POINTER);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[(2) - (2)].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
    break;

  case 13:
#line 173 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Const_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[(1) - (1)].num),AST::NodeType::CONST_INT);
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
    break;

  case 14:
#line 181 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Consts_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[(3) - (3)].num),AST::NodeType::CONST_INT);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
    break;

  case 15:
#line 192 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("int_Type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
    break;

  case 16:
#line 198 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("void_type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
    break;

  case 17:
#line 204 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("int*_Type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
    break;

  case 18:
#line 212 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Function_Without_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[(1) - (3)].str),AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        (yyval.ast) = node;
    }
    break;

  case 19:
#line 220 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Function_With_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[(1) - (4)].str),AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        node->addChildNode((yyvsp[(3) - (4)].ast));
        (yyval.ast) = node;
    }
    break;

  case 20:
#line 230 "c_compiler.y"
    {
    // printf("params: params COMMA param");
    AST::BaseNode * node = new AST::BaseNode("Params",AST::NodeType::DEFINITION);
    node->addChildNode((yyvsp[(1) - (3)].ast));
    node->addChildNode((yyvsp[(3) - (3)].ast));
    (yyval.ast) = node;
}
    break;

  case 21:
#line 237 "c_compiler.y"
    {
    // printf("params: param");
    AST::BaseNode * node = new AST::BaseNode("Single_Param",AST::NodeType::DEFINITION);
    node->addChildNode((yyvsp[(1) - (1)].ast));
    (yyval.ast) = node;
}
    break;

  case 22:
#line 244 "c_compiler.y"
    {
    // printf("param:descriptor identifiers");
    AST::BaseNode * node = new AST::BaseNode("Param_ID",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[(2) - (2)].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[(1) - (2)].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
    break;

  case 23:
#line 252 "c_compiler.y"
    {
    // printf("param:descriptor identifiers '[' CONST ']'");
    AST::BaseNode * node = new AST::BaseNode("Param_ID[CONST]",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[(2) - (5)].str),AST::NodeType::ID);
    AST::BaseNode * ConstNode = new AST::BaseNode((yyvsp[(4) - (5)].num),AST::NodeType::CONST_INT);
    node->addChildNode((yyvsp[(1) - (5)].ast));
    node->addChildNode(IdentifierNode);
    node->addChildNode(ConstNode);
    (yyval.ast) = node;
}
    break;

  case 24:
#line 262 "c_compiler.y"
    {
    // printf("param:descriptor identifiers '[' ']' ");
    AST::BaseNode * node = new AST::BaseNode("Param_ID[]",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[(2) - (4)].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[(1) - (4)].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
    break;

  case 25:
#line 270 "c_compiler.y"
    {
    // printf("param:descriptor SINGLAND identifiers");
    AST::BaseNode * node = new AST::BaseNode("array_&id",AST::NodeType::ARRAY);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[(3) - (3)].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[(1) - (3)].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
    break;

  case 26:
#line 278 "c_compiler.y"
    {
    // printf("param:descriptor SINGLAND '*' identifiers");
    AST::BaseNode * node = new AST::BaseNode("array_*id",AST::NodeType::POINTER);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[(3) - (3)].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[(1) - (3)].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
    break;

  case 27:
#line 286 "c_compiler.y"
    {
    // printf("param:descriptor");
    AST::BaseNode * node = new AST::BaseNode("param_without_id",AST::NodeType::DEFINITION);
    node->addChildNode((yyvsp[(1) - (1)].ast));
    (yyval.ast) = node;
}
    break;

  case 28:
#line 294 "c_compiler.y"
    {
    // printf("body:'{' statements '}'");
    AST::BaseNode *node = new AST::BaseNode("Body",AST::NodeType::BODY);
    node->addChildNode((yyvsp[(2) - (3)].ast));
    (yyval.ast) = node;
}
    break;

  case 29:
#line 301 "c_compiler.y"
    {
    // printf("statements:statements statement");
    AST::BaseNode * node = new AST::BaseNode("Statements",AST::NodeType::STATEMENT);
    if((yyvsp[(1) - (2)].ast) != NULL)
        node->addChildNode((yyvsp[(1) - (2)].ast));
    node->addChildNode((yyvsp[(2) - (2)].ast));
    (yyval.ast) = node;
}
    break;

  case 30:
#line 309 "c_compiler.y"
    {
    // printf("statements:statement");
    (yyval.ast) = NULL;
}
    break;

  case 31:
#line 317 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(1) - (2)].ast));
        (yyval.ast) = node;
    }
    break;

  case 32:
#line 324 "c_compiler.y"
    {
        AST::BaseNode *node = new AST::BaseNode("Declare_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(1) - (2)].ast));
        (yyval.ast) = node;
    }
    break;

  case 33:
#line 331 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Body_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 34:
#line 338 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Return_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 35:
#line 344 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Return_NULL",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
    break;

  case 36:
#line 349 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("If_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (5)].ast));
        node->addChildNode((yyvsp[(5) - (5)].ast));
        (yyval.ast) = node;
    }
    break;

  case 37:
#line 355 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("If_Else_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (7)].ast));
        node->addChildNode((yyvsp[(5) - (7)].ast));
        node->addChildNode((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    }
    break;

  case 38:
#line 363 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode ("While_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (5)].ast));
        node->addChildNode((yyvsp[(5) - (5)].ast));
        (yyval.ast) = node;
    }
    break;

  case 39:
#line 370 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(6) - (6)].ast));
        (yyval.ast) = node;
    }
    break;

  case 40:
#line 376 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (7)].ast));
        node->addChildNode((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    }
    break;

  case 41:
#line 383 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(4) - (7)].ast));
        node->addChildNode((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    }
    break;

  case 42:
#line 390 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(5) - (7)].ast));
        node->addChildNode((yyvsp[(7) - (7)].ast));
        (yyval.ast) = node;
    }
    break;

  case 43:
#line 397 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (9)].ast));
        node->addChildNode((yyvsp[(5) - (9)].ast));
        node->addChildNode((yyvsp[(7) - (9)].ast));
        node->addChildNode((yyvsp[(9) - (9)].ast));
        (yyval.ast) = node;
    }
    break;

  case 44:
#line 406 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (8)].ast));
        node->addChildNode((yyvsp[(5) - (8)].ast));
        node->addChildNode((yyvsp[(8) - (8)].ast));
        (yyval.ast) = node;
    }
    break;

  case 45:
#line 414 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (8)].ast));
        node->addChildNode((yyvsp[(6) - (8)].ast));
        node->addChildNode((yyvsp[(8) - (8)].ast));
        (yyval.ast) = node;
    }
    break;

  case 46:
#line 422 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(4) - (8)].ast));
        node->addChildNode((yyvsp[(6) - (8)].ast));
        node->addChildNode((yyvsp[(8) - (8)].ast));
        (yyval.ast) = node;
    }
    break;

  case 47:
#line 430 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Break_Statement",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
    break;

  case 48:
#line 435 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Continue_Statement",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
    break;

  case 49:
#line 440 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_String",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(4) - (7)].ast));
        (yyval.ast) = node;
    }
    break;

  case 50:
#line 446 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[(3) - (5)].ast));
        (yyval.ast) = node;
    }
    break;

  case 51:
#line 452 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Scanf_Identifier",AST::NodeType::STATEMENT);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[(3) - (5)].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
    break;

  case 52:
#line 474 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Declare_Variable",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 53:
#line 480 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Declare_Variables",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 54:
#line 491 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Variable",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 55:
#line 498 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Variable_Assign",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 56:
#line 507 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("For_Start",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 57:
#line 513 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("For_Expression",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 58:
#line 522 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Constant_Expression",AST::NodeType::EXPRESSION);
        AST::BaseNode * Constant_Node = new AST::BaseNode ((yyvsp[(1) - (1)].num),AST::NodeType::CONST_INT);
        node->addChildNode(Constant_Node);
        (yyval.ast) = node;
    }
    break;

  case 59:
#line 529 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Identifier_Expression",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 60:
#line 535 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Assign",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 61:
#line 542 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Add",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 62:
#line 549 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Sub",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 63:
#line 556 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Mul",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 64:
#line 563 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Div",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 65:
#line 570 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Mod",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 66:
#line 577 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Braces",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 67:
#line 583 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Negative",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(2) - (2)].ast));
        (yyval.ast) = node;
    }
    break;

  case 68:
#line 589 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("And",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 69:
#line 596 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Or",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 70:
#line 603 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Not",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(2) - (2)].ast));
        (yyval.ast) = node;
    }
    break;

  case 71:
#line 609 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("{Consts}",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[(2) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 72:
#line 615 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 73:
#line 622 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Not_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 74:
#line 629 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode("Greater_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 75:
#line 636 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 76:
#line 643 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Greater_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 77:
#line 650 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 78:
#line 657 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Function_Call_With_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[(1) - (4)].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode((yyvsp[(3) - (4)].ast));
        (yyval.ast) = node;
    }
    break;

  case 79:
#line 664 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Function_Call_Without_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[(1) - (3)].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
    break;

  case 80:
#line 671 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("*id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[(2) - (2)].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
    break;

  case 81:
#line 678 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("id[exp]",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[(1) - (4)].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode((yyvsp[(3) - (4)].ast));
        (yyval.ast) = node;
    }
    break;

  case 82:
#line 686 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode("&id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[(2) - (2)].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
    break;

  case 83:
#line 695 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Arg",AST::NodeType::ID);
        node->addChildNode((yyvsp[(1) - (1)].ast));
        (yyval.ast) = node;
    }
    break;

  case 84:
#line 701 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Args",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (3)].ast));
        node->addChildNode((yyvsp[(3) - (3)].ast));
        (yyval.ast) = node;
    }
    break;

  case 85:
#line 709 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("id",AST::NodeType::DEFINITION);
        node->addChildNode(new AST::BaseNode((yyvsp[(1) - (1)].str),AST::NodeType::ID));
        (yyval.ast) = node;
    }
    break;

  case 86:
#line 715 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("ids",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[(1) - (2)].ast));
        node->addChildNode(new AST::BaseNode((yyvsp[(2) - (2)].str),AST::NodeType::ID));
        (yyval.ast) = node;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2528 "y.tab.c"
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


#line 724 "c_compiler.y"


// void AddOutput(int Row, char* type, char* text){
//     char str[50];
//     sprintf(str, "line%d:(%s, %s)\n", Row, type, text);
//     char *tmp = Ans;
//     Ans = (char *) malloc(strlen(tmp) + strlen(str) + 1);
//     sprintf(Ans, "%s%s", tmp, str);
//     if(strlen(tmp) > 0)
//         free(tmp);
//     return ;
// }
