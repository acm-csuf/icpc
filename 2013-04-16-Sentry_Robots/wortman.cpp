// The output of this program matches the sample output, but it is
// judged "wrong answer" by UVa.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Coord {
  Coord()
    : x(0), y(0) { }

  Coord(int _x, int _y)
    : x(_x), y(_y) { }

  bool operator==(const Coord& o) const {
    return (x == o.x) && (y == o.y);
  }

  int x, y;
};

void read_coord_vector(vector<Coord>& out) {
  out.clear();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    out.push_back(Coord());
    cin >> out.back().y >> out.back().x;
  }
}

enum Dir { NORTH=0, EAST=1, SOUTH=2, WEST=3 };

struct Robot {
  Robot() { }

  Robot(const Coord& _pos, const Dir& _dir)
    : pos(_pos), dir(_dir) { }

  Coord pos;
  Dir dir;
};

// abbreviate Point Of Interest as "POI"

enum GridCell { EMPTY, SEEN_POI, UNSEEN_POI, OBSTACLE };

struct Grid {
  Grid(int X, int Y,
       const vector<Coord>& poi,
       const vector<Coord>& obstacles)
    : grid(Y+1, vector<GridCell>(X+1, EMPTY)),
      unseen_poi(poi) {

    for (vector<Coord>::const_iterator i = poi.begin();
	 i != poi.end(); ++i)
      grid[i->y][i->x] = UNSEEN_POI;

    for (vector<Coord>::const_iterator i = obstacles.begin();
	 i != obstacles.end(); ++i)
      grid[i->y][i->x] = OBSTACLE;
  }

  const int Y() const { return grid.size()-1; }
  const int X() const { return grid.front().size()-1; }

  // Fills out with all the Coords in the line of sight of the robot,
  // including the robot's own position.
  void line_of_sight(vector<Coord>& out, const Robot& robot) const {
    out.clear();

    int x = robot.pos.x, y = robot.pos.y;
    assert(grid[y][x] != OBSTACLE);

    while ((x >= 1) && (x <= X()) &&
	   (y >= 1) && (y <= Y()) &&
	   (grid[y][x] != OBSTACLE)) {

      out.push_back(Coord(x, y));

      switch (robot.dir) {
      case NORTH: ++y; break;
      case EAST:  ++x; break;
      case SOUTH: --y; break;
      case WEST:  --x; break;
      }
    }
  }

  int poi_seen_by(const Robot& robot) const {
    vector<Coord> los;
    line_of_sight(los, robot);

    int count = 0;
    for (vector<Coord>::const_iterator i = los.begin();
	 i != los.end(); ++i)
      if (grid[i->y][i->x] == UNSEEN_POI)
	++count;

    assert(count > 0);

    return count;
  }

  void add_robot(const Robot& robot) {
    vector<Coord> los;
    line_of_sight(los, robot);

    for (vector<Coord>::const_iterator i = los.begin();
	 i != los.end(); ++i) {
      if (grid[i->y][i->x] == UNSEEN_POI) {
	grid[i->y][i->x] = SEEN_POI;
	unseen_poi.erase(find(unseen_poi.begin(), unseen_poi.end(), *i));
      }
    }
  }

  vector<vector<GridCell> > grid;
  vector<Coord> unseen_poi;
};

int main() {
  int C;
  cin >> C;

  for (int c = 0; c < C; ++c) {
    int Y, X;
    cin >> Y >> X;

    vector<Coord> poi, obstacles;
    read_coord_vector(poi);
    read_coord_vector(obstacles);

    Grid grid(X, Y, poi, obstacles);

    // Greedy algorithm: Try each uncovered point as a robot
    // position. Keep the position and direction that covers the most
    // points. Repeat until all points are covered.

    int robot_count;
    for (robot_count = 0; !grid.unseen_poi.empty(); ++robot_count) {
      Robot best_robot;
      int best_seen;
      bool best_exists = false;

      // try each uncovered POI
      for (vector<Coord>::const_iterator i = grid.unseen_poi.begin();
	   i != grid.unseen_poi.end(); ++i) {

	// Try all 4 directions at that point. Use an int instead of
	// Dir, which is a little dirty, but works.

	// Double check that we're looping through the directions in
	// the proper order.
	assert((WEST-NORTH+1) == 4);

	for (int dir = NORTH; dir <= WEST; ++dir) {
	  Robot try_robot(*i, (Dir)dir);
	  int try_seen = grid.poi_seen_by(try_robot);
	  if (!best_exists || (try_seen > best_seen)) {
	    best_robot = try_robot;
	    best_seen = try_seen;
	    best_exists = true;
	  }
	}
      }

      assert(best_exists);

      grid.add_robot(best_robot);
    }
    cout << robot_count << endl;
  }

  return 0;
}
