#include "NodePointers.h"

NodePointers::NodePointers(StringList* otherEdDataAT, StringList* otherEdDataD, StringList* otherEdDataFT, StringList* otherEdDataPB, NodePointers* n)
{
	otherDataNUM = otherEdDataAT;
	otherDataD = otherEdDataD;
	otherDataTM = otherEdDataFT;
	otherDataPB = otherEdDataPB;

	pNext = n;
}