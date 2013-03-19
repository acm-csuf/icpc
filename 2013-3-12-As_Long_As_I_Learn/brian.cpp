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
	int sumToEnd;
	node(int inputValue);
};

node::node(int inputValue)
{
	value = inputValue;
	outNode = NULL;
	sumToEnd = 0;
	//cout << "New node created with value of " << inputValue << endl;
}



int main()
{
	vector <node*> nodeVector;
	int numberOfNodes;
	int numberOfEdges;
	int numberOfCases;
	int bestSum;
	int endIndex;
	int maxWeight = 0;
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
			if (temp > maxWeight)
			{
				maxWeight = temp;
			}
			nodeVector.push_back(new node(temp));
		}
		for (int j = 0; j < numberOfEdges; j++)
		{
			cin >> temp;
			cin >> temp2;
			//printf("nodeVector[nodeVector[temp]->outNode]->value=%d\n", nodeVector[nodeVector[temp]->outNode]->value);
			//printf("nodeVector[temp2]->value=%d\n", nodeVector[temp2]->value);
			if (nodeVector[temp]->outNode == NULL)
			{
				nodeVector[temp]->outNode = temp2;
				//cout << "Node " << temp << " outNode set to " << temp2 << endl;
			}
			else if (nodeVector[nodeVector[temp]->outNode]->value < nodeVector[temp2]->value)
			{
				nodeVector[temp]->outNode = temp2;
				//cout << "Node " << temp << " outEdge of " << nodeVector[temp]->outNode << " was set to " << temp2 << endl;
			}
			else
			{
				//cout << "Not replaced\n";
				//cout << "There is an edge going from " << temp << " to " << temp2 << endl;
			}
		}
		bestSum = 0;
		node* currentNode = nodeVector[0];
		while (currentNode->outNode!=NULL)
		{
			//cout << "Out edge = " << currentNode->outNode << endl;
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