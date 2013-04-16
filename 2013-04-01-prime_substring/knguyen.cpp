/**
 * http://uva.onlinejudge.org/external/125/12542.html
 * Status: Accepted
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool primes[100001];

void buildPrimes() {
	memset(primes, false, sizeof(primes));
	primes[2] = true;
	vector<int> allPrimes;
	allPrimes.push_back(2);
	
	for (int i = 3; i < 100001; i++) {
		bool is_prime = true;
		int max_check = (int) ceil(sqrt(i));
		for (int j = 0; j < (int) allPrimes.size(); j++) {
			if (allPrimes[j] > max_check)
				break;
				
			if (i % allPrimes[j] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) 
			allPrimes.push_back(i);
		primes[i] = is_prime;
	}
	
//	for (int i = 2; i < 100001; i++) {
//		if (primes[i]) printf("%d\n",i);
//	}
}

int main() {
	buildPrimes();

	string line;
	cin >> line;
	
	while (line != "0") {
		int max = 0;
		int size = (int) line.size();
		for (int i = 0; i < size; i++) {
			for (int j = 1; j <= size-i; j++) {
					if (j > 5) continue;
					int num = atoi(line.substr(i,j).c_str());
//					printf("Num: %d\n", num);
					if ((max < num) && primes[num]) {
						max = num;
					}
			}
		}
		cout << max << endl;
		
		cin >> line;
	}
	
	return 0;
}
