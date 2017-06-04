#include "stdafx.h"
#include "Comparator.h"
#include "BinaryTreeNode.h"

using namespace std;

bool Comparator::operator()( BinaryTreeNode *a, BinaryTreeNode *b) //comparator function definition responsible for comparing two values and returning them sorted
{
	return a->get_freq() > b->get_freq(); //comparator had to be changed to sort out values from the lowest to the highest so when merging takes place new "parent" value can be merged with next lowest value in the priority_queue
}


