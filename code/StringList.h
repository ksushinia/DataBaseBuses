#pragma once
#include "StringNode.h"
#include "fstream"

using namespace std;

struct StringList
{
	StringNode* pHead, * pTail, * pCur;

	StringList();

	bool is_empty();
	void pushFront(String newInfo);
	void pushBack(String newInfo);
	void insertAfter(StringNode* elem, String newInfo);
	void popFront();
	void eraseAfter(StringNode* elem);

	void readFromFile(ifstream& dataFilem, int& spaces);

	int lengthList();
	bool compareStringList(StringList S1, StringList S2);

	void converToDate(StringList S, int* date);
	void littleConvertToDate(StringList S, int* date);

	bool compareDates(StringList date1, StringList date2);
	bool comparebiba(StringList date1, StringList date2);
	bool compareQuarters(StringList date1, StringList date2);

	bool isTrueDate(int* date);

	void clearStringList();

	void outData(ofstream& outData);
	void outDataOnlyFile(ofstream& outData);
	void outDataOnlyFileWithoutEnter(ofstream& outData);

	int typeOfDate();
	void enterUserData();
	void fillWithInfo(char* string);
};