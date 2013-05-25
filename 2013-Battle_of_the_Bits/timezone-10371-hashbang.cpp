/*
Team hashbang
Christian David
Chad Wyszynski
Hayden Donze

Number: 10371 
Status: Accepted 

*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

class Time {
	public:
		int hours;
		int minutes;
		bool pm;
		Time();
		Time(int hours, int minutes, bool pm);
		bool isMidnight();
		bool isNoon();
		void adjust(int adjHours, int adjMins);
		void adjust(float hours);
		void print();
};

Time::Time() {}

Time::Time(int hours, int minutes, bool pm) {
}


void Time::print() {
	if(isMidnight()) {
		cout << "midnight";
	}
	else if(isNoon()) {
		cout << "noon";
	}
	else {
		if(this->hours == 0) {
			cout << "12" << ":"; 
		}
		else {
			cout << this->hours << ":"; 
		}
		cout << setfill('0') << setw(2) << this->minutes;
		if(this->pm) {
			cout << " p.m.";
		}
		else {
			cout << " a.m.";
		}
	}
	cout << endl;
}

bool Time::isMidnight() {
	return this->hours == 0 && this->minutes == 0 && this->pm == false;
}

bool Time::isNoon() {
	return this->hours == 0 && this->minutes == 0 && this->pm == true;
}

void Time::adjust(float hours) {
	int minutes = 0;
	if(floor(hours) != ceil(hours)) {
		// need to deal with minutes
		// 3.5 = 3, + .5 = 3.5
		// -3.5 = -4, + .5 = -3.5
		minutes = 30;
	}
	this->adjust(floor(hours), minutes);
}

void Time::adjust(int adjHours, int adjMins) {
	int newMin = this->minutes + adjMins;
	int newHour = this->hours + adjHours;
	if(newMin >= 60) {
		newHour++;
	}
	else if(newMin < 0) {
		newHour--;
	}
	if(newHour >= 12 || newHour < 0) {
		// if add huge number ( > 12), we could wrap twice
		int overflowTimes = newHour / 12;
		if(overflowTimes != 0 && ((overflowTimes % 2) != 0)) { // even values are same pm
			this->pm = !(this->pm);
		}
	}
	this->minutes = newMin % 60;
	// cout << "new hours before mod: " << newHour << endl;
	this->hours = newHour % 12;
	// cout << "hours immediately after mod: " << this->hours << endl;
	if(this->hours < 0) {
		// cout << "WE GOT ONE\n";
		this->hours += 12;
		this->pm = !(this->pm);
	}
	// cout << "hours: " << this->hours << endl;
}

void buildTzMap(map<string, float> &tz) {
	tz.insert(pair<string, float>("GMT", 0));
	tz.insert(pair<string, float>("BST", 1));
	tz.insert(pair<string, float>("IST", 1));
	tz.insert(pair<string, float>("WET", 0));
	tz.insert(pair<string, float>("WEST", 1));
	tz.insert(pair<string, float>("CET", 1));
	tz.insert(pair<string, float>("CEST", 2));
	tz.insert(pair<string, float>("EET", 2));
	tz.insert(pair<string, float>("EEST", 3));
	tz.insert(pair<string, float>("MSK", 3));
	tz.insert(pair<string, float>("MSD", 4));
	tz.insert(pair<string, float>("AST", -4));
	tz.insert(pair<string, float>("ADT", -3));
	tz.insert(pair<string, float>("NST", -3.5));
	tz.insert(pair<string, float>("NDT", -2.5));
	tz.insert(pair<string, float>("EST", -5));
	tz.insert(pair<string, float>("EDT", -4));
	tz.insert(pair<string, float>("CST", -6));
	tz.insert(pair<string, float>("CDT", -5));
	tz.insert(pair<string, float>("MST", -7));
	tz.insert(pair<string, float>("MDT", -6));
	tz.insert(pair<string, float>("PST", -8));
	tz.insert(pair<string, float>("PDT", -7));
	tz.insert(pair<string, float>("HST", -10));
	tz.insert(pair<string, float>("AKST", -9));
	tz.insert(pair<string, float>("AKDT", -8));
	tz.insert(pair<string, float>("AEST", 10));
	tz.insert(pair<string, float>("AEDT", 11));
	tz.insert(pair<string, float>("ACST", 9.5));
	tz.insert(pair<string, float>("ACDT", 10.5));
	tz.insert(pair<string, float>("AWST", 8));
}

// returns the number of hours to adjust
void parseLine(string &line, Time &time, pair<string, string> &tzs) {
	stringstream ss(line);
	string timeArg;
	ss >> timeArg;

	if(timeArg == "noon") {
		time.hours = 0;
		time.minutes = 0;
		time.pm = true;
	}
	else if(timeArg == "midnight") {
		time.hours = 0;
		time.minutes = 0;
		time.pm = false;
	}
	else {
		stringstream timeStream(timeArg);
		char nothing;
		int hours;
		timeStream >> time.hours >> nothing >> time.minutes;
		if(time.hours == 12)
			time.hours = 0;
		ss >> timeArg;
		time.pm = timeArg == "p.m.";
	}

	ss >> tzs.first >> tzs.second;
}

int main () {
	
	map<string, float> tzs;
	buildTzMap(tzs);
	int cases;
	cin >> cases;
	string line;
	getline(cin, line); // skip first line

	for(int i = 0; i < cases; i++) {
		getline(cin, line);
		Time time;
		pair<string, string> problemTzs;	
		parseLine(line, time, problemTzs);

//		time.print();
//		cout << problemTzs.first << " ";
//		cout << tzs[problemTzs.first] << endl;
		time.adjust(-tzs[problemTzs.first]);
//		time.print();
//		cout << problemTzs.second << " ";
//		cout << tzs[problemTzs.second] << endl;
		time.adjust(tzs[problemTzs.second]);
		time.print();
//		cout << "\n\n\n";
	}

	return 0;
}
