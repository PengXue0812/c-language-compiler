#include "AsmCodeGenerate.h"
#include <string>
#include <cstring>

Symbol *AsmGenerate::getoffsetofarray(Symbol *arg)
{
    Symbol *result;
    string result_name = arg->getIdName();
    char *splited_result = strtok((char *)result_name.c_str(), "[");

    string firstname = splited_result;
    Symbol *re = this->currentTable->findSymbolLocally(firstname);
    if (re == NULL)
    {
        re = this->currentTable->findSymbolGlobally(firstname);
    }
    int base_offset = re->getPointerAddr() - re->getWidth();
    int total_offset = base_offset;
    // result.push_back(firstname);
    // std::cout<<"splited "<<splited_result<<"\n";
    splited_result = strtok(NULL, " ");
    // std::cout<<"splited "<<splited_result<<"\n";
    int numberi = atoi(splited_result);
    // get i from reg
    //  b[0]
    total_offset += numberi * 4;
    result = new Symbol(firstname, SymbolType::var);
    result->setPointerAddr(total_offset);
    return result;
}

AsmGenerate::AsmGenerate(std::vector<QuadItem *> quadlist, SymbolArea *rootTable)
{
    this->quad_list = quadlist;
    // this->tempVar = tempVar;
    this->rootTable = rootTable;
    // this->funcTable = funcTable;
    this->preSetLabel();

    eax = 0;
    ebx = 0;
    ecx = 0;
    edx = 0;
}

void AsmGenerate::releaseRegister(asmRegister reg)
{
    if (reg == asmRegister::ebx)
    {
        ebx = 0;
        int index = (int)asmRegister::ebx;
        this->registerUsedVar[index - 1] = "";
    }
    else if (reg == asmRegister::ecx)
    {
        ecx = 0;
        int index = (int)asmRegister::ecx;
        this->registerUsedVar[index - 1] = "";
    }
    else if (reg == asmRegister::esi)
    {
        esi = 0;
        int index = (int)asmRegister::esi;
        this->registerUsedVar[index - 1] = "";
    }
    else if (reg == asmRegister::edi)
    {
        edi = 0;
        int index = (int)asmRegister::edi;
        this->registerUsedVar[index - 1] = "";
    }
}

asmRegister AsmGenerate::getRegister(std::string var)
{
    if (ebx == 0)
    {
        // // printf("ebx == 0\n");
        ebx = 1;
        int index = (int)asmRegister::ebx;
        this->registerUsedVar[index - 1] = var;
        return asmRegister::ebx;
    }
    else if (ecx == 0)
    {
        // // printf("ecx == 0\n");
        ecx = 1;
        int index = (int)asmRegister::ecx;
        this->registerUsedVar[index - 1] = var;
        return asmRegister::ecx;
    }
    else if (esi == 0)
    {
        // printf("esi == 0\n");
        esi = 1;
        int index = (int)asmRegister::esi;
        this->registerUsedVar[index - 1] = var;
        return asmRegister::esi;
    }
    else if (edi == 0)
    {
        // printf("edi == 0\n");
        edi = 1;
        int index = (int)asmRegister::edi;
        this->registerUsedVar[index - 1] = var;
        return asmRegister::edi;
    }

    // printf("?????\n");
}

asmRegister AsmGenerate::findRegister(std::string var)
{
    for (int i = 0; i < 8; i++)
    {
        // printf("registerUsedVar[%d] = %s\n", i, this->registerUsedVar[i].c_str());
        if (this->registerUsedVar[i] == var)
        {
            return asmRegister(i + 1);
        }
    }
}

