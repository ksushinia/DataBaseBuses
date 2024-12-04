#include "CardIndex.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

CardIndex::CardIndex()
{
	pHead = nullptr;
	pTail = nullptr;
	pCur = nullptr;
}

void CardIndex::log(ofstream& log)
{
	time_t currentTime;
	time(&currentTime);

	tm tm_time;
	localtime_s(&tm_time, &currentTime);

	char timeStr[20];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &tm_time);

	log << timeStr << ' ';
}

bool CardIndex::is_empty()
{
	return pHead == nullptr;
}

void CardIndex::pushFront(ListPointersCI necessaryInfo, char edPar)
{
	pHead = new CardIndexNode(necessaryInfo, pHead, edPar);
	if (pTail == nullptr)
		pTail = pHead;
}

void CardIndex::pushBack(ListPointersCI necessaryInfo, char edPar)
{
	if (is_empty())
	{
		pushFront(necessaryInfo, edPar);
	}
	else
		insertAfter(pTail, necessaryInfo, edPar);
}

void CardIndex::popFront()
{
	CardIndexNode* nextHead = pHead->pNext;
	delete pHead;
	pHead = nextHead;
	if (pHead == nullptr)
		pTail = nullptr;
}

void CardIndex::insertAfter(CardIndexNode* elem, ListPointersCI necessaryInfo, char edPar)
{
	elem->pNext = new CardIndexNode(necessaryInfo, elem->pNext, edPar);
	if (pTail == elem)
		pTail = pTail->pNext;
}

void CardIndex::eraseAfter(CardIndexNode* elem)
{
	CardIndexNode* nextElem = elem->pNext;
	elem->pNext = nextElem->pNext;
	delete nextElem;
	if (pTail == nextElem)
		pTail = elem;
}

void CardIndex::createEmptyList()
{
	char boba = 'A';
	while (boba <= 'Z')
	{
		pushBack(ListPointersCI(), boba);
		boba++;
	}
}

void CardIndex::compareWithboba(List pointA)
{
	pCur = pHead;
	while (pCur != nullptr)
	{
		if (pointA.pCur != nullptr)
		{
			if (pCur->boba == pointA.pCur->data.pHead->element.string[0])
			{
				pCur->necessaryDataAboutBus.pushBack(&pointA.pCur->data, &pointA.pCur->otherData);
			}
		}
		else
		{
			if (pCur->boba == pointA.pTail->data.pHead->element.string[0])
			{
				pCur->necessaryDataAboutBus.pushBack(&pointA.pTail->data, &pointA.pTail->otherData);
			}
		}
		pCur = pCur->pNext;
	}
}

