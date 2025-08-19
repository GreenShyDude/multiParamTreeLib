#include <vector>
#include <functional>

/* enumerator for compare functuon return values
 * used to keep under controll the output and have consistent switch case with a limited range of values 
 * provide quality of life to devs improveing readability of the code ealso while consulting the source of the library
 */
enum comp_ret {EQUAL, LOWER, HIGHER};

/* ultiNode Class Definition
 * just the definition of the class without any subclass planned
 * to do:
 * - tree branches pointers should be modified into dynamic arrais of pointers => needde implementation of a destructor;
*/ 

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

