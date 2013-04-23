/**
 * http://uva.onlinejudge.org/external/125/12549.html
 * Status: 		Accepted
 * Run Time:	0.024
 */

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int y, x;
vector<vector<int> > grid;
vector<pair<int,int> > interest;

// Count number of interests from one coordination in a orientation
// orient: 0: north; 1: south; 2: east; 3: west
int count_interst(pair<int,int> coor, int orient) {
	int dx, dy;
	switch (orient) {
	case 0:
		dx = 0; dy = -1;
		break;
	case 1:
		dx = 0; dy = 1;
		break;
	case 2:
		dx = -1; dy = 0;
		break;
	case 3:
		dx = 1; dy = 0;
		break;
	}
	
	int ret = 0;	// including interest at original coordinate
	int next_y = coor.first, next_x = coor.second;
	while (next_x >= 0 && next_x < x && next_y >= 0 && next_y < y &&
			(grid[next_y][next_x] != -1)) {
		
		ret += (grid[next_y][next_x] == 1);
		next_x += dx; next_y += dy;
	}
	
	return ret;
}

// Remove interests from one coordination in a orientation
// orient: 0: north; 1: south; 2: east; 3: west
void remove_interest(pair<int,int> coor, int orient) {
	int dx, dy;
	switch (orient) {
	case 0:
		dx = 0; dy = -1;
		break;
	case 1:
		dx = 0; dy = 1;
		break;
	case 2:
		dx = -1; dy = 0;
		break;
	case 3:
		dx = 1; dy = 0;
		break;
	}
	
	int next_x = coor.second, next_y = coor.first;
	while (next_x >= 0 && next_x < x && next_y >= 0 && next_y < y &&
			(grid[next_y][next_x] != -1)) {
			
		if (grid[next_y][next_x] == 1) {
		
			// Search through the list and remove
			for (unsigned int i = 0; i < interest.size(); i += 1) {
				if ((interest[i].first == next_y) && 
						(interest[i].second == next_x)) {
					
					interest.erase(interest.begin()+i);
					break;			
				}
			}
		}
		next_x += dx; next_y += dy;
	}
}

int solve()  {
	int ret = 0;
	while (interest.size() > 0) {
		unsigned int size = interest.size();
		vector<vector<int> > orient(size, vector<int>(4,0));
		pair<int,int> max_coor;
		int max_watch = -1;
		int max_orient;
		for (unsigned int i = 0; i < size; i += 1) {
			for (unsigned int j = 0; j < 4; j += 1) {
				orient[i][j] = count_interst(interest[i], j);
				if (max_watch < orient[i][j]) {
					max_coor = interest[i];
					max_watch = orient[i][j];
					max_orient = j;
				}
			}
		}
		
//		for (unsigned int i = 0; i < size; i += 1) {
//			for (unsigned int j = 0; j < 4; j += 1) {
//				printf("(%d,%d):%d = %d\n",interest[i].first,
//						interest[i].second,j,orient[i][j]);			
//			}
//			printf("--------------\n");
//		}
		
//		printf("Remove interst at (%d,%d) with orientation %d.\n", max_coor.first, max_coor.second, max_orient);
		remove_interest(max_coor, max_orient);
		ret++;
	}
	
	return ret;
}

int main (int argc, char const* argv[]) {
	int c;
	cin >> c;
	
	for (unsigned int i = 0; i < c; i += 1) {
		// Grid inputs
		cin >> y >> x;
		grid = vector<vector<int> >(y, vector<int>(x, 0));
		
		// Points of interest inputs (1)
		int p;
		cin >> p;
		int py, px;
		for (unsigned int i = 0; i < p; i += 1) {
			cin >> py >> px;
			grid[py-1][px-1] = 1;
			interest.push_back(make_pair(py-1, px-1));
		}
		
		// Obstacle inputs (-1)
		int w;
		cin >> w;
		int wy, wx;
		for (unsigned int i = 0; i < w; i += 1) {
			cin >> wy >> wx;
			grid[wy-1][wx-1] = -1;
		}
		
		printf("%d\n", solve());
		
		// Clear inputs
		grid.clear();
		interest.clear();
	}	
		
	return 0;
}

