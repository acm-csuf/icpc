/*

  ACCEPTED solution for

  579 - Clock Hands

  http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=520

  Kevin Wortman

 */

#include <cassert>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Measure angles in units of .001 degree, to avoid floating point
// issues
const int DENOM(1000), CIRCLE(360*DENOM);

// Parse one digit from a string
int one_digit(const string& str, size_t i) {
  char ch(str[i]);
  assert(isdigit(ch));
  return (ch - '0');
}

// Parse a two-digit number from a string
int two_digits(const string& str, size_t i) {
  return (one_digit(str, i)*10 + one_digit(str, i+1));
}

// Return the canonical representation of an angle. Input may be any
// integer, and output is guaranteed to be an equivalent angle measure
// in the range [0, CIRCLE).
int canonical(int degrees) {
  // O(1) time arithmetic would be better than these loops, but they
  // work and are acceptable in contest code
  while (degrees < 0)
    degrees += CIRCLE;
  while (degrees >= CIRCLE)
    degrees -= CIRCLE;
  return degrees;
}

int main() {
  while (true) {
    string line;
    getline(cin, line);

    // parsing the time characters by hand is faster to code up than
    // using a stringstream
    int hour, minute;
    if (line[1] == ':') {
      hour = one_digit(line, 0);
      minute = two_digits(line, 2);
    } else {
      hour = two_digits(line, 0);
      minute = two_digits(line, 3);
    }

    if ((hour == 0) && (minute == 0))
      break;

    int hour_twelfths(hour % 12),
      hour_angle((hour_twelfths * CIRCLE/12) +
		 (minute * CIRCLE/(60*12))), // hour hand moves with every minute
      minute_angle(minute * CIRCLE/60),
      forward(canonical(hour_angle - minute_angle)), // try clockwise and counter-clockwise
      backward(canonical(minute_angle - hour_angle)),
      less(min(forward, backward)), // use nearer of the two angles
      whole(less / DENOM), // whole degrees
      fraction(less % DENOM); // thousandths of degrees

    cout << whole << '.' << setw(3) << setfill('0') << fraction << endl;
  }

  return 0;
}
