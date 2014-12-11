
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

    if (_num_empty == 0) {
      // base case, done
      return 0;
    } else {
      // otherwise try recursing in each cardinal direction
      return min(dfs_direction(start_x, start_y, 0, -1), // N
		 min(dfs_direction(start_x, start_y, +1, 0), // E
		     min(dfs_direction(start_x, start_y, 0, +1), // S
			 dfs_direction(start_x, start_y, -1, 0)))); // W
    }
  }

  int dfs_direction(int start_x, int start_y, int dx, int dy) {
    if (!may_enter(start_x+dx, start_y+dy)) {
      // this direction is impossible
      return INFINITY;
    } else {
      // move one step
      int x = start_x, y = start_y;
      while (may_enter(x+dx, y+dy)) {
	x += dx;
	y += dy;
	visit(x, y);
      }

      // DFS recursion
      int child_steps = dfs(x, y);
	  
      // undo step
      while ((x != start_x) || (y != start_y)) {
	unvisit(x, y);
	x -= dx;
	y -= dy;
      }

      if (child_steps == INFINITY)
	return INFINITY;
      else
	return child_steps + 1; // account for this step
    }
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
