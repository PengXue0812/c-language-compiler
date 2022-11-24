#include "InterCode.h"
#include <typeinfo>
#include <sstream>
#include <string>
#include <iostream>

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

InterCode::InterCode(BaseNode *root)
{
    this->root = root;
}

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

void InterCode::Generate(BaseNode *node, SymbolArea *table)
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
        while (child != NULL)
        {
        }

        break;
        case static_cast<int>(NodeType::STATEMENT):
        break;
        case static_cast<int>(NodeType::DEFINITION ):
        break;
        case static_cast<int>(NodeType::MODIFY):
        break;
        case static_cast<int>(NodeType::ID):
        break;
        case static_cast<int>(NodeType::BODY):
        break;
        default:
            exit(1);
            break;
    }
    
}

void QuadItem:: printItemInfo(int i){

}

Symbol* InterCode::Exp_Stmt_Generate(BaseNode* node, SymbolArea* table){

}

SymbolArea* InterCode:: Body_Generate(BaseNode* node, SymbolArea* table){

}

std::list<int> *InterCode::makelist(int index)
{
    std::list<int> *jumpList = new std::list<int>();
    jumpList->push_back(index);
    return jumpList;
}
std::list<int> *InterCode::merge(std::list<int> *list1, std::list<int> *list2)
{
    list1->merge(*list2);
    return list1;
}
void InterCode::backpatch(std::list<int> *backList, int target)
{
    std::list<int>::iterator it;
    std::cout<<"====backlist_begin====="<<*(backList->begin())<<"=========="<<std::endl;
    std::cout<<"====backlist_end====="<<*(backList->end())<<"=========="<<std::endl;
    std::cout<<"====target====="<<target<<"=========="<<std::endl;
    for (it = backList->begin(); it != backList->end(); it++)
    {
        quad_list[*it]->backpatch(target);
    }
    return;
}

