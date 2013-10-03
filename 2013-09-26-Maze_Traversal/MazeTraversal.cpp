#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cassert>
using namespace std;

int main()
{
	int cases = 0, rows = 0, cols = 0, xPos = 0, yPos = 0;
	int heading = 90;	//North.
	char charIn, dirChar;
	vector< string > maze;
	string tempString;

	cin >> cases;
	for (int i=0; i<cases; i++)
	{
		heading = 90;
		cin >> rows >> cols;
		cin.ignore();
		assert(rows <= 60);
		assert(rows > 0);
		assert(cols <= 60);
		assert(cols > 0);

		for (int j=0; j<rows; j++)
		{
			getline(cin, tempString);
			assert(tempString.length()==cols);
			maze.push_back(tempString);
		}
		cin >> yPos >> xPos;

		while(cin >> charIn, charIn != 'Q')
		{
			switch (charIn)
			{
			case 'R': heading = (heading - 90 + 360) % 360;
				break;
			case 'L': heading = (heading + 90) % 360;
				break;
			case 'F':
				{
					int newX = xPos + (int)(cos(heading*(M_PI*2)/360));
					int newY = yPos - (int)(sin(heading*(M_PI*2)/360));
					if (newX > 0 && newY > 0 && newX <= cols && newY <= rows && maze[newY-1][newX-1] != '*')
					{
						xPos = newX;
						yPos = newY;
					}
				}
			default:	//Do nothing!
				break;
			}
		}

		switch (heading)
			{
			case 0:
				dirChar = 'E';
				break;
			case 90:
				dirChar = 'N';
				break;
			case 180:
				dirChar = 'W';
				break;
			case 270:
				dirChar = 'S';
				break;
			default:	//Oops!
				break;
			}

		cout << yPos << ' ' << xPos << ' ' << dirChar << endl;
		if (i<cases-1) cout << endl;
		maze.clear();
	}

	return 0;
}
