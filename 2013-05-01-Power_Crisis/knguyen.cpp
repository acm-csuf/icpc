/**
 * http://uva.onlinejudge.org/external/1/151.html
 * Status: Accepted
 */

#include <cstdio>
#include <vector>

using namespace std;

int main (int argc, char const* argv[]) {
	int N;	// # of regions
	
	scanf("%d", &N);
	
	while (N != 0) {
		int m = -1;	
		
		for (unsigned int i = 1; i < N; i++) {
			int count = N-1;	// # of regions that haven't been off yet
			int index = 0;	// index of which regions from 0 to N-1
			vector<bool> off(N,false);	// to keep track which region is on (true) or off (false)
			off[index] = true;	// always start from Auckland, which is 1
			
			while (count > 0 && index != 12) {
				int j=0;	// to count up to m
				do {
					index = (index+1) % N;
					j += (!off[index]);
				} while (off[index] || (j<i));
				
				//printf("\t%d",index);

				count--;
				off[index] = true;
			}	
			
			//printf("\t%s\n", (count==0?"found":"not"));

			// the smallest number m that satisfies conditions
			if (count == 0) {
				m = i;
				break;
			}
		}
	
		printf("%d\n", m);
		scanf("%d", &N);
	}
	
	return 0;
}
