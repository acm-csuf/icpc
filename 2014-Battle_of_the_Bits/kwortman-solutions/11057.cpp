
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

int main() {

  while (true) {
    int N, M;
    cin >> N;
    if (!cin)
      break;

    multiset<int> prices;
    for (int i = 0; i < N; ++i) {
      int p;
      cin >> p;
      prices.insert(p);
    }

    cin >> M;

    int best_i, best_j;
    bool got_best = false;
    for (multiset<int>::const_iterator itr = prices.begin();
	 itr != prices.end();
	 ++itr) {
      int i = *itr, j = M - i;

      if ( (j <= 0) ||
	   (prices.count(j) == 0) ||
	   ((i == j) && (prices.count(i) < 2)) )
	continue;

      if (!got_best || (abs(i - j) < abs(best_i - best_j))) {
	best_i = i;
	best_j = j;
	got_best = true;
      }
    }
    
    if (best_i > best_j) {
      swap(best_i, best_j);
    }

    cout << "Peter should buy books whose prices are " << best_i << " and " << best_j << "." << endl << endl;
  }

  return 0;
}

