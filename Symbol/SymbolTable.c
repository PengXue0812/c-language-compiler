#include"SymbolTable.h"

FILE* file = fopen("./symbol.txt","w");
int idIndex = 0;
SymbolTable* createSymbolTable(){
    SymbolTable* symbolTable = (SymbolTable*)malloc(sizeof(SymbolTable));
    symbolTable->count = 0;
    symbolTable->symbols = (Symbol*)malloc(sizeof(Symbol)*100);
    return symbolTable;
}

void addSymbol(SymbolTable* table, Symbol* symbol){
    table->count++;
    table->symbols[table->count-1] = *symbol;
}
void dfs(SymbolArea* sa, AST::BaseNode* node ){
   
    if(node==NULL){
        return;
    }
    if(sa==NULL){
        sa = createSymbolArea();
    }
    // printf("dfs %s\n",node->getContent());
    std::list<AST::BaseNode*> children = node->getAllChildrenNode();
    printf("dfs----- %s\n",node->getContent());
    if(strcmp(node->getContent(),"Declare_Statement")==0){
        AST::BaseNode* descriptor = node->getChildNode();
        char declareType[100];
        strcpy(declareType,descriptor->getContent());
        sa = dfsDeclares(sa,descriptor->getBrotherNode(),declareType);
    }else if(strcmp(node->getContent(),"For_Start")==0){
          for(std::list<AST::BaseNode*>::iterator it = children.begin();it!=children.end();it++){
            // printf("dfs %s\n",(*it)->getContent());
            dfs(sa,*it);
        }

    }




    //  //申明变量   
    // if((strcmp(node->getContent(),"Declare_Variables")==0)||(strcmp(node->getContent(),"Declare_Variable")==0)){
    //     // printf("dfs %s\n",node->getContent());
    //     sa = dfsDeclares(sa,node);
    // //函数的声明  
    // }
    else if((strcmp(node->getContent(),"Def_Func_Block_Body")==0)||(strcmp(node->getContent(),"Def_Func_Block_NoBody")==0)){
       
        AST::BaseNode* funcReType = node->getChildNode();
        //  printf("01\n");
        AST::BaseNode* fun = funcReType->getBrotherNode();
        // printf("%s\n",fun->getContent());
        //  printf("02\n");
        AST::BaseNode* funcName = fun->getChildNode();
        // printf("1\n");
        
        Symbol* s = createSymbol();
        // printf("2\n");
        strcpy(s->name,funcName->getContent());
        strcpy(s->type,funcReType->getContent());
        strcpy(s->idType,"function");
         s->id = idIndex++;
        // printf("3\n");
        fprintf(file ,"add function %s reType:%s  id:%d\n",s->name,s->type,s->id);
        // printf("4\n");
        AST::BaseNode* params = funcName->getBrotherNode();
        dfsParams(sa,params);
        AST::BaseNode* funBody = fun->getBrotherNode();
        dfs(sa,funBody);

    }
    else{
        for(std::list<AST::BaseNode*>::iterator it = children.begin();it!=children.end();it++){
            // printf("dfs %s\n",(*it)->getContent());
            dfs(sa,*it);
        }
        
    }
}

SymbolArea* dfsDeclares(SymbolArea* sa,AST::BaseNode* node,char *declareType){
   if(node==NULL){
    return  sa ;
   }
        AST::BaseNode* var = node->getChildNode();

        //没有赋值
        if(strcmp(var->getContent(),"Variable")==0){
            //  printf("3\n");

            AST::BaseNode* varType = var->getChildNode();

          
            AST::BaseNode* idName = varType->getChildNode();
            Symbol* s = createSymbol();
            strcpy(s->name,idName->getContent());
            strcpy(s->idType,varType->getContent());
            strcpy(s->type,declareType);
            s->id = idIndex++;
            addSymbol(sa,s);
            fprintf(file,"add symbol %s id: %d declareType:%s,idType:%s\n",s->name,s->id,s->type,s->idType);
            
        }else{//申明且赋值  

            AST::BaseNode* varType = var->getChildNode();

            AST::BaseNode* idName = varType->getChildNode();
            Symbol* s = createSymbol();
            strcpy(s->name,idName->getContent());
            strcpy(s->idType,varType->getContent());
            strcpy(s->type,declareType);
            s->id = idIndex++;
            AST::BaseNode* value = varType->getBrotherNode();

            printf("------%s\n",value->getContent());
            if(strcmp(value->getContent(),"Constant_Expression")==0){
                strcpy(s->value,value->getChildNode()->getContent());
                fprintf(file,"add symbol has value %s = %s id: %d declareType:%s, idType:%s\n",s->name,s->value,s->id,s->type,s->idType);
            }else{
                 fprintf(file,"add symbol %s id: %d declareType:%s,idType:%s\n",s->name,s->id,s->type,s->idType);
            }
            addSymbol(sa,s);
        }
        if(strcmp(node->getContent(),"Declare_Variables")==0){
            dfsDeclares(sa,var->getBrotherNode(),declareType);
        }
    
   return sa;
}

SymbolArea* dfsParams(SymbolArea* sa,AST::BaseNode* node){
    if(node==NULL){
        return sa;
    }
    if(strcmp(node->getContent(),"Params")==0){
        std::list<AST::BaseNode*> children = node->getAllChildrenNode();
        for(std::list<AST::BaseNode*>::iterator it = children.begin();it!=children.end();it++){
            dfsParams(sa,*it);
        }
    }else{
        AST::BaseNode* paramType = node->getChildNode();
        AST::BaseNode* paramName = paramType->getBrotherNode();
        Symbol* s = createSymbol();
        strcpy(s->name,paramName->getContent());
        strcpy(s->idType,node->getContent());
        strcpy(s->type,paramType->getContent());

        s->id = idIndex++;
        addSymbol(sa,s);
      fprintf(file,"add param symbol %s id: %d declareType:%s,idType:%s\n",s->name,s->id,s->type,s->idType);
    }
    return sa;

}

