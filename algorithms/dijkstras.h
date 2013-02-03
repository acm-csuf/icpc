#ifndef DIJKSTRAS
#define DIJKSTRAS

#include "graph.hh"
#include <vector>
using namespace std;

struct TempNode
{
	bool in_set;
	int number;
	int came_from;
	double path_length;
};

Path Dijkstras(Graph grph, int start, int end, double &path_length)
{
    path_length = 0;
    vector<TempNode> verticies;
	int count = 0, min_dist = 32000000, min_index = 0;
	Path path;

    TempNode temp;
    for (int i=0; i<grph.n(); i++)
     {
		temp.number = i;
		temp.in_set = true;
		if (i == start)
		{
			temp.path_length = 0;
		}
		else
		{
			temp.path_length = 32000000;
		}
		verticies.push_back(temp);
     }

	count = verticies.size();
    while (count > 0)
    {
		min_dist = 32000000;
		min_index = 0;
		for (int i=0; i<verticies.size(); i++)
		{
			if (verticies[i].path_length < min_dist && verticies[i].in_set == true)
			{
				min_dist = verticies[i].path_length;
				min_index = i;
			}
		}

		if (min_index == end)
		{
			path_length = verticies[min_index].path_length;
			break;
		}
		verticies[min_index].in_set = false;
		count--;

		for (int i=0; i<grph.edges.size(); i++)
		{
			if (grph.edges[i]->v == min_index)
			{

				path_length = verticies[grph.edges[i]->w].path_length;
				if (verticies[grph.edges[i]->w].path_length > verticies[min_index].path_length + grph.edges[i]->weight)
				{
					verticies[grph.edges[i]->w].path_length = verticies[min_index].path_length + grph.edges[i]->weight;
					verticies[grph.edges[i]->w].came_from = min_index;
				}
			}
		}
    }

	int a = end;
	int b = 0;
	do
	{
		b = verticies[a].came_from;
		path = path.extend(*grph.connection(a,b));
		a = b;
	}while (verticies[a].path_length > 0);

	return path;
}
 
#endif
