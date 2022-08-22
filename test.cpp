#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it = myvector.begin();

	//myvector.insert(myvector.end(), 4, 10);

  return 0;
}
