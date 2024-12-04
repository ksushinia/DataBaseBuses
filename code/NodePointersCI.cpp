#include "NodePointersCI.h"

NodePointersCI::NodePointersCI(StringList* editedData, ListPointers* otherEdData, NodePointersCI* n)
{
	necessaryData = editedData;
	otherData = otherEdData;
	pNext = n;
}