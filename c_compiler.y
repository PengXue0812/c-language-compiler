%{
#include <stdio.h>
#include <string.h>
#include "Node/BaseNode.h"
#include "Node/BTNode.h"
#include "Symbol/Symbol.h"
#include "InterCode/InterCode.h"

BaseNode* root;
extern int yylex(void); 

extern int yyparse(void); 
extern FILE* yyin;

int yywrap()
{
    return 1;
}
void yyerror(const char *s)
{
	printf("[error] %s\n", s);
}

int main()
{
    yyin = fopen("./test.txt","r");
    do{
       yyparse(); 
    }while(!feof(yyin));
	
	return 0;
}
%}

%union
{
    char* num;
    BaseNode *ast;
    char *str;
}
%type <ast> program 
%type <ast> blocks 
%type <ast> block
%type <ast> variable 
%type <ast> descriptor 
%type <ast> function 
%type <ast> params  
%type <ast> param 
%type <ast> body 
%type <ast> statements 
%type <ast> statement 
%type <ast> declares
%type <ast> declare
%type <ast> declarevars
%type <ast> forstart
%type <ast> expression
%type <ast> arguments
%type <ast> consts
%type <ast> identifiers 


%right <str> ASSIGN_OP 
%left <ast> OR 
%left <ast> AND 
%left <ast> SINGLAND
%left <str> EQ_OP NE_OP 
%left <str> GT_OP LT_OP GE_OP LE_OP 
%left <ast> '+' '-'
%left <ast> '*' '/' '%'
%right <ast> '!'
%left  <str> '(' ')'
%left  <str> '[' ']'
%token <str> PRINTF 
%token <str> SCANF
%token <str> IDENTIFIER
%token <num> CONST 
%nonassoc LOWER_THAN_ELSE
%token<str> WHILE FOR BREAK CONTINUE IF ELSE RETURN VOID S_QUO D_QUO INT COMMA SEMI 

%%
program:
    blocks
    {
        root = new BaseNode("program",NodeType::ROOT);
        // root->addChildNode(new BaseNode("test"));
        root->addChildNode($1);
        BTTree<BaseNode> printer(root, &BaseNode::getAllChildrenNode,
                        &BaseNode::getStringContent);
        InterCode interCode = InterCode(root);
        printer.print();
        interCode.Root_Generate();
        

    };
//语句块的集合
blocks:
    block
    {
        // printf("blocks->block\n");
        
        $$= $1;
        // BaseNode *node = new BaseNode("a_Block",NodeType::STATEMENT);
        // node->addChildNode($1);
        // $$ = node;
    }
    | blocks block
    {
        // printf("blocks->blocks block\n");
        BaseNode *node =new BaseNode("Blocks",NodeType::STATEMENT);
        node->addChildNode($1);
        node->addChildNode($2);
        // BaseNode * block = new BaseNode("a_Block",NodeType::STATEMENT);
        // block->addChildNode($2);
        // node->addChildNode(block);
        $$ = node;
    }
    ;
