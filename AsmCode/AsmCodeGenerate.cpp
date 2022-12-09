#include"AsmCodeGenerate.h"
#include<string>

Symbol* AsmGenerate::getoffsetofarray(Symbol* arg)
{
    Symbol *result;
    string result_name=arg->getIDName();
    char *splited_result=strtok((char*)result_name.c_str(), "[");
    
    string firstname=splited_result;
    Symbol* re = this->currentTable->findSymbolLocally(firstname);
    if(re == NULL){
        re = this->currentTable->findSymbolGlobally(firstname);
    }
    int base_offset =re->getPointerAddr()-re->getWidth();
    int total_offset=base_offset;
    //result.push_back(firstname);
    //std::cout<<"splited "<<splited_result<<"\n";
    splited_result=strtok(NULL," ");
    //std::cout<<"splited "<<splited_result<<"\n";
    int numberi=atoi(splited_result);
    //get i from reg
    // b[0]
    total_offset+=numberi*4;
    result=new Symbol(firstname,SymbolType::var);
    result->setPointerAddr(total_offset);
    return result;
}


AsmGenerate::AsmGenerate(std::vector<QuadItem*> quadlist, SymbolArea* rootTable) {
    this->quad_list = quadlist;
    //this->tempVar = tempVar;
    this->rootTable = rootTable;
    //this->funcTable = funcTable;
    this->preSetLabel();
   
    
    eax = 0;
    ebx = 0;
    ecx = 0;
    edx = 0;
}

void AsmGenerate::releaseRegister(asmRegister reg) {
    if (reg == asmRegister::ebx) {
        ebx = 0;
        int index = (int)asmRegister::ebx;
        this->registerUsedVar[index - 1] = "";
    } else if (reg == asmRegister::ecx) {
        ecx = 0;
        int index = (int)asmRegister::ecx;
        this->registerUsedVar[index - 1] = "";
    }
}

asmRegister AsmGenerate::getRegister(std::string var) {
    if (ebx == 0) {
        ebx = 1;
        int index = (int)asmRegister::ebx;
        this->registerUsedVar[index - 1] = var;
        return asmRegister::ebx;
    } else if (ecx == 0) {
        ecx = 1;
        int index = (int)asmRegister::ecx;
        this->registerUsedVar[index - 1] = var;
        return asmRegister::ecx;
    }
}

asmRegister AsmGenerate::findRegister(std::string var) {
    for (int i = 0; i < 6; i++) {
        if (this->registerUsedVar[i] == var) {
            return asmRegister(i + 1);
        }
    }

}






// code here















void AsmGenerate::generate()
{
    currentTable = rootTable->getfirstChildTable();
    currentTable->showSymbols();
    // Set header info
    std::cout<<"begin _asm\n";
    std::cout<<"size="<<quad_list.size()<<"\n";
    this->asmcode.addCode("section .text\nglobal main\nmain:\npush ebx\nmov ebp,esp\n");
    for (size_t i = 0; i < this->quad_list.size(); i++) 
    {
        QuadItem *q = quad_list[i];
        OpType optype = q->getOpType();
        q->printItemInfor(i);
        //Symbol* argu1 = quad_list[i]->arg1.var;
        //Symbol* argu2 = quad_list[i]->arg2.var;
        //if(argu1 != NULL)quad_list[i]->arg1.var->showSymbolInfor();
        //if(argu2 != NULL)quad_list[i]->arg2.var->showSymbolInfor();
        if (optype==OpType::addtion || optype==OpType::substract ||
                 optype==OpType::divide || optype==OpType::multiply ||
                 optype==OpType::assign || optype==OpType::mod) {
            this->generateArithmetic(*q);
        }
        /*else if (optype==OpType::CALL) {
            this->generateCallFunction(q);
        } else if (optype==OpType::END_FUNCTION) {
            this->generateEndFunction(q);
        } else if (optype==OpType::RETURN) {
            this->generateReturn(q);
        } */
        else if (optype==OpType::label) {
            int labelIndex = q->getArg(1).target;
            this->asmcode.label("\nlabel" + std::to_string(labelIndex));
        } else if (this->isJumpQuad(optype)) {
            this->generateJump(*q);
        } else if (optype==OpType::power) {
            this->generatePower(*q);
        } else if (optype==OpType::uminus) {
            this->generateNeg(*q);
        }
        else if (optype==OpType::PRINT){
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
    //end
    this->asmcode.addCode("pop ebx\nret\n");
    //write to asm
    
    std::ofstream out("asm/asm_kjh.asm",ios::app);
    out<<(out,this->asmcode);
    std::cout<<"write ok!!\n";
    out.close();
}