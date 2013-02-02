
#include "graph.hh"

#include <iostream>
#include <memory>

int main() {
  Graph empty(0);
  assert(empty.n() == 0);
  assert(empty.m() == 0);
  assert(!empty.is_vertex(-1));
  assert(!empty.is_vertex(0));
  assert(!empty.is_vertex(1));
  assert(empty.empty());
  assert(empty.count_directed() == 0);
  assert(empty.strictly_directed());
  assert(empty.strictly_undirected());

  // example from
  // http://en.wikipedia.org/wiki/Kruskal%27s_algorithm#Example
  const int A=0, B=1, C=2, D=3, E=4, F=5, G=6;
  Graph g(7);

  assert(g.n() == 7);
  assert(g.m() == 0);
  assert(!g.is_vertex(-1));
  assert(g.is_vertex(0));
  assert(g.is_vertex(1));
  assert(g.is_vertex(2));
  assert(g.is_vertex(3));
  assert(g.is_vertex(4));
  assert(g.is_vertex(5));
  assert(g.is_vertex(6));
  assert(!g.is_vertex(7));
  assert(!g.empty());

  g.add_edge(A, B, false, 7);  // 0
  assert(g.m() == 1);
  assert(g.adj[A].size() == 1);
  assert(g.adj[B].size() == 1);
  assert(g.adj[C].empty());
  assert(g.adj[D].empty());
  assert(g.adj[E].empty());
  assert(g.adj[F].empty());
  assert(g.adj[G].empty());
  assert(g.adj[A][0] == g.edges[0]);
  assert(g.adj[B][0] == g.edges[0]);

  g.add_edge(A, D, false, 5);  // 1
  assert(g.m() == 2);
  assert(g.adj[A].size() == 2);
  assert(g.adj[B].size() == 1);
  assert(g.adj[C].empty());
  assert(g.adj[D].size() == 1);
  assert(g.adj[E].empty());
  assert(g.adj[F].empty());
  assert(g.adj[G].empty());
  assert(g.adj[A][1] == g.edges[1]);
  assert(g.adj[D][0] == g.edges[1]);

  g.add_edge(B, C, false, 8);  // 2
  assert(g.m() == 3);
  g.add_edge(B, D, false, 9);  // 3
  assert(g.m() == 4);
  g.add_edge(B, E, false, 7);  // 4
  assert(g.m() == 5);
  g.add_edge(C, E, false, 5);  // 5
  assert(g.m() == 6);
  g.add_edge(D, E, false, 15); // 6
  assert(g.m() == 7);
  g.add_edge(D, F, false, 6);  // 7
  assert(g.m() == 8);
  g.add_edge(E, F, false, 8);  // 8
  assert(g.m() == 9);
  g.add_edge(E, G, false, 9);  // 9
  assert(g.m() == 10);
  g.add_edge(F, G, false, 11); // 10
  assert(g.m() == 11);

  assert(g.connection(A, A) == EDGE_NULL);
  assert(g.connection(A, B) == g.edges[0]);
  assert(g.connection(A, C) == EDGE_NULL);
  assert(g.connection(A, D) == g.edges[1]);
  assert(g.connection(A, E) == EDGE_NULL);
  assert(g.connection(A, F) == EDGE_NULL);
  assert(g.connection(A, G) == EDGE_NULL);

  assert(g.connection(B, A) == g.edges[0]);
  assert(g.connection(B, B) == EDGE_NULL);
  assert(g.connection(B, C) == g.edges[2]);
  assert(g.connection(B, D) == g.edges[3]);
  assert(g.connection(B, E) == g.edges[4]);
  assert(g.connection(B, F) == EDGE_NULL);
  assert(g.connection(B, G) == EDGE_NULL);

  auto_ptr<AdjMatrix> m(g.adj_matrix());

  assert((*m)[A][A] == EDGE_NULL);
  assert((*m)[A][B] == g.edges[0]);
  assert((*m)[A][C] == EDGE_NULL);
  assert((*m)[A][D] == g.edges[1]);
  assert((*m)[A][E] == EDGE_NULL);
  assert((*m)[A][F] == EDGE_NULL);
  assert((*m)[A][G] == EDGE_NULL);

  assert((*m)[B][A] == g.edges[0]);
  assert((*m)[B][B] == EDGE_NULL);
  assert((*m)[B][C] == g.edges[2]);
  assert((*m)[B][D] == g.edges[3]);
  assert((*m)[B][E] == g.edges[4]);
  assert((*m)[B][F] == EDGE_NULL);
  assert((*m)[B][G] == EDGE_NULL);

  assert((*m)[C][A] == EDGE_NULL);
  assert((*m)[C][B] == g.edges[2]);
  assert((*m)[C][C] == EDGE_NULL);
  assert((*m)[C][D] == EDGE_NULL);
  assert((*m)[C][E] == g.edges[5]);
  assert((*m)[C][F] == EDGE_NULL);
  assert((*m)[C][G] == EDGE_NULL);

  assert((*m)[D][A] == g.edges[1]);
  assert((*m)[D][B] == g.edges[3]);
  assert((*m)[D][C] == EDGE_NULL);
  assert((*m)[D][D] == EDGE_NULL);
  assert((*m)[D][E] == g.edges[6]);
  assert((*m)[D][F] == g.edges[7]);
  assert((*m)[D][G] == EDGE_NULL);

  assert((*m)[E][A] == EDGE_NULL);
  assert((*m)[E][B] == g.edges[4]);
  assert((*m)[E][C] == g.edges[5]);
  assert((*m)[E][D] == g.edges[6]);
  assert((*m)[E][E] == EDGE_NULL);
  assert((*m)[E][F] == g.edges[8]);
  assert((*m)[E][G] == g.edges[9]);

  assert((*m)[F][A] == EDGE_NULL);
  assert((*m)[F][B] == EDGE_NULL);
  assert((*m)[F][C] == EDGE_NULL);
  assert((*m)[F][D] == g.edges[7]);
  assert((*m)[F][E] == g.edges[8]);
  assert((*m)[F][F] == EDGE_NULL);
  assert((*m)[F][G] == g.edges[10]);

  assert((*m)[G][A] == EDGE_NULL);
  assert((*m)[G][B] == EDGE_NULL);
  assert((*m)[G][C] == EDGE_NULL);
  assert((*m)[G][D] == EDGE_NULL);
  assert((*m)[G][E] == g.edges[9]);
  assert((*m)[G][F] == g.edges[10]);
  assert((*m)[G][G] == EDGE_NULL);

  assert(g.count_directed() == 0);
  assert(!g.strictly_directed());
  assert(g.strictly_undirected());

  cout << "PASSED" << endl;

  return 0;
}
