
/*
  ACCEPTED solution for

  6567 - Full Board

  https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4578

  Kevin Wortman
*/

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INFINITY = INT_MAX;

enum Cell { EMPTY, OBSTACLE, VISITED };

class Board {
public:
  Board(int width, int height)
    : _cells(height, vector<Cell>(width, EMPTY)),
      _num_empty(width * height) {
    assert(width > 0);
    assert(height > 0);
  }

  int width() const  { return _cells[0].size(); }
  int height() const { return _cells.size(); }

  bool is_position(int x, int y) const {
    return ((x >= 0) &&
	    (x < width()) &&
	    (y >= 0) &&
	    (y < height()));
  }

  bool is_empty(int x, int y) const {
    return get(x, y) == EMPTY;
  }

  bool is_visited(int x, int y) const {
    return get(x, y) == VISITED;
  }

  bool may_enter(int x, int y) const {
    return is_position(x, y) && is_empty(x, y);
  }

  void add_obstacle(int x, int y) {
    assert(is_empty(x, y));
    set(x, y, OBSTACLE);
    --_num_empty;
  }

  void visit(int x, int y) {
    assert(is_empty(x, y));
    set(x, y, VISITED);
    --_num_empty;
  }

  void unvisit(int x, int y) {
    assert(is_visited(x, y));
    set(x, y, EMPTY);
    ++_num_empty;
  }

  // Returns INFINITY or a nonnegative number of steps.
  int min_steps() {
    // try all valid starting points
    int best = INFINITY;
    for (int x = 0; x < width(); ++x) {
      for (int y = 0; y < height(); ++y) {
	if (is_empty(x, y)) {
	  visit(x, y);
	  best = min(best, dfs(x, y));
	  unvisit(x, y);
	}
      }
    }
    return best;
  }

private:

  Cell get(int x, int y) const {
    assert(is_position(x, y));
    return _cells[y][x];
  }

  void set(int x, int y, Cell c) {
    assert(is_position(x, y));
    _cells[y][x] = c;
  }

  // returns INFINITY or a nonnegative number of steps
  int dfs(int start_x, int start_y) {

    assert(is_visited(start_x, start_y));
    assert(_num_empty >= 0);

    // base case, done
    if (_num_empty == 0) {
      return 0;
    }

    int best = INFINITY;

    // try moving both vertically and horizontally.
    for (int horizontal = 0; horizontal <= 1; ++horizontal) {
      // try both forward and backward
      for (int forward = 0; forward <= 1; ++forward) {

	// work out x-velocity and y-velocity
	int dx = 1, dy = 0;
	if (!forward)
	  dx *= -1;
	if (!horizontal)
	  swap(dx, dy);

	int x = start_x, y = start_y;
	// move one step
	if (may_enter(x+dx, y+dy)) {
	  while (may_enter(x+dx, y+dy)) {
	    x += dx;
	    y += dy;
	    visit(x, y);
	  }

	  // DFS recursion
	  int steps = dfs(x, y);
	  if (steps != INFINITY)
	    best = min(best, steps + 1);
	  
	  // undo step
	  while ((x != start_x) || (y != start_y)) {
	    unvisit(x, y);
	    x -= dx;
	    y -= dy;
	  }
	}
      }
    }

    return best;
  }
  	      
  vector<vector<Cell> > _cells;
  int _num_empty;
};

int main() {
  for (int case_num = 1; cin; ++case_num) {
    int height, width;
    cin >> height >> width;
    if (cin) {
      Board board(width, height);

      // skip blank line
      string line;
      getline(cin, line);
      assert(line.empty());

      for (int y = 0; y < height; ++y) {
	getline(cin, line);
	assert(line.size() == width);
	for (int x = 0; x < width; ++x) {
	  char ch = line[x];
	  if (ch == '*')
	    board.add_obstacle(x, y);
	  else
	    assert(ch == '.');
	}
      }

      int steps = board.min_steps();

      cout << "Case " << case_num << ": "
	   << ((steps != INFINITY) ? steps : -1)
	   << endl;
    }
  }

  return 0;
}
