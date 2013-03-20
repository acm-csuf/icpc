// UVa 12376 - As Long as I Learn, I Live
// http://uva.onlinejudge.org/external/123/12376.html

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

int main() {
	vi w;												// learning units
	vector<vi> adj;							// adjacent list
	
	int t;											// # of test cases
	cin >> t;
	
	for (int i=0; i<t; i++) {
		int n, m;									// n: # of nodes; m: # of edges
		cin >> n >> m;
		
		int wt;										// wt: temp learning unit
		for (int j=0; j<n; j++) {
			cin >> wt;
			w.push_back(wt);
			adj.push_back(vi());
		}
				
		int fr, to;								// fr: from node; to: to node
		for (int j=0; j<m; j++) {
			cin >> fr >> to;
			adj[fr].push_back(to);
		}
		
		int totalL = 0;						// totalL: total learning
		int curr = 0;							// curr: current checking node
		while (adj[curr].size() > 0) {
			int maxL = 0;						// maxL: max learning units from 1 node
			int maxP = -1;					// maxP: node that has that max 
			for (int j=0; j < (int)adj[curr].size(); j++) {
				if (maxL < w[adj[curr][j]]) {
					maxL = w[adj[curr][j]];
					maxP = adj[curr][j];
				}
			}
			curr = maxP;
			totalL += maxL;
		}
		
		printf("Case %d: %d %d\n", (i+1), totalL, curr);
		
		w.clear();
		adj.clear();
	}
	
	return 0;
}
