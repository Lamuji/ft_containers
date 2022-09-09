#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
 ft::vector<int> myvector;

  myvector.push_back(1);
  myvector.push_back(2);
  myvector.push_back(3);
  myvector.push_back(4);
  myvector.push_back(5);
  myvector.push_back(6);
  myvector.push_back(8);
  myvector.push_back(1);
  myvector.push_back(9);
  myvector.push_back(10);
  myvector.push_back(11);

  cout << *myvector.erase(myvector.begin() + 1, myvector.begin() + 3) << endl;

  ft::vector<int>::iterator it = myvector.begin();

  for (; it != myvector.end(); it++)
  {
    std::cout << *it << std::endl;
  }

  return 0;
}
