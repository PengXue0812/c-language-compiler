LETTER [a-zA-Z_]
DIGIT [0-9]
WHITE_SPACE [ \t(\r\n)]
%{
# include <stdio.h>
# include "y.tab.h"
# include <string.h>
%}

%% 

"while"     { return WHILE; }
"for"       { return FOR; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }
"if"        { return IF; }
"else"      { return ELSE; }
"printf"    { return PRINTF; }
"scanf"     { return SCANF; }
"return"    { return RETURN; }
"void"      { return VOID; }
"\''"       { return S_QUO; /* 单引号 */}
"\""        { return D_QUO; /* 双引号 */}
"int"       { return INT; }
","         { return COMMA; }
";"         { return SEMI; }
"="         { return ASSIGN_OP; }
"("         { return '('; }
")"         { return ')'; }
"["         { return '['; }
"]"         { return ']'; }
"{"         { return '{'; }
"}"         { return '}'; }

{LETTER}([a-zA-Z_]|{DIGIT})*  {yylval.str = strdup(yytext); return IDENTIFIER;  }


(([1-9]){DIGIT}*)|0  {yylval.num= strdup(yytext); return CONST; }


"+"    { return '+'; }
"-"    { return '-'; }
"*"    { return '*'; }
"/"    { return '/'; }
"%"    { return '%'; }

"=="   { return EQ_OP; }
">"    { return GT_OP; }
"<"    { return LT_OP; }
">="   { return GE_OP; }
"<="   { return LE_OP; }
"!="   { return NE_OP; }

"&&"   { return AND;  }
"||"   { return OR; }
"!"    { return '!'; }
"&"    { return SINGLAND; }


[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ }
"//"[^\n]*   {/* DO NOTHING */}
{WHITE_SPACE} { /* ignore white space */ }
.       {printf("ERROR!!"); }

%%

