#include "Node/BaseNode.h"
#include "Node/BTNode.h"
#include "Symbol/Symbol.h"
#include "AsmCode/AsmCode.h"
#include "AsmCode/AsmCodeGenerate.h"
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
#line 39 "c_compiler.y"

    char* num;
    BaseNode *ast;
    char *str;

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
