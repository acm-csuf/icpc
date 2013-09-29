#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int moveArr[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};

enum
{
	N, E, S, W
} direction;

class r0b0t
{
public:
	int orientation, currentX, currentY;
	r0b0t(int inputY, int inputX)
	{
		currentX = inputX -1;
		currentY = inputY-1;
		orientation = N;
	}
	void forward(vector <vector <char> >& inVector)
	{
		currentY = currentY + moveArr[orientation][0];
		currentX = currentX + moveArr[orientation][1];
		if (inVector[currentX][currentY] == '*')
		{
			currentY = currentY - moveArr[orientation][0];
			currentX = currentX - moveArr[orientation][1];
		}
	}
	void clockwiseTurn()
	{
		orientation = (orientation + 1) % 4;
	}
	void counterClockwiseTurn()
	{
		if (orientation == 0)
		{
			orientation = 3;
		}
		else
		{
			orientation = orientation - 1;
		}
	}
	char getOrientation(int input)
	{
		switch (input)
		{
		case N:
			return 'N';
		case E:
			return 'E';
		case S:
			return 'S';
		case W:
			return 'W';
		}
	}
	void printMaze(vector <vector <char> >& inVector)
	{
		for (int i = 0; i < inVector.size(); i++)
		{
			for (int j = 0; j < inVector[i].size(); j++)
			{
				if (i == currentX && j == currentY)
				{
					cout << "O";
				}
				else
				{
					cout << inVector[i][j];
				}
			}
			cout << endl;
		}
	}
	void printObj()
	{
		printf("%d %d %c\n", currentX + 1, currentY + 1, getOrientation(orientation));
	}
};

int main()
{
	int numberOfCases, rows, columns, startX, startY;
	char move;
	cin >> numberOfCases;
	for (int i = 1; i <= numberOfCases; i++)
	{
		cin >> rows >> columns;
		cin.ignore(255, '\n');
		vector <vector <char> > mazeVector(rows, vector<char>(columns));
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < columns; k++)
			{
				mazeVector[j][k] = cin.get();
			}
			cin.get();
		}
		cin >> startX >> startY;
		r0b0t* robot = new r0b0t(startY, startX);
		do
		{
			move = cin.get();
			switch(move)
			{
			case 'R':
				robot->clockwiseTurn();
				break;
			case 'L':
				robot->counterClockwiseTurn();
				break;
			case 'F':
				robot->forward(mazeVector);
				break;
			case 'Q':
				robot->printObj();
			case '\n': case ' ':
				break;
			}
		} while (move != 'Q');
		if (i != numberOfCases)
		{
			cout << endl;
		}
		delete robot;
		mazeVector.clear();
	}
	return 0;
}
