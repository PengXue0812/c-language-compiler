#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../Node/NodeType.h"

enum class SymbolType {
  integer = 1,
  var = 2,
  temp_var = 3,
  pointer = 4,
  array = 5,
  boolean,
  Void,
  function_name,
};

class Symbol {
 private:
  std::string idName;
  SymbolType idType;
  int width;
  int pointerAddr;
  std::string value;
  bool isUsed;

 public:
  Symbol();  //默认为int类型
  Symbol(std::string name, SymbolType type = SymbolType::var, int width = 4,
         std::string init_value = "0");
  std::string getIdName() { return this->idName; }
  SymbolType& getSymbolType() { return this->idType; }
  int getWidth() { return this->width; }
  void setWidth(int width) { this->width = width; }
  int getPointerAddr() { return this->pointerAddr; }
  void setPointerAddr(int addr) { this->pointerAddr = addr; }
  void showSymbolInfor();
  void setIsUsed() { this->isUsed = true; }
  bool getIsUsed() { return this->isUsed; }
};
class SymbolArea {
 private:
  std::unordered_map<std::string, Symbol*> SymbolMap;
  // std::vector<Symbol*> *symbolArray;
  // std::vector<Symbol*> *argArray;
  SymbolArea* parentArea;
  SymbolArea* firstChildArea;
  SymbolArea* firstBrotherArea;
  static int total_offset;
  int symbolNumber;
  SymbolArea* baseArea;

 public:
  SymbolArea();
  Symbol* findSymbolLocally(std::string name);
  Symbol* findSymbolGlobally(std::string name);
  bool addSymbol(Symbol* symbol);
  SymbolArea* getParentArea();
  SymbolArea* getFirstChildArea();
  SymbolArea* getFirstBrotherArea();
  SymbolArea* getBaseArea();
  
  int getSymbolNumber();
  int setOffset(int offset);
  int getOffset();
  void setParentArea(SymbolArea* parent);
  void setFirstBrotherArea(SymbolArea* brother);
  SymbolArea* addNewChildArea();
  void showSymbolArea();
};
#endif