//语句块(包括函数定义,全局变量的定义)
block: declare SEMI
    {
        // printf("Declare_Statement\n");
        // BaseNode *node = new BaseNode("Declare_Statement",NodeType::DEFINITION);
        // node->addChildNode($1);
        $$ = $1;
    }
    |descriptor function body
    {
        // printf("blockcdescriptor function body\n");
        BaseNode * node = new BaseNode("Def_Func_Block_Body",NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($2);
        node->addChildNode($3);
        $$ = node;
    }
    |descriptor function SEMI
    {
        // printf("block->descriptor function 'SEMI'\n");
        BaseNode * node = new BaseNode("Def_Func_Block_NoBody",NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($2);
        $$ = node;
    }
//变量
variable:IDENTIFIER
    {   
        // printf("variable->IDENTIFIER\n");
        BaseNode * node = new BaseNode("Def_Identifier",NodeType::DEFINITION);
        BaseNode * var_node = new BaseNode($1,NodeType::ID);
        node->addChildNode(var_node);
        $$ = node;
    }
    |IDENTIFIER '[' ']'
    {
        // printf("variable->IDENTIFIER '[' ']'\n");
        BaseNode * node = new BaseNode("Def_array[]",NodeType::ARRAY);
        BaseNode * var_node = new BaseNode($1,NodeType::ID);
        node->addChildNode(var_node);
        $$ = node;
    }
    |IDENTIFIER '[' CONST ']'
    {
        // printf("variable->IDENTIFIER '[' CONST ']'\n");
        BaseNode * node = new BaseNode("Def_array[Const]",NodeType::ARRAY);
        BaseNode * var_node = new BaseNode($1,NodeType::ID);
        // BaseNode * const_node = new BaseNode($3,NodeType::ID);

        BaseNode * const_node = new BaseNode($3, NodeType::CONST_INT);
        node->addChildNode(var_node);
        node->addChildNode(const_node);
        $$ = node;
    }
    |IDENTIFIER '[' expression ']'
    {
        // printf("variable->IDENTIFIER '[' expression ']'\n");
        BaseNode * node = new BaseNode("Def_array[expression]",NodeType::ARRAY);
        BaseNode * var_node = new BaseNode($1,NodeType::ID);
        node->addChildNode(var_node);
        node->addChildNode($3);
    }
    |'*' IDENTIFIER
    {
        // printf("variable->'*' IDENTIFIER\n");
        BaseNode * node = new BaseNode("Def_*Identifier",NodeType::POINTER);
        BaseNode * var_node = new BaseNode($2,NodeType::ID);
        node->addChildNode(var_node);
        $$ = node;
    }
    ;
//数字的序列(1,2,3,4)    
consts:CONST
    {
        // // printf("");
        BaseNode * node = new BaseNode("Const_array",NodeType::EXPRESSION);
        BaseNode * const_node = new BaseNode($1,NodeType::CONST_INT);
        node->addChildNode(const_node);
        $$ = node;
    }
    |consts COMMA CONST
    {
        // // printf("");
        BaseNode * node = new BaseNode("Consts_array",NodeType::EXPRESSION);
        BaseNode * const_node = new BaseNode($3,NodeType::CONST_INT);
        node->addChildNode($1);
        node->addChildNode(const_node);
        $$ = node;
    }
    ;
//标识符
descriptor:INT
    {
        // printf("INTTTTTTT\n");
        BaseNode * node = new BaseNode("int_Type",NodeType::MODIFY);
        $$ = node;
    }
    |VOID 
    {
        // printf("VOID\n");
        BaseNode * node = new BaseNode("void_type",NodeType::MODIFY);
        $$ = node;
    }
    |INT '*'
    {
        // printf("INT* \n");
        BaseNode * node = new BaseNode("int*_Type",NodeType::MODIFY);
        $$ = node;
    }
    ;
//函数的名字与参数列表
function:IDENTIFIER '(' ')'
    {
        // printf("Function_Without_Param\n");
        BaseNode * node = new BaseNode("Function_Without_Param",NodeType::DEFINITION);
        BaseNode * IdentifierNode = new BaseNode($1,NodeType::ID);
        node->addChildNode(IdentifierNode);
        $$ = node;
    }
    |IDENTIFIER '(' params ')'
    {
        // printf("Function_With_Param\n");
        BaseNode * node = new BaseNode("Function_With_Param",NodeType::DEFINITION);
        BaseNode * IdentifierNode = new BaseNode($1,NodeType::ID);
        node->addChildNode(IdentifierNode);
        node->addChildNode($3);
        $$ = node;
    }
    ;
//参数序列    
params:params COMMA param {
    // printf("params: params COMMA param\n");
    BaseNode * node = new BaseNode("Params",NodeType::DEFINITION);
    // BaseNode * param_node = new BaseNode("Single_Param",NodeType::DEFINITION);
    // param_node->addChildNode($3);
    node->addChildNode($1);
    // node->addChildNode(param_node);
    node->addChildNode($3);
    $$ = node;
}
| param {
    // printf("params: param\n");
    // BaseNode * node = new BaseNode("Single_Param",NodeType::DEFINITION);
    // node->addChildNode($1);
    // $$ = node;
    $$ = $1;
};
//单个参数     //int a
param:descriptor IDENTIFIER  {
    // printf("param:descriptor identifiers\n");
    BaseNode * node = new BaseNode("Param_ID",NodeType::DEFINITION);
    BaseNode * IdentifierNode = new BaseNode($2,NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}//int a[10]
|descriptor IDENTIFIER  '[' CONST ']' {
    // printf("param:descriptor identifiers '[' CONST ']'\n");
    BaseNode * node = new BaseNode("Param_ID[CONST]",NodeType::DEFINITION);
    BaseNode * IdentifierNode = new BaseNode($2,NodeType::ID);
    BaseNode * ConstNode = new BaseNode($4,NodeType::CONST_INT);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    node->addChildNode(ConstNode);
    $$ = node;
}//int a[]
|descriptor IDENTIFIER  '[' ']' {
    // printf("param:descriptor identifiers '[' ']'\n");
    BaseNode * node = new BaseNode("Param_ID[]",NodeType::DEFINITION);
    BaseNode * IdentifierNode = new BaseNode($2,NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}// int &a
|descriptor SINGLAND IDENTIFIER{
    // printf("param:descriptor SINGLAND identifiers\n");
    BaseNode * node = new BaseNode("array_&id",NodeType::ARRAY);
    BaseNode * IdentifierNode = new BaseNode($3,NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}//int *a
|descriptor '*' IDENTIFIER{
    // printf("param:descriptor SINGLAND '*' identifiers\n");
    BaseNode * node = new BaseNode("array_*id",NodeType::POINTER);
    BaseNode * IdentifierNode = new BaseNode($3,NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}//int 
|descriptor{
    // printf("param:descriptor\n");
    BaseNode * node = new BaseNode("param_without_id",NodeType::DEFINITION);
    node->addChildNode($1);
    $$ = node;
};
//语句块    
body:'{' statements '}' {
    // printf("body:'{' statements '}'\n");
    BaseNode *node = new BaseNode("Body",NodeType::BODY);
    node->addChildNode($2);
    $$ = node;
};
//句子集 
statements:statements statement {
    // printf("statements:statements statement\n");
    BaseNode * node = new BaseNode("Statements",NodeType::STATEMENT);
    // BaseNode * Single_Statement = new BaseNode("Single_Statement",NodeType::STATEMENT);
    // Single_Statement->addChildNode($2);
    node->addChildNode($1);
    // node->addChildNode(Single_Statement);
    node->addChildNode($2);
    $$ = node;
}
|statement {
    // printf("statements:statement\n");
    // BaseNode * node = new BaseNode("Single_Statement",NodeType::STATEMENT);
    // node->addChildNode($1);
    $$ = $1;
}
;
// 单个句子
statement:
    //表达式;
    expression SEMI
    {
        BaseNode * node = new BaseNode("Expression",NodeType::STATEMENT);
        node->addChildNode($1);
        $$ = node;
    }
    //声明语句;
    | declare SEMI
    {
        // BaseNode *node = new BaseNode("Declare_Statement",NodeType::STATEMENT);
        // node->addChildNode($1);
        $$ = $1;
    }
    //语句块
    | body
    {
        BaseNode * node = new BaseNode("Body_Statement",NodeType::STATEMENT);
        node->addChildNode($1);
        $$ = node;
    }

    | RETURN expression SEMI
    {
        BaseNode * node = new BaseNode("Return_Expression",NodeType::STATEMENT);
        node->addChildNode($2);
        $$ = node;
    }
    | RETURN SEMI
    {
        BaseNode * node = new BaseNode("Return_NULL",NodeType::STATEMENT);
        $$ = node;
    }
    | IF '(' expression ')' statement
    {
        BaseNode * node = new BaseNode ("If_Statement",NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        $$ = node;
    }
    | IF '(' expression ')' statement ELSE statement %prec LOWER_THAN_ELSE{
        BaseNode * node = new BaseNode ("If_Else_Statement",NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        node->addChildNode($7);
        $$ = node;
    }
    | WHILE '(' expression ')' statement
    {   
        BaseNode * node = new BaseNode ("While_Statement",NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        $$ = node;
    }
    | FOR '(' SEMI SEMI ')' statement
    {
        // printf("FOR '(' SEMI SEMI ')' statement\n");
        BaseNode * node = new BaseNode ("For_SEMI_SEMI",NodeType::STATEMENT);
        node->addChildNode($6);
        $$ = node;
    }
    | FOR '(' forstart SEMI SEMI ')' statement
    {
        // printf("FOR '(' forstart SEMI SEMI ')' statement\n");
        BaseNode * node = new BaseNode ("For_Def_SEMI_SEMI",NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($7);
        $$ = node;
    } 
    | FOR '(' SEMI expression SEMI ')' statement
    {
        // printf("FOR '(' SEMI expression SEMI ')' statement\n");
        BaseNode * node = new BaseNode ("For_SEMI_Expression_SEMI",NodeType::STATEMENT);
        node->addChildNode($4);
        node->addChildNode($7);
        $$ = node;
    }
    | FOR '(' SEMI SEMI expression ')' statement
    {
        // printf("FOR '(' SEMI SEMI expression ')' statement\n");
        BaseNode * node = new BaseNode ("For_SEMI_SEMI_Expression",NodeType::STATEMENT);
        node->addChildNode($5);
        node->addChildNode($7);
        $$ = node;
    }
    | FOR '(' forstart SEMI expression SEMI expression ')' statement
    {
        // printf("FOR '(' forstart SEMI expression SEMI expression ')' statement\n");
        BaseNode * node = new BaseNode ("For_Def_SEMI_Expression_SEMI_Expression",NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        node->addChildNode($7);
        node->addChildNode($9);
        $$ = node;
    }
    | FOR '(' forstart SEMI expression SEMI ')' statement
    {
        // printf("FOR '(' forstart SEMI expression SEMI ')' statement\n");
        BaseNode * node = new BaseNode ("For_Def_SEMI_Expression_SEMI",NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        node->addChildNode($8);
        $$ = node;
    }
    | FOR '(' forstart SEMI SEMI expression ')' statement
    {
        // printf("FOR '(' forstart SEMI SEMI expression ')' statement\n");
        BaseNode * node = new BaseNode ("For_Def_SEMI_SEMI_Expression",NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($6);
        node->addChildNode($8);
        $$ = node;
    }
    | FOR '(' SEMI expression SEMI expression ')' statement
    {
        // printf("FOR '(' SEMI expression SEMI expression ')' statement\n");
        BaseNode * node = new BaseNode ("For_SEMI_Expression_SEMI_Expression",NodeType::STATEMENT);
        node->addChildNode($4);
        node->addChildNode($6);
        node->addChildNode($8);
        $$ = node;
    }
    | BREAK SEMI
    {
        BaseNode * node = new BaseNode ("Break_Statement",NodeType::STATEMENT);
        $$ = node;
    }
    | CONTINUE SEMI
    {
        BaseNode * node = new BaseNode ("Continue_Statement",NodeType::STATEMENT);
        $$ = node;
    }
    | PRINTF '(' D_QUO expression D_QUO ')' SEMI
    {
        BaseNode * node = new BaseNode ("Printf_String",NodeType::STATEMENT);
        node->addChildNode($4);
        $$ = node;
    }
    | PRINTF '(' expression ')' SEMI
    {
        BaseNode * node = new BaseNode ("Printf_Expression",NodeType::STATEMENT);
        node->addChildNode($3);
        $$ = node;
    }
    | SCANF '(' IDENTIFIER ')' SEMI
    {
        BaseNode * node = new BaseNode ("Scanf_Identifier",NodeType::STATEMENT);
        BaseNode * Identifier_Node = new BaseNode ($3,NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
;
//声明语句
declare:
    //标识符 要声明的东西的序列
    descriptor declares
    {
        // // printf("Declare_Statement\n");
        BaseNode * node = new BaseNode("Declare_Statement",NodeType::DEFINITION);

        node->addChildNode($1);
        node->addChildNode($2);
        $$ = node;
    }
;
//要声明的东西的序列
declares:
    //id或者id赋值
    declarevars
    {
         // printf("declarevars\n");
        BaseNode * node = new BaseNode("Declare_Variable",NodeType::DEFINITION);
        node->addChildNode($1);
        $$ = node;
    }
    | declarevars COMMA declares
    {
         // printf("declarevars COMMA declares\n");
        BaseNode * node = new BaseNode("Declare_Variables",NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
;
//id或者id赋值
declarevars:
    //id
    variable
    {
        BaseNode * node = new BaseNode("Variable",NodeType::DEFINITION);
        node->addChildNode($1);
        $$ = node;
    }
    //id与赋值语句
    | variable ASSIGN_OP expression
    {
        BaseNode * node = new BaseNode("Variable_Assign",NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
;
forstart:
    declare
    {
        // printf("declares\n");
        BaseNode * node = new BaseNode("For_Declare",NodeType::DEFINITION);
        node->addChildNode($1);
        $$ = node;
    }
    | expression
    {
        // printf("expression\n");
        BaseNode * node = new BaseNode("For_Expression",NodeType::EXPRESSION);
        node->addChildNode($1);
        $$ = node;
    }
    ;

expression:
    CONST
    {
        BaseNode * node = new BaseNode("Constant_Expression",NodeType::EXPRESSION);
        BaseNode * Constant_Node = new BaseNode ($1,NodeType::CONST_INT);
        node->addChildNode(Constant_Node);
        $$ = node;
    }
    | identifiers
    {
        BaseNode * node = new BaseNode("Identifier_Expression",NodeType::EXPRESSION);
        node->addChildNode($1);
        $$ = node;
    }
    | expression ASSIGN_OP expression
    {
        BaseNode * node = new BaseNode("Assign",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '+' expression
    {
        BaseNode * node = new BaseNode("Add",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '-' expression
    {
        BaseNode * node = new BaseNode("Sub",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '*' expression
    {
        BaseNode * node = new BaseNode("Mul",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    |expression '/' expression
    {
        BaseNode * node = new BaseNode("Div",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '%' expression
    {
        BaseNode * node = new BaseNode("Mod",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | '(' expression ')'
    {
        BaseNode * node = new BaseNode("Braces",NodeType::EXPRESSION);
        node->addChildNode($2);
        $$ = node;
    }
    | '-' expression
    {
        BaseNode * node = new BaseNode("Negative",NodeType::OPERATION);
        node->addChildNode($2);
        $$ = node;
    }
    | expression AND expression
    {
        BaseNode * node = new BaseNode("And",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression OR expression
    {
        BaseNode * node = new BaseNode("Or",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | '!' expression
    {
        BaseNode * node = new BaseNode("Not",NodeType::OPERATION);
        node->addChildNode($2);
        $$ = node;
    }
    | '{' consts '}'
    {
        BaseNode * node = new BaseNode("{Consts}",NodeType::EXPRESSION);
        node->addChildNode($2);
        $$ = node;
    }
    | expression EQ_OP expression
    {
        BaseNode * node = new BaseNode("Equal_Operation",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression NE_OP expression
    {
        BaseNode * node = new BaseNode("Not_Equal_Operation",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression GT_OP expression
    {   
        BaseNode * node = new BaseNode("Greater_Operation",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression LT_OP expression
    {
        BaseNode * node = new BaseNode("Less_Operation",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression GE_OP expression
    {
        BaseNode * node = new BaseNode("Greater_Equal_Operation",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression LE_OP expression
    {
        BaseNode * node = new BaseNode("Less_Equal_Operation",NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | IDENTIFIER '(' arguments ')'
    {
        BaseNode * node = new BaseNode("Function_Call_With_Agrs",NodeType::CALL);
        BaseNode * Identifier_Node = new BaseNode ($1,NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode($3);
        $$ = node;
    }
    | IDENTIFIER '(' ')'{
        BaseNode * node = new BaseNode("Function_Call_Without_Agrs",NodeType::CALL);
        BaseNode * Identifier_Node = new BaseNode ($1,NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
    | '*' IDENTIFIER
    {
        BaseNode * node = new BaseNode("*id",NodeType::OPERATION);
        BaseNode * Identifier_Node = new BaseNode ($2,NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
    | IDENTIFIER '[' expression ']'
    {
        BaseNode * node = new BaseNode("id[exp]",NodeType::OPERATION);
        BaseNode * Identifier_Node = new BaseNode ($1,NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode($3);
        $$ = node;
    }
    | SINGLAND IDENTIFIER 
    {   
        BaseNode * node = new BaseNode("&id",NodeType::OPERATION);
        BaseNode * Identifier_Node = new BaseNode ($2,NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
    ;
arguments:
    expression 
    {
        BaseNode * node = new BaseNode("Func_Arg",NodeType::ID);
        node->addChildNode($1);
        $$ = node;
    }
    | arguments COMMA expression
    {
        BaseNode * node = new BaseNode("Func_Args",NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    ;
identifiers:
    IDENTIFIER{
        BaseNode * node = new BaseNode("id",NodeType::DEFINITION);
        node->addChildNode(new BaseNode($1,NodeType::ID));
        $$ = node;
    }
    | identifiers IDENTIFIER
    {
        BaseNode * node = new BaseNode("ids",NodeType::DEFINITION);
        node->addChildNode($1);
        BaseNode * id_node = new BaseNode("id",NodeType::DEFINITION);
        node->addChildNode(new BaseNode($2,NodeType::ID));
        node->addChildNode(id_node);
        // node->addChildNode(new BaseNode($2,NodeType::ID));
        $$ = node;
    }
    ;


%%

// void AddOutput(int Row, char* type, char* text){
//     char str[50];
//     sprintf(str, "line%d:(%s, %s)\n", Row, type, text);
//     char *tmp = Ans;
//     Ans = (char *) malloc(strlen(tmp) + strlen(str) + 1);
//     sprintf(Ans, "%s%s", tmp, str);
//     if(strlen(tmp) > 0)
//         free(tmp);
//     return ;
// }