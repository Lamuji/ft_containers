#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
	ft::vector<int> titi;
	std::vector<int> toto(10);
	toto[0] = 11;
	toto[1] = 14;
	toto[2] = 16;
	toto[3] = 111;
	toto[4] = 21;
	toto[5] = 69;
	toto[6] = 15;
	toto[7] = 14;
	toto[8] = 10;
	toto[9] = 22;

	titi.assign(toto.begin(), toto.end());
 	titi.push_back(32);
	//titi.pop_back();
	for (size_t i = 0 ; i < titi.size(); i++){
		cout << titi[i] << endl;
	}

// 	// titi.push_back(50);
// 	// titi.assign(6,30);

// cout << titi[10] << endl;
// cout << titi.size() << endl;
// titi.pop_back();
// cout << titi.size() << endl;
// cout << titi[10] << endl;


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
