#include "StringList.h"
#include <iostream>
#include <fstream>

using namespace std;

StringList::StringList()
{
	pHead = nullptr;
	pTail = nullptr;
	pCur = nullptr;
}

bool StringList::is_empty()
{
	return pHead == nullptr;
}

void StringList::pushFront(String newInfo)
{
	pHead = new StringNode(newInfo, pHead);
	if (pTail == nullptr)
		pTail = pHead;
}

void StringList::pushBack(String newInfo)
{
	if (is_empty())
	{
		pushFront(newInfo);
	}
	else
		insertAfter(pTail, newInfo);
}

void StringList::popFront()
{
	StringNode* nextHead = pHead->pNext;
	delete pHead;
	pHead = nextHead;
	if (pHead == nullptr)
		pTail = nullptr;
}

void StringList::insertAfter(StringNode* elem, String newInfo)
{
	elem->pNext = new StringNode(newInfo, elem->pNext);
	if (pTail == elem)
		pTail = pTail->pNext;
}

void StringList::eraseAfter(StringNode* elem)
{
	StringNode* nextElem = elem->pNext;
	elem->pNext = nextElem->pNext;
	delete nextElem;
	if (pTail == nextElem)
		pTail = elem;
}

void StringList::readFromFile(ifstream& dataFile, int& spaces)
{
	dataFile.unsetf(ios::skipws);
	String S;
	bool is_end = false;
	while (!is_end)
	{
		S.readStringV2(dataFile, spaces, is_end);
		pushBack(S);
		S.clearString();
	}
}

int StringList::lengthList()
{
	int length = 0;
	pCur = pHead;
	while (pCur != nullptr)
	{
		length++;
		pCur = pCur->pNext;
	}
	return length;
}

bool StringList::compareStringList(StringList S1, StringList S2)
{
	if (S1.lengthList() != S2.lengthList()) return false;
	S1.pCur = S1.pHead;
	S2.pCur = S2.pHead;
	while (S1.pCur != nullptr)
	{
		if (S1.pCur->element.compareString(S1.pCur->element, S2.pCur->element))
		{
			S1.pCur = S1.pCur->pNext;
			S2.pCur = S2.pCur->pNext;
		}
		else return false;
	}
	return true;
}

void StringList::converToDate(StringList S, int* date)
{
	int i = 0, j = 0;
	S.pCur = S.pHead;
	while (1)
	{
		int result = 0;
		while (S.pCur->element.getData(i) != '-')
		{
			if (i == S.pCur->element.stringLenght)
			{
				S.pCur = S.pCur->pNext;
				i = 0;
			}
			if (S.pCur == nullptr || S.pCur->element.string[0] == '\0')
			{
				break;
			}
			result = result * 10 + (S.pCur->element.getData(i) - '0');
			++i;
		}
		date[j] = result;
		if (j > 2) break;
		j++;
		if (S.pCur == nullptr) break;
		if (i == S.pCur->element.stringLenght) break;
		i++;
	}
}

void StringList::littleConvertToDate(StringList date, int* dateint)
{
	date.pCur = date.pHead;
	int i = 1, j = 0;
	while (date.pCur != nullptr)
	{
		int result = 0;
		while (date.pCur->element.getData(i) != '\0')
		{
			if (i == date.pCur->element.stringLenght)
			{
				date.pCur = date.pCur->pNext;
				i = 0;
			}
			if (date.pCur == nullptr) break;
			result = result * 10 + (date.pCur->element.getData(i) - '0');
			++i;
		}
		dateint[j] = result;
		if (j > 0) break;
		j++;
		if (date.pCur == nullptr) break;
		if (i == date.pCur->element.stringLenght) break;
		i++;
	}
}

bool StringList::compareDates(StringList date1, StringList date2)
{
	int Fdate[3], Sdate[3];
	date1.converToDate(date1, Fdate);
	date2.converToDate(date2, Sdate);
	if (date1.isTrueDate(Fdate) && date2.isTrueDate(Sdate))
	{
		if (Fdate[0] > Sdate[0]) return true;
		else if (Fdate[0] == Sdate[0])
		{
			if (Fdate[1] > Sdate[1])
				return true;
			else if (Fdate[1] == Sdate[1])
			{
				if (Fdate[2] > Sdate[2]) return true;
				else if (Fdate[2] == Sdate[2]) return true;
			}
		}
	}
	return false;
}

