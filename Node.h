#ifndef NODE_H 
#define NODE_H
#include <vector>
using namespace std;

class Node
{
public:
	int cityNumber;
	vector <Node*> children;
	bool selected;
	int xCoordinate;
	int yCoordinate;
};
#endif
