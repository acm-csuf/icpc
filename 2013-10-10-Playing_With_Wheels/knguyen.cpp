/** 
 * http://uva.onlinejudge.org/external/100/10067.html
 * Status: Accepted
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

#define mp make_pair
#define x first
#define l second

typedef pair<int,int> ii;

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int tmp[4];
		scanf("%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
		int init = tmp[0]*1000 + tmp[1]*100 + tmp[2]*10 + tmp[3];
		
		scanf("%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
		int target = tmp[0]*1000 + tmp[1]*100 + tmp[2]*10 + tmp[3];
		
		int nforbid;
		scanf("%d", &nforbid);
		
		vector<bool> bt(10000,false);
		bt[init] = true;
		for (int j = 0; j < nforbid; j++) {
			scanf("%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
			bt[tmp[0]*1000 + tmp[1]*100 + tmp[2]*10 + tmp[3]] = true;
		}
		
		//printf("%d -> %d\n", init, target);

		queue<ii> q;
		q.push(mp(init,0));
		bt[init] = true;
		
		int currNum, currLvl, nextNum;
		bool found = false;
		while (q.size() > 0) {
			currNum = q.front().x;
			currLvl = q.front().l;
			q.pop();
			
			if (currNum == target) {
				found = true;
				break;
			}
			
			// 1000
			nextNum = ((currNum / 1000 + 1) % 10) * 1000 + (currNum % 1000);
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
			
			nextNum = ((currNum / 1000 + 9) % 10) * 1000 + (currNum % 1000);
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
			
			// 100
			nextNum = (currNum / 1000 * 1000) + (currNum % 1000 / 100 + 1) % 10 * 100 + (currNum % 100);
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
			
			nextNum = (currNum / 1000 * 1000) + (currNum % 1000 / 100 + 9) % 10 * 100 + (currNum % 100);
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
			
			// 10
			nextNum = (currNum / 100 * 100) + (currNum % 100 / 10 + 1) % 10 * 10 + (currNum % 10);
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
			
			nextNum = (currNum/100 * 100) + (currNum % 100 / 10 + 9) % 10 * 10 + (currNum % 10);
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
			
			// 1
			nextNum = (currNum / 10 * 10) + (currNum % 10 + 1) % 10;
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
			
			nextNum = (currNum / 10 * 10) + (currNum % 10 + 9) % 10;
			if (!bt[nextNum]) {
				q.push(mp(nextNum,currLvl+1));
				bt[nextNum] = true;
			}
		}
		
		if (found) printf("%d\n", currLvl);
		else printf("-1\n");
	}
	
	return 0;
}
