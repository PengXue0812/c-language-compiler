#ifndef _SYMBOL_H_
#define _SYMBOL_H_
#endif
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <string>

struct Symbol
{
    std::string name;
    int value;
    Symbol(std::string name, int value) : name(name), value(value) {}
};
};
