
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

enum Posn { INSIDE, OUTSIDE, BORDER };

class Shape {
private:

  bool _is_square;
  int _x, _y, _l, _r, _g, _b;

public:

  Shape(bool is_square, int x, int y, int l, int r, int g, int b)
    : _is_square(is_square),
      _x(x),
      _y(y),
      _l(l),
      _r(r),
      _g(g),
      _b(b) { }

  int min_x() {
    if (_is_square) {
      return _x;
    } else {
      return _x - _l;
    }
  }

  int min_y() {
    if (_is_square) {
      return _y;
    } else {
      return _x - _l;
    }
  }

  int max_x() {
    return _x + _l;
  }

  int max_y() {
    return _y + _l;
  }

  Posn posn(int x, int y) {
    if (_is_square) {
      if ((x > min_x()) &&
	  (y > min_y()) &&
	  (x < max_x()) &&
	  (y < max_y())) {
	return INSIDE;
      } else if ((x < min_x()) ||
		 (y < min_y()) ||
		 (x > max_x()) ||
		 (y > max_y())) {
	return OUTSIDE;
      } else {
	return BORDER;
      }
    } else { // circle
      int dx = (x - _x),
	dy = (y - _y),
	d2 = dx*dx + dy*dy,
	r2 = _l*_l;
      if (d2 < r2)
	return INSIDE;
      else if (d2 == r2)
	return BORDER;
      else
	return OUTSIDE;
    }
  }

  int r() { return _r; }
  int g() { return _g; }
  int b() { return _b; }
};

int divround(int n, int d) {
  return (int) round( ((double) n) / ((double) d) );
}

int main() {

  int T;
  cin >> T;

  for (int t = 0; t < T; ++t) {
    int R, P;
    cin >> R >> P;

    cout << "Case " << (t+1) << ":" << endl;

    vector<Shape*> shapes;
    /*
    set<Shape*, min_x_less> by_min_x;
    set<Shape*, min_y_less> by_min_y;
    set<Shape*, max_x_less> by_max_x;
    set<Shape*, max_y_less> by_max_y;
    */
    for (int ri = 0; ri < R; ++ri) {
      string otype;
      int px, py, length, r, g, b;
      cin >> otype >> px >> py >> length >> r >> g >> b;

      Shape* s = new Shape((otype == "SQUARE"), px, py, length, r, g, b);

      shapes.push_back(s);
      /*
      by_min_x.push_back(s);
      by_min_y.push_back(s);
      by_max_x.push_back(s);
      by_max_y.push_back(s);
      */
    }

    for (int p = 0; p < P; ++p) {
      int px, py;
      cin >> px >> py;
      
      int r = 0, g = 0, b = 0, n = 0;
      bool on_border = false;
      for (int i = 0; (!on_border) && (i < shapes.size()); ++i) {
	Shape* s = shapes[i];
	switch (s->posn(px, py)) {
	case OUTSIDE:
	  break;
	case BORDER:
	  on_border = true;
	  break;
	case INSIDE:
	  r += s->r();
	  g += s->g();
	  b += s->b();
	  ++n;
	  break;
	}
      }

      if (on_border) {
	r = g = b = 0;
      } else if (n == 0) {
	r = g = b = 255;
      } else {
	r = divround(r, n);
	g = divround(g, n);
	b = divround(b, n);
      }

      cout << "(" << r << ", " << g << ", " << b << ")" << endl;
    }

    for (int r = 0; r < R; ++r) {
      delete shapes[r];
    }

    if (t != (T-1))
      cout << endl;
  }

  return 0;
}

