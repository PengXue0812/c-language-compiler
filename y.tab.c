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
#include "Symbol/SymbolTable.h"
#include "Symbol/Symbol.h"

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

#line 105 "y.tab.c"

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
#line 36 "c_compiler.y"

    char* num;
    AST::BaseNode *ast;
    char *str;

#line 224 "y.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   732

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
       0,    82,    82,    95,   104,   117,   124,   133,   142,   150,
     158,   170,   178,   188,   196,   207,   213,   219,   227,   235,
     246,   256,   264,   272,   282,   290,   298,   306,   313,   320,
     330,   340,   347,   354,   361,   367,   372,   379,   386,   393,
     400,   408,   416,   424,   434,   443,   452,   461,   466,   471,
     477,   483,   494,   507,   514,   526,   533,   542,   549,   559,
     566,   572,   579,   586,   593,   600,   607,   614,   620,   626,
     633,   640,   646,   652,   659,   666,   673,   680,   687,   694,
     702,   708,   715,   723,   732,   738,   747,   752
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

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,   -53,     1,    23,   -17,   -53,    -5,    -4,   -53,   -53,
     -53,    47,    74,    72,     8,   -53,    55,   -53,   -53,    61,
     293,   462,   -53,   205,   -53,     2,   -53,    -3,   -14,   -53,
      51,   462,    86,   462,   462,   -53,    88,    78,    87,   513,
      93,   -53,   693,   101,   102,   105,   106,    91,    94,   108,
     295,   235,     2,   -53,   175,   -53,    96,    30,   112,   -53,
     113,   114,   116,   -53,   -17,   -53,    37,   -53,   -53,   549,
     323,   462,   -53,   -53,   -11,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   462,   462,   462,   462,   -53,
     -53,   340,   115,   462,   265,   -53,   -53,   462,   -53,    75,
     -10,   -53,   -53,   -53,   -53,   -53,   -53,    -7,   -53,   -53,
     -53,   693,   -13,   533,   118,   -53,   693,   706,   482,   715,
     715,    89,    89,    89,    89,    37,    37,   -53,   -53,   -53,
     462,   567,    92,   585,   354,   -53,   107,   693,   603,   -53,
     -53,   119,   -53,   462,   -53,   -53,   497,   109,   128,   205,
     372,   147,   390,   205,   -53,   693,   125,   -53,   -53,   -53,
     205,   621,   408,   426,   162,   149,   140,   -53,   205,   205,
     639,   205,   657,   444,   205,   -53,   -53,   -53,   205,   -53,
     205,   205,   675,   -53,   -53,   -53,   -53,   205,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,    15,     0,     2,     3,     0,     0,    17,     1,
       4,     0,     8,    55,     0,    52,    53,     5,    12,     0,
       0,     0,     7,     0,     6,     0,    18,    27,     0,    21,
       0,     0,     0,     0,     0,     9,    86,    59,     0,     0,
      60,    59,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,    30,     0,     0,     8,    54,
       0,     0,    22,    19,     0,    83,    68,    81,    71,     0,
       0,     0,    10,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      87,     0,     0,     0,     0,    47,    48,     0,    35,     0,
      59,    28,    29,    32,    31,    25,    26,     0,    20,    67,
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
     -53,   -53,   -53,   142,   -53,   -53,     5,   -53,   -53,    84,
     169,   -53,   -52,     4,   159,   -53,   -53,   -20,   -53,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    13,    74,    52,    14,    28,    29,
      53,    54,    55,    56,    15,    16,   136,    57,   112,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    42,   102,    60,     7,     6,    63,   142,     7,     6,
      11,    66,    61,    68,    69,   140,     8,    11,     1,   141,
      12,     2,    62,     9,    27,    64,   143,    58,   114,   -13,
      99,   115,   -13,    75,    76,    77,    17,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    22,    23,
     111,   113,    86,    87,    88,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    27,
     104,   131,    18,   133,   137,    21,    65,   138,    75,    76,
      77,    26,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    19,    25,    20,     1,   159,   135,     2,
      72,   165,    84,    85,    86,    87,    88,    70,   167,    71,
     146,    67,   148,    73,   151,   139,   176,   177,    90,   179,
      91,    92,   183,   155,    93,    94,   184,    97,   185,   186,
     161,    95,   164,    20,    96,   188,   103,   107,   105,   106,
     132,   154,   170,   172,   145,   166,    10,   152,   108,   157,
      75,    76,    77,   182,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    75,    76,    77,   158,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     175,    30,   174,    24,    59,     0,     0,   162,     0,    31,
      32,     0,     0,    33,    34,     0,     0,     0,    43,    44,
      36,    41,   173,    45,    46,    47,    48,    49,     0,    50,
       1,    30,     0,     2,     0,     0,    51,   101,     0,    31,
      32,     0,     0,    33,    34,     0,     0,     0,    43,    44,
      36,    41,     0,    45,    46,    47,    48,    49,     0,    50,
       1,    30,     0,     2,     0,     0,    51,     0,     0,    31,
      32,     0,     0,    33,    34,     0,     0,     0,    43,    44,
      36,   100,     0,    45,    46,    47,    48,    49,     0,    50,
       1,    30,     0,     2,     0,     0,    51,     0,     0,    31,
      32,     0,     0,    33,    34,     0,     0,     0,     0,     0,
      36,    41,     0,     0,     0,     0,     0,     0,     0,    30,
       1,    30,     0,     2,     0,   134,    38,    31,    32,    31,
      32,    33,    34,    33,    34,    35,     0,     0,    36,    37,
      36,    41,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,    38,    98,    38,    31,    32,     0,
       0,    33,    34,   110,     0,     0,    30,     0,    36,    41,
       0,     0,     0,     0,    31,    32,     0,     0,    33,    34,
      30,     0,     0,     0,    38,    36,    41,     0,    31,    32,
       0,     0,    33,    34,     0,     0,     0,   130,    30,    36,
      41,    38,     0,     0,     0,     0,    31,    32,     0,     0,
      33,    34,   160,     0,   150,    38,    30,    36,    41,     0,
       0,     0,     0,     0,    31,    32,     0,     0,    33,    34,
       0,     0,     0,    38,    30,    36,    41,     0,     0,     0,
       0,     0,    31,    32,     0,     0,    33,    34,   169,     0,
     163,    38,    30,    36,    41,     0,     0,     0,     0,     0,
      31,    32,     0,     0,    33,    34,   171,     0,     0,    38,
      30,    36,    41,     0,     0,     0,     0,     0,    31,    32,
       0,     0,    33,    34,   181,     0,     0,    38,    30,    36,
      41,     0,     0,     0,     0,     0,    31,    32,     0,     0,
      33,    34,     0,     0,     0,    38,     0,    36,    41,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      75,    76,    77,    38,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,   156,    89,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,    75,    76,    77,   144,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,   109,
      75,    76,    77,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,   147,    75,    76,
      77,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,   149,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,   153,    75,    76,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,   168,    75,    76,    77,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,   178,
      75,    76,    77,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,   180,    75,    76,
      77,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,   187,    75,    76,    77,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    77,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    80,    81,    82,    83,    84,    85,
      86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      20,    21,    54,     6,     0,     0,    20,    20,     4,     4,
      15,    31,    15,    33,    34,    22,    15,    15,    35,    26,
      25,    38,    25,     0,    19,    39,    39,    25,    39,    39,
      50,    42,    42,     3,     4,     5,    40,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    40,    41,
      70,    71,    15,    16,    17,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    64,
      40,    91,    25,    93,    94,     3,    25,    97,     3,     4,
       5,    20,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    19,    39,    21,    35,   149,    94,    38,
      22,   153,    13,    14,    15,    16,    17,    19,   160,    21,
     130,    25,    20,    26,   134,    40,   168,   169,    25,   171,
      19,    19,   174,   143,    19,    19,   178,    19,   180,   181,
     150,    40,   152,    21,    40,   187,    40,    21,    25,    25,
      25,    22,   162,   163,    26,    20,     4,    40,    64,    40,
       3,     4,     5,   173,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     3,     4,     5,    40,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      40,     6,    33,    14,    25,    -1,    -1,    40,    -1,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    26,    40,    28,    29,    30,    31,    32,    -1,    34,
      35,     6,    -1,    38,    -1,    -1,    41,    42,    -1,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    -1,    34,
      35,     6,    -1,    38,    -1,    -1,    41,    -1,    -1,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    -1,    34,
      35,     6,    -1,    38,    -1,    -1,    41,    -1,    -1,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      35,     6,    -1,    38,    -1,    40,    41,    14,    15,    14,
      15,    18,    19,    18,    19,    22,    -1,    -1,    25,    26,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    41,    40,    41,    14,    15,    -1,
      -1,    18,    19,    20,    -1,    -1,     6,    -1,    25,    26,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    18,    19,
       6,    -1,    -1,    -1,    41,    25,    26,    -1,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    37,     6,    25,
      26,    41,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      18,    19,    20,    -1,    40,    41,     6,    25,    26,    -1,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    41,     6,    25,    26,    -1,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    18,    19,    20,    -1,
      40,    41,     6,    25,    26,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    18,    19,    20,    -1,    -1,    41,
       6,    25,    26,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    18,    19,    20,    -1,    -1,    41,     6,    25,
      26,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    41,    -1,    25,    26,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       3,     4,     5,    41,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    37,    22,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,     3,     4,     5,    22,     7,     8,     9,    10,
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
      15,    16,    17,    -1,    -1,    20,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     5,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     9,    10,    11,    12,    13,    14,
      15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    38,    44,    45,    46,    49,    56,    15,     0,
      46,    15,    25,    47,    50,    57,    58,    40,    25,    19,
      21,     3,    40,    41,    53,    39,    20,    49,    51,    52,
       6,    14,    15,    18,    19,    22,    25,    26,    41,    60,
      62,    26,    60,    23,    24,    28,    29,    30,    31,    32,
      34,    41,    49,    53,    54,    55,    56,    60,    25,    57,
       6,    15,    25,    20,    39,    25,    60,    25,    60,    60,
      19,    21,    22,    26,    48,     3,     4,     5,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    22,
      25,    19,    19,    19,    19,    40,    40,    19,    40,    60,
      26,    42,    55,    40,    40,    25,    25,    21,    52,    20,
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
       0,     2,     1,     1,     2,     2,     3,     3,     1,     3,
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
#line 83 "c_compiler.y"
    {
        root = new AST::BaseNode("program",AST::NodeType::ROOT);
        // root->addChildNode(new AST::BaseNode("test"));
        root->addChildNode((yyvsp[0].ast));
        BTTree<AST::BaseNode> printer(root, &AST::BaseNode::getAllChildrenNode,
                        &AST::BaseNode::getStringContent);
        printer.print();
        dfs(NULL,root);

    }
