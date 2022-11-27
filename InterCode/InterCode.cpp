#include "InterCode.h"

#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>
#include <cstring>

bool isNumber(std::string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

QuadItem::QuadItem(int result, OpType op, int arg1, int arg2)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
}

QuadItem::QuadItem(int result, OpType op, Symbol *arg1, int arg2)
{
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
}

QuadItem::QuadItem(int result, OpType op, int arg1, Symbol *arg2)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.symbol = arg2;
    this->result.target = result;
}

QuadItem::QuadItem(int result, OpType op, Symbol *arg1, Symbol *arg2)
{
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.symbol = arg2;
    this->result.target = result;
}

QuadItem::QuadItem(Symbol *result, OpType op, int arg1, int arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.target = arg2;
}

QuadItem::QuadItem(Symbol *result, OpType op, Symbol *arg1, int arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.target = arg2;
}

QuadItem::QuadItem(Symbol *result, OpType op, int arg1, Symbol *arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.symbol = arg2;
}

QuadItem::QuadItem(Symbol *result, OpType op, Symbol *arg1, Symbol *arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.symbol = arg2;
}

QuadItem::QuadItem(Symbol *result, OpType op, Symbol *arg1)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.symbol = arg1;
}

QuadItem::QuadItem(Symbol *result, OpType op, int arg1)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.target = arg1;
}

QuadItem::QuadItem(int result, OpType op)
{
    this->op = op;
    this->arg1.symbol = NULL;
    this->arg2.symbol = NULL;
    this->result.target = result;
}

QuadItem::QuadItem(Symbol *result, OpType op)
{
    this->op = op;
    this->arg1.symbol = NULL;
    this->arg2.symbol = NULL;
    this->result.symbol = result;
}

InterCode::InterCode(BaseNode *root) { this->root = root; }

void InterCode::Root_Generate()
{
    Generate(this->root, this->rootTable);

    int len = this->quad_list.size();
    int i = 0;
    while (i < len)
    {
        quad_list[i]->printItemInfo(i);
        i++;
    }
}

void InterCode::Generate(BaseNode *node, SymbolArea *symbolArea)
{
    if (node == NULL)
    {
        printf("node is NULL\n");
        exit(1);
    }
    std::string node_content = node->getContent();
    int type = static_cast<int>(node->getNodeType());
    switch (type)
    {
    case static_cast<int>(NodeType::ROOT):
        BaseNode *child = node->getChildNode();

        break;
    case static_cast<int>(NodeType::STATEMENT):
    {
        BaseNode *child = node->getChildNode();
        while (child != NULL)
        {
            Generate(child, symbolArea);
            child = child->getBrotherNode();
        }
    }
    break;
    case static_cast<int>(NodeType::DEFINITION):
    {
        BaseNode *child = node->getChildNode();
        while (child != NULL)
        {
            Generate(child, symbolArea);
            child = child->getBrotherNode();
        }
    }
    break;
    case static_cast<int>(NodeType::MODIFY):
    {
        BaseNode *child = node->getChildNode();
        while (child != NULL)
        {
            Generate(child, symbolArea);
            child = child->getBrotherNode();
        }
    }
    break;
    case static_cast<int>(NodeType::ID):
    {
        BaseNode *child = node->getChildNode();
        while (child != NULL)
        {
            Generate(child, symbolArea);
            child = child->getBrotherNode();
        }
    }
    break;
    case static_cast<int>(NodeType::BODY):
    {
        BaseNode *child = node->getChildNode();
        while (child != NULL)
        {
            Body_Generate(child, symbolArea);
            child = child->getBrotherNode();
        }
    }
    break;
    default:
        exit(1);
        break;
    }
}

void QuadItem::printItemInfo(int i) {}

Symbol *InterCode::Exp_Stmt_Generate(BaseNode *node, SymbolArea *area)
{
    return nullptr;
}

