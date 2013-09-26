// Solution for
// 11917 - Do Your Own Homework
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3068
// Author: Kevin Wortman (kwortman@fullerton.edu)
// Status: Accepted
// 9/26/2013

#include <cassert>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Problem says all integer inputs are in the range [1, 100] and all
// strings are nonempty and have length at most 20.

inline bool is_valid_integer(int x) {
  return (x >= 1) && (x <= 100);
}

inline bool is_valid_string(const string& s) {
  return !s.empty() && (s.size() <= 20);
}

int main() {
  int T;
  cin >> T;
  assert(is_valid_integer(T));

  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    assert(is_valid_integer(N));

    // Use an STL map that maps subject strings to day counts.
    map<string, int> subject_to_days;
    for (int n = 0; n < N; ++n) {
      string name;
      int days;
      cin >> name >> days;
      assert(is_valid_string(name));
      assert(is_valid_integer(days));

      subject_to_days[name] = days;
    }

    int D;
    string due;
    cin >> D >> due;
    assert(is_valid_integer(D));
    assert(is_valid_string(due));

    cout << "Case " << t << ": ";

    // Try to find an entry in the map for this subject.
    map<string, int>::iterator i = subject_to_days.find(due);
    // (i == subject_to_days.end()) means the subject was not found.
    if ((i == subject_to_days.end()) || (i->second > (D+5)))
      cout << "Do your own homework!";
    else if (i->second > D)
      cout << "Late";
    else
      cout << "Yesss";
    cout << endl;
  }

  return 0;
}
