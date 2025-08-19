#include <vector>
#include <functional>

enum comp_ret {EQUAL, LOWER, HIGHER};
template <typename T>
class multiNode{
public:
  multiNode(std::vector<T>, std::function<comp_ret(T,T)>);
  //~multiNode();
  int getNumParams();  
  bool addNode(multiNode *);
  void printTreePX(int );

private:
  std::vector<T> params;
  std::vector<multiNode *> left;
  std::vector<multiNode *> right;
  std::vector<multiNode *> peers_left;
  std::vector<multiNode *> peers_right;
  std::function<comp_ret(T,T)>compare; //must return one of comp_ret values
  
  bool addNodeIter(multiNode *, multiNode *, int);
  bool addPeerNode(multiNode *, multiNode *, int);
  void printTreeIter(multiNode *, int);
  void printPeer(multiNode *, int);
  
  
};

#include "../modules/multiNode.cpp"

