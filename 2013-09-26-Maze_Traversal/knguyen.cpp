/** 
 * http://uva.onlinejudge.org/external/103/10377.html
 * Status: Accepted
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define pos pair<ii, int>

#define mp make_pair

int main() {
	int t; // # of cases
	cin >> t;
	
	for (int k = 0; k < t; k++) {
		int rows, cols;
		cin >> rows >> cols;

		vector<vector<bool> > maze(rows, vector<bool>(cols,false));
		char c;
		scanf("%c", &c);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				scanf("%c", &c);
				if (c == '*') {
					maze[i][j] = true;
				}
			}
			scanf("%c", &c);
		}
		
		/*
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				printf("%d ", maze[i][j]?1:0);
			}
			printf("\n");
		}
		*/
		
		pos r(ii(0,0), 0);
		cin >> r.f.f >> r.f.s;
		r.f.f--; r.f.s--;
		
		//printf("(%d,%d)\n",r.f.f,r.f.s);
		
		while (scanf("%c", &c) && (c != 'Q')) {
			switch (c) {
				case 'R':
					r.s = (r.s + 1) % 4;
					break;
				
				case 'L':
					r.s = (r.s + 3) % 4;
					break;
					
				case 'F':
					switch (r.s) {
						case 0:
							if ((r.f.f - 1 >= 0) && !maze[r.f.f - 1][r.f.s])
								r.f.f--;
							break;
							
						case 1:
							if ((r.f.s + 1 < cols) && !maze[r.f.f][r.f.s + 1])
								r.f.s++;			
							break;
							
						case 2:
							if ((r.f.f + 1 < rows) && !maze[r.f.f + 1][r.f.s])
								r.f.f++;
							break;
							
						case 3:
							if ((r.f.s - 1 >= 0) && !maze[r.f.f][r.f.s - 1])
								r.f.s--;
							break;
					}
					break;
					
			}
			
			//printf("-> (%d, %d, %d)\n", r.f.f, r.f.s, r.s);
		}
		
		printf("%d %d", r.f.f + 1, r.f.s + 1);
		switch (r.s) {
			case 0:
				printf(" N\n");
				break;
			case 1:
				printf(" E\n");
				break;
			case 2:
				printf(" S\n");
				break;
			case 3:
				printf(" W\n");
				break;
		}
		if (k < t-1)
			printf("\n");
	}
	
	return 0;
}
