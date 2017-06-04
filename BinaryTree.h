#pragma once
#include "stdafx.h"
#include "BinaryTreeNode.h"
#include "iostream"
#include "iomanip"

using namespace std;

class BinaryTree
{
public:
	BinaryTree();	//constructor 
	~BinaryTree();  //deconstructor 
	
	//function declarations
	BinaryTreeNode* Merge(BinaryTreeNode *left, BinaryTreeNode *right);	 
	void PrintTree(BinaryTreeNode* leaf, int indentLevel);
	void SetRootNode(BinaryTreeNode* NewRoot);
	BinaryTreeNode* get_root(void);
	int get_indentLevel(void);
	void PrintTree(); 

	//private data members declararions
private:
	int indentLevel = 0;
	void destroyer(BinaryTreeNode* newRoot);
	BinaryTreeNode* NewRoot;
	
	


};


