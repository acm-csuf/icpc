#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// == ParseStr ======================================
//
// This function receives a line of input as a string
// and a pointer to a vector of strings which will
// contain the parsed line. If an empty line is
// encountered, it is also pushed into the vector.
//
// ==================================================
void ParseStr(string line, vector<string>* result)
{
	stringstream ss;
	string temp;

	if (line.empty())
		{
		result->push_back(line);
		return;
		}
	else
		{
		ss.clear();
		ss.str("");
		ss << line;
		while(ss >> temp)
			{
			result->push_back(temp);
			}
		return;
		}
}

// == main ==========================================
//
// This is a sample main that uses ParseStr. It
// displays each element of the resulting vector 
// (each string element) on its own line.
//
// ==================================================

// Sample Input:
//  Hello! This is a
//  test. :)
//
//  Testing 1 2 3.
//
// Sample Output:
//  Hello!
//  This
//  is
//  a
//  test.
//  :)
//  
//  Testing
//  1
//  2
//  3.
//
// ==================================================

int main(void)
{
	string myline;
	vector<string> *myvecptr;
	myvecptr = new vector<string>();
	
	//get a line and parse it until eof
	while(getline(cin,myline))
		{
		ParseStr(myline, myvecptr);
		}

	//display vector
	for(int i = 0; i < myvecptr->size(); ++i)
		{
		cout << myvecptr->at(i) << endl;
		}
	
	return 0;
}
