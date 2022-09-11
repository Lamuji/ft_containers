#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
 ft::vector<char> myvector;

  myvector.push_back('a');
  myvector.push_back('b');
  myvector.push_back('c');
  myvector.push_back('d');
  myvector.push_back('e');
  myvector.push_back('f');
  myvector.push_back('j');
  myvector.push_back('h');
  myvector.push_back('i');
  myvector.push_back('j');
  myvector.push_back('k');

  myvector.erase(myvector.begin() + 1, myvector.begin() + 3);

  ft::vector<char>::iterator it = myvector.begin();

  for (; it != myvector.end(); it++)
  {
    std::cout << *it << std::endl;
  }

  return 0;
}
