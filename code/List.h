#pragma once
#include "Node.h"
#include "fstream"

using namespace std;

struct List
{
	Node* pHead, * pTail, * pCur;

	List();

	bool is_empty();
	void pushFront(StringList newInfo);
	void pushBack(StringList newInfo);
	void insertAfter(Node* elem, StringList newInfo);
	void popFront();
	void eraseAfter(Node* elem);
	bool isUnique(List& tmp, StringList S);

	void readFromFile(ifstream& dataFile);

	//Ќовый тип сравнени€ и заполнени€ массивов
	void fillingWithData(List& tmp, StringList S);

	void outAllDataList(ofstream& logs);
	//void printList(ofstream& outFile);
	//void readFromFile(ifstream& dataFile, List& busType, List& date, List& time, List& pointA);
};