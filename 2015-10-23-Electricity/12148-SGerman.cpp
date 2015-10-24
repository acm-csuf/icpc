//Problem 12148 - Electricity
//Sergio German
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int N, D, M, Y, C, count = 0, total = 0;
	int prev_D, prev_M, prev_Y, prev_C;

	while(cin >> N){
		if(N == 0) break; //Terminate loop

		for(int i = 0; i < N; ++i){
			//Get the current line's values
			cin >> D >> M >> Y >> C;
			//Are we passed the first iteration so we can start comparing dates?
			if(i > 0){
				struct tm a = {0,0,0,D,(M-1),(Y-1900)}; //Format {sec,min,hours,days,months,years}
				struct tm b = {0,0,0,prev_D,(prev_M-1),(prev_Y-1900)}; //See http://www.cplusplus.com/reference/ctime/tm/

				//Convert tm structure to time_t
				time_t currentDay = mktime(&a);
				time_t previousDay = mktime(&b);

				double difference = difftime(currentDay, previousDay)/ (60 * 60 * 24); //Calculates the difference of 2 dates in days
				if(difference == 1) //Is the time difference exactly 1 day?
				{
					count++; //+1 'precisely determinable' days
					total+=(C-prev_C); // Add the difference of consumption between the current day and yesterday
				}
			}
				//Save the current line's values for next iteration
				prev_D = D; prev_M = M; prev_Y = Y; prev_C = C;
		}

	cout << count << " " << total << endl; //output
	count = 0; total = 0; //reset for next set of input data
	}
}
