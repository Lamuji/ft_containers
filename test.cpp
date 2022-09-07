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
	ft::vector<int>::iterator it = myvector.begin() + 4;

	 it = myvector.insert ( it , 200 );
	//myvector.insert(it, 2, 10);
 	cout << *it << endl << endl;
	for (size_t i = 0; i < myvector.size(); i++)
		cout << myvector[i] << endl;
	cout << '\n';
	cout << '\n';
	cout << *myvector.erase(it) << endl;

	for (size_t i = 0; i < myvector.size(); i++)
		cout << myvector[i] << endl;
//	myvector.assign(vec.begin(),vec.end());

  return 0;
}
