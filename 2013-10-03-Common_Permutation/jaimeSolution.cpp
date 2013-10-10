#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//g++ permute.cpp - o p
//./p

int main()
{
	string a , b;
	vector<char> y;

	while(getline(cin,a))
	{
		getline(cin,b);	
		//make permutations
		for(int i = 0; i < a.length(); ++i)	
		{
				for(int j=0; j< b.length();++j)
				{
					
					if(a[i] == b[j])
					{
					  
							y.push_back(a[i]);
							a[i] = '1';
							b[j] = '2';
	
					}			
				}
				 
		}
		sort (y.begin(), y.end());	// sort my vector
		for(int i = 0;i < y.size();++i)
		{
			cout <<	y[i];	
		}
		cout << endl;
		while (!y.empty())// empty so it starts empty
 		 {
     			y.pop_back();
  		 }	
	}
}

