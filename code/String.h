#pragma once
#include <fstream>

using namespace std;

const unsigned N = 10;

struct String
{
	char string[N];
	int stringLenght = 0;
	int digit_count = 0;
	void clearString();
	void addData(int index, char tmp_symbol);
	char getData(int index);
	void readString(ifstream& dataFile, int& spaces);
	void readStringV2(ifstream& dataFile, int& spaces, bool& is_end);
	void outData(ofstream& outFile);
	void outDataWithoutEnter(ofstream& outFile);
	void outDataOnlyFile(ofstream& outFile);
	void outDataOnlyFileWithoutEnter(ofstream& outFile);

	bool compareString(String S1, String S2);
	bool compareFirst(String S1, String S2);

	//Функции созданные для задачи
	void getStringLength();
	void enterUserData();

	//Всё так же функции для задачи, но для работы с датами
	int typeOfDate();
	void converToDate(String S, int* date);
	void littleConvertToDate(String S, int* date);
	bool isTrueDate(int* date);
	bool inTheRightPeriodOfTime(String date1, String S2, String date2);
	bool compareDates(String date1, String date2);
	bool comparebiba(String date1, String date2);
	bool compareQuarters(String date1, String date2);
};