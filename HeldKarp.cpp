#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>
#include "Node.h"
using namespace std;

ofstream outputFile; // Our output file.

int** adjacencyMatrix;
int optimalDistance = 2147483647;

vector <Node*> getSet(vector <int> cityNumbers, vector <int> xCoordinates, vector <int> yCoordinates)
{
	vector <Node*> set;

	for (int i = 0; i < cityNumbers.size(); i++)
	{
		Node* tmp = new Node;
		tmp->cityNumber = cityNumbers.at(i);
		tmp->xCoordinate = xCoordinates.at(i);
		tmp->yCoordinate = yCoordinates.at(i);
		set.push_back(tmp);
	}

	return set;		
}

Node* getRoot()
{
	Node* root = new Node;
	return root;
}

int computeDistance(vector <Node*> set, int idx1, int idx2)
{
	int x1 = set.at(idx1)->xCoordinate;
	int x2 = set.at(idx2)->xCoordinate;
	int y1 = set.at(idx1)->yCoordinate;
	int y2 = set.at(idx2)->yCoordinate;

	float firstClause = x1 - x2;
	firstClause = pow(firstClause, 2);
	float secondClause = y1 - y2;
	secondClause = pow(secondClause, 2);
	float sumOfClauses = firstClause + secondClause;
	float distance = sqrt(sumOfClauses);

	distance = round(distance);

	return distance;
}

void constructAdjacencyMatrix(vector <Node*> set)
{
	int max = set.size();
	adjacencyMatrix = new int*[max];

	for (int i = 0; i < set.size(); i++)
	{
		adjacencyMatrix[i] = new int[max];

		for (int j = 0; j < set.size(); j++)
		{
			adjacencyMatrix[i][j] = computeDistance(set, i, j);
		}	
	}
}

int heldKarp(int initial, vector <int> vertices, string path, int currentCost)
{
	int length = vertices.size();
	int newCurrentCost;

	if (length == 0)
	{
		newCurrentCost = currentCost + adjacencyMatrix[initial][0];
		
		if (newCurrentCost < optimalDistance)
		{
			optimalDistance = newCurrentCost; 
		}

		return (adjacencyMatrix[initial][0]);
	}

	else if (currentCost > optimalDistance)
		return 0;

	else
	{
		// int newVertices[length][length-1];
		vector < vector <int> > newVertices(length, vector <int> (length-1, 1));
		int costOfCurrentNode, costOfChild;
		int bestCost = 2147483647;
	
		for (int i = 0; i < length; i++)
		{
			for (int j = 0, k = 0; j < length; j++, k++)
			{
				if (j == i)
				{
					k--;
					continue;
				}
				
				newVertices.at(i).at(k) = vertices[j];			
				//newVertices[i][k] = vertices[j];
			}

			costOfCurrentNode = adjacencyMatrix[initial][vertices[i]];
			
			newCurrentCost = costOfCurrentNode + currentCost;

			costOfChild = heldKarp(vertices[i], newVertices.at(i), path, newCurrentCost);

			int totalCost = costOfChild + costOfCurrentNode;

			if (totalCost < bestCost)
				bestCost = totalCost;
		}

		return bestCost;
	}
}

int main(int argc, char* argv[])
{
	ifstream inputFile;
	inputFile.open(argv[1]);
	
	string line;
	vector <int> cityNumbers;
	vector <int> xCoordinates;
	vector <int> yCoordinates;

	if (!inputFile)
	{
		cout << "Error opening file." << endl;
		return 1;
	}

	// Load  line by line.
	while (getline(inputFile, line))
	{
		int counter = 0;

		// Parse the string.
		stringstream stream(line);
		
		while (1)
		{
			int tmp;
			stream >> tmp;

			if (stream)
			{
				if (counter == 0)
					cityNumbers.push_back(tmp);

				else if (counter == 1)
					xCoordinates.push_back(tmp);
	
				else if (counter == 2)
					yCoordinates.push_back(tmp);
			}

			else if (!stream) // No more string to parse, break the infinite loop.
			{
				break;
			}

			counter++;
		}		
	}

	vector <Node*> set = getSet(cityNumbers, xCoordinates, yCoordinates);	
	Node* root = getRoot();	
	constructAdjacencyMatrix(set);

	vector <int> vertices; 
	string path = "";

	for (int i = 0; i < set.size(); i++)
	{
		vertices.push_back(i);
	}

	cout << heldKarp(0, vertices, path, 0);	

	/* Print adjmatrix 
	for (int i = 0; i < set.size(); i++)
	{
		cout << i << " ";

		for (int j = 0; j < set.size(); j++)
		{
			cout << adjacencyMatrix[i][j] << " ";
		}

		cout << endl << endl << endl;
	}*/

	

	inputFile.close();

	return 0;
}