void AsmGenerate::generateJump(QuadItem q)
{
    OpType optype = q.getOpType();
    std::string label = "label" + std::to_string(labelMap[q.getArg(3).target]);
    // printf("jump_flag= %d\n", q.quad_item_type);
    if (optype == OpType::JUMP)
    {
        this->asmcode.generateUnaryInstructor(ASM_JUMP, label);
    }
    else
    {
        int flag = q.quad_item_type;
        if (flag == 0)
        {
            std::string value1 = std::to_string(q.getArg(1).target);
            std::string value2 = std::to_string(q.getArg(2).target);
            this->asmcode.generateMov(asmRegister::edx, value1);
            this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, value2);
        }
        else if (flag == 1)
        {
            std::string value2 = this->asmcode.generateInstanceNumber(q.getArg(2).target);
            std::string var1Name = q.getArg(1).symbol->getIdName();
            if (var1Name[0] == 't')
            {
                asmRegister var1Reg = this->findRegister(var1Name);
                this->releaseRegister(var1Reg);
                this->asmcode.generateBinaryInstructor(ASM_CMP, var1Reg, value2);
            }
            else
            {
                int offset = q.getArg(1).symbol->getPointerAddr();
                std::string offsetStr = this->asmcode.generateVar(offset);
                this->asmcode.generateBinaryInstructor(ASM_CMP, offsetStr, value2);
            }
        }
        else if (flag == 2)
        {
            std::string value1 = this->asmcode.generateInstanceNumber(q.getArg(1).target);
            std::string var2Name = q.getArg(2).symbol->getIdName();
            if (var2Name[0] == 't')
            {
                asmRegister var2Reg = this->findRegister(var2Name);
                this->asmcode.generateMov(asmRegister::edx, value1);
                this->releaseRegister(var2Reg);
                this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, var2Reg);
            }
            else
            {
                int offset = q.getArg(2).symbol->getPointerAddr();
                std::string offsetStr = this->asmcode.generateVar(offset);
                this->asmcode.generateBinaryInstructor(ASM_CMP, offsetStr, value1);
            }
        }
        else if (flag == 3)
        {
            std::string value1 = q.getArg(1).symbol->getIdName();
            std::string value2 = q.getArg(2).symbol->getIdName();
            // printf("value1= %s;value2=%s\n", q.getArg(1).symbol->getIdName().c_str(), q.getArg(2).symbol->getIdName().c_str());
            if (value1[0] == 't' && value2[0] == 't')
            {
                asmRegister var1Reg = this->findRegister(value1);
                asmRegister var2Reg = this->findRegister(value2);
                this->asmcode.generateBinaryInstructor(ASM_CMP, var1Reg, var2Reg);
            }
            else if (value1[0] == 't')
            {
                asmRegister var1Reg = this->findRegister(value1);
                int offset = q.getArg(2).symbol->getPointerAddr();
                std::string offsetStr = this->asmcode.generateVar(offset);
                this->asmcode.generateBinaryInstructor(ASM_CMP, var1Reg, offsetStr);
            }
            else if (value2[0] == 't')
            {
                asmRegister var2Reg = this->findRegister(value2);
                int offset = q.getArg(1).symbol->getPointerAddr();
                std::string offsetStr = this->asmcode.generateVar(offset);
                this->asmcode.generateMov(asmRegister::edx, offsetStr);
                this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, var2Reg);
            }
            else
            {
                std::string var1Offset = this->asmcode.generateVar(q.getArg(1).symbol->getPointerAddr());
                std::string var2Offset = this->asmcode.generateVar(q.getArg(2).symbol->getPointerAddr());
                this->asmcode.generateMov(asmRegister::edx, var1Offset);
                this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, var2Offset);
            }
        }

        if (optype == OpType::JUMP_GE)
        {
            this->asmcode.generateUnaryInstructor(ASM_JGE, label);
        }
        else if (optype == OpType::JUMP_GT)
        {
            this->asmcode.generateUnaryInstructor(ASM_JG, label);
        }
        else if (optype == OpType::JUMP_LE)
        {
            this->asmcode.generateUnaryInstructor(ASM_JLE, label);
        }
        else if (optype == OpType::JUMP_LT)
        {
            this->asmcode.generateUnaryInstructor(ASM_JL, label);
        }
        else if (optype == OpType::JUMP_EQ)
        {
            this->asmcode.generateUnaryInstructor(ASM_JE, label);
        }
        else if (optype == OpType::JUMP_NE)
        {
            this->asmcode.generateUnaryInstructor(ASM_JNE, label);
        }
    }
}

void AsmGenerate::preSetLabel()
{
    std::vector<QuadItem *> quad;
    int labelNumber = 0;

    for (auto item : quad_list)
    {
        OpType optype = item->getOpType();
        if (this->isJumpQuad(optype))
        {
            // printf("这个是跳转指令\n");
            int lineNum = item->getArg(3).target;

            if (this->labelMap.count(lineNum) == 0)
            {
                labelMap[lineNum] = labelNumber;
                labelNumber++;
            }
        }
    }

    size_t i = 0;
    for (auto item : quad_list)
    {
        if (this->labelMap.count(i) != 0)
        {
            // printf("添加LABEL\n");
            QuadItem *q = new QuadItem((Symbol *)NULL, OpType::LABEL, labelMap[i], (Symbol *)NULL);
            quad.push_back(q);
        }
        quad.push_back(item);
        i++;
    }
    quad_list = quad;
}

