#include <iostream>
#include <string>
using namespace std;

struct node
{
	char item;
	node *left;
	node *right;
	
    node(char stuff)
    {
		item = stuff;
		left = NULL;
		right = NULL;
	}
};


void fillTree( node *& parent, string &preorder, string inorder);

int main ()
{
	int cases;
	int size;
	string preorder;

	string inorder;
	
	cin >>cases;
	for (int i =0; i <cases; i ++)
	{
		cin >>size;
		
		cin >> preorder;
		cin >>inorder;
		

		node* root;
		root= new node ( preorder[0]);
		fillTree( root, preorder, inorder);
		cout <<endl;
		
	}
	
	return 0;
}



void fillTree( node *& parent, string& preorder, string inorder)
{
	//cout << "tree loop preorder = "<<preorder << " inorder = " <<inorder <<endl;
	string left="";
	string right="";
	
	
	parent =new node (preorder[0]);
	
	//cout <<" -----Parent is now " << parent->item <<endl;
	preorder.erase(0,1);
	for(int j = 0; j < inorder.size(); j ++)
	{
		if(parent->item == inorder[j])
		{
			if(j < (inorder.size()-1)) 
				right = inorder.substr((j+1), (inorder.size()-1)); 
			break;
		}
		else
		{
			left += inorder[j];
		}
	}
	
	//cout <<"Left is " <<left << " right is "<< right <<endl;
	
	if (left.size() >0)
	{
		//cout << "going left -"<<left <<endl;
		fillTree(parent->left,preorder, left); 
	}
	if (right.size()>0)
	{
		//cout << "going right -"<<right <<endl;
		fillTree(parent->right,preorder, right);
	}	
	cout << parent->item;
}
