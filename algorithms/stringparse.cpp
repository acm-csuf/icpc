#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

struct input {
	string str;
	int	value;
};


int main() {
	string token;
	vector<input> v;

	while (cin >> token) {
		char c;
		
		stringstream stoken;
		stringstream newtoken;
		stoken << token;
		
		input in;
		bool first = true;
		
		while ( stoken >> c ) {
			if(c != ':') {
				newtoken << c;
			}
			else {
				newtoken << "*";
				first = false;
			}
		}
		
		//newtoken >> token;
		//cout << token << endl;
		
		if (first) {
			newtoken >> in.value;
		}
		else {
			newtoken >> in.str;
			//cout << in.value << " " << in.str << endl;
			v.push_back(in);
		}
	}

	vector<input>::iterator it;
	cout << "output:" << endl;
	for (it = v.begin(); it != v.end(); it++) {
		cout << (*it).str << " " << (*it).value << endl;
	}

	return 0;
}