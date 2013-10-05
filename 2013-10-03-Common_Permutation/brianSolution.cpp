#include <iostream>
#include <vector>
using namespace std;
int main()
{
	unsigned int i;
	string str1;
	string str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		vector <int> string1Vector(26, 0);
		vector <int> string2Vector(26, 0);
		for (i = 0; i < str1.length(); i++)
		{
			string1Vector[str1[i]-97]++;
		}
		for (i = 0; i < str2.length(); i++)
		{
			string2Vector[str2[i]-97]++;
		}
		for (i = 0; i < 26; i++)
		{
			while (string1Vector[i] > 0 && string2Vector[i] > 0)
			{
				cout << char(i+97);
				string1Vector[i]--;
				string2Vector[i]--;
			}
		}
		cout << endl;
	}
	return 0;
}
