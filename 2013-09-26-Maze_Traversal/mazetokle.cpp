#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int cases;
	int rows;
	int columns;
	string allInCol;
	
	vector<string> maze;
	
	char currentCommand;
	vector<char> instructions;
	
	struct robotInfo
	{
		int rowLocation;
		int colLacation;
		char derectionFacing;
		
	};
	
	robotInfo robot;
	robot.derectionFacing = 'N';
	
	cin >> cases;
	//cases
	for (int i =0; i < cases; i ++)
	{
		//input
		cin >>rows;
		cin >> columns;
		cin.ignore(4,'\n');
		for (int k=0; k<rows; k++)
		{
			getline(cin, allInCol);
			maze.push_back(allInCol);
		}
		cin>> robot.rowLocation;
		cin>> robot.colLacation;
		robot.rowLocation--;
		robot.colLacation--;
		
		cin >> currentCommand;
		while( currentCommand != 'Q')
		{
			instructions.push_back(currentCommand);
			cin >> currentCommand;
		}
		//all input taken in
		
		
		for ( int z =0; z< instructions.size(); z++)
		{
			
			if (instructions[z] == 'R')
			{
				if( robot.derectionFacing == 'N')
					robot.derectionFacing = 'E';
				else if(robot.derectionFacing == 'E')
					robot.derectionFacing ='S';
				else if (robot.derectionFacing == 'S')
					robot.derectionFacing ='W';
				else if (robot.derectionFacing =='W')
					robot.derectionFacing = 'N';
			}
			
			else if (instructions[z] == 'L')
			{
				if( robot.derectionFacing == 'N')
					robot.derectionFacing = 'W';
				else if(robot.derectionFacing == 'W')
					robot.derectionFacing ='S';
				else if (robot.derectionFacing == 'S')
					robot.derectionFacing ='E';
				else if (robot.derectionFacing =='E')
					robot.derectionFacing = 'N';
			}
			
			else if (instructions[z] == 'F') 
			{
				if( robot.derectionFacing == 'N')
				{
					if( maze[robot.rowLocation-1][robot.colLacation]==' ')
						robot.rowLocation--;
				}
				else if(robot.derectionFacing == 'W')
				{
					if( maze[robot.rowLocation][robot.colLacation-1]==' ')
						robot.colLacation--;
				}
				else if (robot.derectionFacing == 'S')
				{
					if( maze[robot.rowLocation+1][robot.colLacation]==' ')
						robot.rowLocation++;
				}
				else if (robot.derectionFacing =='E')
				{
					if( maze[robot.rowLocation][robot.colLacation+1]==' ')
						robot.colLacation++;
				}
			}
			
			
		}
		cout<<robot.rowLocation+1 <<" "<<robot.colLacation+1<< " "<<robot.derectionFacing<<endl;
		
		//puts a blank line behind every case except last one
		if( i != cases-1)
			cout<<endl;
		
		//cleanup time for next case
		maze.clear();
		instructions.clear();
		robot.derectionFacing = 'N';
		//everything else should get over written
		
		
	}
	return 0;
}
