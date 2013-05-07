/**
 * http://uva.onlinejudge.org/external/1/151.html
 * Status: Accepted
 */

#include <cstdio>
#include <vector>

using namespace std;

enum status {ALREADY_OFF = true, NOT_YET_OFF = false};
enum region_name {AUCKLAND = 0, WELLINGTON = 12};

int main (int argc, char const* argv[]) {
	int N;	// # of regions
	
	scanf("%d", &N);
	
	while (N != 0) {
		int m = -1;	
		
		for (unsigned int i = 1; i < N; i++) {
			int count = N-1;	// # of remaining regions that haven't been off yet
			int index = 0;	// index of which regions from 0 to N-1
			vector<bool> off(N, NOT_YET_OFF);	// to keep track which region is already off (true) or not-yet (false)
			off[AUCKLAND] = ALREADY_OFF;	// always start from Auckland (region 1, index 0)
			
			// keep turn off one region for each iteration until Wellington (region 13, index 12) 
			// turn off early or all regions got turned off
			while (count > 0 && index != WELLINGTON) {
				int j=0;	// to count up to m
				
				// find next region to turn off by counting up m not-yet-off regions
				do {
					index = (++index) % N;
					j += (!off[index]);
				} while (off[index] || (j<i));
				
				//printf("\t%d",index);

				// decrease # of remaining regions
				count--;
				// set chosen region to already-off
				off[index] = ALREADY_OFF;
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
