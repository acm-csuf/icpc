//problem 11311 Exclusively Edible
//Niyaz Mahmud

#include <iostream>
#include <stdlib.h>
using namespace std;

int cake(int a, int b, int c, int d)
{
	a = a^b;
	c = c^d;
	a = a^c;
	return a;
}

int main()
{
	/*int t=3,u=2,v=8,w=7;
	t = t^u;
	v = v^w;
	cout << t << endl;
	cout << v << endl;*/
	int num_cases,x,y,a,b,c,d;
	cin >> num_cases;
	for (int i = 0; i < num_cases; ++i)
	{
		cin >> x >> y >> a >> c;
		b = x - a - 1;
		d = y - c - 1;
		if (cake(a,b,c,d) != 0) cout << "Gretel" << endl;
		else cout << "Hansel" << endl;
	}
}

