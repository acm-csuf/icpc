//
// Disjoint sets data structure, as described in
// http://en.wikipedia.org/wiki/Disjoint-set_data_structure
//
// Maintains a partition of elements into disjoint (non-overlapping)
// subsets. The universe of elements in the n integers
// 0...n-1. Initially each integer is in its own singleton set. The
// data structure supports two operations:
//
// Find(x): return a "representative" for the set containing x. The
// representative is a designated element of that set.
//
// Merge(x, y): combine the set containing x with the set containing y
// so that they are now both in the same set.
//
// (Other sources call this operations "union", but that is a C++
// reserved word, so we use "merge" here.)
//
// For example, after DisjointSets(5) we have 5 singleton sets:
//
// {0} {1} {2} {3} {4}
//
// after Merge(1, 2):
//
// {0} {1, 2} {3} {4}
//
// after Merge(0, 3):
//
// {0, 3} {1, 2} {4}
//
// after Merge(2, 4):
//
// {0, 3} {1, 2, 4}
//

#ifndef _DISJOINT_SETS_HH
#define _DISJOINT_SETS_HH

#include <cassert>
#include <vector>

using namespace std;

struct DisjointSets {
  // Parallel arrays of parent indices, and rank values used for
  // balancing purposes.
  vector<int> parent, rank;

  // Initialize n singleton sets with the values 0...n-1.
  DisjointSets(int n) {
    assert(n > 0);
    for (int x = 0; x < n; ++x) {
      parent.push_back(x);
      rank.push_back(0);
    }
  }

  // Return true if x is a valid element.
  bool is_element(int x) {
    return (x >= 0) && (x < parent.size());
  }

  // Return the representative element for the set containing x.
  int find(int x) {
    assert(is_element(x));
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  // Merge the set containing x with the set containing y.
  void merge(int x, int y) {
    assert(is_element(x));
    assert(is_element(y));

    int x_root = find(x), y_root = find(y);
    if (x_root == y_root)
      return;

    if (rank[x_root] < rank[y_root])
      parent[x_root] = y_root;
    else if (rank[x_root] > rank[y_root])
      parent[y_root] = x_root;
    else {
      parent[y_root] = x_root;
      rank[x_root]++;
    }

    assert(find(x) == find(y));
  }
};

#endif
