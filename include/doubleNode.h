#include <string>

class doubleNode {
  int param1;
  std::string param2;
  doubleNode * peer1l;
  doubleNode * peer1r;
  doubleNode * peer2l;
  doubleNode * peer2r;
  doubleNode * left1;
  doubleNode * right1;
  doubleNode * left2;
  doubleNode * right2;
 
  bool addPeerP1(doubleNode * cursor, doubleNode * target); 

  bool addPeerP2(doubleNode * cursor, doubleNode * target);

  bool addNodeP1(doubleNode* cursor,  doubleNode *target);
  
  bool addNodeP2(doubleNode* cursor, doubleNode *target);
  
  void removeNodeP1(doubleNode* cursor, doubleNode * target);
  
  void printPeerP1(doubleNode *Node);
  
  void printPeerP2(doubleNode *Node);

  void printNoodeP1(doubleNode *Node);

  void printNoodeP2(doubleNode *Node);

public:

  doubleNode(int p1, std::string p2);

  bool addNode(doubleNode *target);

  void printTreeP1();
  
  void printTreeP2();

};
