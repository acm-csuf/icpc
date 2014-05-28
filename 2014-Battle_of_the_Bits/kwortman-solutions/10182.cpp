
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum Dir { OUT=0, SW=1, NW=2, N=3, NE=4, SE=5, S=6 };

string dir_str(Dir d) {
  switch (d) {
  case OUT: return "OUT";
  case SW:  return "SW";
  case NW:  return "NW";
  case N:   return "N";
  case NE:  return "NE";
  case SE:  return "SE";
  case S:   return "S";
  }
}

string coord_str(int x, int y) {
  stringstream ss;
  ss << "(" << x << ", " << y << ")";
  return ss.str();
}

struct State {
  Dir dir;
  int x, y, d, t;

  State()
    : dir(OUT), x(0), y(0), d(0), t(0) { }

  void step() {
    //cout << "step " << dir_str(dir) << " from " << coord_str(x, y) << " to ";

    if (dir == OUT) {
      ++y;
      //cout << coord_str(x, y);

      ++d;
      dir = SW;
      t = d - 1;

      if (t == 0) {
	dir = NW;
	t = 1;
      }

      //cout << ", now facing " << dir_str(dir) << " with d=" << d << ", t=" << t << endl;
    } else {
      switch (dir) {
      case OUT: assert(false); break;
      case SW: --x; ++y; break;
      case NW: --x;      break;
      case N :      --y; break;
      case NE: ++x; --y; break;
      case SE: ++x;      break;
      case S :      ++y; break;
      }

      //cout << coord_str(x, y);

      if (--t > 0) {
	//cout << ", still facing " << dir_str(dir);
      } else {
	dir = Dir((dir + 1) % 7);
	t = d;
	//cout << ", rotate to face " << dir_str(dir) << ", t=" << t;
      }
    }

    //cout << endl;
  }
};

int main() {

  while (true) {
    int coord;
    cin >> coord;
    if (!cin) {
      break;
    }

    State st;
    for (int at = 1; at < coord; ++at) {
      //cout << "willi " << at << ", ";
      st.step();
    }

    cout << st.x << " " << st.y << endl;

   }

  return 0;
}

