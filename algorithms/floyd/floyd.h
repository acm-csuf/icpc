#ifndef FLOYD
#define FLOYD
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include "../graph.hh"
typedef std::vector<vector<Path *> > DistanceMatrix;

// Computes the shortest path between each pair of edges (Floyd's algorithm)
DistanceMatrix* floyd(Graph *g);

// Intialize a distance matrix
// Used for the "previous" DistanceMatrix in floyd
void floyd_init(DistanceMatrix *d, Graph *g, AdjMatrix *adj);

// Deallocates a distance matrix
void delete_distance_matrix(DistanceMatrix *d);

// Computes the shortest path between each pair of edges (Floyd's algorithm)
// @param g - a graph with no negative edge weights
// @postconditions - you must delete the returned pointer
// @return a distance matrix containing the shortest paths between two vertices.
// An entry matrix[i][j] is the shortest path between vertices i and j.
DistanceMatrix* floyd(Graph *g) {

	// Get the adjacency matrix representation of the graph
	AdjMatrix *adj_matrix = g->adj_matrix();

	// Temporary matrix; stores previous distance matrix
	DistanceMatrix *previous = new DistanceMatrix(g->n(), 
									std::vector<Path *>(g->n()));
	// Current shortest paths
	DistanceMatrix *shortest_paths = new DistanceMatrix(g->n(), 
									std::vector<Path *>(g->n()));

	// initialize the "previous" matrix
	floyd_init(previous, g, adj_matrix);

	delete_distance_matrix(shortest_paths);
	delete adj_matrix;
	return previous;
}

// Intialize a distance matrix
// Used for the "previous" DistanceMatrix in floyd
// @parm d - distance matrix to initialize
// @param g - graph 
// @param adj - adjacency matrix of graph
void floyd_init(DistanceMatrix *d, Graph *g, AdjMatrix *adj) {

	// Initialize distance matrix.
	for(int i = 0; i < g->n(); i++) {
		for(int j = 0; j < g->n(); j++) {
			if(i == j) {
				// path from vertex to itself
				d->at(i).at(j) = new Path(); // empty path object
			}
			else {
				// distance of vertex i to j
				if(adj->at(i).at(j) != EDGE_NULL) {
					// i and j are adjacent
					Path p;
					// add edge to path
					const Edge *e = adj->at(i).at(j);
					d->at(i).at(j) = p.extend(*e);
				}
				else {
					// i and j are not adjacent
					d->at(i).at(j) = NULL;	
				}
			}
		}
	}
}


// Deallocates a distance matrix
// @param distance matrix to delete
void delete_distance_matrix(DistanceMatrix *d) {
	// Distance matrix contains pointers to paths.
	// Non-null pointers must be deleted to avoid memory leaks.
	for(int i = 0; i < d->size(); i++) {
		for(int j = 0; j < d->at(i).size(); j++) {
			if(d->at(i).at(j) != NULL) {
				delete d->at(i).at(j);
				d->at(i).at(j) = NULL;
			}
		}
	}
}
#endif
