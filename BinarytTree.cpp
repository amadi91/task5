#include "stdafx.h"
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
	 destroyer(NewRoot);
}

void BinaryTree::destroyer(BinaryTreeNode* NewRoot) //recursive destroyer function 
{
	
		if (NewRoot->get_left() != NULL)	//if left is not 0 recall destroyer function to go level lower 
		{
			destroyer(NewRoot->get_left());
		}
		if (NewRoot->get_right() != NULL)  //if right is not 0 recall destroyer function to go level lower 
		{
			destroyer(NewRoot->get_right());
		}
		delete NewRoot;

}

BinaryTreeNode* BinaryTree::Merge(BinaryTreeNode *left, BinaryTreeNode *right)	//merge function (merges two nodes and returnes new node)
{
	BinaryTreeNode* newnode = new BinaryTreeNode(NULL, (left->get_freq() + right->get_freq()), left , right);
	
	return newnode;
}

void BinaryTree::PrintTree()
{
	PrintTree(NewRoot, indentLevel); //passing NewRoot and indentLevel to overload print function
}

void BinaryTree::PrintTree(BinaryTreeNode* leaf, int indentLevel) //Print tree function (2x arguments leaf and indentLevel)
{
	if (leaf != NULL)	//if leaf not equals to 0
	{
		if (leaf->get_right()) // go down to right node
		{
			PrintTree(leaf->get_right(), indentLevel + 5); // call print tree function recursively go right again and increase indent level by 5
		}

		if (indentLevel)	//considering indentaion level and couting indentLevel by using setw()function then follow it with space
		{
			cout << setw(indentLevel) << ' ';
		}

		if (leaf->get_right()) cout << " /\n" << setw(indentLevel) << ' '; //go to the right node and cout /\ for visual thee imitation then allocate in basing on indentLevel and setw() function
		cout << leaf->get_freq() << "\n "; //print frequency

		if (leaf->get_left())  //go to the left node
		{
			cout << std::setw(indentLevel) << ' ' << " \\\n"; //print out indentLevel using setw() function followed by space and ///n
			PrintTree(leaf->get_left(), indentLevel + 5);    //call prinTree recursively to go down to the left node and then increace indentation level by 5 again.
		}
	}
}

void BinaryTree::SetRootNode(BinaryTreeNode* NewRoot)	//SetRootNode function
{
	this->NewRoot = NewRoot;
}

BinaryTreeNode* BinaryTree::get_root(void)	//GetRootNode function
{
	return NewRoot;
}

int BinaryTree::get_indentLevel(void)  //GetIndentationLevel function
{
	return indentLevel;
}
