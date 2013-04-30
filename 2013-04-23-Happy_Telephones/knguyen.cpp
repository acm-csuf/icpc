/**
 *	http://uva.onlinejudge.org/external/122/12205.html
 *	Status: Accepted
 */

#include <vector>
#include <cstdio>

using namespace std;

int main (int argc, char const* argv[]) {
	// N: number of phone calls
	// M: number of intervals
	int N, M;	
	scanf("%d %d", &N, &M);
	
	// s: source (dummy, not used)
	// d: destination (dummy, not used)
	// st: start time
	// du: duration of an interval
	int s, d, st, du;
	
	// pst: police start time
	// pdu: police duration of an interval
	// pet: police end time
	int pst, pdu, pet;
	
	// count: number of active calls within police interval
	int count;
	while (N != 0 && M != 0) {
		// times: vector of N pairs of start time and end time of a call
		vector<pair<int,int> > times(N,pair<int,int>());
		
		// Input calls
		for (unsigned int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &s, &d, &st, &du);
			times[i] = make_pair(st,st+du);
		}
		
		// Input police check interval and process
		for (unsigned int i = 0; i < M; i++) {
			count = 0;
			scanf("%d %d", &pst, &pdu);
			pet = pst + pdu;
			
			// Scan through all input calls
			for (unsigned int j = 0; j < N; j++) {
				// Check for each second to see if there is an active call
				for (unsigned int k = max(pst,times[j].first); k < min(pet,times[j].second); k++) {
					if ((k >= pst && k < pet) || (k > pst && k <= pet)) {
						count++;
						break;		
					}
				}
			}
			printf("%d\n",count);
		}
		
		scanf("%d %d", &N, &M);
	}
	
	return 0;
}
