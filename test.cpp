#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
	ft::vector<int> myvector (10);

	myvector[0] = 1;
	myvector[1] = 2;
	myvector[2] = 3;
	myvector[3] = 4;
	myvector[4] = 5;
	myvector[5] = 6;
	myvector[6] = 7;
	myvector[7] = 8;
	myvector[8] = 9;
	
	myvector.erase(myvector.begin() + 1, myvector.begin() + 5);

	for (size_t i = 0; i < myvector.size(); i++)
		cout << myvector[i] << endl;

  return 0;
}
