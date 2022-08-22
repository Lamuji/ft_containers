#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
  ft::vector<int> toto(10, 5);
  std::cout << *toto.begin() << std::endl;
  return 0;
}
