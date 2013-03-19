#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class node
{
public:
	int value;
	int outNode;
	node(int inputValue);
};

node::node(int inputValue)
{
	value = inputValue;
	outNode = NULL;
}

int main()
{
	vector <node*> nodeVector;
	int numberOfNodes;
	int numberOfEdges;
	int numberOfCases;
	int bestSum;
	int endIndex;
	cin >> numberOfCases;
	cin.ignore(255, '\n');
	for (int i = 0; i < numberOfCases; i++)
	{
		bestSum = 0;
		int temp;
		int temp2;
		string myString;
		getline(cin, myString);
		cin >> numberOfNodes;
		cin >> numberOfEdges;
		for (int j = 0; j < numberOfNodes; j++)
		{
			cin >> temp;
			nodeVector.push_back(new node(temp));
		}
		for (int j = 0; j < numberOfEdges; j++)
		{
			cin >> temp;
			cin >> temp2;
			if (nodeVector[temp]->outNode == NULL)
			{
				nodeVector[temp]->outNode = temp2;
			}
			else if (nodeVector[nodeVector[temp]->outNode]->value < nodeVector[temp2]->value)
			{
				nodeVector[temp]->outNode = temp2;
			}
		}
		bestSum = 0;
		node* currentNode = nodeVector[0];
		while (currentNode->outNode!=NULL)
		{
			endIndex = currentNode->outNode;
			bestSum = bestSum + currentNode->value;
			currentNode = nodeVector[currentNode->outNode];
		}
		bestSum = bestSum + currentNode->value;
		printf("Case %d: %d %d\n", i+1, bestSum, endIndex);
		nodeVector.clear();
		cin.ignore(255, '\n');
	}
	return 0;
}