void CardIndex::readingFromFile(ifstream& dataFile, List& BusType, List& date, List& time, List& pointA, List& pointB, ofstream& logs)
{
	log(logs); logs << "�������� ���������� � �����.\n.";
	dataFile.unsetf(ios::skipws);
	int spaces = 0;
	while (1)
	{
		StringList* s = new StringList();

		s->readFromFile(dataFile, spaces); //���� ��� V2 ������ ������ case
		switch (spaces)
		{
		case 2:
			if (s->lengthList() == 0)
			{
				cout << "������: ����������� ���������� � ������ �������� � ������ ������. ���������� ������� ����������: "; s->enterUserData();
				log(logs); logs << "������: � ������ �� ������� ����������.\n";
				log(logs); logs << "������������ ������� �������: "; s->outDataOnlyFile(logs);
			}
			if (BusType.isUnique(BusType, *s))
			{
				BusType.pushBack(*s);
				log(logs); logs << "�������� ������� 1: "; s->outDataOnlyFile(logs);
				BusType.pCur = BusType.pTail;
			}
			else
			{
				BusType.fillingWithData(BusType, *s);
				log(logs); logs << "������� 1 ��� ����������: "; s->outDataOnlyFile(logs);
			}
			//s->clearStringList();
			break;
		case 3:
			if (s->lengthList() == 0)
			{
				cout << "������: ����������� ���������� � ���� � ������ ������. ���������� ������� ����������: "; s->enterUserData();
				log(logs); logs << "������: � ������ �� ������� ����������\n.";
				log(logs); logs << "������������ ������� �������: "; s->outDataOnlyFile(logs);
			}
			if (date.isUnique(date, *s))
			{
				date.pushBack(*s);
				log(logs); logs << "�������� ������� 2: "; s->outDataOnlyFile(logs);
				date.pCur = date.pTail;
			}
			else
			{
				date.fillingWithData(date, *s);
				log(logs); logs << "������� 2 ��� ����������: "; s->outDataOnlyFile(logs);
			}
			//s->clearStringList();
			break;
		case 4:
			if (s->lengthList() == 0)
			{
				cout << "������: ����������� ���������� � ������� � ������ ������. ���������� ������� ����������: "; s->enterUserData();
				log(logs); logs << "������: � ������ �� ������� ����������\n.";
				log(logs); logs << "������������ ������� �������: "; s->outDataOnlyFile(logs);
			}
			if (time.isUnique(time, *s))
			{
				time.pushBack(*s);
				log(logs); logs << "�������� ������� 3: "; s->outDataOnlyFile(logs);
				time.pCur = time.pTail;
			}
			else
			{
				time.fillingWithData(time, *s);
				log(logs); logs << "������� 3 ��� ����������: "; s->outDataOnlyFile(logs);
			}
			//s->clearStringList();
			break;
		case 5:
			if (s->lengthList() == 0)
			{
				cout << "������ ����������� ���������� � ������ �������� � ������ ������. ���������� ������� ����������: "; s->enterUserData();
				log(logs); logs << "������: � ������ �� ������� ����������\n.";
				log(logs); logs << "������������ ������� �������: "; s->outDataOnlyFile(logs);
			}
			if (pointB.isUnique(pointB, *s))
			{
				pointB.pushBack(*s);
				log(logs); logs << "�������� ������� 4: "; s->outDataOnlyFile(logs);
				pointB.pCur = pointB.pTail;
			}
			else
			{
				pointB.fillingWithData(pointB, *s);
				log(logs); logs << "������� 4 ��� ����������: "; s->outDataOnlyFile(logs);
			}
			//s->clearStringList();
			break;
		case 6:
			if (s->lengthList() == 0)
			{
				cout << "������ ����������� ���������� � ������ ����������� � ������ ������. ���������� ������� ����������: "; s->enterUserData();
				log(logs); logs << "������: � ������ �� ������� ����������.\n";
				log(logs); logs << "������������ ������� �������: "; s->outDataOnlyFile(logs);
			}
			if (pointA.isUnique(pointA, *s))
			{
				pointA.pushBack(*s);
				log(logs); logs << "�������� ������� 5: "; s->outDataOnlyFile(logs);
				pointA.pTail->otherData.pushBack(&BusType.pCur->data, &date.pCur->data, &time.pCur->data, &pointB.pCur->data);
				this->compareWithboba(pointA);
			}
			else
			{
				log(logs); logs << "������� 5 ��� ����������: "; s->outDataOnlyFile(logs);
				//���-�� �� ���������� ���� //������� ������ ������ ������
				if (pointA.pCur->otherData.pTail->otherDataD->compareDates(*pointA.pCur->otherData.pTail->otherDataD, date.pCur->data))
				{
					if (pointA.pCur->otherData.pTail == pointA.pCur->otherData.pHead)
						pointA.pCur->otherData.pushFront(&BusType.pCur->data, &date.pCur->data, &time.pCur->data, &pointB.pCur->data);
					else if (pointA.pCur->otherData.pHead->otherDataD->compareDates(*pointA.pCur->otherData.pHead->otherDataD, date.pCur->data))
					{
						pointA.pCur->otherData.pushFront(&BusType.pCur->data, &date.pCur->data, &time.pCur->data, &pointB.pCur->data);
					}
					else
					{
						pointA.pCur->otherData.pCur = pointA.pCur->otherData.pHead;
						while (!pointA.pCur->otherData.pCur->otherDataD->compareDates(*pointA.pCur->otherData.pCur->pNext->otherDataD, date.pCur->data))
						{
							pointA.pCur->otherData.pCur = pointA.pCur->otherData.pCur->pNext;
						}
						pointA.pCur->otherData.insertAfter(pointA.pCur->otherData.pCur, &BusType.pCur->data, &date.pCur->data, &time.pCur->data, &pointB.pCur->data);
					}
				}
				//�����
				else pointA.pCur->otherData.pushBack(&BusType.pCur->data, &date.pCur->data, &time.pCur->data, &pointB.pCur->data);
			}
			//s->clearStringList();
			spaces = 0;
			break;
		}
		if (dataFile.eof()) break;
	}
	log(logs); logs << "���������� � ���������� ������� ���������.\n";
}

