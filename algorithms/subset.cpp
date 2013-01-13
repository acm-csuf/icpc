#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<char> elements;

    // add elements with duplicates up to 3
    elements.push_back('a');
    elements.push_back('a');
    elements.push_back('a');
    elements.push_back('b');
    elements.push_back('b');
    elements.push_back('b');
    elements.push_back('c');
    elements.push_back('c');
    elements.push_back('c');
    elements.push_back('d');
    elements.push_back('d');
    elements.push_back('d');

    int bits;
    int n = elements.size();

    for (bits = 0; bits < (1 << n); bits++) {
        vector<char> subset;
        int digit;

        
        for (digit=0; digit<n; digit++) {
            if (((1 << digit) & bits) != 0)
                subset.push_back(elements[digit]);
        }

        // if subset size is less than or equal to 3
        // then do something
        if (subset.size() <= 3) {
            cout << "subset " << bits << ":\t";
            for (int x=0; x<subset.size(); x++) {
                cout << subset[x] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
