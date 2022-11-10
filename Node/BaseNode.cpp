#include "BaseNode.h"
#include <cstring>
#include "BTNode.h"


AST::BaseNode::BaseNode() {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->content = strdup("code start");
}

AST::BaseNode::BaseNode(const char* content) {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->content = strdup(content);
}
AST::BaseNode::BaseNode(NodeType type) {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->type = type;
  this->content = strdup("");
}
AST::BaseNode::BaseNode(const char* content, NodeType type) {
  this->cNode = nullptr;
  this->pNode = nullptr;
  this->bNode = nullptr;
  this->type = type;
  this->content = strdup(content);
}
bool AST::BaseNode::addBrotherNode(AST::BaseNode* node) {
  BaseNode* temp = this;
  while (temp->bNode != nullptr) {
    temp = temp->bNode;
  }
  temp->bNode = node;
  node->pNode = this->pNode;
  return true;
}

bool AST::BaseNode::addChildNode(AST::BaseNode* node) {
  if (this->cNode == nullptr) {
    this->cNode = node;
    node->pNode = this;
  } else {
    this->cNode->addBrotherNode(node);
  }
  return true;
}

void AST::BaseNode::printInfo() { printf("%s", this->content); }

//void AST::BaseNode::printTree(BaseNode* node) {
//  printf("%s ", node->content);
//  if (node->bNode) {
//    printTree(node->bNode);
//  }
//  if (node->cNode) {
//    printf("\n");
//    printTree(node->cNode);
//    printf("\n");
//  }
//}
void AST::BaseNode::printTree(BaseNode* node) {
    if (node)
    {
        printf("%s ", node->content);
        if (node->cNode)
        {
            
            printf("(");
            BaseNode* p = node->cNode;
            printTree(p);
            p = p->bNode;
            while (p)
            {
                printf(",");
                printTree(p);
                p = p->bNode;
            }
            printf(")");
        }
    }
}
AST::BaseNode* AST::BaseNode::getFinalBrotherNode() {
  AST::BaseNode* node = this;
  while (node->bNode) {
    node = node->bNode;
  }
  return node;
}
AST::BaseNode::~BaseNode() {
  while (this->bNode) {
    free(this->bNode);
  }
  while (this->cNode) {
    free(this->cNode);
  }
}

std::list<BaseNode*> AST::getAllChildrenNode(){
  std::list<BaseNode>children;
  BaseNode*node = this->cNode;
  children.push_back(node);
  while(node->bNode){
    children.push_back(node);
    node = node->bNode;
  }
  return children;
}
int main() {
  using namespace AST;
  char* a = strdup("root");
  BaseNode* node = new BaseNode(a);
  BaseNode* childNode[10];
  char** b = new char*[10];
  for (int i = 0; i < 10; i++) {
    b[i] = new char{(char)('0' + i)};
    childNode[i] = new BaseNode(b[i]);
    node->addChildNode(childNode[i]);
  }
  BaseNode* child0 = childNode[0];
  for (int j = 0; j < 10; j++) {
    b[j] = new char{(char)('a' + j)};
    childNode[j] = new BaseNode(b[j]);
    child0->addChildNode(childNode[j]);
  }
  
	BTTree<BaseNode> printer(head, &BaseNode::getChildren, &BaseNode::getStringContent);
	printer.print();
  node->printTree(node);
}