#line 1497 "y.tab.c"
    break;

  case 3: /* blocks: block  */
#line 96 "c_compiler.y"
    {
        printf("blocks->block\n");
        
        (yyval.ast)= (yyvsp[0].ast);
        // AST::BaseNode *node = new AST::BaseNode("a_Block",AST::NodeType::STATEMENT);
        // node->addChildNode($1);
        // $$ = node;
    }
#line 1510 "y.tab.c"
    break;

  case 4: /* blocks: blocks block  */
#line 105 "c_compiler.y"
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
#line 1525 "y.tab.c"
    break;

  case 5: /* block: declare SEMI  */
#line 118 "c_compiler.y"
    {
        printf("Declare_Statement\n");
        // AST::BaseNode *node = new AST::BaseNode("Declare_Statement",AST::NodeType::DEFINITION);
        // node->addChildNode($1);
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1536 "y.tab.c"
    break;

  case 6: /* block: descriptor function body  */
#line 125 "c_compiler.y"
    {
        printf("blockcdescriptor function body\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Func_Block_Body",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[-1].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1549 "y.tab.c"
    break;

  case 7: /* block: descriptor function SEMI  */
#line 134 "c_compiler.y"
    {
        printf("block->descriptor function 'SEMI'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Func_Block_NoBody",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1561 "y.tab.c"
    break;

  case 8: /* variable: IDENTIFIER  */
#line 143 "c_compiler.y"
    {   
        printf("variable->IDENTIFIER\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Identifier",AST::NodeType::DEFINITION);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
#line 1573 "y.tab.c"
    break;

  case 9: /* variable: IDENTIFIER '[' ']'  */
#line 151 "c_compiler.y"
    {
        printf("variable->IDENTIFIER '[' ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
#line 1585 "y.tab.c"
    break;

  case 10: /* variable: IDENTIFIER '[' CONST ']'  */
#line 159 "c_compiler.y"
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
#line 1601 "y.tab.c"
    break;

  case 11: /* variable: IDENTIFIER '[' expression ']'  */
#line 171 "c_compiler.y"
    {
        printf("variable->IDENTIFIER '[' expression ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[expression]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        node->addChildNode((yyvsp[-1].ast));
    }
#line 1613 "y.tab.c"
    break;

  case 12: /* variable: '*' IDENTIFIER  */
#line 179 "c_compiler.y"
    {
        printf("variable->'*' IDENTIFIER\n");
        AST::BaseNode * node = new AST::BaseNode("Def_*Identifier",AST::NodeType::POINTER);
        AST::BaseNode * var_node = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(var_node);
        (yyval.ast) = node;
    }
#line 1625 "y.tab.c"
    break;

  case 13: /* consts: CONST  */
#line 189 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Const_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[0].num),AST::NodeType::CONST_INT);
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
#line 1637 "y.tab.c"
    break;

  case 14: /* consts: consts COMMA CONST  */
#line 197 "c_compiler.y"
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Consts_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode((yyvsp[0].num),AST::NodeType::CONST_INT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode(const_node);
        (yyval.ast) = node;
    }
#line 1650 "y.tab.c"
    break;

  case 15: /* descriptor: INT  */
#line 208 "c_compiler.y"
    {
        printf("INTTTTTTT\n");
        AST::BaseNode * node = new AST::BaseNode("int_Type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
#line 1660 "y.tab.c"
    break;

  case 16: /* descriptor: VOID  */
#line 214 "c_compiler.y"
    {
        printf("VOID\n");
        AST::BaseNode * node = new AST::BaseNode("void_type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
#line 1670 "y.tab.c"
    break;

  case 17: /* descriptor: INT '*'  */
#line 220 "c_compiler.y"
    {
        printf("INT* \n");
        AST::BaseNode * node = new AST::BaseNode("int*_Type",AST::NodeType::MODIFY);
        (yyval.ast) = node;
    }
#line 1680 "y.tab.c"
    break;

  case 18: /* function: IDENTIFIER '(' ')'  */
#line 228 "c_compiler.y"
    {
        printf("Function_Without_Param\n");
        AST::BaseNode * node = new AST::BaseNode("Function_Without_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        (yyval.ast) = node;
    }
#line 1692 "y.tab.c"
    break;

  case 19: /* function: IDENTIFIER '(' params ')'  */
#line 236 "c_compiler.y"
    {
        printf("Function_With_Param\n");
        AST::BaseNode * node = new AST::BaseNode("Function_With_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1705 "y.tab.c"
    break;

  case 20: /* params: params COMMA param  */
#line 246 "c_compiler.y"
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
#line 1720 "y.tab.c"
    break;

  case 21: /* params: param  */
#line 256 "c_compiler.y"
        {
    printf("params: param\n");
    // AST::BaseNode * node = new AST::BaseNode("Single_Param",AST::NodeType::DEFINITION);
    // node->addChildNode($1);
    // $$ = node;
    (yyval.ast) = (yyvsp[0].ast);
}
#line 1732 "y.tab.c"
    break;

  case 22: /* param: descriptor IDENTIFIER  */
#line 264 "c_compiler.y"
                             {
    printf("param:descriptor identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-1].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1745 "y.tab.c"
    break;

  case 23: /* param: descriptor IDENTIFIER '[' CONST ']'  */
#line 272 "c_compiler.y"
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
#line 1760 "y.tab.c"
    break;

  case 24: /* param: descriptor IDENTIFIER '[' ']'  */
#line 282 "c_compiler.y"
                                {
    printf("param:descriptor identifiers '[' ']'\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID[]",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[-2].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-3].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1773 "y.tab.c"
    break;

  case 25: /* param: descriptor SINGLAND IDENTIFIER  */
#line 290 "c_compiler.y"
                               {
    printf("param:descriptor SINGLAND identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("array_&id",AST::NodeType::ARRAY);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-2].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1786 "y.tab.c"
    break;

  case 26: /* param: descriptor '*' IDENTIFIER  */
#line 298 "c_compiler.y"
                          {
    printf("param:descriptor SINGLAND '*' identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("array_*id",AST::NodeType::POINTER);
    AST::BaseNode * IdentifierNode = new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID);
    node->addChildNode((yyvsp[-2].ast));
    node->addChildNode(IdentifierNode);
    (yyval.ast) = node;
}
#line 1799 "y.tab.c"
    break;

  case 27: /* param: descriptor  */
#line 306 "c_compiler.y"
           {
    printf("param:descriptor\n");
    AST::BaseNode * node = new AST::BaseNode("param_without_id",AST::NodeType::DEFINITION);
    node->addChildNode((yyvsp[0].ast));
    (yyval.ast) = node;
}
#line 1810 "y.tab.c"
    break;

  case 28: /* body: '{' statements '}'  */
#line 313 "c_compiler.y"
                        {
    printf("body:'{' statements '}'\n");
    AST::BaseNode *node = new AST::BaseNode("Body",AST::NodeType::BODY);
    node->addChildNode((yyvsp[-1].ast));
    (yyval.ast) = node;
}
#line 1821 "y.tab.c"
    break;

  case 29: /* statements: statements statement  */
#line 320 "c_compiler.y"
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
#line 1836 "y.tab.c"
    break;

  case 30: /* statements: statement  */
#line 330 "c_compiler.y"
           {
    printf("statements:statement\n");
    // AST::BaseNode * node = new AST::BaseNode("Single_Statement",AST::NodeType::STATEMENT);
    // node->addChildNode($1);
    (yyval.ast) = (yyvsp[0].ast);
}
#line 1847 "y.tab.c"
    break;

  case 31: /* statement: expression SEMI  */
#line 341 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1857 "y.tab.c"
    break;

  case 32: /* statement: declare SEMI  */
#line 348 "c_compiler.y"
    {
        // AST::BaseNode *node = new AST::BaseNode("Declare_Statement",AST::NodeType::STATEMENT);
        // node->addChildNode($1);
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1867 "y.tab.c"
    break;

  case 33: /* statement: body  */
#line 355 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Body_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1877 "y.tab.c"
    break;

  case 34: /* statement: RETURN expression SEMI  */
#line 362 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Return_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 1887 "y.tab.c"
    break;

  case 35: /* statement: RETURN SEMI  */
#line 368 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Return_NULL",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
#line 1896 "y.tab.c"
    break;

  case 36: /* statement: IF '(' expression ')' statement  */
#line 373 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("If_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1907 "y.tab.c"
    break;

  case 37: /* statement: IF '(' expression ')' statement ELSE statement  */
#line 379 "c_compiler.y"
                                                                          {
        AST::BaseNode * node = new AST::BaseNode ("If_Else_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1919 "y.tab.c"
    break;

  case 38: /* statement: WHILE '(' expression ')' statement  */
#line 387 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode ("While_Statement",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1930 "y.tab.c"
    break;

  case 39: /* statement: FOR '(' SEMI SEMI ')' statement  */
#line 394 "c_compiler.y"
    {
        printf("FOR '(' SEMI SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1941 "y.tab.c"
    break;

  case 40: /* statement: FOR '(' forstart SEMI SEMI ')' statement  */
#line 401 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1953 "y.tab.c"
    break;

  case 41: /* statement: FOR '(' SEMI expression SEMI ')' statement  */
#line 409 "c_compiler.y"
    {
        printf("FOR '(' SEMI expression SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-3].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1965 "y.tab.c"
    break;

  case 42: /* statement: FOR '(' SEMI SEMI expression ')' statement  */
#line 417 "c_compiler.y"
    {
        printf("FOR '(' SEMI SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1977 "y.tab.c"
    break;

  case 43: /* statement: FOR '(' forstart SEMI expression SEMI expression ')' statement  */
#line 425 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI expression SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-6].ast));
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 1991 "y.tab.c"
    break;

  case 44: /* statement: FOR '(' forstart SEMI expression SEMI ')' statement  */
#line 435 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI expression SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-5].ast));
        node->addChildNode((yyvsp[-3].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2004 "y.tab.c"
    break;

  case 45: /* statement: FOR '(' forstart SEMI SEMI expression ')' statement  */
#line 444 "c_compiler.y"
    {
        printf("FOR '(' forstart SEMI SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-5].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2017 "y.tab.c"
    break;

  case 46: /* statement: FOR '(' SEMI expression SEMI expression ')' statement  */
#line 453 "c_compiler.y"
    {
        printf("FOR '(' SEMI expression SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-4].ast));
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2030 "y.tab.c"
    break;

  case 47: /* statement: BREAK SEMI  */
#line 462 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Break_Statement",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
#line 2039 "y.tab.c"
    break;

  case 48: /* statement: CONTINUE SEMI  */
#line 467 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Continue_Statement",AST::NodeType::STATEMENT);
        (yyval.ast) = node;
    }
#line 2048 "y.tab.c"
    break;

  case 49: /* statement: PRINTF '(' D_QUO expression D_QUO ')' SEMI  */
#line 472 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_String",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-3].ast));
        (yyval.ast) = node;
    }
#line 2058 "y.tab.c"
    break;

  case 50: /* statement: PRINTF '(' expression ')' SEMI  */
#line 478 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_Expression",AST::NodeType::STATEMENT);
        node->addChildNode((yyvsp[-2].ast));
        (yyval.ast) = node;
    }
#line 2068 "y.tab.c"
    break;

  case 51: /* statement: SCANF '(' IDENTIFIER ')' SEMI  */
#line 484 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode ("Scanf_Identifier",AST::NodeType::STATEMENT);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2079 "y.tab.c"
    break;

  case 52: /* declare: descriptor declares  */
#line 495 "c_compiler.y"
    {
        // printf("Declare_Statement\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Statement",AST::NodeType::DEFINITION);

        node->addChildNode((yyvsp[-1].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2092 "y.tab.c"
    break;

  case 53: /* declares: declarevars  */
#line 508 "c_compiler.y"
    {
         printf("declarevars\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Variable",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2103 "y.tab.c"
    break;

  case 54: /* declares: declarevars COMMA declares  */
#line 515 "c_compiler.y"
    {
         printf("declarevars COMMA declares\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Variables",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2115 "y.tab.c"
    break;

  case 55: /* declarevars: variable  */
#line 527 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Variable",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2125 "y.tab.c"
    break;

  case 56: /* declarevars: variable ASSIGN_OP expression  */
#line 534 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Variable_Assign",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2136 "y.tab.c"
    break;

  case 57: /* forstart: declare  */
#line 543 "c_compiler.y"
    {
        printf("declares\n");
        AST::BaseNode * node = new AST::BaseNode("For_Start",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2147 "y.tab.c"
    break;

  case 58: /* forstart: expression  */
#line 550 "c_compiler.y"
    {
        printf("expression\n");
        AST::BaseNode * node = new AST::BaseNode("For_Expression",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2158 "y.tab.c"
    break;

  case 59: /* expression: CONST  */
#line 560 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Constant_Expression",AST::NodeType::EXPRESSION);
        AST::BaseNode * Constant_Node = new AST::BaseNode ((yyvsp[0].num),AST::NodeType::CONST_INT);
        node->addChildNode(Constant_Node);
        (yyval.ast) = node;
    }
#line 2169 "y.tab.c"
    break;

  case 60: /* expression: identifiers  */
#line 567 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Identifier_Expression",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2179 "y.tab.c"
    break;

  case 61: /* expression: expression ASSIGN_OP expression  */
#line 573 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Assign",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2190 "y.tab.c"
    break;

  case 62: /* expression: expression '+' expression  */
#line 580 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Add",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2201 "y.tab.c"
    break;

  case 63: /* expression: expression '-' expression  */
#line 587 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Sub",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2212 "y.tab.c"
    break;

  case 64: /* expression: expression '*' expression  */
#line 594 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Mul",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2223 "y.tab.c"
    break;

  case 65: /* expression: expression '/' expression  */
#line 601 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Div",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2234 "y.tab.c"
    break;

  case 66: /* expression: expression '%' expression  */
#line 608 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Mod",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2245 "y.tab.c"
    break;

  case 67: /* expression: '(' expression ')'  */
#line 615 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Braces",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2255 "y.tab.c"
    break;

  case 68: /* expression: '-' expression  */
#line 621 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Negative",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2265 "y.tab.c"
    break;

  case 69: /* expression: expression AND expression  */
#line 627 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("And",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2276 "y.tab.c"
    break;

  case 70: /* expression: expression OR expression  */
#line 634 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Or",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2287 "y.tab.c"
    break;

  case 71: /* expression: '!' expression  */
#line 641 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Not",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2297 "y.tab.c"
    break;

  case 72: /* expression: '{' consts '}'  */
#line 647 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("{Consts}",AST::NodeType::EXPRESSION);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2307 "y.tab.c"
    break;

  case 73: /* expression: expression EQ_OP expression  */
#line 653 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2318 "y.tab.c"
    break;

  case 74: /* expression: expression NE_OP expression  */
#line 660 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Not_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2329 "y.tab.c"
    break;

  case 75: /* expression: expression GT_OP expression  */
#line 667 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode("Greater_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2340 "y.tab.c"
    break;

  case 76: /* expression: expression LT_OP expression  */
#line 674 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2351 "y.tab.c"
    break;

  case 77: /* expression: expression GE_OP expression  */
#line 681 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Greater_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2362 "y.tab.c"
    break;

  case 78: /* expression: expression LE_OP expression  */
#line 688 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2373 "y.tab.c"
    break;

  case 79: /* expression: IDENTIFIER '(' arguments ')'  */
#line 695 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Function_Call_With_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2385 "y.tab.c"
    break;

  case 80: /* expression: IDENTIFIER '(' ')'  */
#line 702 "c_compiler.y"
                        {
        AST::BaseNode * node = new AST::BaseNode("Function_Call_Without_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-2].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2396 "y.tab.c"
    break;

  case 81: /* expression: '*' IDENTIFIER  */
#line 709 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("*id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2407 "y.tab.c"
    break;

  case 82: /* expression: IDENTIFIER '[' expression ']'  */
#line 716 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("id[exp]",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[-3].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = node;
    }
#line 2419 "y.tab.c"
    break;

  case 83: /* expression: SINGLAND IDENTIFIER  */
#line 724 "c_compiler.y"
    {   
        AST::BaseNode * node = new AST::BaseNode("&id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ((yyvsp[0].str),AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        (yyval.ast) = node;
    }
#line 2430 "y.tab.c"
    break;

  case 84: /* arguments: expression  */
#line 733 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Arg",AST::NodeType::ID);
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2440 "y.tab.c"
    break;

  case 85: /* arguments: arguments COMMA expression  */
#line 739 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Args",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-2].ast));
        node->addChildNode((yyvsp[0].ast));
        (yyval.ast) = node;
    }
#line 2451 "y.tab.c"
    break;

  case 86: /* identifiers: IDENTIFIER  */
#line 747 "c_compiler.y"
              {
        AST::BaseNode * node = new AST::BaseNode("id",AST::NodeType::DEFINITION);
        node->addChildNode(new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID));
        (yyval.ast) = node;
    }
#line 2461 "y.tab.c"
    break;

  case 87: /* identifiers: identifiers IDENTIFIER  */
#line 753 "c_compiler.y"
    {
        AST::BaseNode * node = new AST::BaseNode("ids",AST::NodeType::DEFINITION);
        node->addChildNode((yyvsp[-1].ast));
        AST::BaseNode * id_node = new AST::BaseNode("id",AST::NodeType::DEFINITION);
        node->addChildNode(new AST::BaseNode((yyvsp[0].str),AST::NodeType::ID));
        node->addChildNode(id_node);
        // node->addChildNode(new AST::BaseNode($2,AST::NodeType::ID));
        (yyval.ast) = node;
    }
#line 2475 "y.tab.c"
    break;


#line 2479 "y.tab.c"

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

#line 765 "c_compiler.y"


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
