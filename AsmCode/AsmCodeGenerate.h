#ifndef ASMCODEGENERATE_H
#define ASMCODEGENERATE_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "./AsmCode.h"
#include "../Symbol/Symbol.h"
#include "../InterCode/InterCode.h"
using namespace std;

class AsmGenerate
{
private:
    int eax;
    int ebx;
    int ecx;
    int edx;;
    AsmCode asmcode;
    std::string registerUsedVar[6];
    //std::vector<Symbol*> tempVar;
    std::vector<QuadItem*> quad_list;
    std::map<int, int> labelMap;
    SymbolArea* rootTable;
    SymbolArea* currentTable;
    //FuncTable funcTable;
    void releaseRegister(asmRegister reg);
    asmRegister getRegister(std::string var);
    asmRegister findRegister(std::string var);
    void generateSetArg(QuadItem q);
    void generateArithmetic(QuadItem q);
    void generateJump(QuadItem q);
    void generateNeg(QuadItem q);
    void generatePower(QuadItem q);
    void preSetLabel();
    bool isJumpQuad(OpType code);
    void generateprint(QuadItem q);
public:
    Symbol* getoffsetofarray(Symbol* arg);
    inline AsmCode& getAsmCode() { return this->asmcode; }
    //AsmGenerate(std::vector<QuadItem*>quads, std::vector<Symbol*> tempVar, SymbolTable* rootTable, FuncTable funcTable);
    AsmGenerate(std::vector<QuadItem*>quads, SymbolArea* rootTable);
    void generate();
    void printbuffer(){
        std::cout<<"buffer:"<<this->asmcode.getcodeBuffer()<<"\n\n";
    }
};


#endif