#include"AsmCodeGenerate.h"
#include<string>
#include<cstring>

Symbol* AsmGenerate::getoffsetofarray(Symbol* arg)
{
    Symbol *result;
    string result_name=arg->getIdName();
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

void AsmGenerate::generateJump(QuadItem q){
    OpType optype = q.getOpType();
    std::string label = "label" + std::to_string(labelMap[q.getArg(3).target]);
    if (optype == OpType::JUMP) {
        this -> asmcode.generateUnaryInstructor(ASM_JUMP,label);
    }
    else{
        int flag = q.quad_item_type;
        if( flag == 0 ){
            std::string value1 = std::to_string(q.getArg(1).target);
            std::string value2 = std::to_string(q.getArg(2).target);
            this->asmcode.generateMov(asmRegister::edx, value1);
            this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, value2);
        }
        else if(flag == 1){
            std::string value2 = this->asmcode.generateInstanceNumber(q.getArg(2).target);
            std::string var1Name = q.getArg(1).symbol->getIdName();
            if(var1Name[0] == 't'){
                asmRegister var1Reg = this->findRegister(var1Name);
                this->releaseRegister(var1Reg);
                this->asmcode.generateBinaryInstructor(ASM_CMP, var1Reg, value2);
            }
            else{
                int offset = q.getArg(1).symbol->getPointerAddr();
                std::string offsetStr = this->asmcode.generateVar(offset);
                this->asmcode.generateBinaryInstructor(ASM_CMP, offsetStr,value2);                
            }
        }
        else if(flag == 2){
            std::string value1 = this->asmcode.generateInstanceNumber(q.getArg(1).target);
            std::string var2Name = q.getArg(2).symbol->getIdName();
            if(var2Name[0] == 't'){
                asmRegister var2Reg = this->findRegister(var2Name);
                this->asmcode.generateMov(asmRegister::edx, value1);
                this->releaseRegister(var2Reg);
                this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, var2Reg);
            }
            else{
                int offset = q.getArg(2).symbol->getPointerAddr();
                std::string offsetStr =  this->asmcode.generateVar(offset);
                this->asmcode.generateBinaryInstructor(ASM_CMP, offsetStr ,value1);
            }
        }
        else if(flag == 3){
            std::string value1 = std::to_string(q.getArg(1).target);
            std::string value2 = std::to_string(q.getArg(2).target);
            if(value1[0] == 't' && value2[0] == 't'){
                asmRegister var1Reg = this->findRegister(value1);
                asmRegister var2Reg = this->findRegister(value2);
                this->asmcode.generateBinaryInstructor(ASM_CMP, var1Reg, var2Reg);
            }
            else if(value1[0] == 't'){
                asmRegister var1Reg = this->findRegister(value1);
                int offset = q.getArg(2).symbol->getPointerAddr();
                std::string offsetStr = this->asmcode.generateVar(offset);
                this->asmcode.generateBinaryInstructor(ASM_CMP, var1Reg, offsetStr);
            }
            else if(value2[0] == 't'){
                asmRegister var2Reg = this->findRegister(value2);
                int offset = q.getArg(1).symbol->getPointerAddr();
                std::string offsetStr = this->asmcode.generateVar(offset);
                this->asmcode.generateMov(asmRegister::edx, value1);
                this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, var2Reg);
            }
            else{
                std::string var1Offset = this->asmcode.generateVar(q.getArg(1).symbol->getPointerAddr());
                std::string var2Offset = this->asmcode.generateVar(q.getArg(2).symbol->getPointerAddr());
                this->asmcode.generateMov(asmRegister::edx, value1);
                this->asmcode.generateBinaryInstructor(ASM_CMP, asmRegister::edx, var2Offset);
            }
        }
    
        if(optype==OpType::JUMP_GE){
            this->asmcode.generateUnaryInstructor(ASM_JGE,label);
        }
        else if(optype == OpType::JUMP_GT){
            this->asmcode.generateUnaryInstructor(ASM_JG,label);
        }
        else if(optype == OpType::JUMP_LE){
            this->asmcode.generateUnaryInstructor(ASM_JLE,label);
        }
        else if (optype==OpType::JUMP_LT) {
            this->asmcode.generateUnaryInstructor(ASM_JL, label);
        }
         else if (optype==OpType::JUMP_EQ) {
            this->asmcode.generateUnaryInstructor(ASM_JE, label);
        }
         else if (optype==OpType::JUMP_NE) {
            this->asmcode.generateUnaryInstructor(ASM_JNE, label);
        }
    }
}


void AsmGenerate::preSetLabel(){
    std::vector<QuadItem*> quad;
    int labelNumber = 0;

    for(auto item : quad_list){
        OpType optype = item->getOpType();
        if(this->isJumpQuad(optype)){
            int lineNum = item->getArg(3).target;

            if(this->labelMap.count(lineNum) == 0){
                labelMap[lineNum] = labelNumber;
                labelNumber++;
            }
        }
    }

    size_t i = 0;
    for(auto item : quad_list){
        if(this->labelMap.count(i) != 0){
            QuadItem *q = new QuadItem((Symbol*)NULL, OpType::LABEL, (Symbol*)NULL);
            quad.push_back(q);
        }
        quad.push_back(item);
    }
    quad_list = quad;
    
}


// code here
void AsmGenerate::generateArithmetic(QuadItem q){
    std::string instructor;
    OpType optype = q.getOpType();
    int flag = q.quad_item_type;
    int offset;
    if(optype==OpType::ASSIGN){
        Symbol *result = q.getArg(3).symbol;
        string result_name=result->getIdName();
        //对于不是数组的情况
        if(result_name.find("[") < result_name.length()){
            result=getoffsetofarray(result);
        }
        offset = result->getPointerAddr();
        
    }
}














void AsmGenerate::generate()
{
    currentTable = rootTable->getFirstChildArea();
    currentTable->showSymbolArea();
    // Set header info
    std::cout<<"begin _asm\n";
    std::cout<<"size="<<quad_list.size()<<"\n";
    this->asmcode.addCode("section .text\nglobal main\nmain:\npush ebx\nmov ebp,esp\n");
    for (size_t i = 0; i < this->quad_list.size(); i++) 
    {
        QuadItem *q = quad_list[i];
        OpType optype = q->getOpType();
        q->printItemInfo(i);
        //Symbol* argu1 = quad_list[i]->arg1.var;
        //Symbol* argu2 = quad_list[i]->arg2.var;
        //if(argu1 != NULL)quad_list[i]->arg1.var->showSymbolInfor();
        //if(argu2 != NULL)quad_list[i]->arg2.var->showSymbolInfor();
        if (optype==OpType::ADDTION || optype==OpType::SUBTRACTION ||
                 optype==OpType::DIVISION || optype==OpType::MULTIPLICATION ||
                 optype==OpType::ASSIGN || optype==OpType::MOD) {
            this->generateArithmetic(*q);
        }
        /*else if (optype==OpType::CALL) {
            this->generateCallFunction(q);
        } else if (optype==OpType::END_FUNCTION) {
            this->generateEndFunction(q);
        } else if (optype==OpType::RETURN) {
            this->generateReturn(q);
        } */
        else if (optype==OpType::LABEL) {
            int labelIndex = q->getArg(1).target;
            this->asmcode.generateLabel("\nlabel" + std::to_string(labelIndex));
        } else if (this->isJumpQuad(optype)) {
            this->generateJump(*q);
        }else if (optype==OpType::UMINUS) {
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