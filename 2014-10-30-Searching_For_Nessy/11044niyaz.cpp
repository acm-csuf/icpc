//problem 11044 Searching for nessy
//niyaz mahmud
//ACCEPTED

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int num_cases;
	cin >> num_cases;
	for (int i = 0; i < num_cases; ++i)
	{
		double n, m;
		cin >> n >> m;
		n -= 2;
		m -= 2;
		int result = ceil(n/3)*ceil(m/3);
		cout << result << endl;
	}
	return 0;
}
