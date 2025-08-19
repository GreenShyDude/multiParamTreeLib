#include <stdlib.h>
#include <iostream>
#include <string>
#include "include/doubleNode.h"
#include "include/multiNode.h"
#include <vector>
#include <functional>

int main () {
  int base_ind = 4;
  std::vector<multiNode<int> *> tree2;
  std::vector<int> par = {0, 0, 0, 0};
  std::function<comp_ret(int,int)> lambda = [](int a, int b) {
    if (a > b) return HIGHER;
    else if (a<b) return LOWER;
    else return EQUAL;
  };
  std::system("clear");
  std::cout << std::flush;

  for (int i = 0; i < base_ind; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << "insert param (integer) " << j << ": " ;
      std::cin >> par[j];
    }
    tree2.push_back(new multiNode<int>(par,lambda));
  }
  for (int i = 1; i < tree2.size(); i++) {
    tree2[0]->addNode(tree2[i]);
  }
  for (int i = 0; i < base_ind; i++) {
    tree2[0]->printTreePX(i);
  }
  for (int i = 0; i < tree2.size(); i++) {
    delete tree2[i];
  }
 return 0;
}
