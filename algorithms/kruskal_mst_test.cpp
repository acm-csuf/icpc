
#include <iostream>
#include <memory>

#include "kruskal_mst.hh"

double total_weight(const vector<const Edge*>& edges) {
  double total = 0;
  for (int i = 0; i < edges.size(); ++i)
    total += edges[i]->weight;
  return total;
}

int main() {
  const int A=0, B=1, C=2, D=3, E=4, F=5, G=6;

  // First test: example from
  // http://en.wikipedia.org/wiki/Kruskal%27s_algorithm#Example
  {
    Graph g(7);
    g.add_edge(A, B, false, 7);  // 0
    g.add_edge(A, D, false, 5);  // 1
    g.add_edge(B, C, false, 8);  // 2
    g.add_edge(B, D, false, 9);  // 3
    g.add_edge(B, E, false, 7);  // 4
    g.add_edge(C, E, false, 5);  // 5
    g.add_edge(D, E, false, 15); // 6
    g.add_edge(D, F, false, 6);  // 7
    g.add_edge(E, F, false, 8);  // 8
    g.add_edge(E, G, false, 9);  // 9
    g.add_edge(F, G, false, 11); // 10
    assert(g.m() == 11);

    auto_ptr<vector<const Edge*> > t(kruskal_mst_edges(g));

    assert(t->size() == 6);
    assert(total_weight(*t) == (5+5+6+7+7+9));

    assert(t->at(0) == g.connection(A, D));
    assert(t->at(1) == g.connection(C, E));
    assert(t->at(2) == g.connection(D, F));
    assert(t->at(3) == g.connection(A, B));
    assert(t->at(4) == g.connection(B, E));
    assert(t->at(5) == g.connection(E, G));
  }

  // Second test:
  // http://en.wikipedia.org/wiki/File:Msp1.jpg
  {
    Graph g(6);
    g.add_edge(A, B, false, 1); // 0
    g.add_edge(A, D, false, 4); // 0
    g.add_edge(A, E, false, 3); // 0
    g.add_edge(B, D, false, 4); // 0
    g.add_edge(B, E, false, 2); // 0
    g.add_edge(C, E, false, 4); // 0
    g.add_edge(C, F, false, 5); // 0
    g.add_edge(D, E, false, 4); // 0
    g.add_edge(E, F, false, 7); // 0

    auto_ptr<vector<const Edge*> > t(kruskal_mst_edges(g));

    assert(t->size() == 5);
    assert(total_weight(*t) == (1+2+4+4+5));

    assert(t->at(0) == g.connection(A, B));
    assert(t->at(1) == g.connection(B, E));
    assert(t->at(2) == g.connection(A, D));
    assert(t->at(3) == g.connection(C, E));
    assert(t->at(4) == g.connection(C, F));
  }

  cout << "PASSED" << endl;

  return 0;
}
