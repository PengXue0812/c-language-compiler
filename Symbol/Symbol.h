#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "../Node/NodeType.h"

struct Symbol
{
    char name[200];
    char value[200];
    char addr[200];
    char type[200];
    char idType[200];
    int id;
};

Symbol* createSymbol(std::string name,char* type,int id);
Symbol* createSymbol();

struct SymbolArea{
    int count;
    Symbol symbols[100];
    SymbolArea* p;
};
SymbolArea* createSymbolArea();

void addSymbol(SymbolArea* sa,Symbol* s);
#endif