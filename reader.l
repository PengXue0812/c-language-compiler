LETTER [a-zA-Z_]
DIGIT [0-9]
WHITE_SPACE [ \t\n] 
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


(([1-9]){DIGIT}*)|0  {yylval.num= atoi(strdup(yytext)); return CONST; }


"+"    { return ADD; }
"-"    { return SUB; }
"*"    { return MUL; }
"/"    { return DIV; }
"%"    { return MOD; }
"^"    { return POW; }

"=="   { return EQ_OP; }
">"    { return GT_OP; }
"<"    { return LT_OP; }
">="   { return GE_OP; }
"<="   { return LE_OP; }
"!="   { return NE_OP; }

"&&"   { return AND;  }
"||"   { return OR; }
"!"    { return NOT; }
"&"    { return SINGLAND; }


[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { /* DO NOTHING */ }
"//"[^\n]*   {/* DO NOTHING */}
{WHITE_SPACE} { /* ignore white space */ }
.       {printf("ERROR!!"); }
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