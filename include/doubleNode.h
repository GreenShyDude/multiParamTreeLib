#include <string>

namespace mpt {
  
/*
 * doubleNode Class Declaration
 * for each tree branch there is a dedicate doubleNode Pointer
 * to do:
 * - convert the class into a template class with two typpe of parameters and 
 * - compressing parameter pointers into a dynamic pointer (?) *
*/

  class doubleNode {
    int param1;
    std::string param2;
    doubleNode * left1;
    doubleNode * right1;
    doubleNode * left2;
    doubleNode * right2;
    doubleNode * peer1l;
    doubleNode * peer1r;
    doubleNode * peer2l;
    doubleNode * peer2r;

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
}
