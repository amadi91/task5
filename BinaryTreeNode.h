#pragma once
#include "stdafx.h"

using namespace std;

struct BinaryTreeNode
{
public:
	//constructer declaration 

	BinaryTreeNode(char key, int freq, BinaryTreeNode* left, BinaryTreeNode* right); //node constructor
	~BinaryTreeNode();
	//functions declarations
	char get_key(void);
	int get_freq(void); 
	BinaryTreeNode* get_left(void);
	BinaryTreeNode* get_right(void);
	

private: //private data members declarations
	char key;
	int freq;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

};