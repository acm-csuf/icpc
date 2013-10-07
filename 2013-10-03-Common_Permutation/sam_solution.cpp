//Author   : Sam Forrest
//Problem  : Week 3, Common Permutation
//Status   : Accepted

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    while (!cin.eof())
    {
		//2 vectors to count chars in both s1 and s2
		vector <int> count1 (26, 0);
		vector <int> count2 (26, 0);
		getline(cin,s1);
		getline(cin,s2);
		
		//count chars in s1 and s2
		for(int i = 0; i < s1.length(); i++)    
			if ((s1[i] >= 97) && (s1[i] <= 122))
				count1[s1[i]-97]++;

		for(int i = 0; i < s2.length(); i++)
			if ((s2[i] >= 97) && (s2[i] <= 122))
				count2[s2[i]-97]++;
	    
		//iterate through characters in alphabetical order and output them min number of times
		for(int i =0; i < 26; i++)  
			for (int j =0; j < ((count1[i] < count2[i]) ? count1[i] : count2[i]); j++)
				cout << char(i+97);
	
		if(!cin.eof())
			cout << endl;
    }
    return 0;
}
