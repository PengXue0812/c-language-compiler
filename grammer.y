%{
#include <stdio.h>
#include <string.h>

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
    char* str;
}

%token<str> WHILE FOR BREAK CONTINUE IF ELSE PRINTF SCANF RETURN VOID S_QUO D_QUO INT COMMA SEMI ASSIGN_OP ADD SUB MUL DIV MOD POW EQ_OP GT_OP LT_OP GE_OP LE_OP NE_OP AND OR NOT SINGLAND IDENTIFIER CONST

%%
commands:
|commands command

command:DECLEAR SEMI

DECLEAR: INT IDENTIFIERS
{
}

IDENTIFIERS: IDENTIFIERS COMMA IDENTIFIER{
    printf("%s\n", $3);
}
|IDENTIFIER{
    printf("%s\n", $1);
}




%%