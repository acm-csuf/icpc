#include <iostream>
#include "graph.hh"
#include "dijkstras.h"
using namespace std;

enum nodes {A, B, C, D, E, F, G};

int main()
{
	double length;

	Graph graph(7);
	graph.add_edge(A,B,false,7);
	graph.add_edge(A,D,false,5);
	graph.add_edge(B,C,false,8);
	graph.add_edge(B,D,false,9);
	graph.add_edge(B,E,false,7);
	graph.add_edge(C,E,false,5);
	graph.add_edge(D,F,false,6);
	graph.add_edge(E,G,false,9);
	graph.add_edge(E,F,false,8);
	graph.add_edge(F,G,false,11);

	Dijkstras(graph, A, G, length);
	cout << length << endl;

	system("pause");
	return 0;
}