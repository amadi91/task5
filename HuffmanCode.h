#pragma once
#include"stdafx.h"
#include "BinaryTreeNode.h"
#include <queue>
#include "Comparator.h"
#include "stdafx.h"
#include "SymbolFreq.h"
#include "BinaryTree.h"
#include <iostream>

class HuffmanCode
{
public:
	HuffmanCode(); //constructor
	~HuffmanCode();	//deconstructor 

	//function declarations 
	void HuffmanTreeBuilder(void);
	void HuffmanCodeCreator(BinaryTreeNode* NewRoot, string code);
	void HuffmanCodeCreator();


private:
	priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, Comparator>* myQueue;
	map <char, int>* myMainMap;
	BinaryTreeNode* child1;
	BinaryTreeNode* child2;
	BinaryTreeNode* parent;
	BinaryTreeNode* HuffmanRoot;
	SymbolFreq* objectSymFreq;
	BinaryTree* objectBinaryTree;
	string code;

};