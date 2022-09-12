#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
 std::vector<char> myvector;
 std::vector<char> vector;
 std::vector<char> res;

  vector.push_back('a');
  vector.push_back('b');
  vector.push_back('c');
  vector.push_back('d');
  vector.push_back('e');
  myvector.push_back('f');
  myvector.push_back('j');
  myvector.push_back('h');
  myvector.push_back('i');
  myvector.push_back('j');
  myvector.push_back('k');

 res = myvector + vector;

  std::vector<char>::iterator it = myvector.begin();

  for (; it != myvector.end(); it++)
  {
    std::cout << *it << std::endl;
  }

  return 0;
}
