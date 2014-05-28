
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int main() {

  while (true) {
    int a;
    cin >> a;
    if (a == 0) {
      break;
    }

    set<int> seen;
    seen.insert(a);

    while (true) {
      a = (a*a / 100) % 10000;
      if (seen.count(a) == 1)
	break;
      seen.insert(a);
    }

    cout << seen.size() << endl;
  }

  return 0;
}

