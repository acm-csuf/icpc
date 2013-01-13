#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool IsIgnore(vector<string> ignore, vector<string> titles, string word)
{
	//Check if word is in either the list of wrods to ignore or the
	//list of titles already used.
	for (int i=0; i<ignore.size(); i++)
	{
		if (word == ignore[i]) return true;
	}
	for (int i=0; i<titles.size(); i++)
	{
		if (word == titles[i]) return true;
	}
	return false;
}

int main()
{
	char textLine[1000], outLine[1000];
	fstream inFile("data.txt", ios::in);
	vector<string> toIgnore, titles;
	bool ignoreWords = true, indexed;
	string inLine, token;
	int tokenCount = 0, lastItr = -1;
	string outLines[100];

	while (!inFile.eof())
	{
		if (ignoreWords)
		{
			//ignoreWords will be true until we reach "::",
			//signaling the end of the words to ignore.
			inFile >> textLine;
			if (textLine[0] == ':' && textLine[1] == ':')
			{
				//End of ignore words.
				ignoreWords = false;

				//We'll be using getline() from here on out.
				inFile.ignore();
			}
			else
			{
				//Add the word to the ignore list.
				toIgnore.push_back(textLine);
			}
		}
		else
		{
			//Read text line, convert to lowercase and create a string stream.
			getline(inFile, inLine);
			transform(inLine.begin(),inLine.end(),inLine.begin(),::tolower);
			istringstream counter(inLine);

			//Count the number of non-ignored titles.
			//We'll make this many copies of the text line in outLines.
			tokenCount = 0;
			while(counter>>token)
			{
				if (!IsIgnore(toIgnore, titles, token)) tokenCount++;
			}

			lastItr = 0;
			titles.clear();
			istringstream iss(inLine);

			//This for loop tokenizes the string.
			//"i" will act as an index for "outlines".
			for (int i=0; iss >> token; i++ )
			{
				if (!IsIgnore(toIgnore, titles, token))
				{
					//Copy text line into ith outline position.
					outLines[i] = inLine;

					//Find the next occurrence of the token in text line after lastItr.
					int outItr = outLines[i].find(token, max(lastItr, 0));

					//This sets th position of the last valid title.
					lastItr = outItr + token.length();

					//Convert token to uppercase and output the result to the outItr
					//position of the ith outline.
					transform(token.begin(),token.end(),&outLines[i][outItr],::toupper);

					//We're done with this title, add it to the list of used titles.
					titles.push_back(token);

					//Output the finalized text line.
					cout << outLines[i] << endl;
				}
				else
				{
					//This is not a valid title, decrement i to counteract increment
					//(i does not change).
					i--;
				}
			}
		}
	}

	//End program.
	system("pause");
	return 0;
}
