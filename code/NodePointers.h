#pragma once
#include "NodeInfo.h"
#include "StringList.h"

struct NodePointers
{
	StringList* otherDataNUM;
	StringList* otherDataTM;
	StringList* otherDataD;
	StringList* otherDataPB;
	NodePointers* pNext;
	NodePointers(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB, NodePointers* n);
};