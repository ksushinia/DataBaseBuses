#pragma once
#include "ListPointersCI.h"

struct CardIndexNode
{
	ListPointersCI necessaryDataAboutBus;
	char boba;
	CardIndexNode* pNext;

	CardIndexNode(ListPointersCI addedData, CardIndexNode* n, char edPar);
};