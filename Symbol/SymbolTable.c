#include"SymbolTable.h"


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


     //申明变量   
    if((strcmp(node->getContent(),"Declare_Variables")==0)||(strcmp(node->getContent(),"Declare_Variable")==0)){
        // printf("dfs %s\n",node->getContent());
        sa = dfsDeclares(sa,node);
    //函数的声明  
    }else if((strcmp(node->getContent(),"Def_Func_Block_Body")==0)||(strcmp(node->getContent(),"Def_Func_Block_NoBody")==0)){
       
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
        // printf("3\n");
        printf("add function %s reType: %s\n",s->name,s->type);
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

SymbolArea* dfsDeclares(SymbolArea* sa,AST::BaseNode* node){
   if(node==NULL){
    return  sa ;
   }
//    printf("1\n");

   if(strcmp(node->getContent(),"Declare_Variables")==0){
    //  printf("2\n");

        AST::BaseNode* var = node->getChildNode();

        //没有赋值
        if(strcmp(var->getContent(),"Variable")==0){
            //  printf("3\n");

            AST::BaseNode* v_ch = var->getChildNode();

          
            AST::BaseNode* id = v_ch->getChildNode();
            Symbol* s = createSymbol();
            strcpy(s->name,id->getContent());
            strcpy(s->type,v_ch->getContent());
            addSymbol(sa,s);
            printf("add symbol %s\n",s->name);
            
        }else{//申明且赋值

            AST::BaseNode* v_ch = var->getChildNode();

            AST::BaseNode* id = v_ch->getChildNode();
            Symbol* s = createSymbol();
            strcpy(s->name,id->getContent());
            strcpy(s->type,v_ch->getContent());
            AST::BaseNode* value = v_ch->getBrotherNode();

            printf("------%s\n",value->getContent());
            if(strcmp(value->getContent(),"Constant_Expression")==0){
                printf("ok");
                strcpy(s->value,value->getChildNode()->getContent());
                printf("add symbol has value %s = %s \n",s->name,s->value);
            }else{
                printf("add symbol %s\n",s->name);
            }
            addSymbol(sa,s);
             
            
    
        }
        // printf("5\n");
        dfsDeclares(sa,var->getBrotherNode());
   }
   else if(strcmp(node->getContent(),"Declare_Variable")==0){
    //  printf("6\n");
     AST::BaseNode* var = node->getChildNode();
    //   printf("7\n");
         if(strcmp(var->getContent(),"Variable")==0){
            //  printf("3\n");

            AST::BaseNode* v_ch = var->getChildNode();
            AST::BaseNode* id = v_ch->getChildNode();
            Symbol* s = createSymbol();
            strcpy(s->name,id->getContent());
            strcpy(s->type,v_ch->getContent());
            addSymbol(sa,s);
            printf("add symbol %s\n",s->name);
            
        }else{//申明且赋值

            AST::BaseNode* v_ch = var->getChildNode();

            AST::BaseNode* id = v_ch->getChildNode();
            Symbol* s = createSymbol();
            strcpy(s->name,id->getContent());
            strcpy(s->type,v_ch->getContent());
            AST::BaseNode* value = v_ch->getBrotherNode();

            printf("------%s\n",value->getContent());
            if(strcmp(value->getContent(),"Constant_Expression")==0){
       
                strcpy(s->value,value->getChildNode()->getContent());
                printf("add symbol has value %s = %s \n",s->name,s->value);
            }
            addSymbol(sa,s);
             printf("add symbol %s\n",s->name);
            
        }
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
        strcpy(s->type,paramType->getContent());
        addSymbol(sa,s);
        printf("add param %s\n",s->name);
    }
    return sa;

}

