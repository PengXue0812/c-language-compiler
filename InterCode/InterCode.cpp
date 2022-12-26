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

// 所有四元式的构造函数

QuadItem::QuadItem(int result, OpType op, int arg1, int arg2)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
    this->quad_item_type = 0;
}

QuadItem::QuadItem(int result, OpType op, Symbol *arg1, int arg2)
{
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
    this->quad_item_type = 1;
}

QuadItem::QuadItem(int result, OpType op, int arg1, Symbol *arg2)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.symbol = arg2;
    this->result.target = result;
    this->quad_item_type = 2;
}

QuadItem::QuadItem(int result, OpType op, Symbol *arg1, Symbol *arg2)
{
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.symbol = arg2;
    this->result.target = result;
    this->quad_item_type = 3;
}

QuadItem::QuadItem(Symbol *result, OpType op, int arg1, int arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.target = arg2;
    this->quad_item_type = 4;
}

QuadItem::QuadItem(Symbol *result, OpType op, Symbol *arg1, int arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.target = arg2;
    this->quad_item_type = 5;
}

QuadItem::QuadItem(Symbol *result, OpType op, int arg1, Symbol *arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.symbol = arg2;
    this->quad_item_type = 6;
}

QuadItem::QuadItem(Symbol *result, OpType op, Symbol *arg1, Symbol *arg2)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.symbol = arg1;
    this->arg2.symbol = arg2;
    this->quad_item_type = 7;
}

QuadItem::QuadItem(Symbol *result, OpType op, Symbol *arg1)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.symbol = arg1;
    this->quad_item_type = 7;
}

QuadItem::QuadItem(Symbol *result, OpType op, int arg1)
{
    this->result.symbol = result;
    this->op = op;
    this->arg1.target = arg1;
    this->quad_item_type = 6;
}

QuadItem::QuadItem(int result, OpType op)
{
    this->op = op;
    this->arg1.symbol = NULL;
    this->arg2.symbol = NULL;
    this->result.target = result;
    this->quad_item_type = 3;
}

QuadItem::QuadItem(Symbol *result, OpType op)
{
    this->op = op;
    this->arg1.symbol = NULL;
    this->arg2.symbol = NULL;
    this->result.symbol = result;
    this->quad_item_type = 10;
}

InterCode::InterCode(BaseNode *root)
{
    this->root = root;
    this->rootTable = new SymbolArea();
}

