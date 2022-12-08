#ifndef _NODETYPE_H_
#define _NODETYPE_H_
enum NodeType {
  ROOT,        // 根结点
  ID,          // 标识符
  EXPRESSION,  // 表达式
  CONST_INT,   // 整型常量
  OPERATION,   // 运算符
  STATEMENT,   // 语句
  DEFINITION,  // 定义
  MODIFY,      // 赋值
  FUNCTION_CALL,        // 函数调用
  POINTER,     // 指针
  ARRAY,       // 数组
  ADDRESS,     // 地址
  BODY         // 函数体

};

#endif

