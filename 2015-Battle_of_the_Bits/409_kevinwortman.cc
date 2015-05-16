
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Excuse {
  Excuse(string _t, int _b) : text(_t), badness(_b) { }

  string text;
  int badness;
};

int main() {
  for (int case_num = 1; true; ++case_num) {
    int K, E;
    cin >> K >> E;
    if (!cin) {
      break;
    }

    set<string> keywords;
    cin.ignore();
    for (int i = 0; i < K; ++i) {
      string keyword;
      getline(cin, keyword);
      keywords.insert(keyword);
    }

    vector<Excuse> excuses;
    for (int i = 0; i < E; ++i) {
      string text;
      getline(cin, text);
      assert(cin);

      int badness = 0, len = text.length();

      string token;
      for (int j = 0; j < len; ++j) {
	char c = text[j];
	if (isalpha(c)) {
	  token.push_back(tolower(c));
	} else {
	  if (keywords.find(token) != keywords.end()) {
	    ++badness;
	  }
	  token.clear();
	}
      }

      if (keywords.find(token) != keywords.end()) {
	++badness;
      }

      excuses.push_back(Excuse(text, badness));
    }
    //cin.ignore();

    int max_badness = 0;
    for (int i = 0; i < excuses.size(); ++i) {
      max_badness = max(max_badness, excuses[i].badness);
    }

    cout << "Excuse Set #" << case_num << endl;
    for (int i = 0; i < excuses.size(); ++i) {
      if (excuses[i].badness == max_badness) {
	cout << excuses[i].text << endl;
      }
    }
    cout << endl;
  }

  return 0;
}

