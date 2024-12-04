#include "StringNode.h"

StringNode::StringNode(String edElem, StringNode* n)
{
	element = edElem;
	pNext = n;
}