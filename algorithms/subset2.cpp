// Author: Dustin Delmer
// Date: 2/2/2013
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	// initialize vector and fill	
	vector<int> values;
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);
	values.push_back(5);

	// create a bool vector of the same length to mark "active" elements
	vector<bool> active(5);
	
	// outer loop increments set size
	for(int i = 1; i <= active.size(); i++){
		int num_to_choose = i;
		fill(active.begin(), active.end(), false);
		fill(active.begin() + num_to_choose, active.end(), true);
	
		// loop for generating combinations	of current set size
		do {
			for(int i=0; i<active.size(); i++){
				if(!active[i]) { cout << values[i] << ' '; }
			}
			cout << endl;
		}while(next_permutation(active.begin(), active.end()));
	}

	return 0;
}
		
		
		
	

	
