#pragma once
#include "Node.h"
#include "ListPointers.h"

struct NodePointersCI
{
	StringList* necessaryData;
	ListPointers* otherData;

	NodePointersCI* pNext;

	NodePointersCI(StringList* editedData, ListPointers* otherEdData, NodePointersCI* n);
};