#include"Symbol.h"

Symbol* createSymbol(char* name,char* type,int id){
    Symbol* s = (Symbol*)malloc(sizeof(Symbol));
    strcpy(s->name,name);
    strcpy(s->type,type);
    s->id = id;
    return s;
}
Symbol* createSymbol(){
    Symbol* s = (Symbol*)malloc(sizeof(Symbol));
    s->id = 0;
    return s;
}

SymbolArea* createSymbolArea(){
    SymbolArea* sa= (SymbolArea*)malloc(sizeof(SymbolArea));
    // sa->symbols = (Symbol*)malloc(sizeof(Symbol*));
    
    sa->count = 0;
    return sa;
}
void addSymbol(SymbolArea* sa,Symbol* s){
 
    sa->symbols[sa->count] = *s;

    sa->count+=1;

}
// int main(){
//     SymbolArea* sa = createSymbolArea();
//     char name[] = "kjh";
    

//     Symbol* s = createSymbol(name,AST::ROOT,1);
  
//     addSymbol(sa,s);
   
//     printf("%d",sa->symbols[sa->count-1].type);
//     return 0;
// }