void CardIndex::searchBybusType(ofstream& outData, ofstream& logs)
{
	StringList answer;
	cout << "������� ����� ��������: ";
	answer.enterUserData();
	log(logs); logs << "������������ ��� ��������: "; answer.outDataOnlyFile(logs);
	cout << "\n����� ���� ���������� �� �������� �� ��� ������:\n"; outData << "����� ���� ���������� �� �������� �� ��� ������:\n"; answer.outData(outData); cout << "���������� ����������: \n"; outData << "���������� ����������: \n";
	CardIndexNode* cur = pHead;
	while (cur != nullptr)
	{
		cur->necessaryDataAboutBus.pCur = cur->necessaryDataAboutBus.pHead;
		if (cur->necessaryDataAboutBus.is_empty() == true) cur = cur->pNext;
		else
		{
			while (cur->necessaryDataAboutBus.pCur != nullptr)
			{
				cur->necessaryDataAboutBus.pCur->otherData->pCur = cur->necessaryDataAboutBus.pCur->otherData->pHead;
				while (cur->necessaryDataAboutBus.pCur->otherData->pCur != nullptr)
				{
					if (cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataNUM->compareStringList(*cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataNUM, answer))
					{
						cout << "\t����� �: "; outData << "\t����� �: "; cur->necessaryDataAboutBus.pCur->necessaryData->outData(outData);
						cout << "\t����� B: "; outData << "\t����� B: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataPB->outData(outData);
						cout << "\t����� �����������: "; outData << "\t����� �����������: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataTM->outData(outData);
						cout << "\t����: "; outData << "\t����: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataD->outData(outData);
						cout << "\t����� ��������: "; outData << "\t����� ��������: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataNUM->outData(outData);
						//cout << "\tPOINT B: "; outData << "\tPOINT B: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataPB->outData(outData);
						cout << "\n"; outData << "\n";
						log(logs); logs << "���� ������� ������ ��������:\n";
						logs << "\t\t\t\t����� �: "; cur->necessaryDataAboutBus.pCur->necessaryData->outDataOnlyFile(logs);
						logs << "\t\t\t\t����� B: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataPB->outDataOnlyFile(logs);
						logs << "\t\t\t\t����� �����������: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataTM->outDataOnlyFile(logs);
						logs << "\t\t\t\t����: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataD->outDataOnlyFile(logs);
						logs << "\t\t\t\t����� ��������: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataNUM->outDataOnlyFile(logs);
						//logs << "\t\t\t\tPOINT B: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataPB->outDataOnlyFile(logs);
					}
					cur->necessaryDataAboutBus.pCur->otherData->pCur = cur->necessaryDataAboutBus.pCur->otherData->pCur->pNext;
				}
				cur->necessaryDataAboutBus.pCur = cur->necessaryDataAboutBus.pCur->pNext;
			}
			cur = cur->pNext;
		}
	}
}

