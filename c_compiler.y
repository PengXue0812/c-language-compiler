%{
#include <stdio.h>
#include <string.h>
#include "Node/BaseNode.h"
#include "Node/BTNode.h"
#include "Symbol/SymbolTable.h"
#include "Symbol/Symbol.h"

AST::BaseNode* root;
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
    AST::BaseNode *ast;
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
        root = new AST::BaseNode("program",AST::NodeType::ROOT);
        // root->addChildNode(new AST::BaseNode("test"));
        root->addChildNode($1);
        BTTree<AST::BaseNode> printer(root, &AST::BaseNode::getAllChildrenNode,
                        &AST::BaseNode::getStringContent);
        printer.print();
        dfs(NULL,root);

    };
//语句块的集合
blocks:
    block
    {
        printf("blocks->block\n");
        
        $$= $1;
        // AST::BaseNode *node = new AST::BaseNode("a_Block",AST::NodeType::STATEMENT);
        // node->addChildNode($1);
        // $$ = node;
    }
    | blocks block
    {
        printf("blocks->blocks block\n");
        AST::BaseNode *node =new AST::BaseNode("Blocks",AST::NodeType::STATEMENT);
        node->addChildNode($1);
        node->addChildNode($2);
        // AST::BaseNode * block = new AST::BaseNode("a_Block",AST::NodeType::STATEMENT);
        // block->addChildNode($2);
        // node->addChildNode(block);
        $$ = node;
    }
    ;
