// Author: Dustin Delmer
// Date: 2/2/2013
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


// function that removes leading and trailing white space
void strip(string& str){
	stringstream ss (str);
	string temp;	
	str.clear();	
	while(ss>>temp){
		if(!str.empty()){ str += ' '; } 
		str += temp;
	} 
};


// function that parses a string 
//   @arg str - string to be parsed
//   @arg delim - char to be used as delminator
//	 @return value - vector of strings
vector<string>* parse_csv(string str, char delim=','){
	vector<string>* result;
	result = new vector<string>();	
	string temp;	
	for (int i=0; i<str.size(); i++){
		if(str[i]!=delim){ temp += str[i]; }
		else {
			strip(temp);
			result->push_back(temp);
			temp.clear();
		}
	}
	if (!temp.empty()){
		strip(temp);
		result->push_back(temp); 
	}
	return result;
};


	

int main(){
	string str = "this, is a, string, with, some, commas";
	vector<string>* result;
	result = parse_csv(str);	
	
	for (int i=0; i<(result->size()); i++){ cout << result->at(i) << endl; }
	
	delete result;
	return 0;
}
	
