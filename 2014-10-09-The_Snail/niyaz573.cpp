//Solution to problem 573 "The Snail"
//Niyaz Mahmud
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	double well_height, snail_speed, distance_climbed, snail_height, fatigue, fatigue_adj, slide_distance;
	well_height = snail_speed = distance_climbed = snail_height = fatigue = fatigue_adj = slide_distance = 0.0;
	char input2[16]; //XXX XXX XXX XXX\0
	int day = 0;
	string input;
	while(getline(cin,input))
	{
		strcpy(input2, input.c_str());
		if (input == "0 0 0 0") break;
		well_height = atof(strtok(input2," "));
		snail_speed = atof(strtok(NULL," "));
		slide_distance = atof(strtok(NULL," "));
		fatigue = atof(strtok(NULL," "))/100;
		fatigue_adj = fatigue*snail_speed;
		while (distance_climbed >= 0)
		{
			day++;
			distance_climbed += snail_speed;//snail climbs
			if (distance_climbed > well_height)//is the snail out?
			{
				cout << "success on day " << day << endl;
				break;
			}
			distance_climbed -= slide_distance; //snail slides while sleeping
			if (snail_speed>0) snail_speed -= fatigue_adj; //snail gets a little bit tired
		}
		if (distance_climbed < 0) cout << "failure on day " << day << endl;
		well_height = snail_speed = distance_climbed = snail_height = fatigue = fatigue_adj = slide_distance = 0.0;
		day = 0;
	}
	return 0;
}
