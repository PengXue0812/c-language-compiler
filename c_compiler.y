%{
#include <stdio.h>
#include <string.h>
#include "Node/BaseNode.h"

//在lex.yy.c里定义，会被yyparse()调用。在此声明消除编译和链接错误。
extern int yylex(void); 

// 在此声明，消除yacc生成代码时的告警
extern int yyparse(void); 

int yywrap()
{
    return 1;
}
// 该函数在y.tab.c里会被调用，需要在此定义
void yyerror(const char *s)
{
	printf("[error] %s\n", s);
}

int main()
{
	yyparse();
	return 0;
}
%}

%union
{
    int num;
    AST::BaseNode *ast;
    char *str;
}
%type <ast> program 
%type <ast> blocks 
%type <ast> block
%type <ast> variable 
%type <ast> descriptor 
%type <ast> function 
%type <ast> params  
%type <ast> param 
%type <ast> body 
%type <ast> statements 
%type <ast> statement 
%type <ast> declares
%type <ast> declare
%type <ast> declarevars
%type <ast> forstart
%type <ast> expression
%type <ast> arguments
%type <ast> consts
%type <ast> identifiers 


%right <str> ASSIGN_OP 
%left <ast> OR 
%left <ast> AND 
%left <ast> SINGLAND
%left <str> EQ_OP NE_OP 
%left <str> GT_OP LT_OP GE_OP LE_OP 
%left <ast> '+' '-'
%left <ast> '*' '/' '%'
%right <ast> '!'
%left  <str> '(' ')'
%left  <str> '[' ']'
%token <str> PRINTF 
%token <str> SCANF
%token <str> IDENTIFIER
%token <num> CONST 
%nonassoc LOWER_THAN_ELSE
%token<str> WHILE FOR BREAK CONTINUE IF ELSE RETURN VOID S_QUO D_QUO INT COMMA SEMI 

%%
program:
    blocks
    {
        printf("program->blocks");
    }
    ;
//语句块的集合
blocks:
    block
    {
        printf("blocks->block");
    }
    | blocks block
    {
        printf("blocks->blocks block");
    }
    ;
//语句块(包括函数定义,全局变量的定义)
block:descriptor declares SEMI
    {
        printf("block->descriptor declares SEMI");
    }
    |descriptor function body
    {
        printf("block->descriptor function body");
    }
    |descriptor function SEMI
    {
        printf("block->descriptor function 'SEMI'");
    }
//变量
variable:IDENTIFIER
    {
        printf("variable->IDENTIFIER");
    }
    |IDENTIFIER '[' ']'
    {
        printf("variable->IDENTIFIER '[' ']'");
    }
    |IDENTIFIER '[' CONST ']'
    {
        printf("variable->IDENTIFIER '[' CONST ']'");
    }
    |IDENTIFIER '[' expression ']'
    {
        printf("variable->IDENTIFIER '[' expression ']'");
    }
    |'*' IDENTIFIER
    {
        printf("variable->'*' IDENTIFIER");
    }
    ;
//数字的序列(1,2,3,4)    
consts:CONST
    {
        printf("");
    }
    |consts COMMA CONST
    {
        printf("");
    }
    ;
//标识符
descriptor:INT
    {
        printf("");
    }
    |VOID 
    {
        printf("");
    }
    |INT '*'
    {
        printf("");
    }
    ;
//函数的名字与参数列表
function:IDENTIFIER '(' ')'
    {
        printf("");
    }
    |IDENTIFIER '(' params ')'
    {
        printf("");
    }
    ;
params:params COMMA param {
    printf("params: params COMMA param");
}
| param {
    printf("params: param");
};

param:descriptor IDENTIFIER  {
    printf("param:descriptor identifiers");
}
|descriptor IDENTIFIER  '[' CONST ']' {
    printf("param:descriptor identifiers '[' CONST ']'");
}
|descriptor IDENTIFIER  '[' ']' {
    printf("param:descriptor identifiers '[' ']' ");
}
|descriptor SINGLAND IDENTIFIER{
    printf("param:descriptor SINGLAND identifiers");
}
|descriptor SINGLAND '*' IDENTIFIER{
    printf("param:descriptor SINGLAND '*' identifiers");
}
|descriptor{
    printf("param:descriptor");
};
    
body:
'{' statements '}' {
    printf("body:'{' statements '}'");
};

statements:statements statement {
    printf("statements:statements statement");
}
|statement {
    printf("statements:statement");
};

statement:
    expression SEMI
    {

    }
    | declares SEMI
    {

    }
    | body
    {

    }
    | RETURN expression SEMI
    {

    }
    | RETURN SEMI
    {

    }
    | IF '(' expression ')' statement
    {

    }
    | IF '(' expression ')' statement ELSE statement %prec LOWER_THAN_ELSE{

    }
    | WHILE '(' expression ')' statement
    {

    }
    | FOR '(' SEMI SEMI ')' statement
    {

    }
    | FOR '(' forstart SEMI SEMI ')' statement
    {

    } 
    | FOR '(' SEMI expression SEMI ')' statement
    {

    }
    | FOR '(' SEMI SEMI expression ')' statement
    {

    }
    | FOR '(' forstart SEMI expression SEMI expression ')' statement
    {

    }
    | FOR '(' forstart SEMI expression SEMI ')' statement
    {

    }
    | FOR '(' forstart SEMI SEMI expression ')' statement
    {

    }
    | FOR '(' SEMI expression SEMI expression ')' statement
    {

    }
    | BREAK SEMI
    {

    }
    | CONTINUE SEMI
    {

    }
    | PRINTF '(' D_QUO expression D_QUO ')' SEMI
    {

    }
    | PRINTF '(' expression ')' SEMI
    {

    }
    | SCANF '(' IDENTIFIER ')' SEMI
    {

    }
;
declare:
    descriptor declares
    {

    }
;

declares:
    declarevars
    {


    }
    | declarevars COMMA declares
    {

    }
;
declarevars:
    variable
    {

    }
    | variable ASSIGN_OP expression
    {

    }
;
forstart:
    declares
    {

    }
    | expression
    {

    }
    ;

expression:
    CONST
    {

    }
    | identifiers
    {

    }
    | expression ASSIGN_OP expression
    {

    }
    | expression '+' expression
    {

    }
    | expression '-' expression
    {

    }
    | expression '*' expression
    {

    }
    |expression '/' expression
    {

    }
    | expression '%' expression
    {

    }
    | '(' expression ')'
    {

    }
    | '-' expression
    {

    }
    | expression AND expression
    {

    }
    | expression OR expression
    {

    }
    | '!' expression
    {

    }
    | '{' consts '}'
    {

    }
    | expression EQ_OP expression
    {

    }
    | expression NE_OP expression
    {

    }
    | expression GT_OP expression
    {

    }
    | expression LT_OP expression
    {

    }
    | expression GE_OP expression
    {

    }
    | expression LE_OP expression
    {

    }
    | IDENTIFIER '(' arguments ')'
    {

    }
    | IDENTIFIER '(' ')'{

    }
    | '*' IDENTIFIER
     {

    }
    | IDENTIFIER '[' expression ']'
    {

    }
    | SINGLAND IDENTIFIER 
    {

    }
    ;
arguments:
    expression 
    {

    }
    | arguments COMMA expression
    {

    }
    ;
identifiers:
    IDENTIFIER{

    }
    | identifiers IDENTIFIER
    {

    }
    ;


%%

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