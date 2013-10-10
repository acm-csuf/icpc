#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	const int NUM_LETTERS = 26;
	int s1Chars[NUM_LETTERS], s2Chars[NUM_LETTERS];
	string s1 = "", s2 = "";

	while (cin >> s1 >> s2)
	{
		for (int i=0; i<NUM_LETTERS; i++)
		{
			s1Chars[i] = 0;
			s2Chars[i] = 0;
		}

		for (int i=0; i<s1.size(); i++)
		{
			s1Chars[tolower(s1[i]) - 'a']++;
		}

		for (int i=0; i<s2.size(); i++)
		{
			s2Chars[tolower(s2[i]) - 'a']++;
		}

		for (int i=0; i<NUM_LETTERS; i++)
		{
			while(s1Chars[i] > 0 && s2Chars[i] > 0)
			{
				cout << (char)(i+'a');
				s1Chars[i]--;
				s2Chars[i]--;
			}
		}
		cout << endl;
	}

	return 0;
}
