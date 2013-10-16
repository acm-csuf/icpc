// Solution for
// 10067 - Playing with Wheels
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1008
// Author: Kevin Wortman (kwortman@fullerton.edu)
// Status: Accepted
// 10/16/2013

// This solution treats each wheel configuration as a vertex in a
// graph, and uses breadth first search (BFS) to find a shortest path
// from the initial configuration to the goal configuration. Edges to
// the forbidden configurations (vertices) are omitted from the
// graph. You could use Dijkstra's algorithm instead of BFS, but
// that's overkill since the graph is unweighted; BFS is faster,
// simpler, and still produces a shortest path.

#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

struct Vertex {
  // I found it convenient to represent each configuration as a string
  // of four ASCII digits. We need to track each vertex' depth so we
  // can report the shortest path length at the end of BFS.

  string digits;
  int depth;

  Vertex(string _digits, int _depth) {
    digits = _digits;
    depth = _depth;
  }
};

// This is a conventional nonrecursive BFS with two amendments:
//
// - The search stops as soon as a path to the goal is found, instead
//   of traversing every vertex.
//
// - The "avoid" (a.k.a. seen) set is initialized with the start
//   vertex, as usual, *and also* the set of forbidden configurations
//   given as input. This prevents the BFS from ever visiting those
//   vertices.
inline int bfs(const string& start,
	       const string& goal,
	       const set<string>& forbidden) {
  queue<Vertex> todo;
  set<string> avoid(forbidden);
  todo.push(Vertex(start, 0));
  avoid.insert(start);

  while (!todo.empty()) {
    Vertex x = todo.front();
    todo.pop();
    
    if (x.digits == goal)
      return x.depth;

    // Generate the child nodes of x. Each of the four wheels can be
    // rotated.
    for (int i = 0; i < 4; ++i) {
      // Each wheel can rotate left or right. flip==0 means increment
      // the digit, flip==1 means decrement.
      for (int flip = 0; flip <= 1; ++flip) {
	// child digits are a copy of the parent's digits...
	string child(x.digits);
	// ...except one designated digit is
	// incremented/decremented. Note that adding 9 mod 10 is the
	// same as subtracting one, but works correctly with the C++ %
	// operator.
	child[i] = '0' + ((child[i] - '0' + (flip ? 9 : 1)) % 10);

	if (avoid.count(child) == 0) {
	  avoid.insert(child);
	  todo.push(Vertex(child, x.depth + 1));
	}
      }
    }
  }

  // no path exists
  return -1;
}

// Helper function to read four whitespace-separated digits and
// collect them into a contiguous string.
inline string read_digits() {
  string digits;
  for (int i = 0; i < 4; ++i) {
    string d;
    cin >> d;
    digits += d;
  }
  return digits;
}

int main() {
  int N;
  cin >> N;
  for (int n = 0; n < N; ++n) {
    string start = read_digits(), goal = read_digits();

    set<string> forbidden;
    int forbidden_count;
    cin >> forbidden_count;
    for (int i = 0; i < forbidden_count; ++i)
      forbidden.insert(read_digits());

    cout << bfs(start, goal, forbidden) << endl;
  }

  return 0;
}
