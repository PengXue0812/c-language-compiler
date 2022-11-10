%{
#include <stdio.h>
#include <string.h>
#include "../Node/BaseNode.h"
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
    AST::BaseNode* ast;
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