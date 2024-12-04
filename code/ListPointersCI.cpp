#include "ListPointersCI.h"
#include <iostream>
#include <fstream>

using namespace std;

ListPointersCI::ListPointersCI()
{
	pHead = nullptr;
	pTail = nullptr;
	pCur = nullptr;
}

bool ListPointersCI::is_empty()
{
	return pHead == nullptr;
}

void ListPointersCI::pushFront(StringList* necessaryInfo, ListPointers* otherData)
{
	pHead = new NodePointersCI(necessaryInfo, otherData, pHead);
	if (pTail == nullptr)
		pTail = pHead;
}

void ListPointersCI::pushBack(StringList* necessaryInfo, ListPointers* otherData)
{
	if (is_empty())
	{
		pushFront(necessaryInfo, otherData);
	}
	else
		insertAfter(pTail, necessaryInfo, otherData);
}

void ListPointersCI::popFront()
{
	NodePointersCI* nextHead = pHead->pNext;
	delete pHead;
	pHead = nextHead;
	if (pHead == nullptr)
		pTail = nullptr;
}

void ListPointersCI::insertAfter(NodePointersCI* elem, StringList* necessaryInfo, ListPointers* otherData)
{
	elem->pNext = new NodePointersCI(necessaryInfo, otherData, elem->pNext);
	if (pTail == elem)
		pTail = pTail->pNext;
}

void ListPointersCI::eraseAfter(NodePointersCI* elem)
{
	NodePointersCI* nextElem = elem->pNext;
	elem->pNext = nextElem->pNext;
	delete nextElem;
	if (pTail == nextElem)
		pTail = elem;
}

void ListPointersCI::outDataListCI(ofstream& logs)
{
	pCur = pHead;
	logs << "--------------------------------------\n";
	while (pCur != nullptr)
	{
		pCur->necessaryData->outDataOnlyFileWithoutEnter(logs);
		logs << "-->";
		pCur->otherData->outAllData(logs);
		logs << "|\n"; logs << "\V\n";
		pCur = pCur->pNext;
	}
	logs << "NULL\n";
	logs << "--------------------------------------\n";
}