bool StringList::comparebiba(StringList date1, StringList date2)
{
	int Fdate[3];
	date1.converToDate(date1, Fdate);
	int Sdate[3];
	date2.littleConvertToDate(date2, Sdate);
	if (Fdate[1] == Sdate[0]) return true;
	else return false;
}

bool StringList::compareQuarters(StringList date1, StringList date2)
{
	int Fdate[3];
	date1.converToDate(date1, Fdate);
	int Sdate[3];
	date2.littleConvertToDate(date2, Sdate);
	if (((Fdate[1] / 3) == (Sdate[0] - 1)) || ((Fdate[1] / 3) == (Sdate[0]))) return true;
	else return false;
}

bool StringList::isTrueDate(int* date)
{
	if ((date[1] > 12 && date[1] < 1) || (date[2] > 31 && date[2] < 1)) return false;
	bool isLeapYear = false;
	bool isBigMounth = false;
	if (date[0] % 4 == 0)
		isLeapYear = true;
	if (date[1] <= 7 && (date[1] % 2 == 1) || ((date[1] >= 8) && (date[1] % 2 == 0))) isBigMounth = true;
	else isBigMounth = false;

	if (!isBigMounth && date[1] != 2 && date[2] <= 30) return true;
	else if (!isBigMounth && date[1] != 2 && date[2] > 30) return false;

	if (isBigMounth && date[2] <= 31) return true;
	else if (isBigMounth && date[2] > 31) return false;

	if (isLeapYear)
	{
		if (date[1] == 2 && date[2] <= 29) return true;
		else if (date[1] == 2 && date[2] > 29) return false;
	}
	if (!isLeapYear)
	{
		if (date[1] == 2 && date[2] <= 28) return true;
		else if (date[1] == 2 && date[2] > 28) return false;
	}
}

void StringList::clearStringList()
{
	while (!is_empty()) popFront();
}

void StringList::outData(ofstream& outData)
{
	pCur = pHead;
	while (pCur != nullptr)
	{
		pCur->element.outDataWithoutEnter(outData);
		pCur = pCur->pNext;
	}
	cout << '\n';
	outData << '\n';
}

void StringList::outDataOnlyFile(ofstream& outData)
{
	pCur = pHead;
	while (pCur != nullptr)
	{
		pCur->element.outDataOnlyFileWithoutEnter(outData);
		pCur = pCur->pNext;
	}
	outData << '\n';
}

void StringList::outDataOnlyFileWithoutEnter(ofstream& outData)
{
	pCur = pHead;
	outData << "| ";
	while (pCur != nullptr)
	{
		pCur->element.outDataOnlyFileWithoutEnter(outData);
		outData << "->";
		pCur = pCur->pNext;
	}
	outData << "NULL |";
}

int StringList::typeOfDate()
{
	int Fdate[3];
	converToDate(*this, Fdate);
	if (this->pHead->element.stringLenght != 0)
	{
		if (this->pHead->element.string[0] == 'M')
			return 2;
		if (this->pHead->element.string[0] == 'K')
			return 3;
		if (isTrueDate(Fdate))
			return 1;
	}
	else return -1;
}

void StringList::enterUserData()
{
	char string[100];
	cin >> string;
	fillWithInfo(string);
}

void StringList::fillWithInfo(char* string)
{
	int index = 0;
	int index_s = 0;
	String str;
	while (1)
	{
		if (index_s == 10)
		{
			str.stringLenght = index_s;
			pushBack(str);
			str.clearString();
			index_s = 0;
		}
		if (string[index] == '\0')
		{
			//if (index_s == 0) break;
			str.stringLenght = index_s;
			pushBack(str);
			str.clearString();
			index_s = 0;
			break;
		}
		str.string[index_s] = string[index];
		index_s++;
		index++;
	}
}