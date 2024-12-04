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
        alphabet.log(logs);  logs << "Файл успешно открыт.\n";
    }
    else
    {
        alphabet.log(logs);  logs << "ОШИБКА: Файл не открыт или отсутствует.\n";
    }

    alphabet.createEmptyList();
    alphabet.log(logs);  logs << "ШАГ 1: Создана пустая картотека.\n";
    alphabet.log(logs);  logs << "ШАГ 2: Началось заполнение картотеки...\n"; cout << "Началось заполнение картотеки...\n";
    alphabet.readingFromFile(dataFile, time, date, number, pointA, pointB, logs);
    alphabet.log(logs);  logs << "ШАГ 3: Все списки заполнены информацией.\n";
    alphabet.log(logs);  logs << "ШАГ 4: Картотека заполнена информацией.\n\n"; cout << "Картотека заполнена информацией.\n\n";

    alphabet.outToLog(logs);

    //Проработка сценария:
    int answerF = 10;
    int answerSF = 10;
    int answerSS = 10;
    while (answerF != 0)
    {
        cout << "Здравствуйте! Предлагаем вам на выбор несколько параметров: \n\n";
        cout << "| 0 - Завершить программу (работает безотказно).\n";
        cout << "| 1 - Найти всю информацию о нужом вам автобусе по его номеру.\n";
        cout << "| 2 - Узнать маршрут автобуса по его номеру.\n\n";
        cout << "Введите нужный вам параметр: ";  cin >> answerF;
        if (answerF > 2 || answerF < 0) cout << "Ошибка, данного номера выполнения задачи нет. Повторите попытку.\n";
        else
        {
            switch (answerF)
            {
            case 1:
                while (answerSF != 0)
                {
                    alphabet.log(logs);  logs << "Пользователь выбрал поиск всей информации об автобусе по его номеру.\n";
                    alphabet.searchBybusType(outFile, logs);
                    cout << "Выберите нужный параметр: \n";
                    cout << "| 0 - Вернуться назад.\n";
                    cout << "| 1 - Продолжить поиск с другими значениями.\n";
                    cout << "Ввод: "; cin >> answerSF;
                }
                alphabet.log(logs);  logs << "Поиск всей информации об автобусе по его номеру был завершен.\n";
                break;
            case 2:
                while (answerSS != 0)
                {
                    alphabet.log(logs);  logs << "Пользователь выбрал поиск маршрута автобуса по его номеру.\n";
                    alphabet.searchByRoute(outFile, logs);
                    cout << "Выберите нужный параметр: \n";
                    cout << "| 0 - Вернуться назад.\n";
                    cout << "| 1 - Продолжить поиск с другими значениями.\n";
                    cout << "Ввод: "; cin >> answerSS;
                }
                alphabet.log(logs);  logs << "Поиск  маршрута автобуса по его номеру был завершен.\n";
                break;
            }
        }
    }
    cout << "Завершение программы...";
    alphabet.deleteAll(time, date, number, pointA, logs);
    alphabet.log(logs);  logs << "Завершение программы.\n";
}