// Team Bad's solution to Broken Keys

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Variables
    string input;
    string line;
    int numLines = 0;
    bool brokenbool;
    int tests = 0;
    string tableDiv = "+----------+----------------+-----------------------------+";

    // print start of table
    cout << tableDiv << endl
        << "| Keyboard | # of printable | Additionally, the following |" << endl
        << "|          |      lines     |  letter keys can be broken  |" << endl
        << tableDiv << endl;

    while (getline(cin, input) && input != "finish")
    {
        tests++;
        numLines = 0;
        bool broken[26] = {false};
        bool addKeys[26] = {false};

        for(int i = 0; i < input.length(); ++i)
        {
            if (isalpha(input[i]))
            {
            input[i] = tolower(input[i]);
            broken[input[i] - 'a'] = true;
            addKeys[input[i] - 'a'] = true;
            }
        }

        while (getline(cin, line) && line != "END")
        {
            brokenbool = false;

            for (int i = 0; i < line.length(); ++i)
            {
                if (isalpha(line[i]))
                {
                    line[i] = tolower(line[i]);
                    if (broken[line[i] - 'a'])
                    {
                        brokenbool = true;
                        break;
                    }
                }
            }

	    // determine additional keys that can be broken
            if (!brokenbool)
            {
                ++numLines;
                for (int i = 0; i < line.length(); ++i)
                {
                    if (isalpha(line[i]))
                    {
                        addKeys[line[i] - 'a'] = true;
                    }
                }
            }
        }

        // process line = "END"
        brokenbool = false;
        for (int i = 0; i < 3; ++i)
        {
            line = "end";
            if (broken[line[i] - 'a'])
            {
                brokenbool = true;
                break;
            }
        }

	// determine number of lines that can be typed
        if (!brokenbool)
        {
            ++numLines;
            for (int i = 0; i < 3; ++i)
            {
                addKeys[line[i] - 'a'] = true;
            }
        }

	// store additional keys that can be broken
        string addKeysStr = "";
        stringstream ss;
        for (int i = 0; i < 26; ++i)
        {
            if (!addKeys[i])
            {
                ss << char(i + 'a');
            }
        }
        ss >> addKeysStr;

        // print results
        cout << "|" << setw(6) << right << tests << "    |" << setw(9) << numLines
            << "       | " << setw(27) << left << addKeysStr << " |" << endl
            << tableDiv << endl;
    }

    return 0;
}
