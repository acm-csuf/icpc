//Solution to KWIC-index problem
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=352&page=show_problem&problem=59
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

//Populates the ignored words list
void populate_ignored(set<string> &ignored)
{
	string line;
	getline(cin, line);
	while(line != "::")
	{
		ignored.insert(line);
		getline(cin, line);
	}
}

//Prints the contents of the kwic index
void print_kwic_index(multimap<string, string> &kwic)
{
	multimap<string, string>::iterator it;
	for(it = kwic.begin(); it != kwic.end(); it++)
		cout << (*it).second << endl;
}

//Returns true if word is in the ignored list
inline bool is_ignored(string &word, set<string> &ignored)
{
	return ignored.find(word) != ignored.end();
}

//INPUT: string
//OUTPUT: vector containing each word in string (space delimited token)
void str_to_tokens(string &s, vector<string> &tokens)
{
	stringstream stream(s);
	string word;

	//get next word (space delimited)
	while(stream.good())
	{
		getline(stream, word, ' ');
		tokens.push_back(word);
	}
}

//converts a string to lower case
void str_to_lower(string &s)
{
	for(int i = 0; i < s.size(); i++)
		s[i] = tolower(s[i]);
}

//converts a string to upper case
void str_to_upper(string &s)
{
	for(int i = 0; i < s.size(); i++)
		s[i] = toupper(s[i]);
}

//creates a new title with the keyword as uppercase
void get_new_title(vector<string> &words, string &modified_title, int keyword_index)
{
	string temp(words[keyword_index]);
	str_to_upper(temp);
	swap(words[keyword_index], temp);//replaced uppercase keyword and found word
	for(int i = 0; i < words.size() - 1; i++)
	{
		modified_title += words[i];
		modified_title.push_back(' ');
	}

	modified_title += words[words.size() - 1];
	swap(words[keyword_index], temp);//swap words back
}

//processes titles and adds them to kwic index
void process_title(string &title, multimap<string, string> &kwic, set<string> &ignored)
{
	vector<string> words;
	str_to_lower(title);
	//parse title into tokens
	str_to_tokens(title, words);

	//iterate through words, looking for keywords
	//when you find keywords, change case and add to kwic
	for(int i = 0; i < words.size(); i++)	
	{
		if(!is_ignored(words[i], ignored))
		{
			string modified_title = "";
			get_new_title(words, modified_title, i);
			kwic.insert(pair<string, string>(words[i], modified_title));
		}
	}
}

int main()
{
	set<string> ignored; //set of ignored words
	multimap<string, string> kwic; //the kwic index

	populate_ignored(ignored); //get words to ignore

	//process titles
	string title;
	getline(cin, title);
	while(cin.good())
	{
		process_title(title, kwic, ignored);
		getline(cin, title);
	}


	print_kwic_index(kwic); //print the index
	return 0;
}
