#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// Variables
	int num_loop;
	int row;
	int col;
	int adj1;
	int adj2;

	// Get Number of Loops
	cin >> num_loop;

	// Loop
	for (int i = 0; i < num_loop; ++i)
	{
		cin >> row >> col;

		// Equation
		// Round to nearest int
		adj1 = (int) (row / 3 + 0.5);
		adj2 = (int) (col / 3 + 0.5);

		// Return answer
		cout << adj1 * adj2 << endl;
	}

	return 0;
}