void InterCode::Root_Generate()
{
    Generate(this->root, this->rootTable);
    QuadItem *item = new QuadItem(-1, END);
    this->quad_list.push_back(item);
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
        // printf("node is NULL\n");
        exit(1);
    }
    std::string node_content = node->getContent();
    // std::cout << node_content << std::endl;
    int type = static_cast<int>(node->getNodeType());
    switch (type)
    {
    case static_cast<int>(NodeType::ROOT):
    {
        BaseNode *child = node->getChildNode();
        while (child != NULL)
        {
            Generate(child, symbolArea);
            child = child->getBrotherNode();
        }
        break;
    }
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

// void QuadItem::printItemInfo(int i) {}
void QuadItem::printItemInfo(int i)
{
    OpType op_type = this->op;
    int type = this->quad_item_type;
    // std::cout<<"Quad-Type: "<<type<<"  ";
    // std::cout<<"Op_Type: "<<static_cast<int>(op_type)<<std::endl;
    switch (op)
    {
    case OpType::ADDTION:
        if (type == 7)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " ADD "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 6)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " ADD "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 5)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " ADD "
                      << this->arg2.target
                      << std::endl;
        }
        else if (type == 4)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " ADD "
                      << this->arg2.target
                      << std::endl;
        }
        break;
    case OpType::SUBTRACTION:
        if (type == 7)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " SUB "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 6)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " SUB "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 5)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " SUB "
                      << this->arg2.target
                      << std::endl;
        }
        else if (type == 4)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " SUB "
                      << this->arg2.target
                      << std::endl;
        }
        break;
    case OpType::MULTIPLICATION:
        if (type == 7)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " MUL "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 6)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " MUL "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 5)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " MUL "
                      << this->arg2.target
                      << std::endl;
        }
        else if (type == 4)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " MUL "
                      << this->arg2.target
                      << std::endl;
        }
        break;
    case OpType::DIVISION:
        if (type == 7)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " DIV "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 6)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " DIV "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 5)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " DIV "
                      << this->arg2.target
                      << std::endl;
        }
        else if (type == 4)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " DIV "
                      << this->arg2.target
                      << std::endl;
        }
        break;
    case OpType::MOD:
        if (type == 7)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " MOD "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 6)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " MOD "
                      << this->arg2.symbol->getIdName()
                      << std::endl;
        }
        else if (type == 5)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.symbol->getIdName()
                      << " MOD "
                      << this->arg2.target
                      << std::endl;
        }
        else if (type == 4)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << " MOD "
                      << this->arg2.target
                      << std::endl;
        }
        break;
    case OpType::ASSIGN:
    {
        if (type == 6)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName()
                      << " := "
                      << this->arg1.target
                      << std::endl;
        }
        else if (type == 7)
        {
            std::cout << "L" << i << ":  "
                      << this->result.symbol->getIdName() << " := "
                      << this->arg1.symbol->getIdName() << std::endl;
            // std::cout<<result.symbol->getIdName()<<" offset: "<<result.var->getSymOffset()<<std::endl;
            // std::cout<<arg1.symbol->getIdName()<<" offset: "<<arg1.var->getSymOffset()<<std::endl;
        }
    }
    break;
    case JUMP_LT:
        if (type == 3)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " < "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 2)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " < "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 1)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " < "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 0)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " < "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }

        break;
    case JUMP_LE:
        if (type == 3)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " <= "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 2)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " <= "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 1)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " <= "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 0)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " <= "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }

        break;
    case JUMP_GT:
        if (type == 3)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " > "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 2)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " > "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 1)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " > "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 0)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " > "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }

        break;
    case JUMP_GE:
        if (type == 3)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " >= "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 2)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " >= "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 1)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " >="
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 0)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " >= "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }

        break;
    case JUMP_EQ:
        if (type == 3)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " == "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 2)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " == "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 1)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " == "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 0)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " == "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }

        break;
    case JUMP_NE:
        if (type == 3)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " != "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 2)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " != "
                      << this->arg2.symbol->getIdName()
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 1)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.symbol->getIdName()
                      << " != "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }
        else if (type == 0)
        {
            std::cout << "L" << i << ":  "
                      << "if "
                      << this->arg1.target
                      << " != "
                      << this->arg2.target
                      << " goto "
                      << "L"
                      << this->result.target
                      << std::endl;
        }

        break;
    case JUMP:
        std::cout << "L" << i << ":  "
                  << " goto "
                  << "L"
                  << this->result.target
                  << std::endl;
        break;
    case PRINT:
        std::cout << "L" << i << ":  "
                  << "print "
                  << this->result.symbol->getIdName() << std::endl;
        break;

    case END:
        std::cout << "L" << i << ":  "
                  << "END" << std::endl;
        break;

    default:
        //    std::cout<<"\033[31m Error! No such quad! \033[0m"<<std::endl;

        break;
    }
}

