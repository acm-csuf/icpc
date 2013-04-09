#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

#define MIN_VAL -1000000

// Use Floyd algorithm
pair<ii, int> solve(vi n) {
	int size = (int) n.size() + 1;
	vector<vi> f(size, vi(size,MIN_VAL));
	
	for (int i = 0; i < size; i++) 
		f[i][i] = 0;
		
	for (int i = 0; i < size-1; i++)
		f[i][i+1] = n[i];
	
	
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			for (int k = i+1; k < j; k++) {
				f[i][j] = max(f[i][j], f[i][k]+f[k][j]);
			}
		}
	}
	
	ii res;
	int max = MIN_VAL;
	int longest = size;
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			if ((max < f[i][j]) ||
					((max == f[i][j]) && longest < (j-i))) {
				max = f[i][j];
				res = make_pair(i,j);
				longest = j-i;
			} 
		}
	}
	
	return make_pair(res, max);
}

// 
pair<ii, int> solve2(vi n) {
	
	
}

int main() {
	int b;
	scanf("%d", &b);		// # of route descriptions
	
	int s;			// # of stops
	for (int i = 0; i < b; i++) {
		scanf("%d", &s);
		vi nice;
		int n; 		// niceness between stops
		for (int j = 0; j < (s-1); j++) {
			scanf("%d", &n);
			nice.push_back(n);
		}
		
		pair<ii, int> result = solve(nice);
		if (result.second <= 0) {
			printf("Route %d has no nice parts\n", i+1);
		} else {
			printf("The nicest part of route %d is between stops %d and %d\n", i+1, result.first.first+1, result.first.second+1);
		}
						
		nice.clear();
	}

	return 0;
}
