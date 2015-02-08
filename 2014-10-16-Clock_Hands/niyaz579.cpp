//Problem 579:Clock Hands
// ACCEPTED
//Niyaz Mahmud
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int minute, hour;
	string input;
	char time[6]; // HH:MM\0
	while(getline(cin,input))
	{
		strcpy(time, input.c_str());
		if (input == "0:00") break;
		hour = atoi(strtok(time,":"));
		minute = atoi(strtok(NULL," "));
		double alpha, beta, gamma;
		double hour_deg, min_deg;
		hour_deg = hour*30+minute*.5;
		min_deg = minute*6;
		alpha = max(hour_deg,min_deg);
		beta = min(hour_deg,min_deg);
		gamma = alpha-beta;
		if (gamma>180) gamma = 360-gamma;
		cout << fixed << setprecision(3) << gamma << endl;
	}
}
