LETTER [a-zA-Z_]
DIGIT [0-9]
WHITE_SPACE [ \t(\r\n)]
%{
# include <stdio.h>
# include "y.tab.h"
# include <string.h>

int cur_id = 10000;
int cur = 0;
struct Sym{
    char *word;
    char *morpheme;
    int val;
};
struct Sym sym[10000];
FILE *symfile = fopen("./oursym.txt","w");
%}

%% 

"while"     { sym[cur].word=strdup("WHILE"); sym[cur].morpheme=strdup("while"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return WHILE; }
"for"       { sym[cur].word=strdup("FOR"); sym[cur].morpheme=strdup("for"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return FOR; }
"break"     { sym[cur].word=strdup("BREAK"); sym[cur].morpheme=strdup("break"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return BREAK; }
"continue"  { sym[cur].word=strdup("CONTINUE"); sym[cur].morpheme=strdup("continue"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return CONTINUE; }
"if"        { sym[cur].word=strdup("IF"); sym[cur].morpheme=strdup("if"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return IF; }
"else"      { sym[cur].word=strdup("ELSE"); sym[cur].morpheme=strdup("else"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return ELSE; }
"printf"    { sym[cur].word=strdup("PRINTF"); sym[cur].morpheme=strdup("printf"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return PRINTF; }
"scanf"     { sym[cur].word=strdup("SCANF"); sym[cur].morpheme=strdup("scanf"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return SCANF; }
"return"    { sym[cur].word=strdup("RETURN"); sym[cur].morpheme=strdup("return"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return RETURN; }
"void"      { sym[cur].word=strdup("VOID"); sym[cur].morpheme=strdup("void"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return VOID; }
"\''"       { sym[cur].word=strdup("S_QUO"); sym[cur].morpheme=strdup("\'"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return S_QUO; /* 单引号 */}
"\""        { sym[cur].word=strdup("D_QUO"); sym[cur].morpheme=strdup("\""); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return D_QUO; /* 双引号 */}
"int"       { sym[cur].word=strdup("INT"); sym[cur].morpheme=strdup("int"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return INT; }
","         { sym[cur].word=strdup("COMMA"); sym[cur].morpheme=strdup(","); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return COMMA; }
";"         { sym[cur].word=strdup("SEMI"); sym[cur].morpheme=strdup(";"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return SEMI; }
"="         { sym[cur].word=strdup("ASSIGN_OP"); sym[cur].morpheme=strdup("="); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return ASSIGN_OP; }
"("         { sym[cur].word=strdup("LP"); sym[cur].morpheme=strdup("("); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return '('; }
")"         { sym[cur].word=strdup("RP"); sym[cur].morpheme=strdup(")"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return ')'; }
"["         { sym[cur].word=strdup("LMP"); sym[cur].morpheme=strdup("["); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return '['; }
"]"         { sym[cur].word=strdup("RMP"); sym[cur].morpheme=strdup("]"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return ']'; }
"{"         { sym[cur].word=strdup("LBRACE"); sym[cur].morpheme=strdup("{"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return '{'; }
"}"         { sym[cur].word=strdup("RBRACE"); sym[cur].morpheme=strdup("}"); sym[cur].val=0; fprintf(symfile,"%s\t%s\t\n",sym[cur].word,sym[cur].morpheme ); cur++; return '}'; }

{LETTER}([a-zA-Z_]|{DIGIT})*  { 
    int flag = 0;
    for(int i = 0;i<cur;i++){
        if(strcmp(yytext, sym[i].morpheme) == 0){
            sym[cur].word = strdup("IDENTIFIER");
            sym[cur].morpheme = strdup(yytext);
            sym[cur].val = sym[i].val;
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        sym[cur].word = strdup("IDENTIFIER");
        sym[cur].morpheme = strdup(yytext);
        sym[cur].val = cur_id++;
    }
    fprintf(symfile,"%s\t%s\t%d\n",sym[cur].word,sym[cur].morpheme,sym[cur].val );
    cur++;
    yylval.str = strdup(yytext); return IDENTIFIER;  
}


(([1-9]){DIGIT}*)|0  { sym[cur].word=strdup("CONST"); sym[cur].morpheme=strdup(yytext); sym[cur].val=atoi(yytext); fprintf(symfile,"%s\t%s\t%d\n",sym[cur].word,sym[cur].morpheme,sym[cur].val ); cur++; yylval.num= strdup(yytext); return CONST; }


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

