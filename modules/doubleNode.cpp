#include <iostream>
#include "../include/doubleNode.h"
#include <string>

/* MAIN doubleNode CONSTRUCTOR
 * limited to just initialize the 
 *
 */ 
doubleNode::doubleNode(int p1, std::string p2) : 
    param1(p1),
    param2(p2),
    left1(nullptr),
    left2(nullptr),
    right1(nullptr),
    right2(nullptr),
    peer1l(nullptr),
    peer1r(nullptr),
    peer2l(nullptr),
    peer1r(nullptr)
  {}

bool doubleNode::addNode(doubleNode *target){
    if (!target) {
      return false;
    }
    if (!this->addNodeP1(this, target)) return false;
    if (!this->addNodeP2(this, target))
    {
      removeNodeP1(this,target);
      return false;
    }
    return true;
  }

bool doubleNode::addNodeP1(doubleNode* cursor,  doubleNode *target) {
    if (cursor->param1 == target->param1) return addPeerP1(cursor, target);
    else if (target->param1 > cursor->param1 ) {
      if (!cursor->left1) {
        cursor->left1 = target;
        return true;
      } else return addNodeP1(cursor->left1, target);
    } else {
       if (!cursor->right1) {
        cursor->right1 = target;
        return true;
      } else return addNodeP1(cursor->right1, target);
    }
}

bool doubleNode::addNodeP2(doubleNode* cursor, doubleNode *target) {
    if (!cursor->param2.compare(target->param2)) return addPeerP2(cursor, target);
    else if (target->param2.compare(cursor->param2) < 0) {
      if (!cursor->left2) {
        cursor->left2 = target;
        return true;
      } else return addNodeP2(cursor->left2, target);
    } else {
       if (!cursor->right2) {
        cursor->right2 = target;
        return true;
      } else return addNodeP2(cursor->right2, target);
    }  
}

bool doubleNode::addPeerP1(doubleNode * cursor, doubleNode * target) {
    int comp = target->param2.compare(cursor->param2);
    if (!comp) return false;
    else if (comp < 0) {
      if (cursor->peer1l) return addPeerP1(cursor->peer1l, target);
      else cursor->peer1l = target; 
    } 
    else {
      if (cursor->peer1r) return addPeerP1(cursor->peer1r, target);
      else cursor->peer1r = target;
    }
    return true;
}

bool doubleNode::addPeerP2(doubleNode * cursor, doubleNode * target) {    
    if (target->param1 == cursor->param1) return false;
    else if (target->param1 > cursor->param1) {
      if (cursor->peer2l) return addPeerP1(cursor->peer2l, target);
      else cursor->peer2l = target; 
    } else {
      if (cursor->peer2r) return addPeerP1(cursor->peer2r, target);
      else cursor->peer2r = target;
    }
    return true;
}

void doubleNode::removeNodeP1(doubleNode* cursor, doubleNode * target) {
    if (!cursor->left1 && !cursor->right1) return;
    if (target == cursor->left1) { 
      cursor->left1 = nullptr;
      addNode(target->left1);
      addNode(target->right1);
    }
    else if (target == cursor->right1) {
      cursor->right1 = nullptr;
      addNode(target->left1);
      addNode(target->right1);
    }
    return (target->param1 > cursor->param1)?removeNodeP1(cursor->left1,target):removeNodeP1(cursor->right1,target);
}

void doubleNode::printTreeP1() {
    printNoodeP1(this->left1);
    std::cout << this->param1 << " |-";
    printPeerP1(this->peer1l);
    std::cout << this->param2 << "-";
    printPeerP1(this->peer1r);
    std::cout << "| ";
    printNoodeP1(this->right1);
    std::cout << std::endl;
}
   
void doubleNode::printTreeP2() {
    printNoodeP2(this->left2);
    std::cout << this->param2 << " |";
    printPeerP2(this->peer2l);
    std::cout << this->param1 << "-";
    printPeerP2(this->peer2r);
    std::cout << "| ";
    printNoodeP2(this->right2);
    std::cout << std::endl;
}

void doubleNode::printPeerP1(doubleNode *Node) {
    if (!Node) return;
    printPeerP1(Node->peer1l);
    std::cout << Node->param2 << "-";
    printPeerP1(Node->peer1r);
} 
void doubleNode::printPeerP2(doubleNode *Node) {
  if (!Node) return;
  printPeerP1(Node->peer2l);
  std::cout << Node->param1 << "-";
  printPeerP1(Node->peer2r);
}

void doubleNode::printNoodeP1(doubleNode *Node) {
    if (!Node) return;
    printNoodeP1(Node->left1);
    std::cout << Node->param1  << " |-";
    printPeerP1(Node->peer1l);
    std::cout << Node->param2  << "-";
    printPeerP1(Node->peer1r);
    std::cout << "| ";
    printNoodeP1(Node->right1);
}

void doubleNode::printNoodeP2(doubleNode *Node) {
    if (!Node) return;
    printNoodeP2(Node->left2);
    std::cout << Node->param2 << " |-"; 
    printPeerP2(Node->peer2l);
    std::cout << Node->param1  << "-";
    printPeerP2(Node->peer2r);
    std::cout << "| ";
    printNoodeP2(Node->right2);
}
