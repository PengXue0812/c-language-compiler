#ifndef ASMCODE_H
#define ASMCODE_H

// Asm instructor
#define ASM_MOV     "mov"
#define ASM_ADD     "add"
#define ASM_XOR     "xor"
#define ASM_NEG     "neg"
#define ASM_SUB     "sub"
#define ASM_MUL     "mul"
#define ASM_DIV     "div"
#define ASM_PUSH    "push"
#define ASM_POP     "pop"
#define ASM_CALL    "call"
#define ASM_RET     "ret"
#define ASM_CMP     "cmp"
#define ASM_ENTER   "enter"
#define ASM_LEAVE   "leave"

// Jump instructor
#define ASM_JUMP    "jmp"
#define ASM_JE      "je"
#define ASM_JG      "jg"
#define ASM_JGE     "jge"
#define ASM_JL      "jl"
#define ASM_JLE     "jle"
#define ASM_JNE     "jne"

// 32-bit asm register
#define ASM_EAX     "eax"
#define ASM_EBX     "ebx"
#define ASM_ECX     "ecx"
#define ASM_EDX     "edx"
#define ASM_EBP     "ebp"
#define ASM_ESP     "esp"

// Date type
#define DOUBLE_WORD "dword"

// Other characters
#define ASM_LB      "["
#define ASM_RB      "]"
#define ASM_COMMA   ","
#define ASM_COLON   ":"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "../Symbol/Symbol.h"
#include "../InterCode/InterCode.h"
using namespace std;
enum class asmRegister {
    unset = -1,
    eax = 1,
    ebx = 2,
    ecx = 3,
    edx = 4,
    esp = 5,
    ebp = 6
};
class AsmCode {
private:
    std::string codeBuffer;
    std::string transRegister(asmRegister reg);
public:
    AsmCode();
    std::string generateVar(int offset);
    std::string generateInstanceNumber(int value);
    void generateBinaryInstructor(std::string instructor, asmRegister reg1, asmRegister reg2);
    void generateBinaryInstructor(std::string instructor, asmRegister reg, std::string var);
    void generateBinaryInstructor(std::string instructor, std::string var, asmRegister reg);
    void generateBinaryInstructor(std::string instructor, std::string var1, std::string var2);
    void generateUnaryInstructor(std::string instructor, std::string var);
    void generateUnaryInstructor(std::string instructor, asmRegister reg);
    std::string findValueByAddress(asmRegister reg);
    // ADD instructor, add reg1, reg2
    void add(asmRegister reg1, asmRegister reg2);
    // ADD instructor, add reg, var
    void genarateAdd(asmRegister reg, std::string var);
    void genarateSub(asmRegister reg1, asmRegister reg2);
    void genarateSub(asmRegister reg, std::string var);
    void genarateMov(asmRegister reg1, asmRegister reg2);
    void genarateMov(asmRegister reg, std::string var);
    void genarateMov(std::string var, asmRegister reg);
    void genarateMov(std::string var1, std::string var2);
    void genarateMul(asmRegister reg1, asmRegister reg2);
    void genarateMul(asmRegister reg, std::string var);
    void genarateMul(std::string var1, std::string var2);
    void genarateDiv(asmRegister reg1, asmRegister reg2);
    void genarateDiv(asmRegister reg, std::string var);
    void genarateDiv(std::string var, asmRegister reg);
    void genarateDiv(std::string var1, std::string var2);
    void genarateAsmXor(asmRegister reg1, asmRegister reg2);
    void genaratePush(asmRegister reg);
    void genaratePush(std::string var);
    void genaratePop(asmRegister reg);
    void genarateLabel(std::string label);
    void addCode(std::string code);
    friend std::ostream& operator<<(std::ostream& os, const AsmCode& asmcode);
    std::string getcodeBuffer(){return codeBuffer;}

};

    
#endif