#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;


int main() 
{
	ft::vector<int> titi(100);
	cout << titi.capacity();

	// ft::vector<int> toto(10);
	// int *i = toto.data();
	// for (int b = 0; b < 4; b++)
	// {
	// 	i++;
	// 	std::cout << *i << std::endl;
	// }
	// cout<< toto.size() << endl;
	// toto.resize(15);
	// cout<< toto.size() << endl;
  return 0;
}
