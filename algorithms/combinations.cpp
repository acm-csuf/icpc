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
	
	// turn on n-k bits in bool vector, off bits will represent active elements
	int num_to_choose = 3;
	fill(active.begin() + num_to_choose, active.end(), true);
	
	// loop for generating combinations	
	do {
		// if current index is "off" print value at index
		/* alternatively you could push these values into a temp vector and
		apply your desired computations to the temp vector, clearing the
		vector between each iteration */
		for(int i=0; i<active.size(); i++){
			if(!active[i]) { cout << values[i] << ' '; }
		}
		cout << endl;
	/* next_permutation generates permutations lexicographically.  Each time 
	next_permutation is called it shifts the elements of the argument
	vector to generate the next "largest" order.  In our bool vector 00111 is
	the "smallest" permutation, while 11100 is the largest.  This loop will
	end	up generating exactly n choose k combinations */
	}while(next_permutation(active.begin(), active.end()));

	return 0;
}
		
		
		
	

	
