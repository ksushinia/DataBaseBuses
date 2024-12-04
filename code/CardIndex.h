#pragma once
#include "CardIndexNode.h"
#include "List.h"
#include <fstream>

using namespace std;

struct CardIndex
{
	CardIndexNode* pHead, * pTail, * pCur;

	CardIndex();

	bool is_empty();
	void pushFront(ListPointersCI necessaryData, char edPar);
	void pushBack(ListPointersCI necessaryData, char edPar);
	void insertAfter(CardIndexNode* elem, ListPointersCI necessaryData, char edPar);
	void popFront();
	void eraseAfter(CardIndexNode* elem);

	void createEmptyList();

	void readingFromFile(ifstream& dataFile, List& BusType, List& date, List& time, List& pointA, List& pointB, ofstream& logs);

	void compareWithboba(List pointA);
	bool itWas(List pointA);

	void searchBybusType(ofstream& outData, ofstream& logs);
	void searchByRoute(ofstream& outData, ofstream& logs);
	//void searchByDateAndpointA(ofstream& outData, ofstream& logs);

	void log(ofstream& log);

	void outToLog(ofstream& logs);

	//Удаление всех данных
	void deleteAll(List& busType, List& date, List& time, List& pointA, ofstream& logs);
};