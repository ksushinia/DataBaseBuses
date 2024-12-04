#include "Node.h"

using namespace std;

Node::Node(StringList editedInfo, Node* n)
{
	data = editedInfo;
	pNext = n;
}