#include <iostream>
#include <string>
using namespace std;

struct Course
{
	string name;
	int days;
};

int main()
{
	int T, N, to_due;
	Course* courses;
	string to_do;
	bool flag = false;

	cin >> T;
	for (int i=0; i<T; i++)
	{
		cin >> N;
		courses = new Course[N];
		flag = false;
		for (int j=0; j<N; j++)
		{
			cin >> courses[j].name;
			cin >> courses[j].days;
		}
		cin >> to_due >> to_do;
		for (int k=0; k<N; k++)
		{
			if (to_do == courses[k].name)
			{
				if (courses[k].days <= to_due)
				{
					cout << "Case " << (i+1) << ": Yesss\n";
					flag = true;
				}
				else if (courses[k].days <= to_due + 5)
				{
					cout << "Case " << (i+1) << ": Late\n";
					flag = true;
				}
				else
				{
					break;
				}
			}
		}

		if (!flag) cout << "Case " << (i+1) << ": Do your own homework!\n";
	}

	delete courses;
	return 0;
}