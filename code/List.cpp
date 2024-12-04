#include "List.h"
#include <iostream>
#include <fstream>

using namespace std;

List::List()
{
	pHead = nullptr;
	pTail = nullptr;
	pCur = nullptr;
}

bool List::is_empty()
{
	return pHead == nullptr;
}

void List::pushFront(StringList newInfo)
{
	pHead = new Node(newInfo, pHead);
	if (pTail == nullptr)
		pTail = pHead;
}

void List::pushBack(StringList newInfo)
{
	if (is_empty())
	{
		pushFront(newInfo);
	}
	else
		insertAfter(pTail, newInfo);
}

void List::popFront()
{
	Node* nextHead = pHead->pNext;
	delete pHead;
	pHead = nextHead;
	if (pHead == nullptr)
		pTail = nullptr;
}

void List::insertAfter(Node* elem, StringList newInfo)
{
	elem->pNext = new Node(newInfo, elem->pNext);
	if (pTail == elem)
		pTail = pTail->pNext;
}

void List::eraseAfter(Node* elem)
{
	Node* nextElem = elem->pNext;
	elem->pNext = nextElem->pNext;
	delete nextElem;
	if (pTail == nextElem)
		pTail = elem;
}

/*void List::readFromFile(ifstream& dataFile)
{
	dataFile.unsetf(ios::skipws);
	int spaces = 0;
	while (1)
	{
		String S;
		S.readString(dataFile, spaces);
		pushBack(S);
		if (dataFile.eof()) break;
	}
}*/

bool List::isUnique(List& tmp, StringList S)
{
	if (tmp.is_empty()) return true;
	else
	{
		tmp.pCur = tmp.pHead;
		while (tmp.pCur != nullptr)
		{
			if (S.compareStringList(tmp.pCur->data, S))
			{
				//tmp.cur = tmp.cur->pNext;
				return false;
			}
			tmp.pCur = tmp.pCur->pNext;
		}
	}
	return true;
}

void List::fillingWithData(List& tmp, StringList S)
{
	tmp.pCur = tmp.pHead;
	while (tmp.pCur != nullptr)
	{
		if (S.compareStringList(tmp.pCur->data, S)) break;
		tmp.pCur = tmp.pCur->pNext;
	}
	if (tmp.pHead == tmp.pTail) tmp.pCur = tmp.pHead;
}

void List::outAllDataList(ofstream& logs)
{
	pCur = pHead;
	while (pCur != nullptr)
	{
		pCur->data.outDataOnlyFileWithoutEnter(logs);
		logs << "-->";
		pCur->otherData.outAllData(logs);
		logs << "|\n"; logs << "\V\n";
		pCur = pCur->pNext;
	}
	logs << "NULL";
}