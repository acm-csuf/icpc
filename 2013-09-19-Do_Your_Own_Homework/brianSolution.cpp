#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int testCases, subjects, subjectHours, days;
	string subjectName, subjectDue;
	cin >> testCases;
	map<string, int> classMap;
	for (int i = 0; i < testCases; i++)
	{
		cout << "Case " << i+1 << ": ";
		cin >> subjects;
		for (int j = 0; j < subjects; j++)
		{
			cin >> subjectName >> subjectHours;
			classMap[subjectName] = subjectHours;
		}
		cin >> days >> subjectDue;
		if (classMap[subjectDue] == 0)
			cout << "Do your own homework!\n";
		else if (classMap[subjectDue] <= days)
			cout << "Yesss\n";
		else if (classMap[subjectDue] <= days + 5)
			cout << "Late\n";
		else
			cout << "Do your own homework!\n";
		classMap.clear();
	}
	return 0;
}
