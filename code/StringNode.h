#pragma once
#include "String.h"

struct StringNode
{
	String element;
	StringNode* pNext;

	StringNode(String edElem, StringNode* n);
};