#include "stdafx.h"
#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(char key, int freq, BinaryTreeNode *left, BinaryTreeNode *right)
{					 //initializing private member variables of a class
	this->key = key;
	this->freq = freq;
	this->left = left;
	this->right = right;
}

BinaryTreeNode::~BinaryTreeNode()  //deconstructor
{
}

char BinaryTreeNode::get_key(void)		//get function for key
{
	return key;
}
int BinaryTreeNode::get_freq(void)		//get function for freq
{
	return freq;
}
BinaryTreeNode* BinaryTreeNode::get_left(void) //get function for left branch
{
	return left;
}
BinaryTreeNode* BinaryTreeNode::get_right(void)	//get function for right branch
{
	return right;
}

