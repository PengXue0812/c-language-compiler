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

void QuadItem::printItemInfo(int i)
{
}

Symbol *InterCode::Exp_Stmt_Generate(BaseNode *node, SymbolArea *area)
{
    return null;
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
        if (node_content == "If_Else_Statement")
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
            BaseNode *elseContent->getBrotherNode();
            Body_Generate(elseContent, elseSymbelArea);
           //回填执行完if的body后,需要跳转else后面的三地址码
            int end = quad_list.size();
            temp->backpatch(end);
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
    }

    std::list<int> *InterCode::makelist(int index)
    {
        std::list<int> *jumpList = new std::list<int>();
        jumpList->push_back(index);
        return jumpList;
    }
    std::list<int> *InterCode::merge(std::list<int> * list1, std::list<int> * list2)
    {
        list1->merge(*list2);
        return list1;
    }
    void InterCode::backpatch(std::list<int> * backList, int target)
    {
        std::list<int>::iterator it;
        std::cout << "====backlist_begin=====" << *(backList->begin()) << "==========" << std::endl;
        std::cout << "====backlist_end=====" << *(backList->end()) << "==========" << std::endl;
        std::cout << "====target=====" << target << "==========" << std::endl;
        for (it = backList->begin(); it != backList->end(); it++)
        {
            quad_list[*it]->backpatch(target);
        }
        return;
    }
