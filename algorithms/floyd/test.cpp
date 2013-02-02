#include "floyd.h"
#include "../graph.hh"
// undirected graph tests
void undirected_tests(void); // runs all undirected graph tests
void undirected_one_edge(void);

// unit tests for undirected graphs
void undirected_tests(void) {
	undirected_one_edge();
}

// Tests floyd for one edge (trivial case)
void undirected_one_edge(void) {
	Graph g(1);
	DistanceMatrix *asps = floyd(&g);

	delete_distance_matrix(asps);
}

int main() {
	undirected_tests();
	return 0;
}
