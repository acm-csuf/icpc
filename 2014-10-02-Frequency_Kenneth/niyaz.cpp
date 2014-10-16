//Ali (Niyaz) Mahmud "Whats the frequency kenneth?" ACM problem solution
//C++11
#include <string>
#include <map>
#include <iostream>
using namespace std;
int main()
{
	map<char, int> charbucket;
	string input;
	string output = "";
	while(getline(cin,input))
	{
		if (input=="")
		{
			break;
		}
		for (int i = 0; input[i]!='\0'; i++)
		{
			if(isalpha(input[i]))charbucket[input[i]]++;
		}
		//find highest in map
		int highest = 0;
		for (map<char,int>::iterator it = charbucket.begin(); it != charbucket.end(); ++it)
		{
			if (it->second>highest)
			{
				highest=it->second;	
			}
		}
		//find all with highest
		for (map<char,int>::iterator it = charbucket.begin();	it != charbucket.end(); ++it)
		{
			if (it->second == highest)
			{
				output += it->first;
			}
		}
		for (map<char,int>::iterator it = charbucket.begin(); it != charbucket.end(); ++it)
		{
			it->second = 0;
		}
		output += " ";
		output += to_string(highest);
		output += "\n";
	}
	cout << output;
	return 0;
}
