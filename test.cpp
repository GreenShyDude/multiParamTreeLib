#include <stdlib.h>
#include <iostream>
#include <string>
#include "include/doubleNode.h"
#include "include/multiNode.h"
#include <vector>
#include <functional>

int main () {
  std::vector<multiNode<int> *> tree2;
  std::vector<std::vector<int>> par = {
    {1, 1, 1, 1},
    {1, 2 ,2 ,1},
    {1 ,4, 1, 4},
    {1, -1, -2 , -4},
    {1, -1, -2 , -4},
    {2, -5, -2 , -2},
    {11, 1, -2 , 6}, 
    {1, 6, 1, 7}, 
    {17, 25 ,2 ,1},
    {1 ,4, 21, 4},
    {15, -16, -2 , -4},
    {1, -61, -2 , -42},
    {111, -211, -2 , -4},
    {1,-61, -662 , -42},
    {1, 1, 11, 1},
    {6, 26 ,2 ,1},
    {1 ,45, 1, 4},
    {1, -1, -22 , -74},
    {12, -12, -26 , -477},
    {32, -5, -2 , -22},
    {1661, 1, -211 , 6}, 
    {1, 6, -13, 72}, 
    {157, 265 ,2 ,16}, 
    {-15 ,54, 21, 4}, 
    {-555, -216, -2 , -54}, 
    {51, -621, -52 , -462}, 
    {-1611, -6211, -22 , -42}, 
    {53,-65, -65 , -42}
  };
  std::function<comp_ret(int,int)> lambda = [](int a, int b) {
    if (a > b) return HIGHER;
    else if (a<b) return LOWER;
    else return EQUAL;
  };
  std::system("clear");
  std::cout << std::flush;

  for (int i = 0; i < par.size(); i++) tree2.push_back(new multiNode<int>(par[i],lambda));
  for (int i = 1; i < tree2.size(); i++) tree2[0]->addNode(tree2[i]);
  for (int i = 0; i < tree2[0]->getNumParams(); i++)tree2[0]->printTreePX(i);
  for (int i = tree2.size() -1; i >= 0; i--) delete tree2[i];
  return 0;
}
