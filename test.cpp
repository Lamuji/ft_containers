#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector/vector.hpp"
#include <vector>

using namespace std;

int main() 
{
	ft::vector<int> myvector (20);

	myvector[0] = 1;
	myvector[1] = 2;
	myvector[2] = 3;
	myvector[3] = 4;
	myvector[4] = 5;
	myvector[5] = 5;
	myvector[6] = 6;
	myvector[7] = 7;
	myvector[8] = 8;
	myvector[9] = 9;
	myvector[10] = 10;
	myvector[11] = 11;
	ft::vector<int>::iterator it = myvector.begin() + 4;
	ft::vector<int>::iterator it2 = myvector.begin() + 9;
	myvector.insert(myvector.begin() + 1, it, it2);

	for (size_t i = 0; i < myvector.size(); i++)
		cout << myvector[i] << endl;

	ft::vector<int> newvector(20);
	myvector.swap(newvector);
	cout << "new vector\n";
	for (size_t i = 0; i < myvector.size(); i++)
		cout << myvector[i] << endl;
	cout << "old\n";
	for (size_t i = 0; i < newvector.size(); i++)
		cout << newvector[i] << endl;

  return 0;
}
