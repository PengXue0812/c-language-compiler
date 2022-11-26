#ifndef _INTERCODE_H_
#define _INTERCODE_H_

#include <list>
#include <vector>
#include <stack>
#include "Symbol/Symbol.h"
#include "../Node/BaseNode.h"
#include "../Node/NodeType.h"

enum OpType
{
    ADDTION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MOD,
    ASSIGN,
    LOGIC_AND,
    LOGIC_OR,
    LOGIC_NOT,
    UMINUS,
    LABEL,
    JUMP,
    JUMP_LT,
    JUMP_LE,
    JUMP_GT,
    JUMP_GE,
    JUMP_EQ,
    JUMP_NE,
    RETURN_OP,
    PRINT,
    SCAN,
};

union Arg
{
    int target;
    Symbol *symbol;
};

class QuadItem
{
public:
    OpType op;
    Arg arg1;
    Arg arg2;
    Arg result;
    QuadItem(int result,OpType op);
    QuadItem(Symbol* result, OpType op, int arg1, int arg2);
    QuadItem(Symbol* result, OpType op, Symbol* arg1, int arg2);
    QuadItem(Symbol* result, OpType op, int arg1, Symbol* arg2);
    QuadItem(Symbol* result, OpType op, Symbol* arg1, Symbol* arg2);
    QuadItem(Symbol* result, OpType op, int arg1);  //assign const to var;
    QuadItem(Symbol* result, OpType op, Symbol* arg1); //assign var to var;
    QuadItem(int result, OpType op, Symbol* arg1, int arg2);
    QuadItem(int result, OpType op, int arg1, Symbol* arg2);
    QuadItem(int result, OpType op, int arg1, int arg2);
    QuadItem(int result,OpType op, Symbol* arg1, Symbol* arg2);    
    QuadItem(int result, OpType op, int arg1);
    QuadItem(Symbol* result, OpType op);

    void printItemInfo(int i);

    inline void backpatch(int target)
    {
        this->result.target = target;
    }

    inline OpType getOpType()
    {
        return this->op;
    }


    inline Arg getArg(int index)
    {
        if (index == 1)
            return this->arg1;
        else if (index == 2)
            return this->arg2;
        else if (index == 3)
            return this->result;
    }
};


class InterCode {
private: 
    BaseNode* root;
    std::vector<QuadItem* > quad_list;
    SymbolArea* rootTable;
    std::vector<Symbol* >temp_list;
    std::stack<int>logic;
    std::stack<std::list<int> > trueList;
    std::stack<std::list<int> > falseList;

public:
    InterCode();
    // 从ast生成中间代码；
    InterCode(BaseNode* root);
    Symbol* Exp_Stmt_Generate(BaseNode* node, SymbolArea* symbol_table);
    SymbolArea* Body_Generate(BaseNode* node, SymbolArea* symbol_table);
    void Generate(BaseNode* node, SymbolArea* symbol_table);
    void Root_Generate();
    int getFalseJump(int i);
    void addItem(QuadItem* item);
    void showList();
    // 3 func for patch
    std::list<int> *makelist(int index);
    std::list<int> *merge(std::list<int> *list1, std::list<int> *list2);
    void backpatch(std::list<int> *backList, int target);
    std::vector<QuadItem* > getQuadlist(){return quad_list;}
    SymbolArea* getTable(){return rootTable;}

};

#endif