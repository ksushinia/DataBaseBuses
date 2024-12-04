#pragma once
#include "NodePointers.h"

struct ListPointers
{
	NodePointers* pHead, * pTail, * pCur;

	ListPointers();

	bool is_empty();
	void pushFront(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB);
	void pushBack(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB);
	void insertAfter(NodePointers* elem, StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB);
	void popFront();
	void eraseAfter(NodePointers* elem);

	void outAllData(ofstream& logs);
};