#include <vector>
#include <functional>
#include <iostream>

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
template<typename T>
int multiNode<T>::getNumParams() {return params.size();}

template<typename T>
bool multiNode<T>::addNode(multiNode<T> * target) {
  if (target->params.size() != params.size()) return false;
  for (int  i = 0; i < params.size(); i++) if (!addNodeIter(this, target, i)) return false;
  //std::cout << "ADDED" << std::endl;
  return true;
}

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
  //std::cout << "begin" << std::endl;
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
  printPeer(cursor->peers_left[par], par);
  printPeer(cursor->peers_right[par], par);
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
