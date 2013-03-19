
//////////////////////////////////////////////////////////////////////////////
// graph.hh, copy-pasted...
//////////////////////////////////////////////////////////////////////////////

#ifndef _GRAPH_HH
#define _GRAPH_HH

#include <cassert>
#include <vector>

using namespace std;

struct Edge {
  // An edge has two vertex endpoints: v and w. It may or may not be
  // directed and may have a defined numerical weight. When an edge is
  // directed, v is the "from" end and w is the "to" end. In an
  // undirected edge, v and w are interchangeable.
  int index, v, w;
  bool directed;
  double weight;

  Edge(int index_, int v_, int w_, bool directed_, double weight_)
    : index(index_),
      v(v_),
      w(w_),
      directed(directed_),
      weight(weight_) { }

  // Is x one of the ends?
  bool is_incident(int x) const {
    return (x == v) || (x == w);
  }

  // Can this edge flow into vertex x?
  bool enters(int x) const {
    if (directed)
      return x == w;
    else
      return is_incident(x);
  }

  // Can this edge flow out of vertex x?
  bool exits(int x) const {
    if (directed)
      return x == v;
    else
      return is_incident(x);
  }

  // Can this edge flow from "from" to "to"?
  bool connects(int from, int to) const {
    if (from != to)
      return exits(from) && enters(to);
    else
      return (v == from) && (w == from);
  }

  // Assuming x is one of this edge's ends, return the other end.
  int opposite(int x) const {
    assert(is_incident(x));
    return (x != v) ? v : w;
  }
};

// Declaring this constant avoids some pointer casting nonsense later
// on.
Edge const* const EDGE_NULL = 0;

// Adjacency matrix. For AdjMatrix m, m[v][w] is the edge connecting v
// to w, or EDGE_NULL if no such edge exists.
typedef vector<vector<Edge const*> > AdjMatrix;

// A graph. Stores the edges in a vector, and also an adjacency list
// data structure for fast neighbor lookups of sparse graphs. Each
// individual Edge can be either directed or undirected, so this data
// structure supports "mixed" graphs with both kind of edges, although
// most graph algorithms support only one kind of edge. This data
// structure can also accomodate "multigraphs" where multiple edges
// can be defined between any pair of vertices, although again most
// algorithms don't handle that situation.
struct Graph {
  // Edge objects in the order they were added (unsorted).
  vector<Edge*> edges;

  // Adjacency list: adj[v] is all the edges incident to vertex v. The
  // elements are pointers to the same Edge objects stored in the
  // vector above.
  vector<vector<Edge*> > adj;

  // n is the count of vertices.
  Graph(int n)
  : adj(n) { }

  // destructor
  ~Graph() {
    for (vector<Edge*>::iterator i = edges.begin(); i != edges.end(); ++i)
      delete *i;
  }

  int n() const { return adj.size(); }    // # vertices
  int m() const { return edges.size(); }  // # edges

  bool is_vertex(int x) const { return (x >= 0) && (x < n()); }

  bool empty() const { return n() == 0; }

  int add_edge(int v, int w, bool directed=false, double weight=0.0) {
    assert(is_vertex(v));
    assert(is_vertex(w));
    edges.push_back(new Edge(m(), v, w, directed, weight));
    adj[v].push_back(edges.back());
    adj[w].push_back(edges.back());
  }

  // Find an edge connecting "from" to "to", or EDGE_NULL if no such
  // edge exists.
  Edge const* connection(int from, int to) const {
    for (vector<Edge*>::const_iterator e = adj[from].begin(); 
	 e != adj[from].end(); ++e)
      if ((*e)->connects(from, to))
	return *e;
    return EDGE_NULL;
  }

  // Build adjacency matrix. Caller owns the object.
  AdjMatrix* adj_matrix() const {
    assert(!empty());
    AdjMatrix* m = new AdjMatrix(n(), vector<Edge const*>(n(), EDGE_NULL));
    for (vector<Edge*>::const_iterator i = edges.begin(); i != edges.end(); ++i) {
      const Edge& e = **i;
      (*m)[e.v][e.w] = &e;
      if (!e.directed)
	(*m)[e.w][e.v] = &e;
    }
    return m;
  }

  // Query the directedness of the graph.

  int count_directed() const {
    int total = 0;
    for (vector<Edge*>::const_iterator e = edges.begin(); e != edges.end(); ++e)
      if ((*e)->directed)
	++total;
    return total;
  }

  bool strictly_directed() const { return count_directed() == m(); }
  bool strictly_undirected() const { return count_directed() == 0; }
};

// A path is a sequence of Edges.
struct Path {
  vector<Edge const*> edges;
  double weight; // cache the total weight so it can be computed in
		 // constant time

  Path()
    : weight(0) { }

  // copy constructor
  Path(const Path *p) {
	this->edges = p->edges;
	this->weight = p->weight;
  }

  // Concatenates one path with another
  // @param p - path to add to this
  // @returns - new path
  Path *concat(Path *p) {
	Path *new_path;
	Path *prev_path = new Path(this);

	for(int i = 0; i < p->edges.size(); i++) {
		new_path = prev_path->extend(*(p->edges.at(i)));

		delete prev_path;
		prev_path = new_path;
	}
	return new_path;
  }

  //@postcondition - caller must deallocate path returned
  Path *extend(const Edge& e) const {
	Path *new_path = new Path(this);
	new_path->edges.push_back(&e);
	new_path->weight += e.weight;
	return new_path;
  }
};

#endif

//////////////////////////////////////////////////////////////////////////////
// end of graph.hh
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n, m;
    cin >> n >> m;

    // learning[v] is the point value of vertex v
    vector<int> learning(n);
    for (int i = 0; i < n; i++)
      cin >> learning[i];

    // create a graph with n vertices
    Graph g(n);
    // add the m directed edges
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g.add_edge(u, v, true);
    }

    int u = 0,   // current vertex
      total = 0; // total points
    while (true) {
      // search for the outgoing edge to the vertex of highest value
      int best = 0;
      bool is_outgoing = false; // were there any outgoing edges?
      for (vector<Edge*>::const_iterator e = g.adj[u].begin();
	   e != g.adj[u].end(); e++) {
	if ((*e)->exits(u)) {
	  // found an outgoing edge
	  is_outgoing = true;
	  int v = (*e)->opposite(u);
	  // is it the best so far?
	  if (learning[v] > learning[best])
	    best = v;
	}
      }

      // not a single outgoing edge, stop
      if (!is_outgoing)
	break;

      // move to u and absorb its knowledge
      u = best;
      total += learning[best];
    }

    cout << "Case " << (t+1) << ": " << total << " " << u << endl;
  }
  return 0;
}

