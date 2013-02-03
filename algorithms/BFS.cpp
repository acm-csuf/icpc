// Authors:  Dustin & Fidel
#include <iostream>
#include "graph.hh"
#include <vector>
#include <memory>
#include <queue>

using namespace std;

// modify this method to do w/e computations are desired on
// the visited node
void visit(int node){ cout << node << endl; };


// Breadth First Search traversal
//   @arg - Graph : a graph
//   @arg - start_node : where to start
//   @return - a pointer to an ordered vector of visited nodes
void BFS(Graph g, int start_node){
	vector<bool> visited(g.n());
	fill(visited.begin(), visited.end(), false);
	queue<int> q;
	vector<int>* result;
    
	
	visit(start_node);
	visited[start_node] = true;
	q.push(start_node);
	
	
	while(!q.empty()){
		int current = q.front();
		q.pop();
		
		for( int i =0; i < g.adj[current].size(); i++){
			int end = g.adj[current][i]->opposite(current);
			if(visited[end]==false){
				visit(end);
				visited[end] = true;
				q.push(end);
			}
		}
		
	}		
};
	


int main(){
    // example from
    // http://en.wikipedia.org/wiki/Kruskal%27s_algorithm#Example
    const int A=0, B=1, C=2, D=3, E=4, F=5, G=6;
    Graph g(7);
    g.add_edge(A, B);  // 0
    g.add_edge(A, D);  // 1
    g.add_edge(B, C);  // 2
    g.add_edge(B, D);  // 3
    g.add_edge(B, E);  // 4
    g.add_edge(C, E);  // 5
    g.add_edge(D, E);  // 6
    g.add_edge(D, F);  // 7
    g.add_edge(E, F);  // 8
    g.add_edge(E, G);  // 9
    g.add_edge(F, G);  // 10    


	// Start BFS	
	int start_vertex = 0;
	vector<int>* result;
	BFS(g, start_vertex);

    
    return 0;
}


