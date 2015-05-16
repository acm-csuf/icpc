
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;

    vector<long long> S;
    for (int i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      S.push_back(x);
    }

    sort(S.begin(), S.end());

    bool solved = false;
    for (int di = n-1; (di >= 0) && !solved; --di) {
      for (int ai = 0; (ai < n) && !solved; ++ai) {
	for (int bi = 0; (bi < n) && !solved; ++bi) {
	  for (int ci = 0; (ci < n) && !solved; ++ci) {
	    if ((di != ai) &&
		(di != bi) &&
		(di != ci) &&
		(ai != bi) &&
		(ai != ci) &&
		(bi != ci)) {
	      if ( (S[ai] + S[bi] + S[ci]) == S[di] ) {
		cout << S[di] << endl;
		solved = true;
	      }
	    }
	  }
	}
      }
    }

    if (!solved) {
      cout << "no solution" << endl;
    }
  }
  return 0;
}

