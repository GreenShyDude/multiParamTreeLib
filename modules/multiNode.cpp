#include <vector>
#include <functional>
#include <iostream>

/* TEMPLATE NODE MAIN CONSTURCTORS: 
 * This construtor allows to use vector std library to increse the quality of life of the dev that will use this library
 * 
 * It needs a custom compare function to reduce the responsabilities of the code 
 * To do:
 * - Add default compare that will nened a custom implementation of the < > ==  <= >= operators
 */
template<typename T>
multiNode<T>::multiNode(std::vector<T> n_params, std::function<comp_ret(T,T)> n_cmp) {
  params = n_params;
  for (int i = 0; i < params.size(); i++) {
    left.push_back(nullptr);
    right.push_back(nullptr);
    peers_left.push_back(nullptr);
    peers_right.push_back(nullptr);
  }
  compare = n_cmp;
}

/*
template<typename T>
multiNode::~multiNode() {
}
*/

/* TEMPLATE FUNCTION getNumParams
 * Do i really need to explain this
 */
template<typename T>
int multiNode<T>::getNumParams() {return params.size();}

/* TEMPLATE FUNCTION addNode - Chaining Method
 * Public method to start the insertion of a preinitialized Node
 * 
 * Devs must instantiate a node that they want to add to the tree
 * 
 * Devs are responsable for the tree mantainence
 * 
 * Ideas & Tips:
 * - This implementation allows to implement nodes as elment of an hash table to minmize the time complexity to acces to them
*/
template<typename T>
bool multiNode<T>::addNode(multiNode<T> * target) {
  if (target->params.size() != params.size()) return false;
  for (int  i = 0; i < params.size(); i++) if (!addNodeIter(this, target, i)) return false;
  //std::cout << "ADDED" << std::endl;
  return true;
}

/* TEMPLATE FUNCTION addNodeIter - Chaining Method  
 * Private recursive Iterator for a single given parameter (potensial not recursive implementation in the future) 
 * 
 * It manages through a switch the comparison of the tow nodes for a specific parameter
 * 
 * To do: 
 * - improvement for spatial and time optimization to lower compiling and execution time => possible solution through a template integer parameter
 *
*/
template<typename T>
bool multiNode<T>::addNodeIter(multiNode<T> * cursor, multiNode<T> * target, int par) {
  switch (compare(cursor->params[par],target->params[par])) {
    case HIGHER:
      if (!cursor->right[par]) {
        cursor->right[par] = target;
        break;
      }
      return addNodeIter(cursor->right[par], target, par);
    case LOWER:
      if (!cursor->left[par]) {
        cursor->left[par] = target;
        break;
      }
      return addNodeIter(cursor->left[par], target, par);
    case EQUAL: return addPeerNode(cursor, target, par);
    default:
      std::cout << "ERROR: PROVIDED COMPARE RETURNS NOT VALID VALUES" << std::endl;
      return false; 
  }
  return true;
}

/* TEMPLATE FUNCTION addPeerNode - Chaining Method  
 * Private recursive Iterator for a single given parameter (potensial not recursive implementation in the future) 
 * 
 * It manages through looped a switch the comparison of the tow nodes for every parameter
 * 
 * To do: 
 * - improvement for spatial and time optimization to lower compiling and execution time => possible solution through a template integer parameter
 *
*/
template<typename T>
bool multiNode<T>::addPeerNode(multiNode<T> * cursor, multiNode<T> * target, int par) {
  //std::cout << "ITERATION" << std::endl;
  for (int i = 0; i < params.size(); i++) {
    if (i == par) continue;
    switch (compare(cursor->params[i],target->params[i])) {
      case EQUAL:
      break;
      case HIGHER:
        if (!cursor->peers_right[par]) {
          cursor->peers_right[par] = target;
          return true;
        }
        return addPeerNode(cursor->peers_right[par], target ,par);
      case LOWER:
        if (!cursor->peers_left[par]) {
          cursor->peers_left[par] = target;
          return true;
        }
        return addPeerNode(cursor->peers_left[par], target ,par);
      default:
        std::cout << "ERROR: PROVIDED COMPARE RETURNS NOT VALID VALUES" << std::endl;
        return false; 
    }
  }
  return false;
}

template<typename T>
void multiNode<T>::printTreePX(int par) {
  printTreeIter(this->left[par], par);
  std::cout << this->params[par] << " |-";
  printPeer(this->peers_left[par], par);
  printPeer(this->peers_right[par], par);
  std::cout << "| ";
  printTreeIter(this->right[par], par);
  std::cout << std::endl;
}

template<typename T>
void multiNode<T>::printTreeIter(multiNode<T> *cursor, int par)  {
  //std::cout << "begin iter" << std::endl;
  if (!cursor) return;
  printTreeIter(cursor->left[par], par);
  std::cout << cursor->params[par] << " |-";
  printPeer(cursor, par);
  std::cout << "| ";
  printTreeIter(cursor->right[par], par);
}

template<typename T>
void multiNode<T>::printPeer(multiNode<T> *cursor, int par) {
  if (!cursor) return;
  
  printPeer(cursor->peers_left[par], par);
  for (int i = 0; i < params.size(); i++) {
    if (par !=  i) std::cout << "(" << cursor->params[i] << ")";
    
    std::cout << ( (i==(params.size()-1) || i == par  || ( i == par -1 && par == (params.size() -1) ) )?"":":");   
  }
  std::cout << "-";
  printPeer(cursor->peers_right[par], par);
 
}
