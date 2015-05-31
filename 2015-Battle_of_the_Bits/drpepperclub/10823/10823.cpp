// 10823
#include <iostream>
#include <iomanip>
#include <string>
#include "math.h"

using namespace std;

struct obj {
	string type;
	int cx;
	int cy;
	int len;
	int r;
	int g;
	int b;
};

bool isOnObj(int px, int py, obj* myobj) {
	if (myobj->type == "SQUARE") {
		if (((px == myobj->cx) || (px == myobj->cx + myobj->len)) && ((py >= myobj->cx) || (py <= myobj->cy + myobj->len))) {
			return true;
		}
		if (((py == myobj->cy) || (py == myobj->cy + myobj->len)) && ((px >= myobj->cy) || (px <= myobj->cx + myobj->len))) {
			return true;
		}
		return false;
	}
	
	//else circle
	if (pow(px - myobj->cx, 2) + pow(py - myobj->cy, 2) == pow(myobj->len, 2)) {
		return true;
	}
	return false;
}

bool isInObj(int px, int py, obj* myobj) {
	if (myobj->type == "SQUARE") {
		if ((px > myobj->cx) && (px < myobj->cx + myobj->len) && (py > myobj->cy) && (py < myobj->cy + myobj->len)) {
			return true;
		}
		return false;
	}
	
	//else circle
	if (pow(px - myobj->cx, 2) + pow(py - myobj->cy, 2) < pow(myobj->len, 2)) {
		return true;
	}
	return false;
}

int main(){
	// Variables
	int numCases;
	int numObjs;
	int numPoints;
	int px;
	int py;
	
	
	cin >> numCases;
	
	for (int i=1; i <= numCases; i++) {
		cin >> numObjs >> numPoints;
		cout << "Case " << i << ":" << endl;
		
		int currR = 0;
		int currG = 0;
		int currB = 0;
		int numIntersections = 0;
		
		obj objs[numObjs];
		for (int i=0; i < numObjs; ++i) {
			cin >> objs[i].type
			    >> objs[i].cx
			    >> objs[i].cy
			    >> objs[i].len
			    >> objs[i].r
			    >> objs[i].g
			    >> objs[i].b;
		}
		for (int i=0; i < numPoints; ++i) {
			cin >> px >> py;
			numIntersections = 0;
			if (isOnObj(px, py, &(objs[i]))) {
				currR = currG = currB = 0;
			}
			else {
				for (int j=0; j < numObjs; ++j) {
					if (isInObj(px, py, &(objs[j]))) {
						currR += objs[j].r;
						currG += objs[j].g;
						currB += objs[j].b;
						++numIntersections;
					}
				}
				if (numIntersections > 0) {
					currR = int((currR / numIntersections) + .5);
					currG = int((currG / numIntersections) + .5);
					currB = int((currB / numIntersections) + .5);
				}
				else {
					currR = currG = currB = 255;
				}
			}
			cout << "(" << currR << ", " << currG << ", " << currB << ")" << endl;
		}
		cout << endl;
	}	
	
	return 0;
}
