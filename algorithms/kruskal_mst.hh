
//
// Kruskal's algorithm for minimum spanning trees.
//

#ifndef _KRUSKAL_MST_HH
#define _KRUSKAL_MST_HH

#include <algorithm>

#include "disjoint_sets.hh"
#include "graph.hh"

// Utility function to compare edge weights, used in sorting.
bool compare_edge_ptr_weight(const Edge* x, const Edge* y) {
  return x->weight < y->weight;
}

// Find the edges in the minimum spanning tree of g. Returns a pointer
// to a vector of Edge pointers. The Edge pointers refer to the Edge
// objects owned by g. The client is responsible for eventually
// deleting the returned vector.
vector<const Edge*>* kruskal_mst_edges(const Graph& g) {
  assert(!g.empty());

  // Sort the edges into nonincreasing order by weight. We use a
  // stable sort to make unit testing easier, but stability is not
  // otherwise necessary.
  vector<Edge*> sorted_edges = g.edges;
  stable_sort(sorted_edges.begin(),
	      sorted_edges.end(),
	      compare_edge_ptr_weight);

  // Use a disjoint set data structure to keep track of the patchwork
  // forest of spanned subgraphs that we'll create. Initially every
  // vertex is its own component; every time we add an edge, those
  // components get connected. When we're done the whole graph has
  // been connected into one component.
  DisjointSets parts(g.n());

  // Edges in the minimum spanning tree.
  vector<const Edge*>* in_tree(new vector<const Edge*>());

  for (vector<Edge*>::iterator i = sorted_edges.begin();
       i != sorted_edges.end(); ++i) {
    const Edge& e = **i;
    // Does this edge connect distinct components?
    if (parts.find(e.v) != parts.find(e.w)) {
      in_tree->push_back(&e); // Yes, so add it to the tree
      parts.merge(e.v, e.w); // Now the components are one
    }
  }

  return in_tree;
}

#endif
