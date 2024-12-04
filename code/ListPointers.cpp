#include "ListPointers.h"
#include <iostream>
#include <fstream>

using namespace std;

// Конструктор класса ListPointers
ListPointers::ListPointers()
{
    // Инициализируем указатели на голову, хвост и текущий элемент списка как nullptr
    pHead = nullptr;
    pTail = nullptr;
    pCur = nullptr;
}

// Метод проверки, пуст ли список
bool ListPointers::is_empty()
{
    // Возвращаем true, если pHead равен nullptr, что означает, что список пуст
    return pHead == nullptr;
}

// Метод добавления элемента в начало списка
void ListPointers::pushFront(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB)
{
    // Создаем новый узел и устанавливаем его в качестве головы списка
    pHead = new NodePointers(otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB, pHead);
    // Если хвост был пуст, устанавливаем хвост на голову (единственный элемент в списке)
    if (pTail == nullptr)
        pTail = pHead;
}

// Метод добавления элемента в конец списка
void ListPointers::pushBack(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB)
{
    // Если список пуст, используем метод pushFront для добавления элемента
    if (is_empty())
    {
        pushFront(otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB);
    }
    else
        // Иначе, добавляем элемент после текущего хвоста
    {
        insertAfter(pTail, otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB);
    }
}

// Метод удаления элемента из начала списка
void ListPointers::popFront()
{
    // Сохраняем указатель на следующий элемент после головы
    NodePointers* nextHead = pHead->pNext;
    // Удаляем текущую голову
    delete pHead;
    // Обновляем голову на следующий элемент
    pHead = nextHead;
    // Если новый голова пуст, также очищаем хвост
    if (pHead == nullptr)
        pTail = nullptr;
}

// Метод вставки элемента после заданного узла
void ListPointers::insertAfter(NodePointers* elem, StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB)
{
    // Создаем новый узел и вставляем его после указанного элемента
    elem->pNext = new NodePointers(otherEdDataAT, otherEdDataD, otherEdDataFT, otherEdDataPB, elem->pNext);
    // Если вставленный элемент стал последним (хвостом), обновляем указатель на хвост
    if (pTail == elem)
        pTail = pTail->pNext;
}

// Метод удаления элемента после заданного узла
void ListPointers::eraseAfter(NodePointers* elem)
{
    // Сохраняем указатель на элемент, который будет удален
    NodePointers* nextElem = elem->pNext;
    // Обновляем указатель на следующий элемент после удаляемого
    elem->pNext = nextElem->pNext;
    // Удаляем узел
    delete nextElem;
    // Если удаленный элемент был хвостом, обновляем указатель на хвост
    if (pTail == nextElem)
        pTail = elem;
}

// Метод вывода всех данных списка в файл
void ListPointers::outAllData(ofstream& logs)
{
    // Устанавливаем текущий элемент на голову списка
    pCur = pHead;
    // Печатаем начало строки в файл
    logs << "|| ";
    // Проходим по всем элементам списка
    while (pCur != nullptr)
    {
        // Выводим данные из каждого узла в файл без перехода на новую строку
        pCur->otherDataNUM->outDataOnlyFileWithoutEnter(logs); logs << "->";
        pCur->otherDataD->outDataOnlyFileWithoutEnter(logs); logs << "->";
        pCur->otherDataTM->outDataOnlyFileWithoutEnter(logs); logs << "->";
        pCur->otherDataPB->outDataOnlyFileWithoutEnter(logs); logs << "->";
        // Переходим к следующему элементу
        pCur = pCur->pNext;
    }
    // Выводим конец строки в файл
    logs << "NULL";
    logs << " ||\n";
}