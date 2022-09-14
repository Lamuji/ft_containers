#include <iostream>
#include "vector/enable_if.hpp"
#include "vector/is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
 ft::vector<char> myvector;
 std::vector<char> vector;

  vector.push_back('a');
  vector.push_back('b');
  vector.push_back('c');
  vector.push_back('d');
  vector.push_back('e');

  myvector.push_back('a');
  myvector.push_back('b');
  myvector.push_back('c');
  myvector.push_back('d');
  myvector.push_back('e');

  vector.erase(vector.end() - 3, vector.end() - 1);
  myvector.erase(myvector.end() - 3, myvector.end() - 1);

  ft::vector<char>::iterator myit = myvector.begin();
  std::vector<char>::iterator it = vector.begin();

  std::cout << "MY VECTOR ERASE\n";
  for (; myit != myvector.end(); myit++)
  {
    std::cout << *myit << std::endl;
  }
  std::cout << "========================\n";
  for (; it != vector.end(); it++)
  {
    std::cout << *it << std::endl;
  }

  return 0;
}
