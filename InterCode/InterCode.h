#ifndef _INTERCODE_H_
#define _INTERCODE_H_

#include <list>
#include <vector>
#include <stack>
#include "../Symbol/Symbol.h"
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
    END
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
    int quad_item_type;
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
    BaseNode* root;//语法树根节点
    std::vector<QuadItem* > quad_list;//四元式列表
    SymbolArea* rootTable;//符号表根节点
    std::vector<Symbol* >temp_list;//临时变量列表
    std::stack<int>logic;//逻辑运算栈
    std::stack<std::list<int> > trueList;//真值列表
    std::stack<std::list<int> > falseList;//假值列表

public:
    InterCode();
    // 从ast生成中间代码；
    InterCode(BaseNode* root);
    Symbol* Exp_Stmt_Generate(BaseNode* node, SymbolArea* symbol_table);//表达式语句生成
    SymbolArea* Body_Generate(BaseNode* node, SymbolArea* symbol_table);//函数体生成
    void Generate(BaseNode* node, SymbolArea* symbol_table);//生成中间代码
    void Root_Generate();//总的入口
    int getFalseJump(int i);//获取假值跳转
    void addItem(QuadItem* item);//添加四元式
    void showList();//显示四元式列表
    // 3 func for patch
    std::list<int> *makelist(int index);//生成列表
    std::list<int> *merge(std::list<int> *list1, std::list<int> *list2);//合并列表
    void backpatch(std::list<int> *backList, int target);//回填
    std::vector<QuadItem* > getQuadlist(){return quad_list;}//获取四元式列表
    SymbolArea* getTable(){return rootTable;}//获取符号表

};

#endif