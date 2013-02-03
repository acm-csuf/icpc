// Examples of creating 2D, 3D, and 4D STL vectors succinctly.

#include <vector>

using namespace std;

int main() {
  // vector has a constructor
  //   vector<type>(N, default-value)
  // that initializes the vector with N copies of default-value.
  vector<double> arr(30, 3.2); // 30 copies of 3.2

  // 10 rows, 20 columns, all filled with 0.0. We use the constructor
  // described above to create a default-value representing one row,
  // which is copied for each of the 10 requested rows. Note there are
  // 2 dimensions and therefore 2 trailing ">" symbols in the matrix'
  // type and 2 trailing ")" symbols at the end of the line.
  vector<vector<double> > table(10, vector<double>(20, 0.0));

  // you can use usual subscript operators
  table[0][0] = 3;
  table[9][9] = 5;

  // 3D 15x20x25 box, all elements -3.0. 3 dimensions and 3 trailing
  // >'s and )'s.
  vector<vector<vector<double> > > box(15, vector<vector<double> >(20, vector<double>(25, -3.0)));

  // 4D 15x20x25x30 box, all elements 17. 4 dimensions and 4 trailing
  // >'s and )'s.
  vector<vector<vector<vector<double> > > > hyper(15, vector<vector<vector<double> > >(20, vector<vector<double> >(25, vector<double>(30, 17))));
}