//语句块(包括函数定义,全局变量的定义)
block: declare SEMI
    {
        printf("Declare_Statement\n");
        // AST::BaseNode *node = new AST::BaseNode("Declare_Statement",AST::NodeType::DEFINITION);
        // node->addChildNode($1);
        $$ = $1;
    }
    |descriptor function body
    {
        printf("blockcdescriptor function body\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Func_Block_Body",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($2);
        node->addChildNode($3);
        $$ = node;
    }
    |descriptor function SEMI
    {
        printf("block->descriptor function 'SEMI'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Func_Block_NoBody",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($2);
        $$ = node;
    }
//变量
variable:IDENTIFIER
    {   
        printf("variable->IDENTIFIER\n");
        AST::BaseNode * node = new AST::BaseNode("Def_Identifier",AST::NodeType::DEFINITION);
        AST::BaseNode * var_node = new AST::BaseNode($1,AST::NodeType::ID);
        node->addChildNode(var_node);
        $$ = node;
    }
    |IDENTIFIER '[' ']'
    {
        printf("variable->IDENTIFIER '[' ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode($1,AST::NodeType::ID);
        node->addChildNode(var_node);
        $$ = node;
    }
    |IDENTIFIER '[' CONST ']'
    {
        printf("variable->IDENTIFIER '[' CONST ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[Const]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode($1,AST::NodeType::ID);
        // AST::BaseNode * const_node = new AST::BaseNode($3,AST::NodeType::ID);

        AST::BaseNode * const_node = new AST::BaseNode($3, AST::NodeType::CONST_INT);
        node->addChildNode(var_node);
        node->addChildNode(const_node);
        $$ = node;
    }
    |IDENTIFIER '[' expression ']'
    {
        printf("variable->IDENTIFIER '[' expression ']'\n");
        AST::BaseNode * node = new AST::BaseNode("Def_array[expression]",AST::NodeType::ARRAY);
        AST::BaseNode * var_node = new AST::BaseNode($1,AST::NodeType::ID);
        node->addChildNode(var_node);
        node->addChildNode($3);
    }
    |'*' IDENTIFIER
    {
        printf("variable->'*' IDENTIFIER\n");
        AST::BaseNode * node = new AST::BaseNode("Def_*Identifier",AST::NodeType::POINTER);
        AST::BaseNode * var_node = new AST::BaseNode($2,AST::NodeType::ID);
        node->addChildNode(var_node);
        $$ = node;
    }
    ;
//数字的序列(1,2,3,4)    
consts:CONST
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Const_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode($1,AST::NodeType::CONST_INT);
        node->addChildNode(const_node);
        $$ = node;
    }
    |consts COMMA CONST
    {
        // printf("");
        AST::BaseNode * node = new AST::BaseNode("Consts_array",AST::NodeType::EXPRESSION);
        AST::BaseNode * const_node = new AST::BaseNode($3,AST::NodeType::CONST_INT);
        node->addChildNode($1);
        node->addChildNode(const_node);
        $$ = node;
    }
    ;
//标识符
descriptor:INT
    {
        printf("INTTTTTTT\n");
        AST::BaseNode * node = new AST::BaseNode("int_Type",AST::NodeType::MODIFY);
        $$ = node;
    }
    |VOID 
    {
        printf("VOID\n");
        AST::BaseNode * node = new AST::BaseNode("void_type",AST::NodeType::MODIFY);
        $$ = node;
    }
    |INT '*'
    {
        printf("INT* \n");
        AST::BaseNode * node = new AST::BaseNode("int*_Type",AST::NodeType::MODIFY);
        $$ = node;
    }
    ;
//函数的名字与参数列表
function:IDENTIFIER '(' ')'
    {
        printf("Function_Without_Param\n");
        AST::BaseNode * node = new AST::BaseNode("Function_Without_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode($1,AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        $$ = node;
    }
    |IDENTIFIER '(' params ')'
    {
        printf("Function_With_Param\n");
        AST::BaseNode * node = new AST::BaseNode("Function_With_Param",AST::NodeType::DEFINITION);
        AST::BaseNode * IdentifierNode = new AST::BaseNode($1,AST::NodeType::ID);
        node->addChildNode(IdentifierNode);
        node->addChildNode($3);
        $$ = node;
    }
    ;
//参数序列    
params:params COMMA param {
    printf("params: params COMMA param\n");
    AST::BaseNode * node = new AST::BaseNode("Params",AST::NodeType::DEFINITION);
    // AST::BaseNode * param_node = new AST::BaseNode("Single_Param",AST::NodeType::DEFINITION);
    // param_node->addChildNode($3);
    node->addChildNode($1);
    // node->addChildNode(param_node);
    node->addChildNode($3);
    $$ = node;
}
| param {
    printf("params: param\n");
    // AST::BaseNode * node = new AST::BaseNode("Single_Param",AST::NodeType::DEFINITION);
    // node->addChildNode($1);
    // $$ = node;
    $$ = $1;
};
//单个参数     //int a
param:descriptor IDENTIFIER  {
    printf("param:descriptor identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode($2,AST::NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}//int a[10]
|descriptor IDENTIFIER  '[' CONST ']' {
    printf("param:descriptor identifiers '[' CONST ']'\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID[CONST]",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode($2,AST::NodeType::ID);
    AST::BaseNode * ConstNode = new AST::BaseNode($4,AST::NodeType::CONST_INT);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    node->addChildNode(ConstNode);
    $$ = node;
}//int a[]
|descriptor IDENTIFIER  '[' ']' {
    printf("param:descriptor identifiers '[' ']'\n");
    AST::BaseNode * node = new AST::BaseNode("Param_ID[]",AST::NodeType::DEFINITION);
    AST::BaseNode * IdentifierNode = new AST::BaseNode($2,AST::NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}// int &a
|descriptor SINGLAND IDENTIFIER{
    printf("param:descriptor SINGLAND identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("array_&id",AST::NodeType::ARRAY);
    AST::BaseNode * IdentifierNode = new AST::BaseNode($3,AST::NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}//int *a
|descriptor '*' IDENTIFIER{
    printf("param:descriptor SINGLAND '*' identifiers\n");
    AST::BaseNode * node = new AST::BaseNode("array_*id",AST::NodeType::POINTER);
    AST::BaseNode * IdentifierNode = new AST::BaseNode($3,AST::NodeType::ID);
    node->addChildNode($1);
    node->addChildNode(IdentifierNode);
    $$ = node;
}//int 
|descriptor{
    printf("param:descriptor\n");
    AST::BaseNode * node = new AST::BaseNode("param_without_id",AST::NodeType::DEFINITION);
    node->addChildNode($1);
    $$ = node;
};
//语句块    
body:'{' statements '}' {
    printf("body:'{' statements '}'\n");
    AST::BaseNode *node = new AST::BaseNode("Body",AST::NodeType::BODY);
    node->addChildNode($2);
    $$ = node;
};
//句子集 
statements:statements statement {
    printf("statements:statements statement\n");
    AST::BaseNode * node = new AST::BaseNode("Statements",AST::NodeType::STATEMENT);
    // AST::BaseNode * Single_Statement = new AST::BaseNode("Single_Statement",AST::NodeType::STATEMENT);
    // Single_Statement->addChildNode($2);
    node->addChildNode($1);
    // node->addChildNode(Single_Statement);
    node->addChildNode($2);
    $$ = node;
}
|statement {
    printf("statements:statement\n");
    // AST::BaseNode * node = new AST::BaseNode("Single_Statement",AST::NodeType::STATEMENT);
    // node->addChildNode($1);
    $$ = $1;
}
;
// 单个句子
statement:
    //表达式;
    expression SEMI
    {
        AST::BaseNode * node = new AST::BaseNode("Expression",AST::NodeType::STATEMENT);
        node->addChildNode($1);
        $$ = node;
    }
    //声明语句;
    | declare SEMI
    {
        // AST::BaseNode *node = new AST::BaseNode("Declare_Statement",AST::NodeType::STATEMENT);
        // node->addChildNode($1);
        $$ = $1;
    }
    //语句块
    | body
    {
        AST::BaseNode * node = new AST::BaseNode("Body_Statement",AST::NodeType::STATEMENT);
        node->addChildNode($1);
        $$ = node;
    }

    | RETURN expression SEMI
    {
        AST::BaseNode * node = new AST::BaseNode("Return_Expression",AST::NodeType::STATEMENT);
        node->addChildNode($2);
        $$ = node;
    }
    | RETURN SEMI
    {
        AST::BaseNode * node = new AST::BaseNode("Return_NULL",AST::NodeType::STATEMENT);
        $$ = node;
    }
    | IF '(' expression ')' statement
    {
        AST::BaseNode * node = new AST::BaseNode ("If_Statement",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        $$ = node;
    }
    | IF '(' expression ')' statement ELSE statement %prec LOWER_THAN_ELSE{
        AST::BaseNode * node = new AST::BaseNode ("If_Else_Statement",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        node->addChildNode($7);
        $$ = node;
    }
    | WHILE '(' expression ')' statement
    {   
        AST::BaseNode * node = new AST::BaseNode ("While_Statement",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        $$ = node;
    }
    | FOR '(' SEMI SEMI ')' statement
    {
        printf("FOR '(' SEMI SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode($6);
        $$ = node;
    }
    | FOR '(' forstart SEMI SEMI ')' statement
    {
        printf("FOR '(' forstart SEMI SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($7);
        $$ = node;
    } 
    | FOR '(' SEMI expression SEMI ')' statement
    {
        printf("FOR '(' SEMI expression SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode($4);
        node->addChildNode($7);
        $$ = node;
    }
    | FOR '(' SEMI SEMI expression ')' statement
    {
        printf("FOR '(' SEMI SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode($5);
        node->addChildNode($7);
        $$ = node;
    }
    | FOR '(' forstart SEMI expression SEMI expression ')' statement
    {
        printf("FOR '(' forstart SEMI expression SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        node->addChildNode($7);
        node->addChildNode($9);
        $$ = node;
    }
    | FOR '(' forstart SEMI expression SEMI ')' statement
    {
        printf("FOR '(' forstart SEMI expression SEMI ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_Expression_SEMI",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($5);
        node->addChildNode($8);
        $$ = node;
    }
    | FOR '(' forstart SEMI SEMI expression ')' statement
    {
        printf("FOR '(' forstart SEMI SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_Def_SEMI_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        node->addChildNode($6);
        node->addChildNode($8);
        $$ = node;
    }
    | FOR '(' SEMI expression SEMI expression ')' statement
    {
        printf("FOR '(' SEMI expression SEMI expression ')' statement\n");
        AST::BaseNode * node = new AST::BaseNode ("For_SEMI_Expression_SEMI_Expression",AST::NodeType::STATEMENT);
        node->addChildNode($4);
        node->addChildNode($6);
        node->addChildNode($8);
        $$ = node;
    }
    | BREAK SEMI
    {
        AST::BaseNode * node = new AST::BaseNode ("Break_Statement",AST::NodeType::STATEMENT);
        $$ = node;
    }
    | CONTINUE SEMI
    {
        AST::BaseNode * node = new AST::BaseNode ("Continue_Statement",AST::NodeType::STATEMENT);
        $$ = node;
    }
    | PRINTF '(' D_QUO expression D_QUO ')' SEMI
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_String",AST::NodeType::STATEMENT);
        node->addChildNode($4);
        $$ = node;
    }
    | PRINTF '(' expression ')' SEMI
    {
        AST::BaseNode * node = new AST::BaseNode ("Printf_Expression",AST::NodeType::STATEMENT);
        node->addChildNode($3);
        $$ = node;
    }
    | SCANF '(' IDENTIFIER ')' SEMI
    {
        AST::BaseNode * node = new AST::BaseNode ("Scanf_Identifier",AST::NodeType::STATEMENT);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ($3,AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
;
//声明语句
declare:
    //标识符 要声明的东西的序列
    descriptor declares
    {
        // printf("Declare_Statement\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Statement",AST::NodeType::DEFINITION);

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
         printf("declarevars\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Variable",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        $$ = node;
    }
    | declarevars COMMA declares
    {
         printf("declarevars COMMA declares\n");
        AST::BaseNode * node = new AST::BaseNode("Declare_Variables",AST::NodeType::DEFINITION);
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
        AST::BaseNode * node = new AST::BaseNode("Variable",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        $$ = node;
    }
    //id与赋值语句
    | variable ASSIGN_OP expression
    {
        AST::BaseNode * node = new AST::BaseNode("Variable_Assign",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
;
forstart:
    declare
    {
        printf("declares\n");
        AST::BaseNode * node = new AST::BaseNode("For_Start",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        $$ = node;
    }
    | expression
    {
        printf("expression\n");
        AST::BaseNode * node = new AST::BaseNode("For_Expression",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        $$ = node;
    }
    ;

expression:
    CONST
    {
        AST::BaseNode * node = new AST::BaseNode("Constant_Expression",AST::NodeType::EXPRESSION);
        AST::BaseNode * Constant_Node = new AST::BaseNode ($1,AST::NodeType::CONST_INT);
        node->addChildNode(Constant_Node);
        $$ = node;
    }
    | identifiers
    {
        AST::BaseNode * node = new AST::BaseNode("Identifier_Expression",AST::NodeType::EXPRESSION);
        node->addChildNode($1);
        $$ = node;
    }
    | expression ASSIGN_OP expression
    {
        AST::BaseNode * node = new AST::BaseNode("Assign",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '+' expression
    {
        AST::BaseNode * node = new AST::BaseNode("Add",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '-' expression
    {
        AST::BaseNode * node = new AST::BaseNode("Sub",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '*' expression
    {
        AST::BaseNode * node = new AST::BaseNode("Mul",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    |expression '/' expression
    {
        AST::BaseNode * node = new AST::BaseNode("Div",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression '%' expression
    {
        AST::BaseNode * node = new AST::BaseNode("Mod",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | '(' expression ')'
    {
        AST::BaseNode * node = new AST::BaseNode("Braces",AST::NodeType::EXPRESSION);
        node->addChildNode($2);
        $$ = node;
    }
    | '-' expression
    {
        AST::BaseNode * node = new AST::BaseNode("Negative",AST::NodeType::OPERATION);
        node->addChildNode($2);
        $$ = node;
    }
    | expression AND expression
    {
        AST::BaseNode * node = new AST::BaseNode("And",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression OR expression
    {
        AST::BaseNode * node = new AST::BaseNode("Or",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | '!' expression
    {
        AST::BaseNode * node = new AST::BaseNode("Not",AST::NodeType::OPERATION);
        node->addChildNode($2);
        $$ = node;
    }
    | '{' consts '}'
    {
        AST::BaseNode * node = new AST::BaseNode("{Consts}",AST::NodeType::EXPRESSION);
        node->addChildNode($2);
        $$ = node;
    }
    | expression EQ_OP expression
    {
        AST::BaseNode * node = new AST::BaseNode("Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression NE_OP expression
    {
        AST::BaseNode * node = new AST::BaseNode("Not_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression GT_OP expression
    {   
        AST::BaseNode * node = new AST::BaseNode("Greater_Operation",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression LT_OP expression
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Operation",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression GE_OP expression
    {
        AST::BaseNode * node = new AST::BaseNode("Greater_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | expression LE_OP expression
    {
        AST::BaseNode * node = new AST::BaseNode("Less_Equal_Operation",AST::NodeType::OPERATION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    | IDENTIFIER '(' arguments ')'
    {
        AST::BaseNode * node = new AST::BaseNode("Function_Call_With_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ($1,AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode($3);
        $$ = node;
    }
    | IDENTIFIER '(' ')'{
        AST::BaseNode * node = new AST::BaseNode("Function_Call_Without_Agrs",AST::NodeType::CALL);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ($1,AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
    | '*' IDENTIFIER
    {
        AST::BaseNode * node = new AST::BaseNode("*id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ($2,AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
    | IDENTIFIER '[' expression ']'
    {
        AST::BaseNode * node = new AST::BaseNode("id[exp]",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ($1,AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        node->addChildNode($3);
        $$ = node;
    }
    | SINGLAND IDENTIFIER 
    {   
        AST::BaseNode * node = new AST::BaseNode("&id",AST::NodeType::OPERATION);
        AST::BaseNode * Identifier_Node = new AST::BaseNode ($2,AST::NodeType::ID);
        node->addChildNode(Identifier_Node);
        $$ = node;
    }
    ;
arguments:
    expression 
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Arg",AST::NodeType::ID);
        node->addChildNode($1);
        $$ = node;
    }
    | arguments COMMA expression
    {
        AST::BaseNode * node = new AST::BaseNode("Func_Args",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        node->addChildNode($3);
        $$ = node;
    }
    ;
identifiers:
    IDENTIFIER{
        AST::BaseNode * node = new AST::BaseNode("id",AST::NodeType::DEFINITION);
        node->addChildNode(new AST::BaseNode($1,AST::NodeType::ID));
        $$ = node;
    }
    | identifiers IDENTIFIER
    {
        AST::BaseNode * node = new AST::BaseNode("ids",AST::NodeType::DEFINITION);
        node->addChildNode($1);
        AST::BaseNode * id_node = new AST::BaseNode("id",AST::NodeType::DEFINITION);
        node->addChildNode(new AST::BaseNode($2,AST::NodeType::ID));
        node->addChildNode(id_node);
        // node->addChildNode(new AST::BaseNode($2,AST::NodeType::ID));
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