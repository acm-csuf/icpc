// 12096 - The SetStack Computer
// Solution by Kevin Wortman <kwortman@fullerton.edu>
// 
// This code uses set, stack, set_union, set_intersection, and
// lexicographical_compare from STL to achieve a very concise
// solution. It is correct but gets the "Time Limit Exceeded" judge
// result from UVa. Probably because my DUP implementation copies a
// set by value rather than by reference.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// Set of sets recursive data structure.
struct Set {
  // Compare two sets. Necessary for a Set to be included in an STL
  // set.
  bool operator<(const Set& o) const {
    int diff = elts.size() - o.elts.size();
    if (diff < 0)
      return true;
    else if (diff > 0)
      return false;
    else
      // Note: lexicographical_compare calls operator< recursively on
      // each element of the two sets.
      return lexicographical_compare(elts.begin(), elts.end(),
				     o.elts.begin(), o.elts.end());
      
  }

  set<Set> elts;
};

// Helper to pop the stack twice.
void pop_pop(stack<Set>& stack, Set& a, Set& b) {
  a = stack.top();
  stack.pop();
  b = stack.top();
  stack.pop();
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;

    stack<Set> stack;

    for (int n = 0; n < N; ++n) {
      string cmd;
      cin >> cmd;

      if (cmd == "PUSH") {
	stack.push(Set());
      } else if (cmd == "DUP") {
	stack.push(stack.top());
      } else if (cmd == "ADD") {
	Set a, b, c;
	pop_pop(stack, a, b);
	c = b;
	c.elts.insert(a);
	stack.push(c);
      } else {
	Set a, b, c;
	pop_pop(stack, a, b);

	if (cmd == "UNION") {
	  set_union(a.elts.begin(), a.elts.end(),
		    b.elts.begin(), b.elts.end(),
		    inserter(c.elts, c.elts.begin()));
	} else if (cmd == "INTERSECT") {
	    set_intersection(a.elts.begin(), a.elts.end(),
			     b.elts.begin(), b.elts.end(),
			     inserter(c.elts, c.elts.begin()));
	} 
	
	stack.push(c);
      }

      cout << stack.top().elts.size() << endl;
    }

    cout << "***" << endl;
  }
  return 0;
}
