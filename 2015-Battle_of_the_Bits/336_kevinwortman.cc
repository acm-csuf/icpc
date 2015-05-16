
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 30,
  MAX_TTL = MAX_N,
  INF = 999;

int find_index(map<int, int>& id_to_index, int id) {
  if (id_to_index.count(id) > 0) {
    return id_to_index[id];
  } else {
    int index = id_to_index.size();
    id_to_index[id] = index;
    return index;
  }
}

int main() {

  int case_num = 1;

  while (true) {
    int m;
    cin >> m;
    if (!cin) {
      break;
    }

    if (m == 0)
      break;

    map<int, int> id_to_index;

    // read edges into adjacency matrix
    vector<vector<bool> > adj(MAX_N, vector<bool>(MAX_N, false));
    for (int i = 0; i < m; ++i) {
      int s_id, t_id;
      cin >> s_id >> t_id;
      assert(cin);

      int s = find_index(id_to_index, s_id),
	t = find_index(id_to_index, t_id);

      adj[s][t] = adj[t][s] = true;
    }

    int n = id_to_index.size();

    // Floyd-Warshall

    vector<vector<int> > dist(n, vector<int>(n, INF));

    for (int v = 0; v < n; ++v) {
      for (int w = 0; w < n; ++w) {
	if (v == w)
	  dist[v][w] = 0;
	else if (adj[v][w])
	  dist[v][w] = 1;
      }
    }

    for (int k = 0; k < n; ++k) {
      for (int v = 0; v < n; ++v) {
	for (int w = 0; w < n; ++w) {
	  if ((dist[v][k] != INF) && (dist[k][w] != INF)) {
	    dist[v][w] = min(dist[v][w],
			     dist[v][k] + dist[k][w]);
	  }
	}
      }
    }

    // queries
    while (true) {
      int start_id, ttl;
      cin >> start_id >> ttl;
      assert(cin);

      if (start_id == 0)
	break;

      int unreachable = 0,
	s = id_to_index[start_id];
      for (int v = 0; v < n; ++v) {
	if (dist[s][v] > ttl) {
	  ++unreachable;
	}
      }

      cout << "Case " << case_num 
	   << ": " << unreachable 
	   << " nodes not reachable from node " << start_id 
	   << " with TTL = " << ttl 
	   << "." << endl;
      ++case_num;
    }
  }

  return 0;
}