// code here
void AsmGenerate::generateArithmetic(QuadItem q)
{
    std::string instructor;
    OpType optype = q.getOpType();
    int flag = q.quad_item_type;
    // printf("flag = %d\n", flag);
    int offset;
    if (optype == OpType::ASSIGN)
    {
        Symbol *result = q.getArg(3).symbol;
        string result_name = result->getIdName();
        if (result_name.find("[") < result_name.size())
        {
            result = getoffsetofarray(result);
        }

        offset = result->getPointerAddr();
        std::string result_ebp_offset = this->asmcode.generateVar(offset);
        if (flag == 7)
        {
            Symbol *arg1 = q.getArg(1).symbol;
            std::string tempVar = arg1->getIdName();
            if (tempVar.find("[") < tempVar.size())
            {
                arg1 = getoffsetofarray(arg1);
            }
            if (tempVar[0] == 't')
            {
                asmRegister tempVarReg = this->findRegister(tempVar);
                this->asmcode.generateMov(result_ebp_offset, tempVarReg);
                this->releaseRegister(tempVarReg);
            }
            else
            {
                int varOffset = arg1->getPointerAddr();
                std::string varEbpOffset = this->asmcode.generateVar(varOffset);
                this->asmcode.generateMov(asmRegister::edx, varEbpOffset);
                this->asmcode.generateMov(result_ebp_offset, asmRegister::edx);
            }
        }
        else
        {
            int tempVar = q.getArg(1).target;
            this->asmcode.generateMov(result_ebp_offset, DOUBLE_WORD + std::string(" ") + std::to_string(tempVar));
        }
        return;
    }
    if (optype == OpType::ADDTION)
        instructor = ASM_ADD;
    else if (optype == OpType::SUBTRACTION)
        instructor = ASM_SUB;

    asmRegister tempVar1Reg = asmRegister::unset;
    asmRegister tempVar2Reg = asmRegister::unset;
    asmRegister resultReg = asmRegister::unset;
    int value1, value2;
    std::string arg1IdName = "";
    std::string arg2IdName = "";
    std::string resultIdName = q.getArg(3).symbol->getIdName();

    if (flag == 7)
    {
        arg1IdName = q.getArg(1).symbol->getIdName();
        arg2IdName = q.getArg(2).symbol->getIdName();
        if (arg1IdName[0] == 't')
        {
            tempVar1Reg = this->findRegister(arg1IdName);
            this->releaseRegister(tempVar1Reg);
        }
        if (arg2IdName[0] == 't')
        {
            tempVar2Reg = this->findRegister(arg2IdName);
            this->releaseRegister(tempVar2Reg);
        }
        if (resultIdName[0] == 't')
        {
            resultReg = this->getRegister(resultIdName);
        }
        // printf("arg1IdName = %s, arg2IdName = %s, resultIdName = %s\n", arg1IdName.c_str(), arg2IdName.c_str(), resultIdName.c_str());
        // printf("tempVar1Reg = %d, tempVar2Reg = %d, resultReg = %d\n", tempVar1Reg, tempVar2Reg, resultReg);
        if (tempVar1Reg != asmRegister::unset && tempVar2Reg != asmRegister::unset)
        {
            if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
            {
                this->asmcode.generateBinaryInstructor(instructor, tempVar1Reg, tempVar2Reg);
            }
            else
            {
                if (optype == OpType::MULTIPLICATION)
                {
                    this->asmcode.generateMul(tempVar1Reg, tempVar2Reg);
                }
                else if (optype == OpType::DIVISION || optype == OpType::MOD)
                {
                    this->asmcode.generateDiv(tempVar1Reg, tempVar2Reg);
                }
            }
            if (resultReg != asmRegister::unset)
            {
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    if (tempVar1Reg != resultReg)
                    {
                        this->asmcode.generateMov(resultReg, tempVar1Reg);
                    }
                }
                else
                {
                    if (optype == OpType::MULTIPLICATION || optype == OpType::DIVISION)
                    {
                        this->asmcode.generateMov(resultReg, asmRegister::eax);
                    }
                    else
                    {
                        this->asmcode.generateMov(resultReg, asmRegister::edx);
                    }
                }
            }
            else
            {
                Symbol *result = q.getArg(3).symbol;
                int offset = result->getPointerAddr();
                std::string ebp_offset = this->asmcode.generateVar(offset);
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    if (tempVar1Reg != resultReg)
                    {
                        this->asmcode.generateMov(ebp_offset, tempVar1Reg);
                    }
                }
                else
                {
                    if (optype == OpType::MULTIPLICATION || optype == OpType::DIVISION)
                    {
                        this->asmcode.generateMov(ebp_offset, asmRegister::eax);
                    }
                    else
                    {
                        this->asmcode.generateMov(ebp_offset, asmRegister::edx);
                    }
                }
            }
        }
        else if (tempVar1Reg != asmRegister::unset || tempVar2Reg != asmRegister::unset)
        {
            asmRegister reg = asmRegister::unset;
            Symbol *vars = NULL;
            std::string var = "";
            if (tempVar1Reg == asmRegister::unset)
            {
                reg = tempVar2Reg;
                Symbol *vars = q.getArg(1).symbol;
                int offset = vars->getPointerAddr();
                var = this->asmcode.generateVar(offset);
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    this->asmcode.generateBinaryInstructor(instructor, var, reg);
                    this->asmcode.generateMov(reg, var);
                }
                else
                {
                    if (optype == OpType::MULTIPLICATION || optype == OpType::DIVISION)
                    {
                        if (optype == OpType::MULTIPLICATION)
                        {
                            this->asmcode.generateMul(reg, var);
                        }
                        else
                        {
                            this->asmcode.generateDiv(var, reg);
                        }
                        this->asmcode.generateMov(reg, asmRegister::eax);
                    }
                    else
                    {
                        this->asmcode.generateDiv(var, reg);
                        this->asmcode.generateMov(reg, asmRegister::edx);
                    }
                }
            }
            else
            {
                reg = tempVar1Reg;
                Symbol *vars = q.getArg(2).symbol;
                int offset = vars->getPointerAddr();
                var = this->asmcode.generateVar(offset);
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    this->asmcode.generateBinaryInstructor(instructor, reg, var);
                }
                else
                {
                    if (optype == OpType::MULTIPLICATION || optype == OpType::DIVISION)
                    {
                        if (optype == OpType::MULTIPLICATION)
                        {
                            this->asmcode.generateMul(reg, var);
                        }
                        else
                        {
                            this->asmcode.generateDiv(reg, var);
                        }
                        if (reg != resultReg)
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::eax);
                        }
                        else
                        {
                            this->asmcode.generateMov(reg, asmRegister::eax);
                        }
                    }
                    else
                    {
                        this->asmcode.generateDiv(reg, var);
                        this->asmcode.generateMov(reg, asmRegister::edx);
                    }
                }
                // this->asmcode.generateBinaryInstructor(instructor, reg, var);
            }
            if (resultReg != asmRegister::unset)
            {
                if (reg != resultReg)
                {
                    this->asmcode.generateMov(resultReg, reg);
                }
            }
            else
            {
                Symbol *result = q.getArg(3).symbol;
                int offset = result->getPointerAddr();
                std::string ebp_offset = this->asmcode.generateVar(offset);
                this->asmcode.generateMov(ebp_offset, reg);
            }
        }
        else if (tempVar1Reg == asmRegister::unset && tempVar2Reg == asmRegister::unset)
        {
            Symbol *var1 = q.getArg(1).symbol;
            Symbol *var2 = q.getArg(2).symbol;
            std::string var1_ebp_offset = this->asmcode.generateVar(var1->getPointerAddr());
            std::string var2_ebp_offset = this->asmcode.generateVar(var2->getPointerAddr());
            if (resultReg != asmRegister::unset)
            {
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    this->asmcode.generateMov(resultReg, var1_ebp_offset);
                    this->asmcode.generateBinaryInstructor(instructor, resultReg, var2_ebp_offset);
                }
                else
                {
                    if (optype == OpType::MULTIPLICATION)
                    {
                        this->asmcode.generateMul(var1_ebp_offset, var2_ebp_offset);
                    }
                    else
                    {
                        this->asmcode.generateDiv(var1_ebp_offset, var2_ebp_offset);
                    }
                    if (optype == OpType::MOD)
                    {
                        this->asmcode.generateMov(resultReg, asmRegister::edx);
                    }
                    else
                    {
                        this->asmcode.generateMov(resultReg, asmRegister::eax);
                    }
                }
            }
        }
    }
    else if (flag == 6 || flag == 5)
    {
        // printf("tempVar1Reg=%d, tempVar2Reg=%d, resultReg=%d\n", tempVar1Reg, tempVar2Reg, resultReg);
        if (flag == 6)
        {
            value1 = q.getArg(1).target;
            std::string instance = this->asmcode.generateInstanceNumber(value1);
            arg2IdName = q.getArg(2).symbol->getIdName();
            if (arg2IdName[0] == 't')
            {
                tempVar2Reg = this->findRegister(arg2IdName);
                this->releaseRegister(tempVar2Reg);
                resultReg = this->getRegister(resultIdName);
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    this->asmcode.generateBinaryInstructor(instructor, tempVar2Reg, instance);
                    if (optype == OpType::SUBTRACTION)
                    {
                        this->asmcode.generateUnaryInstructor(ASM_NEG, tempVar2Reg);
                    }
                    if (resultReg != tempVar2Reg)
                    {
                        this->asmcode.generateMov(resultReg, tempVar2Reg);
                    }
                }
                else
                {
                    this->asmcode.generateAsmXor(asmRegister::edx, asmRegister::edx);
                    asmRegister regInstance = asmRegister::eax;
                    this->asmcode.generateMov(regInstance, instance);
                    if (optype == OpType::MULTIPLICATION)
                    {
                        this->asmcode.generateUnaryInstructor(ASM_MUL, tempVar2Reg);
                        this->asmcode.generateMov(resultReg, asmRegister::eax);
                    }
                    else
                    {
                        this->asmcode.generateUnaryInstructor(ASM_DIV, tempVar2Reg);
                        if (optype == OpType::DIVISION)
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::eax);
                        }
                        else
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::edx);
                        }
                    }
                }
            }
            else
            {
                resultReg = this->getRegister(resultIdName);
                int offset = q.getArg(2).symbol->getPointerAddr();
                std::string ebpOffset = DOUBLE_WORD + this->asmcode.generateVar(offset);
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    this->asmcode.generateAsmXor(resultReg, resultReg);
                    this->asmcode.generateMov(resultReg, instance);
                    this->asmcode.generateBinaryInstructor(instructor, resultReg, ebpOffset);
                }
                else
                {
                    this->asmcode.generateAsmXor(asmRegister::edx, asmRegister::edx);
                    this->asmcode.generateMov(asmRegister::eax, instance);
                    if (optype == OpType::MULTIPLICATION)
                    {
                        this->asmcode.generateUnaryInstructor(ASM_MUL, ebpOffset);
                        this->asmcode.generateMov(resultReg, asmRegister::eax);
                    }
                    else
                    {
                        this->asmcode.generateUnaryInstructor(ASM_DIV, ebpOffset);
                        if (optype == OpType::DIVISION)
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::eax);
                        }
                        else
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::edx);
                        }
                    }
                }
            }
        }
        else
        {
            value2 = q.getArg(2).target;
            arg1IdName = q.getArg(1).symbol->getIdName();
            std::string instance = this->asmcode.generateInstanceNumber(value2);
            if (arg1IdName[0] == 't')
            {
                tempVar1Reg = this->findRegister(arg1IdName);
                this->releaseRegister(tempVar1Reg);
                resultReg = this->getRegister(resultIdName);
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    this->asmcode.generateBinaryInstructor(instructor, tempVar1Reg, instance);
                    if (resultReg != tempVar1Reg)
                    {
                        this->asmcode.generateMov(resultReg, tempVar2Reg);
                    }
                }
                else
                {
                    this->asmcode.generateAsmXor(asmRegister::edx, asmRegister::edx);
                    resultReg = this->getRegister(resultIdName);
                    // the instance number use result register.
                    asmRegister regInstance = resultReg;
                    this->asmcode.generateMov(regInstance, instance);
                    // int offset = q.getArg(1).symbol->getPointerAddr();
                    // std::string ebpOffset = this->asmcode.generateVar(offset);

                    this->asmcode.generateMov(asmRegister::eax, tempVar1Reg);

                    if (optype == OpType::MULTIPLICATION)
                    {
                        this->asmcode.generateUnaryInstructor(ASM_MUL, regInstance);
                        this->asmcode.generateMov(resultReg, asmRegister::eax);
                    }
                    else
                    {
                        this->asmcode.generateUnaryInstructor(ASM_DIV, regInstance);
                        if (optype == OpType::DIVISION)
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::eax);
                        }
                        else
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::edx);
                        }
                    }
                }
            }
            else
            {
                resultReg = this->getRegister(resultIdName);
                int offset = q.getArg(1).symbol->getPointerAddr();
                std::string ebpOffset = DOUBLE_WORD + this->asmcode.generateVar(offset);
                if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
                {
                    this->asmcode.generateAsmXor(resultReg, resultReg);
                    this->asmcode.generateMov(resultReg, ebpOffset);
                    this->asmcode.generateBinaryInstructor(instructor, resultReg, instance);
                }
                else
                {
                    this->asmcode.generateAsmXor(asmRegister::edx, asmRegister::edx);
                    asmRegister instanceReg = resultReg;
                    this->asmcode.generateMov(asmRegister::eax, ebpOffset);
                    this->asmcode.generateMov(instanceReg, instance);
                    if (optype == OpType::MULTIPLICATION)
                    {
                        this->asmcode.generateUnaryInstructor(ASM_MUL, instanceReg);
                        this->asmcode.generateMov(resultReg, asmRegister::eax);
                    }
                    else
                    {
                        this->asmcode.generateUnaryInstructor(ASM_DIV, instanceReg);
                        if (optype == OpType::DIVISION)
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::eax);
                        }
                        else
                        {
                            this->asmcode.generateMov(resultReg, asmRegister::edx);
                        }
                    }
                }
            }
        }
    }
    else if (flag == 4)
    {
        value1 = q.getArg(1).target;
        value2 = q.getArg(2).target;
        std::string instance1 = this->asmcode.generateInstanceNumber(value1);
        std::string instance2 = this->asmcode.generateInstanceNumber(value2);
        resultReg = this->getRegister(resultIdName);
        if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION)
        {
            this->asmcode.generateMov(resultReg, instance1);
            this->asmcode.generateBinaryInstructor(instructor, resultReg, instance2);
        }
        else
        {
            this->asmcode.generateAsmXor(asmRegister::edx, asmRegister::edx);
            this->asmcode.generateMov(asmRegister::eax, instance1);
            this->asmcode.generateMov(resultReg, instance2);
            if (optype == OpType::MULTIPLICATION)
            {
                this->asmcode.generateUnaryInstructor(ASM_MUL, resultReg);
                this->asmcode.generateMov(resultReg, asmRegister::eax);
            }
            else
            {
                this->asmcode.generateUnaryInstructor(ASM_DIV, resultReg);
                if (optype == OpType::DIVISION)
                {
                    this->asmcode.generateMov(resultReg, asmRegister::eax);
                }
                else
                {
                    this->asmcode.generateMov(resultReg, asmRegister::edx);
                }
            }
        }
    }
}

