
#include <iostream>

#include "disjoint_sets.hh"

int main() {
  DisjointSets ds(4);

  assert(ds.find(0) == 0);
  assert(ds.find(1) == 1);
  assert(ds.find(2) == 2);
  assert(ds.find(3) == 3);

  ds.merge(2, 3);
  assert(ds.find(0) == 0);
  assert(ds.find(1) == 1);
  assert(ds.find(2) == 2);
  assert(ds.find(3) == 2);

  ds.merge(1, 0);
  assert(ds.find(0) == 1);
  assert(ds.find(1) == 1);
  assert(ds.find(2) == 2);
  assert(ds.find(3) == 2);

  ds.merge(1, 3);
  assert(ds.find(0) == 1);
  assert(ds.find(1) == 1);
  assert(ds.find(2) == 1);
  assert(ds.find(3) == 1);

  cout << "PASSED" << endl;

  return 0;
}
