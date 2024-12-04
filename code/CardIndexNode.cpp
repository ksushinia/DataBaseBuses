#include "CardIndexNode.h"

CardIndexNode::CardIndexNode(ListPointersCI addedData, CardIndexNode* n, char edPar)
{
	necessaryDataAboutBus = addedData;
	boba = edPar;
	pNext = n;
}