/** 
 * http://uva.onlinejudge.org/external/107/10701.html
 * Status: Accepted
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	char c;
};

void postPrint(Node* root) {
	if (root != NULL) {
		postPrint(root->left);
		postPrint(root->right);
		cout << root->c;
	}
}

Node* buildTree(string preStr, string inStr) {
	int size = (int) preStr.size();
	//cout << "preStr = " << preStr << "; inStr = " << inStr << "; size = " << size << "\n";
	
	if (size > 0) {
		Node* root = new Node();
		root->c = preStr[0];

		if (size == 1) 
			return root;
		
		int rootPos = 0;
		for (int i = 0; i < size; i++) {
			//cout << "  inStr[i] = " << inStr[i] << "; preStr[0] = " << preStr[0] << "\n";
			if (inStr[i] == preStr[0]) {
				rootPos = i;
				break;
			}
		}
		
		//cout << " rootPos = " << rootPos << "\n";
		
		string leftPre(preStr,1,rootPos);
		string leftIn(inStr,0,rootPos);
		root->left = buildTree(leftPre,leftIn);
		
		if (size > rootPos) { 
			string rightPre(preStr,rootPos+1,size-rootPos-1);
			string rightIn(inStr,rootPos+1,size-rootPos-1);
			root->right = buildTree(rightPre,rightIn);
		}
		
		return root;
	}
	
	return NULL;
}

int main() {
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		int n;
		string preStr, inStr;
		cin >> n >> preStr >> inStr;

		Node* root;
		root = buildTree(preStr,inStr);
		postPrint(root);
		cout << "\n";
	}	
	
	return 0;
}
