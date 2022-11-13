/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "c_compiler.y"
{
    char* num;
    AST::BaseNode *ast;
    char *str;
}
/* Line 1529 of yacc.c.  */
#line 115 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

