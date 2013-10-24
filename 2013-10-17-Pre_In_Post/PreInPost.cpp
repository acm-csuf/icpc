#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int find(string str, char toFind, int start)
{
	for (int i=start; i<str.length(); i++)
	{
		if (str[i] == toFind)
		{
			return i;
		}
	}
	return -1;
}

/*======================================
Warning: the following code is horrific. 
======================================*/
void FindPost(string pre, string in, char* post, int startL, int endL, int startR, int endR, int startP, int endP)
{
	if (startL > endL)
	{
		return;
	}
	post[endP] = pre[startL];
	if (startL == endL)
	{
		return;
	}

	int startL1, startL2, startR1, startR2, endL1, endL2, endR1, endR2, startP1, endP1, startP2, endP2;
	endR1 = find(in, pre[startL],startR+1)-1;
	assert(endR1>=0);

	startL1 = startL+1;
	endL1 = startL1 + endR1-startR;
	startR1 = startR;
	startP1 = startP;
	endP1 = startP1 + endR1-startR;

	startL2 = endL1+1;
	endL2 = endL;
	startR2 = endR1+2;
	endR2 = endR;
	startP2 = endP1+1;
	endP2 = endP-1;

	FindPost(pre, in, post, startL1, endL1, startR1, endR1, startP1, endP1);
	FindPost(pre, in, post, startL2, endL2, startR2, endR2, startP2, endP2);
}
/*================
End horrific code.
================*/

int main()
{
	int C=0, N=0;
	string pre, in;
	char* post;

	for (cin >> C; C>0; C--)
	{
		cin >> N >> pre >> in;
		post = new char[N+1];
		post[N] = '\0';
		FindPost(pre, in, post, 0, N-1, 0, N-1, 0, N-1);
		cout << post << endl;

		delete post;
	}

	return 0;
}