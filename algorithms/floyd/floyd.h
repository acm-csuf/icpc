#ifndef FLOYD
#define FLOYD
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include "../graph.hh"
typedef std::vector<std::vector<Path *> > DistanceMatrix;

// Computes the shortest path between each pair of edges (Floyd's algorithm)
DistanceMatrix* floyd(Graph *g);

// Intialize a distance matrix
// Used for the "previous" DistanceMatrix in floyd
void floyd_init(DistanceMatrix *d, Graph *g, AdjMatrix *adj);

// Deallocates a distance matrix
void delete_distance_matrix(DistanceMatrix *d);

// Returns the minimum of two paths
// If they're of equal weight, return the one with least vertices.
Path *min_path(Path *p1, Path *p2);

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

	// calculate all-pairs shortest path
	for(int k = 1; k < g->n() + 1; k++) {
		for(int i = 0; i < g->n(); i++) {
			for(int j = 0; j < g->n(); j++) {
				// delete current shortest path value (stale)
				if(shortest_paths->at(i).at(j) != NULL) {
					delete shortest_paths->at(i).at(j);
				}

				// calculate shortest path
				// TODO this breaks if not a complete graph (if any previous
				// value is NULL.
				Path *potential = 
					previous->at(i).at(k - 1)->concat(previous->at(i).at(j)); 
				Path *new_path = min_path(potential, previous->at(i).at(j));
				shortest_paths->at(i).at(j) = new Path(new_path);  
				//TODO fix memory leak with potential
			}	
		}	
		// Swap which structure is the most recent shortest path.
		// This is an optimation trick to avoid creating a 3D matrix.
		swap(shortest_paths, previous); 
	}	

	cout << "seg?\n";
	delete_distance_matrix(previous);
	delete adj_matrix;
	return shortest_paths;
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
			cout << "i, j" << i << ", " << j << endl;
			if(d->at(i).at(j) != NULL) {

				delete d->at(i).at(j);
				d->at(i).at(j) = NULL;
			}
		}
	}
}

// Returns the shortest of two paths.
// If they're of equal weight, return the one with least edges.
// @param p1 - a path
// @param p2 - another path
// @return the shorter of the two paths. If they're of equal weight, return the
// one with the least edges.
Path *min_path(Path *p1, Path *p2) {
	Path *shortest;
	if(p1->weight < p2->weight) {
		// p1 shorter than p2
		shortest = p1;
	} 
	else if(p2->weight < p1->weight) {
		// p2 shorter than p1
		shortest = p2;
	}
	else {
		// p1 and p2 have same weight
		if(p1->edges.size() < p2->edges.size()) {
			shortest = p1;
		}
		else {
			shortest = p2;
		}
	}
	return shortest;
}

// Gets the new potential path
Path *get_potential(Path *p1, Path *p2) {

}
#endif