SymbolArea *InterCode::Body_Generate(BaseNode *node, SymbolArea *area)
{
    if (node == NULL)
    {
        printf("node is NULL\n");
        exit(1);
    }
    std::string node_content = node->getContent();
    int type = static_cast<int>(node->getNodeType());
    switch (type)
    {
    case static_cast<int>(NodeType::BODY):
    {
        BaseNode *child = node->getChildNode();
        while (child != NULL)
        {
            Body_Generate(child, area);
            child = child->getBrotherNode();
        }
    }
    break;
    case static_cast<int>(NodeType::STATEMENT):
    {
        if (node_content == "If_Statement")
        {
            BaseNode *condition = node->getChildNode();
            Exp_Stmt_Generate(condition, area);
            int start = this->quad_list.size();
            std::list<int> ifTrue = trueList.top();
            std::list<int> ifFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            backpatch(&ifTrue, start);
            SymbolArea *ifSymbelArea = area->addNewChildArea();
            BaseNode *ifContent = condition->getBrotherNode();
            Body_Generate(ifContent, ifSymbelArea);
            int end = this->quad_list.size();
            backpatch(&ifFalse, end);
            QuadItem *item = new QuadItem(end, OpType::JUMP);
            this->quad_list.push_back(item);
        }

        else if (node_content == "If_Else_Statement")
        {
            BaseNode *condition = node->getChildNode();
            //去生成if的条件的三地址码
            Exp_Stmt_Generate(condition, area);
            int start = quad_list.size();
            //存着if的条件为真该跳转的位置的trueList
            std::list<int> ifTrue = trueList.top();
            //存着if的条件为假该跳转的位置的falseList
            std::list<int> ifFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            //回填if的条件为真该跳转的位置的trueList
            backpatch(&ifTrue, start);
            //创建一个新的符号表,是if为真的符号表
            SymbolArea *ifSymbelArea = area->addNewChildArea();
            //生成if的body
            BaseNode *ifContent = condition->getBrotherNode();
            Body_Generate(ifContent, ifSymbelArea);

            //执行完if的body后,需要跳转else后面的三地址码
            QuadItem *temp = new QuadItem((int)NULL, OpType::JUMP);
            this->quad_list.push_back(temp);
            temp = quad_list.back();

            //回填if的条件为假该跳转的位置的falseList
            int elseStart = quad_list.size();
            backpatch(&ifFalse, elseStart);

            //生成else的body
            SymbolArea *elseSymbelArea = area->addNewChildArea();
            BaseNode * elseContent = ifContent->getBrotherNode();
            Body_Generate(elseContent, elseSymbelArea);
            //回填执行完if的body后,需要跳转else后面的三地址码
            int end = quad_list.size();
            temp->backpatch(end);
        }
        else if (node_content == "While_Statement")
        {
            BaseNode *condition = node->getChildNode();
            //去生成While的条件的三地址码
            Exp_Stmt_Generate(condition, area);
            int start = quad_list.size();
            //存着While的条件为真该跳转的位置的trueList
            std::list<int> whileTrue = trueList.top();
            //存着While的条件为假该跳转的位置的falseList
            std::list<int> whileFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            //回填While的条件为真该跳转的位置的trueList
            backpatch(&whileTrue, whileTrue.back() + 2);
            //创建一个新的符号表,是while的body的符号表
            SymbolArea *whileSymbelArea = area->addNewChildArea();
            //生成while的body
            BaseNode *while_content = node->getBrotherNode();
            while (while_content != NULL)
            {
                Body_Generate(while_content, whileSymbelArea);
                while_content = while_content->getBrotherNode();
                SymbolArea *whileSymbelArea = area->addNewChildArea();
            }
            //回填执行完while的body后,条件为假需要跳出循环后面的三地址码
            int end = quad_list.size();
            QuadItem *temp = new QuadItem(start, OpType::JUMP);
            this->quad_list.push_back(temp);
            backpatch(&whileFalse, end + 1);
        }
        else
        {
            BaseNode *child = node->getChildNode();
            while (child != NULL)
            {
                Body_Generate(child, area);
                child = child->getBrotherNode();
            }
        }
    }
    case static_cast<int>(NodeType::DEFINITION):{
        if(node_content == "Declare_Statement"){
            int type = static_cast<int>(SymbolType::integer);//默认为int
            BaseNode *child = node->getChildNode();
            if(child->getContent() == "void_type"){
                type = static_cast<int>(SymbolType::Void);
            }
            else if(child->getContent() == "int*_Type"){
                type =static_cast<int>(SymbolType::pointer);
            }
            child = child->getBrotherNode();
            while(child != NULL){
                Body_Generate(child,area);
                child = child->getBrotherNode();
            }
        }
        else if(node_content == "Declare_Variable"||node_content == "Declare_Variables"){
            BaseNode *child = node->getChildNode();
            BaseNode *mod_node = node->getParentNode()->getChildNode();
            if(child->getContent() =="Variable"){//只声明不赋值
                BaseNode * ccNode = child->getChildNode();
                std::string name = ccNode->getContent();
                if(name == "Def_array[Const]"){
                    std::string array_name = ccNode->getChildNode()->getContent();
                    Symbol * array_symbol = area->findSymbolLocally(array_name);
                    if(array_symbol !=nullptr && static_cast<int>(array_symbol->getSymbolType()) == static_cast<int>(SymbolType::array)){
                        std::cout<<"error: redefinition of "<<array_name<<std::endl;
                        exit(1);
                    }
                    std::string array_size = ccNode->getChildNode()->getBrotherNode()->getContent();
                    int size = std::stoi(array_size);
                    Symbol * symbol = new Symbol(array_name,SymbolType::array,size * 4);
                    area->setOffset(area->getOffset() + symbol->getWidth());
                    area->addSymbol(symbol);
                }
                // else if(name == "Def_*Identifier"){
                //     std::string pointer_name = ccNode->getChildNode()->getContent();
                //     Symbol * pointer_symbol = area->findSymbolLocally(pointer_name);
                //     if(pointer_symbol !=nullptr && static_cast<int>(pointer_symbol->getType()) == static_cast<int>(SymbolType::pointer)){
                //         std::cout<<"error: redefinition of "<<pointer_name<<std::endl;
                //         exit(1);
                //     }
                //     Symbol * symbol = new Symbol(pointer_name,SymbolType::pointer,4);
                //     area->addSymbol(symbol);//指针加入符号表，并不会改变offset
                // }
                else if(name == "Def_Identifier"){
                    if(mod_node->getContent() == "int*_Type"){
                        std::string pointer_name = ccNode->getChildNode()->getContent();
                        Symbol * pointer_symbol = area->findSymbolLocally(pointer_name);
                        if(pointer_symbol !=nullptr && static_cast<int>(pointer_symbol->getSymbolType()) == static_cast<int>(SymbolType::pointer)){
                            std::cout<<"error: redefinition of "<<pointer_name<<std::endl;
                            exit(1);
                        }
                        Symbol * symbol = new Symbol(pointer_name,SymbolType::pointer,4);
                        area->addSymbol(symbol);//指针加入符号表，并不会改变offset
                    }
                    else{
                        std::string identifier_name = strcat("*",ccNode->getContent());
                        Symbol * identifier_symbol = area->findSymbolLocally(identifier_name);
                        if(identifier_symbol !=nullptr && static_cast<int>(identifier_symbol->getSymbolType()) == static_cast<int>(SymbolType::integer)){
                            std::cout<<"error: redefinition of "<<identifier_name<<std::endl;
                            exit(1);
                        }
                        Symbol * symbol = new Symbol(identifier_name,SymbolType::var,4);
                        area->setOffset(area->getOffset() + symbol->getWidth());
                        area->addSymbol(symbol);
                    }                    
                }
            }
            else if(child->getContent() == "Variable_Assign"){
                if(child->getChildNode()->getContent() == "Def_Identifier"){
                    if(mod_node->getContent() == "int*_Type"){
                      //int * a = &b;
                      std::string pointer_name = child->getChildNode()->getChildNode()->getContent();
                        Symbol * pointer_symbol = area->findSymbolLocally(pointer_name);
                        if(pointer_symbol !=nullptr && static_cast<int>(pointer_symbol->getSymbolType()) == static_cast<int>(SymbolType::pointer)){
                            std::cout<<"error: redefinition of "<<pointer_name<<std::endl;
                            exit(1);
                        }
                        Symbol * var = new Symbol(pointer_name,SymbolType::pointer);
                        Symbol * addr_var = Exp_Stmt_Generate(child->getChildNode()->getBrotherNode(),area);
                        area->addSymbol(var);
                        QuadItem *temp = new QuadItem(var,OpType::ASSIGN,addr_var);
                        this->quad_list.push_back(temp);
                    }
                    else {
                        std::string identifier_name = child->getChildNode()->getChildNode()->getContent();
                        Symbol * identifier_symbol = area->findSymbolLocally(identifier_name);
                        if(identifier_symbol !=nullptr && static_cast<int>(identifier_symbol->getSymbolType()) == static_cast<int>(SymbolType::integer)){
                            std::cout<<"error: redefinition of "<<identifier_name<<std::endl;
                            exit(1);
                        }
                        BaseNode * ccNode = child->getChildNode()->getBrotherNode();
                        Symbol * symbol = Exp_Stmt_Generate(ccNode,area);
                        std::string symbol_name = symbol->getIdName();

                        Symbol * var = new Symbol(identifier_name,SymbolType::var,4);
                        int var_type = static_cast<int>(var->getSymbolType());
                        int symbol_type = static_cast<int>(symbol->getSymbolType());
                        if(var_type == 2 && symbol_type == 2){
                            area->setOffset(area->getOffset() + var->getWidth());
                            area->addSymbol(var);
                        }
                        QuadItem* quad;
                        if(isNumber(symbol_name))
                        {
                            quad = new QuadItem(var,OpType::ASSIGN, atoi(symbol->getIdName().c_str()));
                        }
                        else 
                        {
                            quad = new QuadItem(var, OpType::ASSIGN, symbol);
                        }
                        this->quad_list.push_back(quad);
                    
                    }
                    
                } 
            }
        }
    }
  }
}
std::list<int> *InterCode::makelist(int index) {
    std::list<int> *jumpList = new std::list<int>();
    jumpList->push_back(index);
    return jumpList;
}
std::list<int> *InterCode::merge(std::list<int> * list1,
                                std::list<int> * list2) {
    list1->merge(*list2);
    return list1;
}
void InterCode::backpatch(std::list<int> * backList, int target) {
    std::list<int>::iterator it;
    std::cout << "====backlist_begin=====" << *(backList->begin())
                << "==========" << std::endl;
    std::cout << "====backlist_end=====" << *(backList->end())
                << "==========" << std::endl;
    std::cout << "====target=====" << target << "==========" << std::endl;
    for (it = backList->begin(); it != backList->end(); it++) {
        quad_list[*it]->backpatch(target);
    }
    return;
}