void AsmGenerate::generateNeg(QuadItem q)
{
    std::string varName = q.getArg(1).symbol->getIdName();
    std::string result = q.getArg(3).symbol->getIdName();
    if (varName[0] == 't' && result[0] == 't')
    {
        asmRegister varReg = this->findRegister(varName);
        this->releaseRegister(varReg);
        asmRegister resultReg = this->getRegister(result);
        if (resultReg != varReg)
        {
            this->asmcode.generateMov(resultReg, varReg);
        }
        this->asmcode.generateUnaryInstructor(ASM_NEG, resultReg);
    }
    else if (varName[0] == 't')
    {
        asmRegister varReg = this->findRegister(varName);
        this->releaseRegister(varReg);
        int offset = q.getArg(3).symbol->getPointerAddr();
        std::string ebpOffset = this->asmcode.generateVar(offset);
        this->asmcode.generateUnaryInstructor(ASM_NEG, varReg);
        this->asmcode.generateMov(ebpOffset, varReg);
    }
    else if (result[0] == 't')
    {
        int offset = q.getArg(1).symbol->getPointerAddr();
        std::string ebpOffset = this->asmcode.generateVar(offset);
        asmRegister resultReg = this->getRegister(result);
        this->asmcode.generateMov(resultReg, ebpOffset);
        this->asmcode.generateUnaryInstructor(ASM_NEG, resultReg);
    }
    else
    {
        int varOff = q.getArg(1).symbol->getPointerAddr();
        int resultOff = q.getArg(3).symbol->getPointerAddr();
        std::string varEbpOff = this->asmcode.generateVar(varOff);
        std::string resultEBPOff = this->asmcode.generateVar(resultOff);
        this->asmcode.generateMov(asmRegister::edx, varEbpOff);
        this->asmcode.generateUnaryInstructor(ASM_NEG, asmRegister::edx);
        this->asmcode.generateMov(resultEBPOff, asmRegister::edx);
    }
}

