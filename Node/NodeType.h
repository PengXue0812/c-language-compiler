namespace AST {
enum NodeType {
  root = 0,        //根结点
  def_var = 1,     //定义变量
  assign_var = 2,  //调用变量
  def_func = 3,    //定义函数
  call_func = 4,   //调用函数
  op = 5,          //操作符
  stmt = 6,        //语句类型
  loop = 7,        //循环类型
  select = 8,      //选择类型
  literal = 9,     //字面量
};
}
