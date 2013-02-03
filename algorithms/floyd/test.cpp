#include "floyd.h"
#include "../graph.hh"
// undirected graph tests
void undirected_tests(void); // runs all undirected graph tests
void undirected_one_vertex(void);
void undirected_two_vertices(void);

// unit tests for undirected graphs
void undirected_tests(void) {
	undirected_one_vertex();
	undirected_two_vertices();
}

// Tests floyd for one vertex (trivial case)
void undirected_one_vertex(void) {
	Graph g(1);
	DistanceMatrix *asps = floyd(&g);
	Path *p = asps->at(0).at(0);
	assert(p != NULL);
	assert(p->weight == 0);
	delete_distance_matrix(asps);
}

// Tests floyd for two vertices
void undirected_two_vertices(void) {
	Graph g(2);
	g.add_edge(0, 1, false, 10); // edge between two vertices

	DistanceMatrix *asps = floyd(&g);
	assert(asps->at(0).at(0)->weight == 0);
	assert(asps->at(1).at(1)->weight == 0);
	assert(asps->at(0).at(1)->weight == 10);
	assert(asps->at(1).at(0)->weight == 10);
	delete_distance_matrix(asps);
}

int main() {
	undirected_tests();
	return 0;
}
