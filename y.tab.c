/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c_compiler.y"

#include <stdio.h>
#include <string.h>
#include "Node/BaseNode.h"
#include "Node/BTNode.h"
AST::BaseNode* root;
extern int yylex(void); 

extern int yyparse(void); 
extern FILE* yyin;

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
    yyin = fopen("./test.txt","r");
    do{
       yyparse(); 
    }while(!feof(yyin));
	
	return 0;
}

#line 102 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN_OP = 258,               /* ASSIGN_OP  */
    OR = 259,                      /* OR  */
    AND = 260,                     /* AND  */
    SINGLAND = 261,                /* SINGLAND  */
    EQ_OP = 262,                   /* EQ_OP  */
    NE_OP = 263,                   /* NE_OP  */
    GT_OP = 264,                   /* GT_OP  */
    LT_OP = 265,                   /* LT_OP  */
    GE_OP = 266,                   /* GE_OP  */
    LE_OP = 267,                   /* LE_OP  */
    PRINTF = 268,                  /* PRINTF  */
    SCANF = 269,                   /* SCANF  */
    IDENTIFIER = 270,              /* IDENTIFIER  */
    CONST = 271,                   /* CONST  */
    LOWER_THAN_ELSE = 272,         /* LOWER_THAN_ELSE  */
    WHILE = 273,                   /* WHILE  */
    FOR = 274,                     /* FOR  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    RETURN = 279,                  /* RETURN  */
    VOID = 280,                    /* VOID  */
    S_QUO = 281,                   /* S_QUO  */
    D_QUO = 282,                   /* D_QUO  */
    INT = 283,                     /* INT  */
    COMMA = 284,                   /* COMMA  */
    SEMI = 285                     /* SEMI  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ASSIGN_OP 258
#define OR 259
#define AND 260
#define SINGLAND 261
#define EQ_OP 262
#define NE_OP 263
#define GT_OP 264
#define LT_OP 265
#define GE_OP 266
#define LE_OP 267
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "c_compiler.y"

    char* num;
    AST::BaseNode *ast;
    char *str;

#line 221 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN_OP = 3,                  /* ASSIGN_OP  */
  YYSYMBOL_OR = 4,                         /* OR  */
  YYSYMBOL_AND = 5,                        /* AND  */
  YYSYMBOL_SINGLAND = 6,                   /* SINGLAND  */
  YYSYMBOL_EQ_OP = 7,                      /* EQ_OP  */
  YYSYMBOL_NE_OP = 8,                      /* NE_OP  */
  YYSYMBOL_GT_OP = 9,                      /* GT_OP  */
  YYSYMBOL_LT_OP = 10,                     /* LT_OP  */
  YYSYMBOL_GE_OP = 11,                     /* GE_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_13_ = 13,                       /* '+'  */
  YYSYMBOL_14_ = 14,                       /* '-'  */
  YYSYMBOL_15_ = 15,                       /* '*'  */
  YYSYMBOL_16_ = 16,                       /* '/'  */
  YYSYMBOL_17_ = 17,                       /* '%'  */
  YYSYMBOL_18_ = 18,                       /* '!'  */
  YYSYMBOL_19_ = 19,                       /* '('  */
  YYSYMBOL_20_ = 20,                       /* ')'  */
  YYSYMBOL_21_ = 21,                       /* '['  */
  YYSYMBOL_22_ = 22,                       /* ']'  */
  YYSYMBOL_PRINTF = 23,                    /* PRINTF  */
  YYSYMBOL_SCANF = 24,                     /* SCANF  */
  YYSYMBOL_IDENTIFIER = 25,                /* IDENTIFIER  */
  YYSYMBOL_CONST = 26,                     /* CONST  */
  YYSYMBOL_LOWER_THAN_ELSE = 27,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 31,                  /* CONTINUE  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_RETURN = 34,                    /* RETURN  */
  YYSYMBOL_VOID = 35,                      /* VOID  */
  YYSYMBOL_S_QUO = 36,                     /* S_QUO  */
  YYSYMBOL_D_QUO = 37,                     /* D_QUO  */
  YYSYMBOL_INT = 38,                       /* INT  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_SEMI = 40,                      /* SEMI  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_blocks = 45,                    /* blocks  */
  YYSYMBOL_block = 46,                     /* block  */
  YYSYMBOL_variable = 47,                  /* variable  */
  YYSYMBOL_consts = 48,                    /* consts  */
  YYSYMBOL_descriptor = 49,                /* descriptor  */
  YYSYMBOL_function = 50,                  /* function  */
  YYSYMBOL_params = 51,                    /* params  */
  YYSYMBOL_param = 52,                     /* param  */
  YYSYMBOL_body = 53,                      /* body  */
  YYSYMBOL_statements = 54,                /* statements  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_declare = 56,                   /* declare  */
  YYSYMBOL_declares = 57,                  /* declares  */
  YYSYMBOL_declarevars = 58,               /* declarevars  */
  YYSYMBOL_forstart = 59,                  /* forstart  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_arguments = 61,                 /* arguments  */
  YYSYMBOL_identifiers = 62                /* identifiers  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   734

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    91,   100,   113,   121,   130,   139,   147,
     155,   167,   175,   185,   193,   204,   210,   216,   224,   232,
     243,   253,   261,   269,   279,   287,   295,   303,   310,   317,
     327,   337,   344,   351,   358,   364,   369,   376,   383,   390,
     397,   405,   413,   421,   431,   440,   449,   458,   463,   468,
     474,   480,   491,   503,   510,   522,   529,   538,   545,   555,
     562,   568,   575,   582,   589,   596,   603,   610,   616,   622,
     629,   636,   642,   648,   655,   662,   669,   676,   683,   690,
     698,   704,   711,   719,   728,   734,   743,   748
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN_OP", "OR",
  "AND", "SINGLAND", "EQ_OP", "NE_OP", "GT_OP", "LT_OP", "GE_OP", "LE_OP",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'('", "')'", "'['", "']'",
  "PRINTF", "SCANF", "IDENTIFIER", "CONST", "LOWER_THAN_ELSE", "WHILE",
  "FOR", "BREAK", "CONTINUE", "IF", "ELSE", "RETURN", "VOID", "S_QUO",
  "D_QUO", "INT", "COMMA", "SEMI", "'{'", "'}'", "$accept", "program",
  "blocks", "block", "variable", "consts", "descriptor", "function",
  "params", "param", "body", "statements", "statement", "declare",
  "declares", "declarevars", "forstart", "expression", "arguments",
  "identifiers", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,   -52,   -10,    21,    -9,   -52,    -6,   -52,   -52,   -52,
       3,    78,    29,   -24,    -7,    10,   -52,    65,   295,   464,
     -52,   207,   -52,   -52,    -5,   -52,    -2,   -14,   -52,    12,
     464,    30,   464,   464,   -52,    92,    32,    51,   515,    76,
     -52,   695,    95,    96,   102,   103,    70,    84,   107,   297,
     237,    -5,   -52,   177,   -52,    88,    31,   110,   -52,   108,
     112,   114,   -52,    -9,   -52,    64,   -52,   -52,   551,   325,
     464,   -52,   -52,    11,   464,   464,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   -52,   -52,
     342,   113,   464,   267,   -52,   -52,   464,   -52,    79,    34,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,    -4,   -52,   -52,
     -52,   695,   -12,   535,   115,   -52,   695,   708,   484,   717,
     717,    91,    91,    91,    91,    64,    64,   -52,   -52,   -52,
     464,   569,   119,   587,   356,   -52,   100,   695,   605,   -52,
     -52,   120,   -52,   464,   -52,   -52,   499,   106,   109,   207,
     374,   149,   392,   207,   -52,   695,   123,   -52,   -52,   -52,
     207,   623,   410,   428,   164,   117,   111,   -52,   207,   207,
     641,   207,   659,   446,   207,   -52,   -52,   -52,   207,   -52,
     207,   207,   677,   -52,   -52,   -52,   -52,   207,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    15,     0,     2,     3,     0,    17,     1,     4,
       0,     8,    55,     0,     0,    53,    12,     0,     0,     0,
       7,     0,     6,     5,     0,    18,    27,     0,    21,     0,
       0,     0,     0,     0,     9,    86,    59,     0,     0,    60,
      59,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,    30,     0,     0,     8,    54,     0,
       0,    22,    19,     0,    83,    68,    81,    71,     0,     0,
       0,    10,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    87,
       0,     0,     0,     0,    47,    48,     0,    35,     0,    59,
      52,    28,    29,    32,    31,    25,    26,     0,    20,    67,
      80,    84,     0,     0,     0,    72,    61,    70,    69,    73,
      74,    75,    76,    77,    78,    62,    63,    64,    65,    66,
       0,     0,     0,     0,     0,    57,     0,    58,     0,    34,
      24,     0,    79,     0,    82,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    85,     0,    50,    51,    38,
       0,     0,     0,     0,     0,    36,     0,    39,     0,     0,
       0,     0,     0,     0,     0,    49,    42,    41,     0,    40,
       0,     0,     0,    37,    46,    45,    44,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   143,   -52,   -52,     7,   -52,   -52,    85,
     157,   -52,   -51,    89,   -21,   -52,   -52,   -18,   -52,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    12,    73,    51,    13,    27,    28,
      52,    53,    54,    55,    14,    15,   136,    56,   112,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    41,   102,    58,    59,     7,    62,     6,   142,    10,
      10,     6,    65,    60,    67,    68,    20,    21,   140,    11,
      57,     8,   141,    61,    26,    63,     1,   143,    16,     2,
     100,    98,    19,    23,    74,    75,    76,    64,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    24,
     114,   111,   113,   115,    71,    66,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      26,   104,   131,   -13,   133,   137,   -13,    72,   138,    85,
      86,    87,    74,    75,    76,    25,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    17,   159,    18,
       1,    89,   165,     2,    83,    84,    85,    86,    87,   167,
      94,    69,   146,    70,    90,    91,   151,   176,   177,   139,
     179,    92,    93,   183,    95,   155,    96,   184,   103,   185,
     186,    18,   161,   105,   164,   107,   188,   106,   132,   148,
     152,   145,   154,   166,   170,   172,   157,     9,   108,   158,
     174,   175,    74,    75,    76,   182,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    74,    75,    76,
      22,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   135,    29,     0,     0,     0,     0,     0,   162,
       0,    30,    31,     0,     0,    32,    33,     0,     0,     0,
      42,    43,    35,    40,   173,    44,    45,    46,    47,    48,
       0,    49,     1,    29,     0,     2,     0,     0,    50,   101,
       0,    30,    31,     0,     0,    32,    33,     0,     0,     0,
      42,    43,    35,    40,     0,    44,    45,    46,    47,    48,
       0,    49,     1,    29,     0,     2,     0,     0,    50,     0,
       0,    30,    31,     0,     0,    32,    33,     0,     0,     0,
      42,    43,    35,    99,     0,    44,    45,    46,    47,    48,
       0,    49,     1,    29,     0,     2,     0,     0,    50,     0,
       0,    30,    31,     0,     0,    32,    33,     0,     0,     0,
       0,     0,    35,    40,     0,     0,     0,     0,     0,     0,
       0,    29,     1,    29,     0,     2,     0,   134,    37,    30,
      31,    30,    31,    32,    33,    32,    33,    34,     0,     0,
      35,    36,    35,    40,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    37,    97,    37,    30,
      31,     0,     0,    32,    33,   110,     0,     0,    29,     0,
      35,    40,     0,     0,     0,     0,    30,    31,     0,     0,
      32,    33,    29,     0,     0,     0,    37,    35,    40,     0,
      30,    31,     0,     0,    32,    33,     0,     0,     0,   130,
      29,    35,    40,    37,     0,     0,     0,     0,    30,    31,
       0,     0,    32,    33,   160,     0,   150,    37,    29,    35,
      40,     0,     0,     0,     0,     0,    30,    31,     0,     0,
      32,    33,     0,     0,     0,    37,    29,    35,    40,     0,
       0,     0,     0,     0,    30,    31,     0,     0,    32,    33,
     169,     0,   163,    37,    29,    35,    40,     0,     0,     0,
       0,     0,    30,    31,     0,     0,    32,    33,   171,     0,
       0,    37,    29,    35,    40,     0,     0,     0,     0,     0,
      30,    31,     0,     0,    32,    33,   181,     0,     0,    37,
      29,    35,    40,     0,     0,     0,     0,     0,    30,    31,
       0,     0,    32,    33,     0,     0,     0,    37,     0,    35,
      40,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    74,    75,    76,    37,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,   156,    88,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,    74,    75,    76,   144,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,   109,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,   147,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,   149,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,   153,    74,    75,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,   168,    74,    75,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,   178,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,   180,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,   187,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    76,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    79,    80,    81,    82,
      83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      18,    19,    53,    24,     6,    15,    20,     0,    20,    15,
      15,     4,    30,    15,    32,    33,    40,    41,    22,    25,
      25,     0,    26,    25,    17,    39,    35,    39,    25,    38,
      51,    49,     3,    40,     3,     4,     5,    25,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    39,
      39,    69,    70,    42,    22,    25,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      63,    40,    90,    39,    92,    93,    42,    26,    96,    15,
      16,    17,     3,     4,     5,    20,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    19,   149,    21,
      35,    25,   153,    38,    13,    14,    15,    16,    17,   160,
      40,    19,   130,    21,    19,    19,   134,   168,   169,    40,
     171,    19,    19,   174,    40,   143,    19,   178,    40,   180,
     181,    21,   150,    25,   152,    21,   187,    25,    25,    20,
      40,    26,    22,    20,   162,   163,    40,     4,    63,    40,
      33,    40,     3,     4,     5,   173,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     3,     4,     5,
      13,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    93,     6,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    40,    28,    29,    30,    31,    32,
      -1,    34,    35,     6,    -1,    38,    -1,    -1,    41,    42,
      -1,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      -1,    34,    35,     6,    -1,    38,    -1,    -1,    41,    -1,
      -1,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      -1,    34,    35,     6,    -1,    38,    -1,    -1,    41,    -1,
      -1,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    35,     6,    -1,    38,    -1,    40,    41,    14,
      15,    14,    15,    18,    19,    18,    19,    22,    -1,    -1,
      25,    26,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    41,    40,    41,    14,
      15,    -1,    -1,    18,    19,    20,    -1,    -1,     6,    -1,
      25,    26,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      18,    19,     6,    -1,    -1,    -1,    41,    25,    26,    -1,
      14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    37,
       6,    25,    26,    41,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    18,    19,    20,    -1,    40,    41,     6,    25,
      26,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    41,     6,    25,    26,    -1,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    18,    19,
      20,    -1,    40,    41,     6,    25,    26,    -1,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    18,    19,    20,    -1,
      -1,    41,     6,    25,    26,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    18,    19,    20,    -1,    -1,    41,
       6,    25,    26,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    41,    -1,    25,
      26,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     3,     4,     5,    41,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    37,    22,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,     3,     4,     5,    22,     7,     8,
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
      13,    14,    15,    16,    17,    -1,    -1,    20,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     9,    10,    11,    12,
      13,    14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    38,    44,    45,    46,    49,    15,     0,    46,
      15,    25,    47,    50,    57,    58,    25,    19,    21,     3,
      40,    41,    53,    40,    39,    20,    49,    51,    52,     6,
      14,    15,    18,    19,    22,    25,    26,    41,    60,    62,
      26,    60,    23,    24,    28,    29,    30,    31,    32,    34,
      41,    49,    53,    54,    55,    56,    60,    25,    57,     6,
      15,    25,    20,    39,    25,    60,    25,    60,    60,    19,
      21,    22,    26,    48,     3,     4,     5,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    22,    25,
      19,    19,    19,    19,    40,    40,    19,    40,    60,    26,
      57,    42,    55,    40,    40,    25,    25,    21,    52,    20,
      20,    60,    61,    60,    39,    42,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      37,    60,    25,    60,    40,    56,    59,    60,    60,    40,
      22,    26,    20,    39,    22,    26,    60,    20,    20,    20,
      40,    60,    40,    20,    22,    60,    37,    40,    40,    55,
      20,    60,    40,    40,    60,    55,    20,    55,    20,    20,
      60,    20,    60,    40,    33,    40,    55,    55,    20,    55,
      20,    20,    60,    55,    55,    55,    55,    20,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     3,     3,     1,     3,
       4,     4,     2,     1,     3,     1,     1,     2,     3,     4,
       3,     1,     2,     5,     4,     3,     3,     1,     3,     2,
       1,     2,     2,     1,     3,     2,     5,     7,     5,     6,
       7,     7,     7,     9,     8,     8,     8,     2,     2,     7,
       5,     5,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     2,     4,     2,     1,     3,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: blocks  */
