/**
 * Problem: http://uva.onlinejudge.org/external/5/507.html
 * 
 * Status: UNSOLVED :( 
 *
 * Attempt1: solve() 	:: Time limit exceeded
 * Attempt2: solve2() :: Time limit exceeded
 * Attempt3: solve3() :: Wrong answer @ 0.476s
 */

#include <vector>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;		// position pair
typedef vector<int> vi;			

#define MIN_VAL -1000000

vi nice;
vector<vi> f;

// Use something similar to Floyd algorithm
// Result: Time Exceeding Limit
pair<ii, int> solve() {
	int size = (int) nice.size() + 1;
	vector<vi> f(size, vi(size,MIN_VAL));
	
	for (int i = 0; i < size; i++) 
		f[i][i] = 0;
		
	for (int i = 0; i < size-1; i++)
		f[i][i+1] = nice[i];
	
	
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

// Calculate niceness between stops i and j.
// Use for solve2 function
int niceness(int i, int j) {
	// base case
	if (i == j) 
		return 0;
	
	// given
	if ((j-i) == 1) {
		return nice[i];
	}
	
	// lookup case
	if (f[i][j] > MIN_VAL) {
		return f[i][j];
	}
	
	f[i][(i+j)/2] = niceness(i, (i+j)/2);
	f[(i+j)/2][j] = niceness((i+j)/2, j);
	f[i][j] = f[i][(i+j)/2] + f[(i+j)/2][j];
	return f[i][j];
}

// Recurion and look-up table
// Result: Time Exceeding Limit
pair<ii, int> solve2() {
	int size = (int) nice.size() + 1;
	f = vector<vi>(size, vi(size,MIN_VAL));
	
	ii res;
	int max = MIN_VAL;
	int longest = size;
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			int n = niceness(i, j);
			if ((max < n) ||
					((max == n) && longest < (j-i))) {
				max = n;
				res = make_pair(i,j);
				longest = j-i;
			} 
		}
	}
	
	return make_pair(res, max);
}

// Compact
// Result: Wrong answer @ 0.476s
pair<ii, int> solve3() {
	int size = (int) nice.size();
	vector<ii> track_ii;
	vi track_i;
	int start = 0;
	int sum = 0;
	
	bool sign_start = (nice[0] > 0);
	bool sign = sign_start; // TRUE if > 0; otherwise, FALSE
	for (int i = 0; i < size; i++) {
		if (sign != (nice[i] > 0)) {
			track_ii.push_back(make_pair(start, i-1));
			track_i.push_back(sum);
			sign = (nice[i] > 0);
			start = i;
			sum = nice[i];
		} else {
			sum += nice[i];
		}
	}
	track_ii.push_back(make_pair(start, size-1));
	track_i.push_back(sum);
	
//	for (int i = 0; i < (int) track_i.size(); i++) {
//		printf("(%d -> %d): %d\n", track_ii[i].first, track_ii[i].second, track_i[i]);
//	}

	bool change = true;
	start = (sign_start ? 0 : 1);
	while (change) {
		change = false;
		while (track_i.size() > start + 2) {
			int new_val = track_i[start] + track_i[start+1] + track_i[start+2];
			if ((new_val >= track_i[start]) && (new_val >= track_i[start+2])) {
				track_i[start] += (track_i[start+1] + track_i[start+2]);
				track_i.erase(track_i.begin()+start+1, track_i.begin()+start+3);
				track_ii[start].second = track_ii[start+2].second;
				track_ii.erase(track_ii.begin()+start+1, track_ii.begin()+start+3);
				change = true;
			} else {
				start += 2;
			}
			
//			printf("-------------\n");
//			for (int i = 0; i < (int) track_i.size(); i++) {
//				printf("(%d -> %d): %d\n", track_ii[i].first, track_ii[i].second, track_i[i]);
//			}
		}
		start = (sign_start ? 0 : 1);
	}
	
//	printf("-----------------------\n");
//	for (int i = 0; i < (int) track_i.size(); i++) {
//		printf("(%d -> %d): %d\n", track_ii[i].first, track_ii[i].second, track_i[i]);
//	}
	
	int max = MIN_VAL;
	int longest = 0;
	ii res;
	for (int i = 0; i < (int) track_i.size(); i++) {
		if (track_i[i] > max) {
			max = track_i[i];
			res = track_ii[i];
			longest = res.second - res.first;
		} 
		
		if ((track_i[i] == max) && (longest < (track_ii[i].second - track_ii[i].first))) {
			res = track_ii[i];
			longest = res.second - res.first;
		}
	}
	
	return make_pair(res, max);
}


int main() {
	int b;
	scanf("%d", &b);		// # of route descriptions
	
	int s;			// # of stops
	for (int i = 0; i < b; i++) {
		scanf("%d", &s);
		nice = vi ((s-1), 0);
		for (int j = 0; j < (s-1); j++) {
			scanf("%d", &nice[j]);
		}
		
		pair<ii, int> result = solve3();
		if (result.second <= 0) {
			printf("Route %d has no nice parts\n", i+1);
		} else {
//			printf("The nicest part of route %d is between stops %d and %d\n", i+1, result.first.first+1, result.first.second+1);
			printf("The nicest part of route %d is between stops %d and %d\n", i+1, result.first.first+1, result.first.second+2); 	// solve3 only
		}
						
		nice.clear();
	}

	return 0;
}
