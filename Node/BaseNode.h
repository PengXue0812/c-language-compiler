#ifndef _BASENODE_H_
#define _BASENODE_H_
#include <stdio.h>
#include <stdlib.h>

#include <list>
#include <string>

#include "NodeType.h"
namespace AST {
class BaseNode {
 private:
  int depth;
  NodeType type;
  BaseNode *pNode;
  BaseNode *bNode;
  BaseNode *cNode;

 protected:
  char *content;

  static void tree(BaseNode *, int, bool, bool *, char *);

 public:
  // constructors:
  BaseNode();

  BaseNode(NodeType);

  BaseNode(const char *, NodeType);

  BaseNode(const char *);

  // setters:
  bool setParentNode(BaseNode *parent) {
    this->pNode = parent;
    return true;
  }
  bool addChildNode(BaseNode *);

  bool addBrotherNode(BaseNode *);

  // getters:
  BaseNode *getFinalBrotherNode();

  NodeType getNodeType() { return this->type; }

  char *getContent() { return this->content; }
  std::string getStringContent() {
    std::string s(this->content);
    return s;
  }

  std::list<BaseNode *> getAllChildrenNode();
  BaseNode *getChildNode() { return this->cNode; }

  BaseNode *getParentNode() { return this->pNode; }

  BaseNode *getBrotherNode() { return this->bNode; }

  // printers:
  void printTree(BaseNode *);

  void printInfo();

  // deconstructor:
  ~BaseNode();
};
}  // namespace AST
#endif