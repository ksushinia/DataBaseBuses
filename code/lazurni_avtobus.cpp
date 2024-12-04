#include <iostream>
#include <fstream>
#include "List.h"
#include "StringList.h"
#include "locale"
#include "CardIndex.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    List pointA, number, time, date, pointB;
    CardIndex alphabet;
    ifstream dataFile("dataFile.txt", ios::in);
    ofstream outFile("outFile.txt", ios::out);
    ofstream logs("logs.txt", ios::out);

    //ifstream A("A.txt", ios::in);
    //ifstream B("B.txt", ios::in);
    //int dates2[3];
    //StringList ab, bob;
    //ab.enterUserData();
    //ab.converToDate(ab, dates2);

    if (dataFile.is_open())
    {
        alphabet.log(logs);  logs << "���� ������� ������.\n";
    }
    else
    {
        alphabet.log(logs);  logs << "������: ���� �� ������ ��� �����������.\n";
    }

    alphabet.createEmptyList();
    alphabet.log(logs);  logs << "��� 1: ������� ������ ���������.\n";
    alphabet.log(logs);  logs << "��� 2: �������� ���������� ���������...\n"; cout << "�������� ���������� ���������...\n";
    alphabet.readingFromFile(dataFile, time, date, number, pointA, pointB, logs);
    alphabet.log(logs);  logs << "��� 3: ��� ������ ��������� �����������.\n";
    alphabet.log(logs);  logs << "��� 4: ��������� ��������� �����������.\n\n"; cout << "��������� ��������� �����������.\n\n";

    alphabet.outToLog(logs);

    //���������� ��������:
    int answerF = 10;
    int answerSF = 10;
    int answerSS = 10;
    while (answerF != 0)
    {
        cout << "������������! ���������� ��� �� ����� ��������� ����������: \n\n";
        cout << "| 0 - ��������� ��������� (�������� ����������).\n";
        cout << "| 1 - ����� ��� ���������� � ����� ��� �������� �� ��� ������.\n";
        cout << "| 2 - ������ ������� �������� �� ��� ������.\n\n";
        cout << "������� ������ ��� ��������: ";  cin >> answerF;
        if (answerF > 2 || answerF < 0) cout << "������, ������� ������ ���������� ������ ���. ��������� �������.\n";
        else
        {
            switch (answerF)
            {
            case 1:
                while (answerSF != 0)
                {
                    alphabet.log(logs);  logs << "������������ ������ ����� ���� ���������� �� �������� �� ��� ������.\n";
                    alphabet.searchBybusType(outFile, logs);
                    cout << "�������� ������ ��������: \n";
                    cout << "| 0 - ��������� �����.\n";
                    cout << "| 1 - ���������� ����� � ������� ����������.\n";
                    cout << "����: "; cin >> answerSF;
                }
                alphabet.log(logs);  logs << "����� ���� ���������� �� �������� �� ��� ������ ��� ��������.\n";
                break;
            case 2:
                while (answerSS != 0)
                {
                    alphabet.log(logs);  logs << "������������ ������ ����� �������� �������� �� ��� ������.\n";
                    alphabet.searchByRoute(outFile, logs);
                    cout << "�������� ������ ��������: \n";
                    cout << "| 0 - ��������� �����.\n";
                    cout << "| 1 - ���������� ����� � ������� ����������.\n";
                    cout << "����: "; cin >> answerSS;
                }
                alphabet.log(logs);  logs << "�����  �������� �������� �� ��� ������ ��� ��������.\n";
                break;
            }
        }
    }
    cout << "���������� ���������...";
    alphabet.deleteAll(time, date, number, pointA, logs);
    alphabet.log(logs);  logs << "���������� ���������.\n";
}