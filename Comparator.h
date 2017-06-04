#pragma once
#include "BinaryTreeNode.h"

struct Comparator
{
	bool operator()(BinaryTreeNode *a, BinaryTreeNode *b);  //comparator declaration
};
