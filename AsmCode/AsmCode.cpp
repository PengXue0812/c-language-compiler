#include "AsmCode.h"
#include <string.h>
AsmCode::AsmCode()
{
}

std::string AsmCode::transRegister(asmRegister reg)
{
    if (reg == asmRegister::eax)
        return ASM_EAX;
    else if (reg == asmRegister::ebx)
        return ASM_EBX;
    else if (reg == asmRegister::ecx)
        return ASM_ECX;
    else if (reg == asmRegister::edx)
        return ASM_EDX;
    else if (reg == asmRegister::ebp)
        return ASM_EBP;
    else if (reg == asmRegister::esp)
        return ASM_ESP;
    else
        return "";
}

std::string AsmCode::generateVar(int offset)
{
    std::string ans = ASM_LB + std::string(ASM_EBP);
    if (offset > 0)
    {
        ans += "+";
        ans += std::to_string(offset);
    }
    else
    {
        ans += "-";
        ans += std::to_string(-offset);
    }
    ans += ASM_RB;
    return ans;
}

std::string AsmCode::generateInstanceNumber(int value)
{
    std::string ans = DOUBLE_WORD;
    ans += " " + std::to_string(value);
    return ans;
}
void AsmCode::generateBinaryInstructor(std::string instructor, asmRegister reg1, asmRegister reg2)
{
    this->codeBuffer += instructor + std::string(" ") + this->transRegister(reg1) + "," + this->transRegister(reg2) + "\n";
}

void AsmCode::generateBinaryInstructor(std::string instructor, asmRegister reg, std::string var)
{
    this->codeBuffer += instructor + std::string(" ") + this->transRegister(reg) + "," + var + "\n";
}

void AsmCode::generateBinaryInstructor(std::string instructor, std::string var, asmRegister reg)
{
    this->codeBuffer += instructor + std::string(" ") + var + "," + this->transRegister(reg) + "\n";
}

void AsmCode::generateBinaryInstructor(std::string instructor, std::string var1, std::string var2)
{
    this->codeBuffer += instructor + " " + var1 +
                        +ASM_COMMA + var2 + "\n";
}

void AsmCode::generateUnaryInstructor(std::string instructor, asmRegister reg)
{
    this->codeBuffer += instructor + " " + this->transRegister(reg) + "\n";
}

void AsmCode::generateUnaryInstructor(std::string instructor, std::string var)
{
    this->codeBuffer += instructor + " " + var + "\n";
}

std::string AsmCode::findValueByAddress(asmRegister reg)
{
    return ASM_LB + this->transRegister(reg) + ASM_RB;
}

void AsmCode::addCode(std::string code)
{
    this->codeBuffer += code;
    this->codeBuffer += "\n";
}

void AsmCode::generateAdd(asmRegister reg1, asmRegister reg2)
{
    this->generateBinaryInstructor(ASM_ADD, reg1, reg2);
}

void AsmCode::generateAdd(asmRegister reg, std::string var)
{
    this->generateBinaryInstructor(ASM_ADD, reg, var);
}

void AsmCode::generateSub(asmRegister reg1, asmRegister reg2)
{
    this->generateBinaryInstructor(ASM_SUB, reg1, reg2);
}

void AsmCode::generateSub(asmRegister reg, std::string var)
{
    this->generateBinaryInstructor(ASM_SUB, reg, var);
}

void AsmCode::generateMov(asmRegister reg1, asmRegister reg2)
{
    this->generateBinaryInstructor(ASM_MOV, reg1, reg2);
}

void AsmCode::generateMov(asmRegister reg, std::string var)
{
    this->generateBinaryInstructor(ASM_MOV, reg, var);
}

void AsmCode::generateMov(std::string var, asmRegister reg)
{
    this->generateBinaryInstructor(ASM_MOV, var, reg);
}

void AsmCode::generateMov(std::string var1, std::string var2)
{
    this->generateBinaryInstructor(ASM_MOV, var1, var2);
}

// Save the answer to eax
void AsmCode::generateMul(asmRegister reg1, asmRegister reg2)
{
    this->generateAsmXor(asmRegister::edx, asmRegister::edx);
    this->generateMov(asmRegister::eax, reg1);
    this->generateUnaryInstructor(ASM_MUL, reg2);
}

void AsmCode::generateMul(asmRegister reg, std::string var)
{
    this->generateAsmXor(asmRegister::edx, asmRegister::edx);
    this->generateMov(asmRegister::eax, reg);
    this->generateUnaryInstructor(ASM_MUL, DOUBLE_WORD + var);
}

void AsmCode::generateMul(std::string var1, std::string var2)
{
    this->generateAsmXor(asmRegister::edx, asmRegister::edx);
    this->generateMov(asmRegister::eax, var1);
    this->generateUnaryInstructor(ASM_MUL, DOUBLE_WORD + var2);
}

void AsmCode::generateDiv(asmRegister reg1, asmRegister reg2)
{
    this->generateAsmXor(asmRegister::edx, asmRegister::edx);
    this->generateMov(asmRegister::eax, reg1);
    this->generateUnaryInstructor(ASM_DIV, reg2);
}

void AsmCode::generateDiv(asmRegister reg, std::string var)
{
    this->generateAsmXor(asmRegister::edx, asmRegister::edx);
    this->generateMov(asmRegister::eax, reg);
    this->generateUnaryInstructor(ASM_DIV, DOUBLE_WORD + var);
}

void AsmCode::generateDiv(std::string var, asmRegister reg)
{
    this->generateAsmXor(asmRegister::edx, asmRegister::edx);
    this->generateMov(asmRegister::eax, var);
    this->generateUnaryInstructor(ASM_DIV, reg);
}

void AsmCode::generateDiv(std::string var1, std::string var2)
{
    this->generateAsmXor(asmRegister::edx, asmRegister::edx);
    this->generateMov(asmRegister::eax, var1);
    this->generateUnaryInstructor(ASM_DIV, DOUBLE_WORD + var2);
}

void AsmCode::generateAsmXor(asmRegister reg1, asmRegister reg2)
{
    this->generateBinaryInstructor(ASM_XOR, reg1, reg2);
}

void AsmCode::generateAsmXor(asmRegister reg1, std::string var)
{
    this->generateBinaryInstructor(ASM_XOR, reg1, var);
}

void AsmCode::generatePush(asmRegister reg)
{
    this->generateUnaryInstructor(ASM_PUSH, reg);
}

void AsmCode::generatePush(std::string var)
{
    this->generateUnaryInstructor(ASM_PUSH, var);
}

void AsmCode::generatePop(asmRegister reg)
{
    this->generateUnaryInstructor(ASM_POP, reg);
}

void AsmCode::generateLabel(std::string label)
{
    this->codeBuffer += label + ASM_COLON + "\n";
}

std::ostream &operator<<(std::ostream &os, const AsmCode &code)
{
    std::string content = code.codeBuffer;
    while (content[content.length() - 1] == '\n')
    {
        content = content.substr(0, content.length() - 1);
    }    
    os << content;
    return os;
}