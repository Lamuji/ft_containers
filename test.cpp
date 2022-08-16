#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>



int main() 
{
  std::vector<int> titi;
  titi.push_back(5);
  titi.push_back(7);
  titi.push_back(4);
  titi.push_back(9);

  ft::vector<int> toto(4, 100);
  int *i = toto.data();
  for (int b = 0; b < 4; b++)
  {
    i++;
    std::cout << *i << std::endl;
  }
  return 0;
}
