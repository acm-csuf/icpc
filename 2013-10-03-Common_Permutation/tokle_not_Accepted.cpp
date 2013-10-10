#include <iostream>
#include <string>
#include <algorithm>
using namespace std;




int main ()
{
	string a;
	string b;
	string x;
	
	while(true)
	{
		cin >>a;
		if (cin.fail()) 
			return 0;
		cin >>b;
		if (cin.fail()) 
			return 0;
	
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
	
		for (int i = 0; i < a.length(); i++)
		{
			for (int j=0; j <b.length(); j++)
			{
				if( a[i] == b[j])
				{
					x += b[j];
					b[j]='A'; //so we no longer "compare" element b[j] (because there wont be any input in caps)
					break; // so we no longer compare element a[i] (by moving on to next outer loop iteration)
				}
			}
		}
		
		
		//sort(x.begin(), x.end());
		cout << x <<endl;
		
		
		x="";
	}
	
	
	return 0;
}
