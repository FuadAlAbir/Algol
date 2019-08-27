#include <iostream>
#include <cstdlib>
#include <time.h>

using std::cout;
using std::endl;

int main()
{
	clock_t t;
	t = clock();

	size_t size = 10000000;
	int *pInt = new int[size];
	for(size_t i = 0; i < size; i++)
    {
		pInt[i] = rand();
    }

	t = clock() - t;
	cout << "time: " << t << " miliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

	system("pause");
	delete [] pInt;
	return 0;
}