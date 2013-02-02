#ifndef FLOYD
#define FLOYD
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdio.h>
#include "attraction.h"

const int INF =  std::numeric_limits<int>::max();

//INPUT: complete graph, with edge weights calculated by distanceTo
//OUTPUT: matrix where [i][j] represents the shortest path weight from i to j
std::vector<std::vector<int> > floyd(std::vector<attraction> &attrs) {
	//initialize apsp matrix
	std::vector<std::vector<std::vector<int> > > temp(attrs.size() + 1, 
									std::vector<std::vector<int> >(attrs.size(),
										std::vector<int>(attrs.size(), INF)));

	for(int i = 0; i < attrs.size(); i++) {
		for(int j = 0; j < attrs.size(); j++) {
			if(i == j)
				temp[0][i][j] = 0;
			else //this is the only line that needs to be changed
				temp[0][i][j] = std::min(INF, attrs[i].distanceTo(attrs[j]));			
		}
	}

	//calculate all-pairs shortest path
	for(int k = 1; k < attrs.size() + 1; k++) {
		for(int i = 0; i < attrs.size(); i++) {
			for(int j = 0; j < attrs.size(); j++) {
				temp[k][i][j] =  
					std::min(
						temp[k - 1][i][k - 1] + temp[k - 1][k - 1][j],
						temp[k - 1][i][j]
					);
			}	
		}	
	}	

	return temp[attrs.size()];
}

//print apsp
void printApsp(std::vector<std::vector<int> > &apsp, int numItems) {
	for(int i = 0; i < numItems; i++) {
		for(int j = 0; j < numItems; j++) {
			printf("%-7d", apsp[i][j]);
		}
		std::cout << std::endl;
	}
}

#endif