#line 80 "c_compiler.y"
    {
        root = new AST::BaseNode("program",AST::NodeType::ROOT);
        // root->addChildNode(new AST::BaseNode("test"));
        root->addChildNode((yyvsp[0].ast));
        BTTree<AST::BaseNode> printer(root, &AST::BaseNode::getAllChildrenNode,
                        &AST::BaseNode::getStringContent);
        printer.print();

    }
#line 1493 "y.tab.c"
    break;

  case 3: /* blocks: block  */
#line 92 "c_compiler.y"
    {
        printf("blocks->block\n");
        
        (yyval.ast)= (yyvsp[0].ast);
        // AST::BaseNode *node = new AST::BaseNode("a_Block",AST::NodeType::STATEMENT);
        // node->addChildNode($1);
        // $$ = node;
    }
#line 1506 "y.tab.c"
    break;

  case 4: /* blocks: blocks block  */
#line 101 "c_compiler.y"
    {
        printf("blocks->blocks block\n");
        AST::BaseNode *node =new AST::BaseNode("Blocks",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-1].ast));
        node->addChildNode((yyvsp[0].ast));
        // AST::BaseNode * block = new AST::BaseNode("a_Block",AST::NodeType::STATEMENT);
        // block->addChildNode($2);
        // node->addChildNode(block);
        (yyval.ast) = node;
    }
