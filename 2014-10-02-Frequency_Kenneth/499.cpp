/*

  accepted solution to
  499 What's The Frequency, Kenneth?
  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=440

  Kevin Wortman

 */

#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  while (cin) {
    string line;
    getline(cin, line);

    if (cin) {

      multiset<char> freq;
      set<char> distinct;
      for (string::iterator i = line.begin(); i != line.end(); ++i) {
	if (isalpha(*i)) {
	  freq.insert(*i);
	  distinct.insert(*i);
	}
      }

      int max_count = 0;
      for (set<char>::iterator i = distinct.begin(); i != distinct.end(); ++i)
	max_count = max(max_count, int(freq.count(*i)));

      for (set<char>::iterator i = distinct.begin(); i != distinct.end(); ++i)
	if (freq.count(*i) == max_count)
	  cout << *i;

      cout << ' ' << max_count << endl;
    }
  }

  return 0;
}