void AsmGenerate::generateprint(QuadItem q)
{
    Symbol *result = q.getArg(3).symbol;
    int offset = result->getPointerAddr();
    std::string result_ebp_offset = this->asmcode.generateVar(offset);
    this->asmcode.addCode("mov eax," + result_ebp_offset + "\n");
    this->asmcode.addCode("call print_int_i\n");
}

bool AsmGenerate::isJumpQuad(OpType optype)
{
    return optype == OpType::JUMP || optype == OpType::JUMP_LT || optype == OpType::JUMP_LE ||
           optype == OpType::JUMP_GT || optype == OpType::JUMP_GE || optype == OpType::JUMP_EQ ||
           optype == OpType::JUMP_NE;
}

void AsmGenerate::generate()
{
    currentTable = rootTable;
    currentTable->showSymbolArea();
    // Set header info
    // printf("Generating asm code!!!\n");
    std::cout << "begin _asm\n";
    std::cout << "size=" << quad_list.size() << "\n";
    this->asmcode.addCode("extern exit\n");
    // this->asmcode.addCode("\%include './AsmCode/print_int_i.asm'\n");
    this->asmcode.addCode("section .text\nglobal main\nmain:\npush ebx\nmov ebp,esp\n");
    for (size_t i = 0; i < this->quad_list.size(); i++)
    {
        QuadItem *q = quad_list[i];
        OpType optype = q->getOpType();
        // printf("optype: %d\n", optype);
        q->printItemInfo(i);
        // Symbol* argu1 = quad_list[i]->arg1.var;
        // Symbol* argu2 = quad_list[i]->arg2.var;
        // if(argu1 != NULL)quad_list[i]->arg1.var->showSymbolInfor();
        // if(argu2 != NULL)quad_list[i]->arg2.var->showSymbolInfor();
        if (optype == OpType::ADDTION || optype == OpType::SUBTRACTION ||
            optype == OpType::DIVISION || optype == OpType::MULTIPLICATION ||
            optype == OpType::ASSIGN || optype == OpType::MOD)
        {
            this->generateArithmetic(*q);
        }
        /*else if (optype==OpType::CALL) {
            this->generateCallFunction(q);
        } else if (optype==OpType::END_FUNCTION) {
            this->generateEndFunction(q);
        } else if (optype==OpType::RETURN) {
            this->generateReturn(q);
        } */
        else if (optype == OpType::LABEL)
        {
            // printf("gengrate LABEL\n");
            int labelIndex = q->getArg(1).target;
            this->asmcode.generateLabel("\nlabel" + std::to_string(labelIndex));
        }
        else if (this->isJumpQuad(optype))
        {
            this->generateJump(*q);
        }
        else if (optype == OpType::PRINT)
        {
            this->generateprint(*q);
        }
        /* else if (optype==OpType::GET_ADDRESS) {
        this->generateGetAddress(q);
    }else if (optype==OpType::ASSIGN_ARRAY || optype==OpType::ASSIGN_POINTER) {
        this->generateAssignArray(q);
    } else if (optype==OpType::GET_ARRAY || optype==OpType::GET_VALUE) {
        this->generateGetArrayValue(q);
    }*/
    }
    // end
    this->asmcode.addCode("pop ebx\npush 0\ncall exit");

    this->asmcode.addCode("\%include './AsmCode/print_int_i.asm'\n");

    // 覆盖写入
    std::ofstream out("AsmCode/result.asm", ios::trunc);
    out << (out, this->asmcode);
    std::cout << this->asmcode;
    std::cout << "write ok!!\n";
    out.close();
}