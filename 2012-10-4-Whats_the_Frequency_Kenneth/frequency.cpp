#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<ctype.h>

using namespace std;

pair<string, int> processMap(map<char,int> &m)
{
	string chars = "";
	int maxFrequency = 0;
	for(map<char,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if((*it).second > maxFrequency)
		{
			chars.clear();
			maxFrequency = (*it).second;
			chars.push_back((*it).first);
		}
		else if((*it).second == maxFrequency)
			chars.push_back((*it).first);
	}
	sort(chars.begin(), chars.end());
	return pair<string, char>(chars, maxFrequency);
}

pair<string, int> findMostFrequentChars(string line)
{
	map<char, int> frequencies;
	
	for(int i = 0; i < line.size(); i++)
	{
		if(isalpha(line[i]))
		{
			if(frequencies.find(line[i]) != frequencies.end())
				frequencies[line[i]]++; 
			else
				frequencies.insert(pair<char, int>(line[i], 1));
		}
	}

	return processMap(frequencies);
}

int main()
{
	string line;
	while(cin.good())
	{
		getline(cin, line);
		if(cin.good())
		{
			pair<string, int> p = findMostFrequentChars(line);
			cout << p.first << " " << p.second << endl;
		}
	}
	return 0;
}