// 表达式生成四元式
Symbol *InterCode::Exp_Stmt_Generate(BaseNode *node, SymbolArea *area)
{
    if (node == NULL)
    {
        // printf("node is NULL\n");
        exit(1);
    }
    // 确定节点的类型和内容
    std::string node_content = node->getContent();
    // std::cout << node_content << std::endl;
    int type = static_cast<int>(node->getNodeType());
    switch (type)
    {
    case static_cast<int>(NodeType::FUNCTION_CALL):
    {
        if (node_content == "Function_Call_With_Args")
        {
            BaseNode *child = node->getChildNode();
            if (child->getContent() == "print")
            {
                // printf("ENTER PRINT\n");
                std::string var_name;
                bool isPointer = false;
                Symbol *var;
                if (child->getBrotherNode()->getChildNode()->getContent() == "Identifier_Expression")
                {
                    // printf("ID\n");
                    var_name = child->getBrotherNode()->getChildNode()->getChildNode()->getChildNode()->getContent();
                    var = area->findSymbolGlobally(var_name);
                }
                else
                {
                    // printf("PON\n");
                    var = Exp_Stmt_Generate(child->getBrotherNode()->getChildNode(), area);
                }

                // // printf("END FIND\n");

                QuadItem *quad = new QuadItem(var, OpType::PRINT);
                this->quad_list.push_back(quad);
                // printf("PRINT SUCCESS\n");
            }
        }
    }
    break;
    case static_cast<int>(NodeType::OPERATION):
    {
        // // printf("############OPPPPPPPP:%s\n", node_content.c_str());
        // 对于加减乘除生成四元式
        if (node_content == "Add" || node_content == "Sub" || node_content == "Mul" || node_content == "Div" || node_content == "Mod")
        {
            // // printf("operation\n");
            Symbol *arg1 = Exp_Stmt_Generate(node->getChildNode(), area);

            arg1->setIsUsed();
            Symbol *arg2 = Exp_Stmt_Generate(node->getChildNode()->getBrotherNode(), area);
            arg2->setIsUsed();
            Symbol *result = new Symbol("temp " + std::to_string(this->temp_list.size()), SymbolType::temp_var, 4);
            this->temp_list.push_back(result);
            OpType op;
            // // printf("operation222\n");
            if (node_content == "Add")
            {
                op = OpType::ADDTION;
            }
            else if (node_content == "Sub")
            {
                op = OpType::SUBTRACTION;
            }
            else if (node_content == "Mul")
            {
                op = OpType::MULTIPLICATION;
            }
            else if (node_content == "Div")
            {
                op = OpType::DIVISION;
            }
            else if (node_content == "Mod")
            {
                op = OpType::MOD;
            }
            QuadItem *quad;
            // // printf("operation333 %s\n", node_content.c_str());
            // // printf("%s\n", arg1->getIdName().c_str());
            // // printf("%d\n", isNumber(arg1->getIdName().c_str()));
            if (isNumber(arg1->getIdName()) && isNumber(arg2->getIdName()))
            {
                quad = new QuadItem(result, op, std::stoi(arg1->getIdName()), std::stoi(arg2->getIdName()));
            }
            else if (isNumber(arg1->getIdName()) && !isNumber(arg2->getIdName()))
            {
                quad = new QuadItem(result, op, std::stoi(arg1->getIdName()), arg2);
            }
            else if (!isNumber(arg1->getIdName()) && isNumber(arg2->getIdName()))
            {
                quad = new QuadItem(result, op, arg1, std::stoi(arg2->getIdName()));
            }
            else
            {
                quad = new QuadItem(result, op, arg1, arg2);
            }
            // // printf("operation444\n");
            this->quad_list.push_back(quad);
            return result;
        }
        // 对于赋值生成四元式
        else if (node_content == "Assign")
        {
            // printf("ASSIGNAssign\n");
            OpType op = ASSIGN;
            Symbol *result = Exp_Stmt_Generate(node->getChildNode(), area);
            result->setIsUsed();
            Symbol *arg1 = Exp_Stmt_Generate(node->getChildNode()->getBrotherNode(), area);
            SymbolType result_symbol_type = result->getSymbolType();
            SymbolType arg1_symbol_type = arg1->getSymbolType();
            if (result_symbol_type == SymbolType::pointer && result_symbol_type == SymbolType::pointer)
            {
                result->setPointerAddr(arg1->getPointerAddr());
            }
            if (arg1_symbol_type == SymbolType::var && result_symbol_type == SymbolType::array ||
                arg1_symbol_type == SymbolType::var && result_symbol_type == SymbolType::pointer)
            {
                printf("\033[31m warning: incompatible integer to pointer conversion assigning to 'int *' from 'int'; take the address with & \033[0m\n");
            }
            else if (arg1_symbol_type == SymbolType::array && result_symbol_type == SymbolType::var ||
                     arg1_symbol_type == SymbolType::pointer && result_symbol_type == SymbolType::var)
            {
                printf("\033[31m warning: incompatible pointer to integer conversion assigning to 'int' from 'int *'; dereference with *\n\033[0m\n");
            }
            QuadItem *quad;
            if (isNumber(arg1->getIdName()))
            {
                // printf("ADD AN QUAD：isNumber ASSIGN %s \n", arg1->getIdName().c_str());
                quad = new QuadItem(result, op, std::stoi(arg1->getIdName()));
            }
            else
            {
                // printf("ADD AN QUAD：isNotNumber %s \n", arg1->getIdName().c_str());
                quad = new QuadItem(result, op, arg1);
            }
            this->quad_list.push_back(quad);
            return result;
        }
        // 对于基本的逻辑运算
        else if (node_content == "Equal_Operation" || node_content == "Not_Equal_Operation" || node_content == "Greater_Operation" || node_content == "Greater_Equal_Operation" || node_content == "Less_Operation" || node_content == "Less_Equal_Operation")
        {
            // // printf("logic operation\n");
            std::cout << area << std::endl;
            Symbol *arg1 = Exp_Stmt_Generate(node->getChildNode(), area);
            // // printf("logic operation1\n");
            arg1->setIsUsed();
            Symbol *arg2 = Exp_Stmt_Generate(node->getChildNode()->getBrotherNode(), area);
            arg2->setIsUsed();
            // // printf("logic operation2\n");
            OpType op;
            if (node_content == "Equal_Operation")
            {
                op = JUMP_EQ;
            }
            else if (node_content == "Not_Equal_Operation")
            {
                op = JUMP_NE;
            }
            else if (node_content == "Greater_Operation")
            {
                op = JUMP_GT;
            }
            else if (node_content == "Greater_Equal_Operation")
            {
                op = JUMP_GE;
            }
            else if (node_content == "Less_Operation")
            {
                op = JUMP_LT;
            }
            else if (node_content == "Less_Equal_Operation")
            {
                op = JUMP_LE;
            }
            // // printf("logic operation3\n");

            QuadItem *quad_true;
            if (isNumber(arg1->getIdName()) && isNumber(arg2->getIdName()))
            {
                quad_true = new QuadItem(int(NULL), op, std::stoi(arg1->getIdName()), std::stoi(arg2->getIdName()));
            }
            else if (isNumber(arg1->getIdName()) && !isNumber(arg2->getIdName()))
            {
                quad_true = new QuadItem(int(NULL), op, std::stoi(arg1->getIdName()), arg2);
            }
            else if (!isNumber(arg1->getIdName()) && isNumber(arg2->getIdName()))
            {
                quad_true = new QuadItem(int(NULL), op, arg1, std::stoi(arg2->getIdName()));
            }
            else
            {
                quad_true = new QuadItem(int(NULL), op, arg1, arg2);
            }
            // // printf("logic operation4\n");

            QuadItem *quad_false = new QuadItem(int(NULL), JUMP);
            std::list<int> this_true_list;
            int len = quad_list.size();
            this_true_list.push_back(len);
            this->quad_list.push_back(quad_true);
            std::list<int> this_false_list;
            len = quad_list.size();
            this_false_list.push_back(len);
            this->quad_list.push_back(quad_false);
            trueList.push(this_true_list);
            falseList.push(this_false_list);
        }
        // 对于与或非的操作（短路）
        else if (node_content == "And" || node_content == "Or" || node_content == "Not")
        {
            if (node_content == "And")
            {
                BaseNode *left = node->getChildNode();
                Exp_Stmt_Generate(left, area);
                logic.push(quad_list.size());
                BaseNode *right = left->getBrotherNode();
                Exp_Stmt_Generate(right, area);
                std::list<int> left_true, left_false, right_true, right_false;
                right_true = trueList.top();
                trueList.pop();
                left_true = trueList.top();
                trueList.pop();
                right_false = falseList.top();
                falseList.pop();
                left_false = falseList.top();
                falseList.pop();
                left_false.merge(right_false);
                falseList.push(left_false);
                trueList.push(right_true);
                backpatch(&left_true, logic.top());
                logic.pop();
                break;
            }
            else if (node_content == "Or")
            {
                BaseNode *left = node->getChildNode();
                Exp_Stmt_Generate(left, area);
                logic.push(quad_list.size());
                BaseNode *right = left->getBrotherNode();
                Exp_Stmt_Generate(right, area);
                std::list<int> left_true, left_false, right_true, right_false;
                right_true = trueList.top();
                trueList.pop();
                left_true = trueList.top();
                trueList.pop();
                right_false = falseList.top();
                falseList.pop();
                left_false = falseList.top();
                falseList.pop();
                left_true.merge(right_true);
                trueList.push(left_true);
                falseList.push(right_false);
                backpatch(&left_false, logic.top());
                logic.pop();
                break;
            }
            else if (node_content == "Not")
            {
                // // printf("------------------not operation\n");
                BaseNode *child = node->getChildNode();
                while (child != nullptr)
                {
                    Exp_Stmt_Generate(child, area);
                    child = child->getBrotherNode();
                }
                // // printf("------------------not operation1\n");
                std::list<int> this_true_list, this_false_list;
                this_true_list = trueList.top();
                trueList.pop();
                this_false_list = falseList.top();
                falseList.pop();
                trueList.push(this_false_list);
                falseList.push(this_true_list);
                // // printf("------------------not operation2\n");
                break;
            }
        }
        // 对于数组元素的处理（和偏移量什么的相关）
        else if (node_content == "id[exp]")
        {
            std::string arr_name = node->getChildNode()->getContent();
            BaseNode *exp = node->getChildNode()->getBrotherNode();
            Symbol *index = Exp_Stmt_Generate(exp, area);
            std::string index_name = index->getIdName();
            Symbol *result = new Symbol(arr_name + "[" + index_name + "]");
            return result;
        }
        // 对于取地址运算符进行处理
        else if (node_content == "&id")
        {
            std::string id_name = node->getChildNode()->getContent();
            Symbol *id = area->findSymbolGlobally(id_name);
            int offset = id->getPointerAddr();
            Symbol *tresult = new Symbol("&" + id_name, SymbolType::pointer);
            tresult->setPointerAddr(offset);
            return tresult;
        }
        // 对于解析地址运算符
        else if (node_content == "*id")
        {
            std::string id_name = node->getChildNode()->getContent();
            Symbol *id = area->findSymbolGlobally(id_name);
            int offset = id->getPointerAddr();
            Symbol *tresult = new Symbol("*" + id_name, SymbolType::var);
            tresult->setPointerAddr(offset);
            return tresult;
        }
        else if (node_content == "Negative")
        {
            BaseNode *child = node->getChildNode();
            Symbol *result = Exp_Stmt_Generate(child, area);
            std::string result_name = result->getIdName();
            Symbol *tresult = new Symbol("-" + result_name);
            return tresult;
        }
    }
    break;
    // 对于固定值的处理
    case static_cast<int>(NodeType::EXPRESSION):
    {
        if (node_content == "Constant_Expression")
        {
            Symbol *res = new Symbol(node->getChildNode()->getContent());
            return res;
        }
        else if (node_content == "Identifier_Expression")
        {
            // // printf("Identifier_Expression\n");
            std::string id_name = node->getChildNode()->getChildNode()->getContent();
            // // printf("Identifier_Expression %s\n", id_name.c_str());
            // std::cout << area << std::endl;

            Symbol *id = area->findSymbolGlobally(id_name);
            // std::cout << "aaaaaaaaaaaaaaaaaaaa:" << id << std::endl;
            // // printf("Identifier_Expression %s\n", id_name.c_str());
            return id;
        }
        else if (node_content == "For_Expression")
        {
            Exp_Stmt_Generate(node->getChildNode(), area);
        }
        else if (node_content == "Braces")
        {
            // // printf("braces begin\n");
            Symbol *symbol = Exp_Stmt_Generate(node->getChildNode(), area);
            symbol->setIsUsed();
            // // printf("braces csdsa\n");
            return symbol;
        }
    }
    break;
    default:
        // printf("Error: Unknown node type in Exp_Stmt_Generate");
        exit(1);
    }
}
SymbolArea *InterCode::Body_Generate(BaseNode *node, SymbolArea *area)
{
    if (node == NULL)
    {
        // printf("node is NULL\n");
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
        // printf("-----------------NodeContent: %s\n", node_content.c_str());
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
            int elseStart = quad_list.size();
            backpatch(&ifFalse, elseStart);
        }
        else if (node_content == "If_Else_Statement")
        {
            BaseNode *condition = node->getChildNode();
            // 去生成if的条件的三地址码
            Exp_Stmt_Generate(condition, area);
            int start = quad_list.size();
            // 存着if的条件为真该跳转的位置的trueList
            std::list<int> ifTrue = trueList.top();
            // 存着if的条件为假该跳转的位置的falseList
            std::list<int> ifFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            // 回填if的条件为真该跳转的位置的trueList
            backpatch(&ifTrue, start);
            // 创建一个新的符号表,是if为真的符号表
            //  // printf("add if area\n");
            SymbolArea *ifSymbelArea = area->addNewChildArea();
            // 生成if的body
            BaseNode *ifContent = condition->getBrotherNode();
            Body_Generate(ifContent, ifSymbelArea);

            // 执行完if的body后,需要跳转else后面的三地址码
            QuadItem *temp = new QuadItem((int)NULL, OpType::JUMP);
            this->quad_list.push_back(temp);
            temp = quad_list.back();

            // 回填if的条件为假该跳转的位置的falseList
            int elseStart = quad_list.size();
            backpatch(&ifFalse, elseStart);

            // 生成else的body
            //  // printf("add else area\n");
            SymbolArea *elseSymbelArea = area->addNewChildArea();
            BaseNode *elseContent = ifContent->getBrotherNode();
            Body_Generate(elseContent, elseSymbelArea);
            // 回填执行完if的body后,需要跳转else后面的三地址码
            int end = quad_list.size();
            temp->backpatch(end);
        }
        else if (node_content == "While_Statement")
        {
            // // printf("while-------------------\n");
            BaseNode *condition = node->getChildNode();
            // 去生成While的条件的三地址码
            int start = quad_list.size();
            Exp_Stmt_Generate(condition, area);
            // // printf("while----------kjhkjkjhkjhkjh---------\n");

            // 存着While的条件为真该跳转的位置的trueList
            std::list<int> whileTrue = trueList.top();
            // 存着While的条件为假该跳转的位置的falseList
            std::list<int> whileFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            // 回填While的条件为真该跳转的位置的trueList
            backpatch(&whileTrue, whileTrue.back() + 1);
            // 创建一个新的符号表,是while的body的符号表
            SymbolArea *whileSymbelArea = area->addNewChildArea();
            // 生成while的body
            BaseNode *while_content = condition->getBrotherNode();
            while (while_content != NULL)
            {
                Body_Generate(while_content, whileSymbelArea);
                while_content = while_content->getBrotherNode();
                SymbolArea *whileSymbelArea = area->addNewChildArea();
            }
            // 回填执行完while的body后,条件为假需要跳出循环后面的三地址码
            int end = quad_list.size();
            QuadItem *temp = new QuadItem(start, OpType::JUMP);
            this->quad_list.push_back(temp);
            backpatch(&whileFalse, end + 1);
        }
        else if (node_content == "For_Def_SEMI_Expression_SEMI_Expression")
        {
            // // printf("For_Def_SEMI_Expression_SEMI_Expression\n");
            // 生成for的初始化声明
            BaseNode *forDeclear = node->getChildNode();
            SymbolArea *forDeclearArea = area->addNewChildArea();
            if (forDeclear->getContent() == "For_Expression")
            {
                Exp_Stmt_Generate(forDeclear, forDeclearArea);
            }
            else
            {
                Body_Generate(forDeclear->getChildNode(), forDeclearArea);
            }

            // // printf("forDeclearArea\n");
            // 下一句是for循环的开始
            int forStart = quad_list.size();
            BaseNode *forCondition = forDeclear->getBrotherNode();
            // // printf("forConditiowawsdfasdn\n");
            Exp_Stmt_Generate(forCondition, forDeclearArea);
            // // printf("forConditio111n\n");
            std::list<int> forTrue = trueList.top();
            std::list<int> forFalse = falseList.top();
            trueList.pop();
            falseList.pop();
            // // printf("forCondition\n");
            //???
            backpatch(&forTrue, forTrue.back() + 2);
            // SymbolArea *forBodyArea = area->addNewChildArea();
            BaseNode *forBody = forCondition->getBrotherNode()->getBrotherNode();
            Body_Generate(forBody, forDeclearArea);
            // // printf("forBody\n");
            BaseNode *forUpdate = forCondition->getBrotherNode();
            Exp_Stmt_Generate(forUpdate, forDeclearArea);
            QuadItem *temp = new QuadItem(forStart, OpType::JUMP);
            this->quad_list.push_back(temp);
            backpatch(&forFalse, quad_list.size());
        }
        else if (node_content == "Expression_Statement")
        {
            Exp_Stmt_Generate(node->getChildNode(), area);
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
    case static_cast<int>(NodeType::DEFINITION):
    {
        if (node_content == "Declare_Statement")
        {
            // // printf("kjh1\n");
            int type = static_cast<int>(SymbolType::integer); // 默认为int
            BaseNode *child = node->getChildNode();
            if (child->getContent() == "void_type")
            {
                type = static_cast<int>(SymbolType::Void);
            }
            else if (child->getContent() == "int*_Type")
            {
                type = static_cast<int>(SymbolType::pointer);
            }
            child = child->getBrotherNode();
            while (child != NULL)
            {
                Body_Generate(child, area);
                child = child->getBrotherNode();
            }
        }
        else if (node_content == "Declare_Variable" || node_content == "Declare_Variables")
        {
            // // printf("kjh2\n");
            // // printf("aaaa:%s\n", node->getContent());
            BaseNode *child = node->getChildNode();
            // // printf("bbbb:%s\n", node->getParentNode()->getContent());
            BaseNode *mod_node = node->getParentNode()->getChildNode();
            // // printf("aaaaaaaaaa\n");
            // printf("%s\n", child->getContent());
            if (child->getContent() == "Variable")
            { // 只声明不赋值

                BaseNode *ccNode = child->getChildNode();
                std::string name = ccNode->getContent();
                if (name == "Def_array[Const]")
                {
                    std::string array_name = ccNode->getChildNode()->getContent();
                    Symbol *array_symbol = area->findSymbolLocally(array_name);
                    if (array_symbol != nullptr && static_cast<int>(array_symbol->getSymbolType()) == static_cast<int>(SymbolType::array))
                    {
                        std::cout << "error: redefinition of " << array_name << std::endl;
                        exit(1);
                    }
                    std::string array_size = ccNode->getChildNode()->getBrotherNode()->getContent();
                    int size = std::stoi(array_size);
                    Symbol *symbol = new Symbol(array_name, SymbolType::array, size * 4);
                    area->setOffset(area->getOffset() + symbol->getWidth());
                    symbol->setPointerAddr(area->getOffset());
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
                else if (name == "Def_Identifier")
                {
                    if (mod_node->getContent() == "int*_Type")
                    {
                        std::string pointer_name = ccNode->getChildNode()->getContent();
                        Symbol *pointer_symbol = area->findSymbolLocally(pointer_name);
                        if (pointer_symbol != nullptr && static_cast<int>(pointer_symbol->getSymbolType()) == static_cast<int>(SymbolType::pointer))
                        {
                            std::cout << "error: redefinition of " << pointer_name << std::endl;
                            exit(1);
                        }
                        Symbol *symbol = new Symbol(pointer_name, SymbolType::pointer, 4);
                        symbol->setPointerAddr(-1); // 野指针
                        area->addSymbol(symbol);    // 指针加入符号表，并不会改变offset
                    }
                    else
                    {
                        std::string identifier_name = ccNode->getChildNode()->getContent();
                        Symbol *identifier_symbol = area->findSymbolLocally(identifier_name);
                        if (identifier_symbol != nullptr && static_cast<int>(identifier_symbol->getSymbolType()) == static_cast<int>(SymbolType::integer))
                        {
                            std::cout << "error: redefinition of " << identifier_name << std::endl;
                            exit(1);
                        }
                        Symbol *symbol = new Symbol(identifier_name, SymbolType::var, 4);
                        area->setOffset(area->getOffset() + symbol->getWidth());
                        symbol->setPointerAddr(area->getOffset());
                        // printf("add symbol : %s\n", symbol->getIdName().c_str());
                        area->addSymbol(symbol);
                    }
                }
            }
            else if (child->getContent() == "Variable_Assign")
            {
                // // printf("kjh3\n");

                if (child->getChildNode()->getContent() == "Def_Identifier")
                {
                    // // printf("kjh4\n");

                    if (mod_node->getContent() == "int*_Type")
                    {
                        // int * a = &b;
                        std::string pointer_name = child->getChildNode()->getChildNode()->getContent();
                        Symbol *pointer_symbol = area->findSymbolLocally(pointer_name);
                        if (pointer_symbol != nullptr && static_cast<int>(pointer_symbol->getSymbolType()) == static_cast<int>(SymbolType::pointer))
                        {
                            std::cout << "error: redefinition of " << pointer_name << std::endl;
                            exit(1);
                        }
                        Symbol *var = new Symbol(pointer_name, SymbolType::pointer);
                        Symbol *addr_var = Exp_Stmt_Generate(child->getChildNode()->getBrotherNode(), area);
                        var->setPointerAddr(addr_var->getPointerAddr());
                        area->addSymbol(var);
                        QuadItem *temp = new QuadItem(var, OpType::ASSIGN, addr_var);
                        this->quad_list.push_back(temp);
                    }
                    else
                    {
                        // // printf("enter INT type\n");

                        std::string identifier_name = child->getChildNode()->getChildNode()->getContent();
                        Symbol *identifier_symbol = area->findSymbolLocally(identifier_name);
                        if (identifier_symbol != nullptr && static_cast<int>(identifier_symbol->getSymbolType()) == static_cast<int>(SymbolType::integer))
                        {
                            std::cout << "error: redefinition of " << identifier_name << std::endl;
                            exit(1);
                        }
                        // // printf("xp-1\n");
                        BaseNode *ccNode = child->getChildNode()->getBrotherNode();
                        // // printf("xp-1.5\n");
                        // // printf("%s\n", ccNode->getContent().c_str());
                        Symbol *symbol = Exp_Stmt_Generate(ccNode, area);
                        // // printf("xp-2\n");
                        std::string symbol_name = symbol->getIdName();

                        // // printf("xp1\n");
                        Symbol *var = new Symbol(identifier_name, SymbolType::var, 4);
                        int var_type = static_cast<int>(var->getSymbolType());
                        int symbol_type = static_cast<int>(symbol->getSymbolType());
                        // // printf("%d %d \n", var_type, symbol_type);
                        if (var_type == 2 && (symbol_type == 2 || symbol_type == 3))
                        {
                            area->setOffset(area->getOffset() + var->getWidth());
                            var->setPointerAddr(area->getOffset());
                            area->addSymbol(var);
                            // // printf("var\n");
                        }
                        // // printf("xp2\n");
                        QuadItem *quad;
                        if (isNumber(symbol_name))
                        {
                            quad = new QuadItem(var, OpType::ASSIGN, atoi(symbol->getIdName().c_str()));
                        }
                        else
                        {
                            quad = new QuadItem(var, OpType::ASSIGN, symbol);
                        }
                        this->quad_list.push_back(quad);

                        // // printf("xp3\n");
                    }
                }
            }
            BaseNode *brother = child->getBrotherNode();
            if (brother)
            {
                Body_Generate(brother, area);
            }
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
std::list<int> *InterCode::merge(std::list<int> *list1,
                                 std::list<int> *list2)
{
    list1->merge(*list2);
    return list1;
}
void InterCode::backpatch(std::list<int> *backList, int target)
{
    std::list<int>::iterator it;
    // std::cout << "====backlist_begin=====" << *(backList->begin())
    //           << "==========" << std::endl;
    // std::cout << "====backlist_end=====" << *(backList->end())
    //           << "==========" << std::endl;
    // std::cout << "====target=====" << target << "==========" << std::endl;
    for (it = backList->begin(); it != backList->end(); it++)
    {
        quad_list[*it]->backpatch(target);
    }
    return;
}
