#include "ListPointers.h"
#include <iostream>
#include <fstream>

using namespace std;

// ����������� ������ ListPointers
ListPointers::ListPointers()
{
    // �������������� ��������� �� ������, ����� � ������� ������� ������ ��� nullptr
    pHead = nullptr;
    pTail = nullptr;
    pCur = nullptr;
}

// ����� ��������, ���� �� ������
bool ListPointers::is_empty()
{
    // ���������� true, ���� pHead ����� nullptr, ��� ��������, ��� ������ ����
    return pHead == nullptr;
}

// ����� ���������� �������� � ������ ������
void ListPointers::pushFront(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB)
{
    // ������� ����� ���� � ������������� ��� � �������� ������ ������
    pHead = new NodePointers(otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB, pHead);
    // ���� ����� ��� ����, ������������� ����� �� ������ (������������ ������� � ������)
    if (pTail == nullptr)
        pTail = pHead;
}

// ����� ���������� �������� � ����� ������
void ListPointers::pushBack(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB)
{
    // ���� ������ ����, ���������� ����� pushFront ��� ���������� ��������
    if (is_empty())
    {
        pushFront(otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB);
    }
    else
        // �����, ��������� ������� ����� �������� ������
    {
        insertAfter(pTail, otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB);
    }
}

// ����� �������� �������� �� ������ ������
void ListPointers::popFront()
{
    // ��������� ��������� �� ��������� ������� ����� ������
    NodePointers* nextHead = pHead->pNext;
    // ������� ������� ������
    delete pHead;
    // ��������� ������ �� ��������� �������
    pHead = nextHead;
    // ���� ����� ������ ����, ����� ������� �����
    if (pHead == nullptr)
        pTail = nullptr;
}

// ����� ������� �������� ����� ��������� ����
void ListPointers::insertAfter(NodePointers* elem, StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB)
{
    // ������� ����� ���� � ��������� ��� ����� ���������� ��������
    elem->pNext = new NodePointers(otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB, elem->pNext);
    // ���� ����������� ������� ���� ��������� (�������), ��������� ��������� �� �����
    if (pTail == elem)
        pTail = pTail->pNext;
}

// ����� �������� �������� ����� ��������� ����
void ListPointers::eraseAfter(NodePointers* elem)
{
    // ��������� ��������� �� �������, ������� ����� ������
    NodePointers* nextElem = elem->pNext;
    // ��������� ��������� �� ��������� ������� ����� ����������
    elem->pNext = nextElem->pNext;
    // ������� ����
    delete nextElem;
    // ���� ��������� ������� ��� �������, ��������� ��������� �� �����
    if (pTail == nextElem)
        pTail = elem;
}

// ����� ������ ���� ������ ������ � ����
void ListPointers::outAllData(ofstream& logs)
{
    // ������������� ������� ������� �� ������ ������
    pCur = pHead;
    // �������� ������ ������ � ����
    logs << "|| ";
    // �������� �� ���� ��������� ������
    while (pCur != nullptr)
    {
        // ������� ������ �� ������� ���� � ���� ��� �������� �� ����� ������
        pCur->otherDataNUM->outDataOnlyFileWithoutEnter(logs); logs << "->";
        pCur->otherDataD->outDataOnlyFileWithoutEnter(logs); logs << "->";
        pCur->otherDataTM->outDataOnlyFileWithoutEnter(logs); logs << "->";
        pCur->otherDataPB->outDataOnlyFileWithoutEnter(logs); logs << "->";
        // ��������� � ���������� ��������
        pCur = pCur->pNext;
    }
    // ������� ����� ������ � ����
    logs << "NULL";
    logs << " ||\n";
}