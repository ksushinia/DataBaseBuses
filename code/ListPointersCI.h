#pragma once
#include "NodePointersCI.h"

struct ListPointersCI
{
	NodePointersCI* pHead, * pTail, * pCur;

	ListPointersCI();

	bool is_empty();
	void pushFront(StringList* editedData, ListPointers* otherEdData);
	void pushBack(StringList* editedData, ListPointers* otherEdData);
	void insertAfter(NodePointersCI* elem, StringList* editedData, ListPointers* otherEdData);
	void popFront();
	void eraseAfter(NodePointersCI* elem);

	void outDataListCI(ofstream& logs);
};