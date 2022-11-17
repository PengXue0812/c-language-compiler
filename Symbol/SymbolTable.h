#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_


#include "Symbol.h"
#include"../Node/BaseNode.h"
#include <list>

struct SymbolTable
{
    Symbol* symbols;
    int count;
};

SymbolTable* createSymbolTable();
void addSymbol(SymbolTable* table, Symbol* symbol);
SymbolArea* dfsDeclares(SymbolArea* sa,AST::BaseNode* node,char* declareType);
SymbolArea* dfsParams(SymbolArea* sa,AST::BaseNode* node);
void dfs(SymbolArea* area, AST::BaseNode* node );


#endif
