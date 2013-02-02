#ifndef FLOYD
#define FLOYD
#include <vector>
#include "../graph.hh"
typedef vector<vector<Path> > DistanceMatrix;

// Computes the shortest path between each pair of edges (Floyd's algorithm)
// @param g - a graph with no negative edge weights
// @return a distance matrix containing the shortest paths between two vertices.
// An entry matrix[i][j] is the shortest path between vertices i and j.
DistanceMatrix* floyd(Graph *g) {

	DistanceMatrix *shortest_paths;
	return shortest_paths;
}
#endif
