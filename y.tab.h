/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    WHILE = 258,                   /* WHILE  */
    FOR = 259,                     /* FOR  */
    BREAK = 260,                   /* BREAK  */
    CONTINUE = 261,                /* CONTINUE  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    PRINTF = 264,                  /* PRINTF  */
    SCANF = 265,                   /* SCANF  */
    RETURN = 266,                  /* RETURN  */
    VOID = 267,                    /* VOID  */
    S_QUO = 268,                   /* S_QUO  */
    D_QUO = 269,                   /* D_QUO  */
    INT = 270,                     /* INT  */
    COMMA = 271,                   /* COMMA  */
    SEMI = 272,                    /* SEMI  */
    ASSIGN_OP = 273,               /* ASSIGN_OP  */
    ADD = 274,                     /* ADD  */
    SUB = 275,                     /* SUB  */
    MUL = 276,                     /* MUL  */
    DIV = 277,                     /* DIV  */
    MOD = 278,                     /* MOD  */
    POW = 279,                     /* POW  */
    EQ_OP = 280,                   /* EQ_OP  */
    GT_OP = 281,                   /* GT_OP  */
    LT_OP = 282,                   /* LT_OP  */
    GE_OP = 283,                   /* GE_OP  */
    LE_OP = 284,                   /* LE_OP  */
    NE_OP = 285,                   /* NE_OP  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    NOT = 288,                     /* NOT  */
    SINGLAND = 289,                /* SINGLAND  */
    IDENTIFIER = 290,              /* IDENTIFIER  */
    CONST = 291                    /* CONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define WHILE 258
#define FOR 259
#define BREAK 260
#define CONTINUE 261
#define IF 262
#define ELSE 263
#define PRINTF 264
#define SCANF 265
#define RETURN 266
#define VOID 267
#define S_QUO 268
#define D_QUO 269
#define INT 270
#define COMMA 271
#define SEMI 272
#define ASSIGN_OP 273
#define ADD 274
#define SUB 275
#define MUL 276
#define DIV 277
#define MOD 278
#define POW 279
#define EQ_OP 280
#define GT_OP 281
#define LT_OP 282
#define GE_OP 283
#define LE_OP 284
#define NE_OP 285
#define AND 286
#define OR 287
#define NOT 288
#define SINGLAND 289
#define IDENTIFIER 290
#define CONST 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "grammer.y"

    int num;
    char* str;

#line 144 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
