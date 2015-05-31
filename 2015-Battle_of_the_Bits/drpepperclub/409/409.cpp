// Template Program
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int numInSet(string excuse, string* keywords, int K){
	// replace nonalpha's with white space
	for(int i=0; i < excuse.length(); ++i) {
		if (!isalpha(excuse[i])) {
			excuse[i] = ' ';
		}
		else {
			excuse[i] = tolower(excuse[i]);
		}
	}
	
	// parse excuse into words
	stringstream ss;
	ss.clear();
	ss << excuse;
	string word;
	int counter = 0;
	
	while(ss >> word) {
		for(int i = 0; i<K; ++i) {
			if (keywords[i] == word) {
				++counter;
			}
		}
	}
	return counter;
}

int main(){
	// Variables
	string output = "";
	int K;
	int E;
	int caseNum = 0;
	
	while( cin>>K ) {
		// Read in
		cin>>E;
		++caseNum;
		
		// More Variables
		string keywords[K];
		string word;
		string excuse;
		string excuses[E];
		int highestWordCount = 0;
		int wordCount[E];
	
		// Loop through
		for(int i=0; i < K; i++) {
			cin>>word;
			keywords[i] = word;
		}
	
		getline(cin, excuse);
		for(int i=0; i < E; i++) {
			excuse = "";
			getline(cin, excuse);
			excuses[i] = excuse;
			wordCount[i] = 0;
			//check if keyword is in excuse/sentence
			wordCount[i] = numInSet(excuse, keywords, K);
			
			if(wordCount[i] > highestWordCount) {
				highestWordCount = wordCount[i];
			}
		}
		
		cout << "Excuse Set #" << caseNum << endl;
		
		for(int i=0; i<E; ++i) {
			if (highestWordCount == wordCount[i]) {
				cout << excuses[i] << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
