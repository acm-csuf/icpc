//2013 icpc light switches problem
//niyaz mahmud
//ACCEPTED

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool is_ps(unsigned long int x)
{
	return x == (floor(sqrt(x))*floor(sqrt(x)));
}

bool ps_is_on(unsigned long int x, unsigned long int T)
{
	if (T<x && sqrt(x)<T) return false;
	return true;
}

bool is_on(unsigned long int a, unsigned long int b, unsigned long int c)
{ //a is the bulb in question, b is the elapsed time, c is the number of bulbs
	unsigned long int T = b%c; //T is relevant time
	if (T == 0) return false;
	bool on = false;
	if (is_ps(a))
	{
		if (ps_is_on(a,T)) 
			return true;
		else
			return false;
	}
	if (T>a) return false;
	unsigned long int d = (unsigned long int)(a/T);
	if (d>(unsigned long int)sqrt(a))
		d = (unsigned long int)(ceil(a/d));
	for (unsigned long int i = 1; i <= d; ++i)
		if (a%i==0) 
			on=!on;
	if (on)
		return true;
	return false;
}

int main()
{
	int test_case = 0;
	unsigned long int a,b,c;
	while(cin >> c >> b >> a)
	{
		++test_case;
		cout << "Case " << test_case << ": ";
		if (is_on(a,b,c)) cout << "On";
		else cout << "Off";
		cout << endl;
	}
	return 0;
}
