#pragma once
#include "ListPointers.h"
#include "StringList.h"

struct Node
{
	StringList data;
	ListPointers otherData;
	Node* pNext;

	Node(StringList editedInfo, Node* n);
};