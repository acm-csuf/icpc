// ============================================================================
// Programmer: Brittany Parker
// Date: October 23, 2014
// Description:
//	This is my solution to problem 624 - CD, accepted through UVa. I used
// Dustin Delmer's code from combinations.cpp in the algorithms section to
// generate combinations.
// ============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int tapeLen;
	int numTracks;
	int bestSum;
	int sum;
	stringstream ssBestSolution;

	// loop until eof
	while (cin >> tapeLen)
	{
		bestSum = 0;
		sum = 0;
		cin >> numTracks;

		int trackTimes[numTracks];
		for(int i=0; i < numTracks; ++i)
		{
			cin >> trackTimes[i];
		}

		// create a bool vector of the same length to mark "active" elements
		vector<bool> active(numTracks);

		// loop through (n choose 1) combinations to (n choose numTracks) combinations
		for(int num_to_choose=1; num_to_choose <= numTracks; ++num_to_choose)
		{
			// turn on n-k bits in bool vector, off bits will represent active elements
			fill(active.begin() + num_to_choose, active.end(), true);

			// loop for generating combinations
			do {
				// if current index is "off", include track time in sum
				for(int i=0; i<active.size(); i++)
				{
					if(!active[i])
					{
						sum += trackTimes[i];
					}
				}

				// update best sum and solution if current combination is better
				if (sum <= tapeLen && sum > bestSum)
				{
					bestSum = sum;
					ssBestSolution.str("");
					// loop through trackTimes array and append to bestSolution if boolean index is "off"
					for(int i=0; i<active.size(); i++)
					{
						if(!active[i])
						{
							ssBestSolution << trackTimes[i] << " ";
						}
					}
				}

				sum = 0;

			/* next_permutation generates permutations lexicographically.  Each time
			next_permutation is called it shifts the elements of the argument
			vector to generate the next "largest" order.  In our bool vector 00011 is
			the "smallest" permutation, while 11000 is the largest.  This loop will
			end	up generating exactly n choose k combinations */
			}while(next_permutation(active.begin(), active.end()));

			// clear active vector
			fill(active.begin(), active.end(), false);
		} // end combination loop

		// display solution
		cout << ssBestSolution.str() << "sum:" << bestSum << endl;
	}

return 0;
}
