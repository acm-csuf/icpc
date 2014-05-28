
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  while (true) {

    vector<int> cf(9, 0);
    for (int d = 8; d >= 0; --d)
      cin >> cf[d];
    if (!cin)
      break;

    bool all_zero = true;
    for (int d = 8; d >= 0; --d)
      if (cf[d] != 0)
	all_zero = false;

    if (all_zero) {
      cout << "0" << endl;
    } else {
      
      bool first_term = true;
      for (int d = 8; d >= 0; --d) {
	if (cf[d] == 0)
	  continue;

	// sign
	if (first_term) {
	  if (cf[d] < 0) {
	    cout << "-";
	  }
	} else {
	  if (cf[d] < 0) {
	    cout << " - ";
	  } else {
	    cout << " + ";
	  }
	}

	// coefficient
	if (abs(cf[d]) != 1 || d == 0)
	  cout << abs(cf[d]);

	// x
	if (d > 0)
	  cout << "x";

	// exponent
	if (d > 1)
	  cout << "^" << d;

	first_term = false;
      }

      cout << endl;
    }
  }

  return 0;
}

