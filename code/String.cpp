#include "String.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;

void String::addData(int index, char tmp_symbol)
{
	string[index] = tmp_symbol;
}

void String::clearString()
{
	for (int i = 0; i < stringLenght; i++)
	{
		string[i] = '\0';
	}
	stringLenght = 0;
}

void String::getStringLength()
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
		stringLenght++;
	}
}

char String::getData(int index)
{
	return string[index];
}

void String::readString(ifstream& dataFile, int& spaces)
{
	char tmp_symbol = '-';
	int index = 0;
	dataFile.unsetf(ios::skipws);
	while (tmp_symbol != '\n' || !dataFile.eof())
	{
		if (dataFile.eof())
		{
			spaces = 0;
			break;
		}
		dataFile >> tmp_symbol;
		if (tmp_symbol == ' ')
		{
			spaces++;
			break;
		}
		if (tmp_symbol == '\n')
		{
			spaces++;
			break;
		}
		addData(index, tmp_symbol);
		index++;
		if (dataFile.eof())
		{
			spaces = 0;
			break;
		}
		stringLenght++;
		if (stringLenght >= N) break;
	}
}

void String::readStringV2(ifstream& dataFile, int& spaces, bool& is_end)
{
	char tmp_symbol = '-';
	int index = 0;
	dataFile.unsetf(ios::skipws);
	while (tmp_symbol != '\n' || !dataFile.eof())
	{
		if (dataFile.eof())
		{
			spaces = 0;
			break;
		}
		dataFile >> tmp_symbol;
		if (tmp_symbol == ' ')
		{
			while (tmp_symbol == ' ') dataFile >> tmp_symbol;
		}
		if (tmp_symbol == '|')
		{
			spaces++;
			is_end = true;
			break;
		}
		if (tmp_symbol == '\n')
		{
			is_end = true;
			break;
		}
		addData(index, tmp_symbol);
		index++;
		if (dataFile.eof())
		{
			is_end = true;
			spaces = 0;
			break;
		}
		stringLenght++;
		if (stringLenght >= N) break;
	}
}

void String::outData(ofstream& outFile)
{
	for (int index = 0; index < stringLenght; index++)
	{
		cout << getData(index);
		outFile << getData(index);
	}
	cout << '\n';
	outFile << '\n';
}

void String::outDataWithoutEnter(ofstream& outFile)
{
	for (int index = 0; index < stringLenght; index++)
	{
		cout << getData(index);
		outFile << getData(index);
	}
}

void String::outDataOnlyFile(ofstream& outFile)
{
	for (int index = 0; index < stringLenght; index++)
	{
		outFile << getData(index);
	}
	outFile << '\n';
}

void String::outDataOnlyFileWithoutEnter(ofstream& outFile)
{
	for (int index = 0; index < stringLenght; index++)
	{
		outFile << getData(index);
	}
}

bool String::compareString(String S1, String S2)
{
	if (1 == 0) return false;
	else
	{
		for (int i = 0; i < stringLenght; i++)
		{
			if (S1.string[i] != S2.string[i]) return false;
		}
	}
	return true;
}

bool String::compareFirst(String S1, String S2)
{
	if (S1.string[0] <= S2.string[0]) return true;
	else return false;
}

void String::enterUserData()
{
	cin >> string;
	this->getStringLength();
}

void String::converToDate(String S, int* date)
{
	int i = 0, j = 0;
	while (i != S.stringLenght)
	{
		int result = 0;
		while (S.getData(i) != '-')
		{
			if (i == S.stringLenght) break;
			result = result * 10 + (S.getData(i) - '0');
			++i;
		}
		date[j] = result;
		if (j > 2) break;
		j++;
		if (i == S.stringLenght) break;
		i++;
	}
}

bool String::isTrueDate(int* date)
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

bool String::inTheRightPeriodOfTime(String date1, String S, String date2)
{
	int FDate[3], StringDate[3], SDate[3];
	date1.converToDate(date1, FDate);
	S.converToDate(S, StringDate);
	date2.converToDate(date2, SDate);
	if (date1.isTrueDate(FDate) && S.isTrueDate(StringDate) && date2.isTrueDate(SDate))
	{
		if ((FDate[0] < StringDate[0]) && (StringDate[0] < SDate[0])) return true;
		else if ((FDate[0] <= StringDate[0]) && (StringDate[0] < SDate[0]))
		{
			if (FDate[1] == StringDate[1])
			{
				if (FDate[2] <= StringDate[2]) return true;
			}
		}
		else if ((FDate[0] < StringDate[0]) && (StringDate[0] <= SDate[0]))
		{
			if (StringDate[1] == SDate[1])
			{
				if (StringDate[2] <= SDate[2]) return true;
			}
		}
		else if ((FDate[0] == StringDate[0]) && (StringDate[0] == SDate[0]))
		{
			if ((FDate[1] < StringDate[1]) && (StringDate[1] < SDate[1])) return true;
			else if ((FDate[1] == StringDate[1]) && (StringDate[1] == SDate[1]))
			{
				if ((FDate[2] <= StringDate[2]) && (StringDate[2] <= SDate[2])) return true;
			}
			else if ((FDate[1] == StringDate[1]))
			{
				if (FDate[2] <= StringDate[2]) return true;
			}
			else if ((StringDate[1] == SDate[1]))
			{
				if (StringDate[2] <= SDate[2]) return true;
			}
		}
	}
	return false;
}

bool String::compareDates(String date1, String date2)
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

int String::typeOfDate()
{
	int Fdate[3];
	converToDate(*this, Fdate);
	if (stringLenght != 0)
	{
		if (string[0] == 'M')
			return 2;
		if (string[0] == 'K')
			return 3;
		if (isTrueDate(Fdate))
			return 1;
	}
	else return -1;
}

bool String::comparebiba(String date1, String date2)
{
	int Fdate[3];
	date1.converToDate(date1, Fdate);
	int Sdate[3];
	date2.littleConvertToDate(date2, Sdate);
	if (Fdate[1] == Sdate[0]) return true;
	else return false;
}

bool String::compareQuarters(String date1, String date2)
{
	int Fdate[3];
	date1.converToDate(date1, Fdate);
	int Sdate[3];
	date2.littleConvertToDate(date2, Sdate);
	if (((Fdate[1] / 3) == (Sdate[0] - 1)) || ((Fdate[1] / 3) == (Sdate[0]))) return true;
	else return false;
}

void String::littleConvertToDate(String date, int* dateint)
{
	int i = 1, j = 0;
	while (i != date.stringLenght)
	{
		int result = 0;
		while (date.getData(i) != '-')
		{
			if (i == date.stringLenght) break;
			result = result * 10 + (date.getData(i) - '0');
			++i;
		}
		dateint[j] = result;
		if (j > 0) break;
		j++;
		if (i == date.stringLenght) break;
		i++;
	}
}