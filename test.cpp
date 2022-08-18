#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
	ft::vector<int> titi(5);
	titi[0] = 1;
	titi[1] = 3;
	titi[2] = 5;
	titi[3] = 42;
	titi[4] = 11;

cout << titi.back() << endl;



  //int *i = titi.data();


  // for (int b = 0; b < 4; b++)
  // {
  //   std::cout << *i << std::endl;
  //   i++;
  // }
  // cout << titi.size() << endl;
  // titi.resize(12);
  // cout << titi.capacity() << endl;
  // cout << titi.size() << endl;
  // cout << toto.empty() << endl;

  // titi.push_back(5);
  // titi.push_back(7);
  // titi.push_back(4);
  // titi.push_back(9);

  // ft::vector<int> toto(4, 100);
  // int *i = toto.data();
  // for (int b = 0; b < 4; b++)
  // {
  //   i++;
  //   std::cout << *i << std::endl;
  // }
  // std::cout << toto.max_size() << std::endl;
  // std::cout << titi.max_size() << std::endl;
  //return 0;
}
