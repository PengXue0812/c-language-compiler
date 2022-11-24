#include "BaseNode.h"

#include <cstring>
#include <iostream>

#include "BTNode.h"

BaseNode::BaseNode() {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->content = strdup("code start");
}

BaseNode::BaseNode(const char* content) {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->content = strdup(content);
}
BaseNode::BaseNode(NodeType type) {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->type = type;
  this->content = strdup("");
}
BaseNode::BaseNode(const char* content, NodeType type) {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->type = type;
  this->content = strdup(content);
}
bool BaseNode::addFirstBrotherNode(BaseNode* node) {
  BaseNode* temp = this->bNode;
  this->bNode = node;
  node->bNode = temp;
  return true;
}
bool BaseNode::addLastBrotherNode(BaseNode* node) {
  BaseNode* temp = this->getFinalBrotherNode();
  temp->bNode = node;
  return true;
}

bool BaseNode::addChildNode(BaseNode* node) {
  if (this->cNode == nullptr) {
    this->cNode = node;
    node->pNode = this;
  } else {
    this->cNode->addLastBrotherNode(node);
  }
  return true;
}

void BaseNode::printInfo() { printf("%s", this->content); }

// void BaseNode::printTree(BaseNode* node) {
//   printf("%s ", node->content);
//   if (node->bNode) {
//     printTree(node->bNode);
//   }
//   if (node->cNode) {
//     printf("\n");
//     printTree(node->cNode);
//     printf("\n");
//   }
// }
void BaseNode::printTree(BaseNode* node) {
  if (node) {
    printf("%s ", node->content);
    if (node->cNode) {
      printf("(");
      BaseNode* p = node->cNode;
      printTree(p);
      p = p->bNode;
      while (p) {
        printf(",");
        printTree(p);
        p = p->bNode;
      }
      printf(")");
    }
  }
}
BaseNode* BaseNode::getFinalBrotherNode() {
  BaseNode* node = this;
  while (node->bNode) {
    node = node->bNode;
  }
  return node;
}
BaseNode::~BaseNode() {
  while (this->bNode) {
    free(this->bNode);
  }
  while (this->cNode) {
    free(this->cNode);
  }
}

std::list<BaseNode*> BaseNode::getAllChildrenNode() {
  std::list<BaseNode*> children;
  BaseNode* node = this->cNode;
  while (node) {
    children.push_back(node);
    node = node->bNode;
  }
  return children;
}
// int main() {
//   using namespace AST;
//   char* a = strdup("root");
//   BaseNode* node = new BaseNode(a);
//   BaseNode* childNode[10];
//   char** b = new char*[10];
//   for (int i = 0; i < 10; i++) {
//     b[i] = new char{(char)('0' + i)};
//     childNode[i] = new BaseNode(b[i]);
//     node->addChildNode(childNode[i]);
//   }
//   BaseNode* child0 = childNode[0];
//   for (int j = 0; j < 10; j++) {
//     b[j] = new char{(char)('a' + j)};
//     childNode[j] = new BaseNode(b[j]);
//     child0->addChildNode(childNode[j]);
//   }
//  child0->addFirstBrotherNode(new BaseNode("brother"));
//   BTTree<BaseNode> printer(node, &BaseNode::getAllChildrenNode,
//                            &BaseNode::getStringContent);
//   printer.print();
//   //   node->printTree(node);
//   return 0;
// }