#line 1521 "y.tab.c"
    break;

  case 5: /* block: descriptor declares SEMI  */
#line 114 "c_compiler.y"
    {
        printf("block->descriptor declares SEMI\n");
        AST::BaseNode *node =new AST::BaseNode("Def_Variable_Block",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1533 "y.tab.c"
    break;

  case 6: /* block: descriptor function body  */
#line 122 "c_compiler.y"
    {
        printf("blockcdescriptor function body\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Func_Block_Body",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[-1].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1546 "y.tab.c"
    break;

  case 7: /* block: descriptor function SEMI  */
#line 131 "c_compiler.y"
    {
        printf("block->descriptor function 'SEMI'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Func_Block_NoBody",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1558 "y.tab.c"
    break;

  case 8: /* variable: IDENTIFIER  */
#line 140 "c_compiler.y"
    {   
        printf("variable->IDENTIFIER\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Identifier",AST::NodeType::DEFINITION);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
#line 1570 "y.tab.c"
    break;

  case 9: /* variable: IDENTIFIER '[' ']'  */
#line 148 "c_compiler.y"
    {
        printf("variable->IDENTIFIER '[' ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
#line 1582 "y.tab.c"
    break;

  case 10: /* variable: IDENTIFIER '[' CONST ']'  */
#line 156 "c_compiler.y"
    {
        printf("variable->IDENTIFIER '[' CONST ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[Const]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[-3].str),AST::NodeType::ID);
        // AST::BaseNode * const_node = new AST::BaseNode($3,AST::NodeType::ID);

        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[-1].num), AST::NodeType::CONST_INT);
        node->addChildNode(var_node);
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
#line 1598 "y.tab.c"
    break;

  case 11: /* variable: IDENTIFIER '[' expression ']'  */
#line 168 "c_compiler.y"
    {
        printf("variable->IDENTIFIER '[' expression ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[expression]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        node->addChildNode((yyvsp[-1].ast));
    }
#line 1610 "y.tab.c"
    break;

  case 12: /* variable: '*' IDENTIFIER  */
#line 176 "c_compiler.y"
    {
        printf("variable->'*' IDENTIFIER\n");
        AST::BaseNode * node = new AST::BaseNode("Def_*Identifier",AST::NodeType::POINTER);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
#line 1622 "y.tab.c"
    break;

  case 13: /* consts: CONST  */
#line 186 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Const_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[0].num),AST::NodeType::CONST_INT);
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
#line 1634 "y.tab.c"
    break;

  case 14: /* consts: consts COMMA CONST  */
#line 194 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Consts_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[0].num),AST::NodeType::CONST_INT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
#line 1647 "y.tab.c"
    break;

  case 15: /* descriptor: INT  */
#line 205 "c_compiler.y"
    {
        printf("INTTTTTTT\n");
        AST::BaseNode * node = new AST::BaseNode("int_Type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
#line 1657 "y.tab.c"
    break;

  case 16: /* descriptor: VOID  */
#line 211 "c_compiler.y"
    {
        printf("VOID\n");
        AST::BaseNode * node = new AST::BaseNode("void_type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
#line 1667 "y.tab.c"
    break;

  case 17: /* descriptor: INT '*'  */
#line 217 "c_compiler.y"
    {
        printf("INT* \n");
        AST::BaseNode * node = new AST::BaseNode("int*_Type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
#line 1677 "y.tab.c"
    break;

  case 18: /* function: IDENTIFIER '(' ')'  */
#line 225 "c_compiler.y"
    {
        printf("Function_Without_Param\n");
        AST::BaseNode * node = new AST::BaseNode("Function_Without_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        (yyval.ast) = node;
    }
#line 1689 "y.tab.c"
    break;

  case 19: /* function: IDENTIFIER '(' params ')'  */
#line 233 "c_compiler.y"
    {
        printf("Function_With_Param\n");
        AST::BaseNode * node = new AST::BaseNode("Function_With_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1702 "y.tab.c"
    break;

  case 20: /* params: params COMMA param  */
#line 243 "c_compiler.y"
                          {
    printf("params: params COMMA param\n");
    AST::BaseNode * node = new AST::BaseNode("Params",AST::NodeType::DEFINITION);
    // AST::BaseNode * param_node = new AST::BaseNode("Single_Param",AST::NodeType::DEFINITION);
    // param_node->addChildNode($3);
    node->addChildNode((yyvsp[-2].ast));
    // node->addChildNode(param_node);
    node->addChildNode((yyvsp[0].ast));
    (yyval.ast) = node;
}
#line 1717 "y.tab.c"
    break;

  case 21: /* params: param  */
#line 253 "c_compiler.y"
        {
    printf("params: param\n");
    // AST::BaseNode * node = new AST::BaseNode("Single_Param",AST::NodeType::DEFINITION);
    // node->addChildNode($1);
    // $$ = node;
    (yyval.ast) = (yyvsp[0].ast);
}
#line 1729 "y.tab.c"
    break;

  case 22: /* param: descriptor IDENTIFIER  */
#line 261 "c_compiler.y"
                             {
    printf("param:descriptor identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-1].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1742 "y.tab.c"
    break;

  case 23: /* param: descriptor IDENTIFIER '[' CONST ']'  */
#line 269 "c_compiler.y"
                                      {
    printf("param:descriptor identifiers '[' CONST ']'\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID[CONST]",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[-3].str),AST::NodeType::ID);
    AST::BaseNode * ConstNode = new AST::BaseNode((yyvsp[-1].num),AST::NodeType::CONST_INT);
    node->addChildNode((yyvsp[-4].ast));
    node->addChildNode(IdentifierNode);
    node->addChildNode(ConstNode);
    (yyval.ast) = node;
}
#line 1757 "y.tab.c"
    break;

  case 24: /* param: descriptor IDENTIFIER '[' ']'  */
#line 279 "c_compiler.y"
                                {
    printf("param:descriptor identifiers '[' ']'\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID[]",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[-2].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-3].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1770 "y.tab.c"
    break;

  case 25: /* param: descriptor SINGLAND IDENTIFIER  */
#line 287 "c_compiler.y"
                               {
    printf("param:descriptor SINGLAND identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("array_&id",AST::NodeType::ARRAY);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-2].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1783 "y.tab.c"
    break;

  case 26: /* param: descriptor '*' IDENTIFIER  */
#line 295 "c_compiler.y"
                          {
    printf("param:descriptor SINGLAND '*' identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("array_*id",AST::NodeType::POINTER);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-2].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1796 "y.tab.c"
    break;

  case 27: /* param: descriptor  */
#line 303 "c_compiler.y"
           {
    printf("param:descriptor\n");
    AST::BaseNode * node = new AST::BaseNode("param_without_id",AST::NodeType::DEFINITION);
    node->addChildNode((yyvsp[0].ast));
    (yyval.ast) = node;
}
#line 1807 "y.tab.c"
    break;

  case 28: /* body: '{' statements '}'  */
#line 310 "c_compiler.y"
                        {
    printf("body:'{' statements '}'\n");
    AST::BaseNode *node = new AST::BaseNode("Body",AST::NodeType::BODY);
    node->addChildNode((yyvsp[-1].ast));
    (yyval.ast) = node;
}
#line 1818 "y.tab.c"
    break;

  case 29: /* statements: statements statement  */
#line 317 "c_compiler.y"
                                {
    printf("statements:statements statement\n");
    AST::BaseNode * node = new AST::BaseNode("Statements",AST::NodeType::STATEMENT);
    // AST::BaseNode * Single_Statement = new AST::BaseNode("Single_Statement",AST::NodeType::STATEMENT);
    // Single_Statement->addChildNode($2);
    node->addChildNode((yyvsp[-1].ast));
    // node->addChildNode(Single_Statement);
    node->addChildNode((yyvsp[0].ast));
    (yyval.ast) = node;
}
#line 1833 "y.tab.c"
    break;

  case 30: /* statements: statement  */
#line 327 "c_compiler.y"
           {
    printf("statements:statement\n");
    // AST::BaseNode * node = new AST::BaseNode("Single_Statement",AST::NodeType::STATEMENT);
    // node->addChildNode($1);
    (yyval.ast) = (yyvsp[0].ast);
}
#line 1844 "y.tab.c"
    break;

  case 31: /* statement: expression SEMI  */
#line 338 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1854 "y.tab.c"
    break;

  case 32: /* statement: declare SEMI  */
#line 345 "c_compiler.y"
    {
        AST::BaseNode *node = new AST::BaseNode("Declare_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1864 "y.tab.c"
    break;

  case 33: /* statement: body  */
#line 352 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Body_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1874 "y.tab.c"
    break;

  case 34: /* statement: RETURN expression SEMI  */
#line 359 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Return_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1884 "y.tab.c"
    break;

  case 35: /* statement: RETURN SEMI  */
#line 365 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Return_NULL",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
#line 1893 "y.tab.c"
    break;

  case 36: /* statement: IF '(' expression ')' statement  */
#line 370 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("If_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1904 "y.tab.c"
    break;

  case 37: /* statement: IF '(' expression ')' statement ELSE statement  */
#line 376 "c_compiler.y"
                                                                          {
        AST::BaseNode * node = new AST::BaseNode ("If_Else_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1916 "y.tab.c"
    break;

  case 38: /* statement: WHILE '(' expression ')' statement  */
#line 384 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode ("While_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1927 "y.tab.c"
    break;

  case 39: /* statement: FOR '(' SEMI SEMI ')' statement  */
#line 391 "c_compiler.y"
    {
        printf("FOR '(' SEMI SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1938 "y.tab.c"
    break;

  case 40: /* statement: FOR '(' forstart SEMI SEMI ')' statement  */
#line 398 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1950 "y.tab.c"
    break;

  case 41: /* statement: FOR '(' SEMI expression SEMI ')' statement  */
#line 406 "c_compiler.y"
    {
        printf("FOR '(' SEMI expression SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-3].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1962 "y.tab.c"
    break;

  case 42: /* statement: FOR '(' SEMI SEMI expression ')' statement  */
#line 414 "c_compiler.y"
    {
        printf("FOR '(' SEMI SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1974 "y.tab.c"
    break;

  case 43: /* statement: FOR '(' forstart SEMI expression SEMI expression ')' statement  */
#line 422 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI expression SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-6].ast));
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1988 "y.tab.c"
    break;

  case 44: /* statement: FOR '(' forstart SEMI expression SEMI ')' statement  */
#line 432 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI expression SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-5].ast));
        node->addChildNode((yyvsp[-3].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2001 "y.tab.c"
    break;

  case 45: /* statement: FOR '(' forstart SEMI SEMI expression ')' statement  */
#line 441 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-5].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2014 "y.tab.c"
    break;

  case 46: /* statement: FOR '(' SEMI expression SEMI expression ')' statement  */
#line 450 "c_compiler.y"
    {
        printf("FOR '(' SEMI expression SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2027 "y.tab.c"
    break;

  case 47: /* statement: BREAK SEMI  */
#line 459 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Break_Statement",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
#line 2036 "y.tab.c"
    break;

  case 48: /* statement: CONTINUE SEMI  */
#line 464 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Continue_Statement",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
#line 2045 "y.tab.c"
    break;

  case 49: /* statement: PRINTF '(' D_QUO expression D_QUO ')' SEMI  */
#line 469 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_String",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-3].ast));
        (yyval.ast) = node;
    }
#line 2055 "y.tab.c"
    break;

  case 50: /* statement: PRINTF '(' expression ')' SEMI  */
#line 475 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        (yyval.ast) = node;
    }
#line 2065 "y.tab.c"
    break;

  case 51: /* statement: SCANF '(' IDENTIFIER ')' SEMI  */
#line 481 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Scanf_Identifier",AST::NodeType::STATEMENT);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2076 "y.tab.c"
    break;

  case 52: /* declare: descriptor declares  */
#line 492 "c_compiler.y"
    {
        printf("descriptor declares\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_stmt_w_;",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-1].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2088 "y.tab.c"
    break;

  case 53: /* declares: declarevars  */
#line 504 "c_compiler.y"
    {
         printf("declarevars\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Variable",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2099 "y.tab.c"
    break;

  case 54: /* declares: declarevars COMMA declares  */
#line 511 "c_compiler.y"
    {
         printf("declarevars COMMA declares\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Variables",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2111 "y.tab.c"
    break;

  case 55: /* declarevars: variable  */
#line 523 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Variable",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2121 "y.tab.c"
    break;

  case 56: /* declarevars: variable ASSIGN_OP expression  */
#line 530 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Variable_Assign",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2132 "y.tab.c"
    break;

  case 57: /* forstart: declare  */
#line 539 "c_compiler.y"
    {
        printf("declares\n");
        AST::BaseNode * node = new AST::BaseNode("For_Start",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2143 "y.tab.c"
    break;

  case 58: /* forstart: expression  */
#line 546 "c_compiler.y"
    {
        printf("expression\n");
        AST::BaseNode * node = new AST::BaseNode("For_Expression",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2154 "y.tab.c"
    break;

  case 59: /* expression: CONST  */
#line 556 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Constant_Expression",AST::NodeType::EXPRESSION);
        AST::BaseNode * Constant_Node = new AST::BaseNode ((yyvsp[0].num),AST::NodeType::CONST_INT);
        node->addChildNode(Constant_Node);
        (yyval.ast) = node;
    }
#line 2165 "y.tab.c"
    break;

  case 60: /* expression: identifiers  */
#line 563 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Identifier_Expression",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2175 "y.tab.c"
    break;

  case 61: /* expression: expression ASSIGN_OP expression  */
#line 569 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Assign",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2186 "y.tab.c"
    break;

  case 62: /* expression: expression '+' expression  */
#line 576 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Add",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2197 "y.tab.c"
    break;

  case 63: /* expression: expression '-' expression  */
#line 583 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Sub",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2208 "y.tab.c"
    break;

  case 64: /* expression: expression '*' expression  */
#line 590 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Mul",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2219 "y.tab.c"
    break;

  case 65: /* expression: expression '/' expression  */
#line 597 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Div",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2230 "y.tab.c"
    break;

  case 66: /* expression: expression '%' expression  */
#line 604 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Mod",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2241 "y.tab.c"
    break;

  case 67: /* expression: '(' expression ')'  */
#line 611 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Braces",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2251 "y.tab.c"
    break;

  case 68: /* expression: '-' expression  */
#line 617 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Negative",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2261 "y.tab.c"
    break;

  case 69: /* expression: expression AND expression  */
#line 623 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("And",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2272 "y.tab.c"
    break;

  case 70: /* expression: expression OR expression  */
#line 630 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Or",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2283 "y.tab.c"
    break;

  case 71: /* expression: '!' expression  */
#line 637 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Not",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2293 "y.tab.c"
    break;

  case 72: /* expression: '{' consts '}'  */
#line 643 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("{Consts}",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2303 "y.tab.c"
    break;

  case 73: /* expression: expression EQ_OP expression  */
#line 649 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2314 "y.tab.c"
    break;

  case 74: /* expression: expression NE_OP expression  */
#line 656 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Not_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2325 "y.tab.c"
    break;

  case 75: /* expression: expression GT_OP expression  */
#line 663 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode("Greater_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2336 "y.tab.c"
    break;

  case 76: /* expression: expression LT_OP expression  */
#line 670 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2347 "y.tab.c"
    break;

  case 77: /* expression: expression GE_OP expression  */
#line 677 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Greater_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2358 "y.tab.c"
    break;

  case 78: /* expression: expression LE_OP expression  */
#line 684 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2369 "y.tab.c"
    break;

  case 79: /* expression: IDENTIFIER '(' arguments ')'  */
#line 691 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Function_Call_With_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2381 "y.tab.c"
    break;

  case 80: /* expression: IDENTIFIER '(' ')'  */
#line 698 "c_compiler.y"
                        {
        AST::BaseNode * node = new AST::BaseNode("Function_Call_Without_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2392 "y.tab.c"
    break;

  case 81: /* expression: '*' IDENTIFIER  */
#line 705 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("*id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2403 "y.tab.c"
    break;

  case 82: /* expression: IDENTIFIER '[' expression ']'  */
#line 712 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("id[exp]",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2415 "y.tab.c"
    break;

  case 83: /* expression: SINGLAND IDENTIFIER  */
#line 720 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode("&id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2426 "y.tab.c"
    break;

  case 84: /* arguments: expression  */
#line 729 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Arg",AST::NodeType::ID);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2436 "y.tab.c"
    break;

  case 85: /* arguments: arguments COMMA expression  */
#line 735 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Args",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2447 "y.tab.c"
    break;

  case 86: /* identifiers: IDENTIFIER  */
#line 743 "c_compiler.y"
              {
        AST::BaseNode * node = new AST::BaseNode("id",AST::NodeType::DEFINITION);
        node->addChildNode(new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID));
        (yyval.ast) = node;
    }
#line 2457 "y.tab.c"
    break;

  case 87: /* identifiers: identifiers IDENTIFIER  */
#line 749 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("ids",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-1].ast));
        AST::BaseNode * id_node = new AST::BaseNode("id",AST::NodeType::DEFINITION);
        node->addChildNode(new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID));
        node->addChildNode(id_node);
        // node->addChildNode(new AST::BaseNode($2,AST::NodeType::ID));
        (yyval.ast) = node;
    }
#line 2471 "y.tab.c"
    break;


#line 2475 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 761 "c_compiler.y"


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
