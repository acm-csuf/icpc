#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include "graph.hh"

const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;
const int E = 4;
const int F = 5;
const int G = 6;
const int H = 7;
const int I = 8;

bool depthFirstSearch(Graph * g, int startingNode, int endingNode)
{
	set <int> visitedSet;
	queue <int> edgeQueue;
	edgeQueue.push(startingNode);
	do
	{
		int currentVertex= edgeQueue.front();
		edgeQueue.pop();
		printf("Current vertex = %d\n", currentVertex);
		//Modify here
		if (currentVertex == endingNode)
		{
			return true;
		}
		visitedSet.insert(currentVertex);
		for (unsigned int i = 0; i < g->adj[currentVertex].size(); i++)
		{
			int vert = g->adj[currentVertex][i]->opposite(currentVertex);
			if (visitedSet.find(vert) == visitedSet.end())
			{
				edgeQueue.push(vert);
			}
		}
	}
	while (!edgeQueue.empty());

	return false;
}

int main()
{
	Graph * g = new Graph(9);
	g->add_edge(A,B,false,5);		//0
	g->add_edge(B,C,false,12);		//1
	g->add_edge(C,D,false,6);		//2
	g->add_edge(D,E,false,8);		//3
	g->add_edge(E,F,false,15);		//4
	g->add_edge(F,G,false,6);		//5
	g->add_edge(G,H,false,8);		//6
	g->add_edge(H,I,false,3);		//7
	g->add_edge(A,F,false,15);		//8
	g->add_edge(D,G,false,6);		//9
	g->add_edge(F,H,false,8);		//10
	g->add_edge(C,I,false,3);		//11

	if (depthFirstSearch(g, A, H))
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}

	if (depthFirstSearch(g, A, 64))
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
//	for (int j = 0; j < 9; j++)
//	{
//		for (unsigned int i = 0; i < g->adj[j].size(); i++)
//		{
//			printf("g->adj[%d][%d]->index=%d\n",j, i,g->adj[j][i]->index);
//		}
//	}
	return 0;
}
