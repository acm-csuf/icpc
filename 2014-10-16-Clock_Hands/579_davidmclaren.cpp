#include <iostream>
#include <cmath>		// For abs()
#include <string.h>
#include <assert.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// Variables
	string input;
	double h_angle;
	double m_angle;
	double angle1;
	double angle2;
	double smallest_angle;
	double hour;
	double minute;

	cin >> input;

	while (input != "0:00")
	{
		hour = atoi(input.substr(0, input.find(":")).c_str());
		minute = atoi(input.substr(input.find(":") + 1).c_str());
		// Offset by 1 to ignore the :

		// Trick have to account for the hour hand moving between hours!
		// Each hour is 30 degrees
		h_angle = (hour * 30.0) + (minute * 0.5);
		m_angle = minute * 6.0;

		// Testing
		//cout << "h_angle: " << h_angle << endl;
		//cout << "m_angle: " << m_angle << endl;

		// Reset 360 to 0
		if (h_angle == 360)
		{
			h_angle = 0;
		}

		if (m_angle == 360)
		{
			m_angle = 0;
		}

		// Calculate the angles
		angle1 = abs(h_angle - m_angle);
		angle2 = 360 - angle1;

		// Testing
		/*
		cout << "Angle1: " << angle1 << endl
			 << "Angle2: " << angle2 << endl
			 << endl;
		 */

		if (angle1 <= angle2)
		{
			smallest_angle = angle1;
		}
		else
		{
			smallest_angle = angle2;
		}

		cout.precision(3);
		cout << fixed << smallest_angle<< endl;

		assert(smallest_angle <= 180);

		cin >> input;
	}

	return 0;
}
