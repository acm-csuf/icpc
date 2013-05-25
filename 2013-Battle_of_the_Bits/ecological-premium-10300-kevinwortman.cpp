// Accepted solution for 10300 "Ecological Premium"
//
// Kevin Wortman
//
// This is a quick solution based on implementing exactly what is
// written in the problem description.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int f;
    cin >> f;

    double burden = 0;
    for (int j = 0; j < f; ++j) {
      int size, animals, friendliness;
      cin >> size >> animals >> friendliness;

      // The "animals" term can be eliminated from the numerator and
      // denominator but I didn't even bother.
      double b = (static_cast<double>(size) / animals) * friendliness * animals;
      burden += b;
    }

    cout << burden << endl;
  }
  return 0;
}