void CardIndex::searchByRoute(ofstream& outData, ofstream& logs)
{
	StringList answer;
	cout << "������� ����� ��������: ";
	answer.enterUserData();
	log(logs); logs << "������������ ��� ��������: "; answer.outDataOnlyFile(logs);
	cout << "\n����� �������� �� ������ ��������: \n"; outData << "����� �������� �� ������ ��������: \n"; answer.outData(outData); cout << "���������� ����������: \n"; outData << "���������� ����������: \n";
	CardIndexNode* cur = pHead;
	while (cur != nullptr)
	{
		cur->necessaryDataAboutBus.pCur = cur->necessaryDataAboutBus.pHead;
		if (cur->necessaryDataAboutBus.is_empty() == true) cur = cur->pNext;
		else
		{
			while (cur->necessaryDataAboutBus.pCur != nullptr)
			{
				cur->necessaryDataAboutBus.pCur->otherData->pCur = cur->necessaryDataAboutBus.pCur->otherData->pHead;
				while (cur->necessaryDataAboutBus.pCur->otherData->pCur != nullptr)
				{
					if (cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataNUM->compareStringList(*cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataNUM, answer))
					{
						cout << "\t����� A: "; outData << "\t����� �: "; cur->necessaryDataAboutBus.pCur->necessaryData->outData(outData);
						/*cout << "\tNUMBER: "; outData << "\tNUMBER: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataTM->outData(outData);
						cout << "\tDATE: "; outData << "\tDATE: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataD->outData(outData);
						cout << "\ttime: "; outData << "\ttime: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataNUM->outData(outData);*/
						cout << "\t����� B: "; outData << "\tPOINT B: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataPB->outData(outData);
						cout << "\n"; outData << "\n";
						log(logs); logs << "���� ������� ������ ��������:\n";
						logs << "\t\t\t\t����� �: "; cur->necessaryDataAboutBus.pCur->necessaryData->outDataOnlyFile(logs);
						logs << "\t\t\t\t����� B: "; cur->necessaryDataAboutBus.pCur->otherData->pCur->otherDataPB->outDataOnlyFile(logs);
						//logs << "\t\t\t\t����� �����������: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataTM->outDataOnlyFile(logs);
						//logs << "\t\t\t\t����: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataD->outDataOnlyFile(logs);
						//logs << "\t\t\t\t����� ��������: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataNUM->outDataOnlyFile(logs);
						//logs << "\t\t\t\tPOINT B: "; cur->necessaryDataAboutFlight.pCur->otherData->pCur->otherDataPB->outDataOnlyFile(logs);
					}
					cur->necessaryDataAboutBus.pCur->otherData->pCur = cur->necessaryDataAboutBus.pCur->otherData->pCur->pNext;
				}
				cur->necessaryDataAboutBus.pCur = cur->necessaryDataAboutBus.pCur->pNext;
			}
			cur = cur->pNext;
		}
	}
}


void CardIndex::deleteAll(List& busType, List& date, List& time, List& pointA, ofstream& logs)
{
	log(logs); logs << "������ ������� ���� ������.\n";
	while (!is_empty())
	{
		while (!pHead->necessaryDataAboutBus.is_empty()) pHead->necessaryDataAboutBus.popFront();
		popFront();
	}
	while (!busType.is_empty()) busType.popFront();
	busType.pCur = nullptr;
	while (!date.is_empty()) date.popFront();
	date.pCur = nullptr;
	while (!time.is_empty()) time.popFront();
	time.pCur = nullptr;
	while (!pointA.is_empty())
	{
		while (!pointA.pHead->otherData.is_empty()) pointA.pHead->otherData.popFront();
		pointA.popFront();
	}
	pointA.pCur = nullptr;
	log(logs); logs << "������� ���� �����������.\n";
}

void CardIndex::outToLog(ofstream& logs)
{
	pCur = pHead;
	log(logs); logs << "������ ������ ���� ����������.\n";
	while (pCur != nullptr)
	{
		logs << "��������: " << pCur->boba << "\n";
		pCur->necessaryDataAboutBus.outDataListCI(logs);
		logs << "|\n";
		logs << "V\n";
		pCur = pCur->pNext;
	}
	logs << "NULL\n";
	log(logs); logs << "����� ���� ���������� ��������.\n\n";
}