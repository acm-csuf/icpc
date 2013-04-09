#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Niceness between stops i and j.
int niceness(const vector<int>& n, int i, int j) {
  assert(i < j);
  int total = 0;
  for (int x = i; x < j; ++x)
    total += n[x];
  return total;
}

int main() {
  int b;
  cin >> b;
  for (int r = 1; r <= b; ++r) {
    int s;
    cin >> s;

    // n[i] is the niceness of the segment from stop i to i+1. Note:
    // we'll use array indices 1...s instead of the usual 0...s-1, in
    // order to be consistent with the problem description.
    vector<int> n(s, 0);
    for (int i = 1; i < s; ++i)
      cin >> n[i];

    int best_start, best_end, best_niceness;
    bool has_best = false;
    for (int i = 1; i < s; ++i) {
      for (int j = i+1; j <= s; ++j) {
	int cur_niceness = niceness(n, i, j);
	if (!has_best ||
	    (cur_niceness > best_niceness) ||
	    ((cur_niceness == best_niceness) &&
	     ( ((j-i) > (best_end-best_start)) ||
	       (i < best_start) ))) {
	  has_best = true;
	  best_start = i;
	  best_end = j;
	  best_niceness = cur_niceness;
	}
      }
    }
    assert(has_best);

    if (best_niceness <= 0)
      cout << "Route " << r << " has no nice parts" << endl;
    else
      cout << "The nicest part of route " << r << " is between stops "
	   << best_start << " and " << best_end << endl;
  }
  return 0;
}
