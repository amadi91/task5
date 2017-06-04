#include "stdafx.h"
#include "HuffmanCode.h"

using namespace std;

HuffmanCode::HuffmanCode()
{
	myQueue = new priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, Comparator >;
	myMainMap = new map <char, int>;
	//creating object of different classes to access desired functions
	objectSymFreq = new SymbolFreq;
	objectBinaryTree = new BinaryTree;
}

HuffmanCode::~HuffmanCode()
{
	if (myMainMap != NULL)
		delete myMainMap;
	if (myQueue != NULL)
		delete myQueue;
	if (child1 != NULL);
		delete child1;
	if (child2 != NULL)
		delete child2;
	if (parent != NULL)
		delete parent;
	if (HuffmanRoot != NULL)
		delete HuffmanRoot;
	
}


void HuffmanCode::HuffmanTreeBuilder(void)
{
	//Triggering functions existing in "SymolFreq" class
	objectSymFreq->readFromFile(); // <- Reading from external file
	objectSymFreq->vecmapCreator(); // <- Creating an instance of the map and then populating it and sorting it from highest to the lowest 

	//Getting a map form "SymbolFreq" class and copying it in to "myMain map"
	myMainMap = objectSymFreq->get_myMap();

	//iterating through the map and pushing values back on the priotioty_queue 
	for (map<char, int>::iterator it = myMainMap->begin(); it != myMainMap->end(); ++it)
	{
		BinaryTreeNode* node = new BinaryTreeNode(it->first, it->second, NULL, NULL);
		myQueue->push(node);
	}

	while (myQueue->size() > 1)	//iterating through myQueue untill there is one element left inside 
	{
		
		child1 = myQueue->top(); //taking off the fist top value from the priority queue and saving it in "child1"
		myQueue->pop();			 //popping off the fist value from the queue  
		child2 = myQueue->top(); //taking off the fist top value from the priority queue and saving it in "child2
		myQueue->pop();		     //popping off the fist value from the queue  

		parent = objectBinaryTree->Merge(child1, child2); //calling merge function from "BinaryThree" and passing child1 and child2 then saving it as parrent
		myQueue->push(parent);	//pushing parent on the priority queue

	}

	HuffmanRoot = myQueue->top(); //taking off the first (reming) value from the priority queue and saving it in "HufmanRoot"
	objectBinaryTree->SetRootNode(HuffmanRoot); //Setting the Root



}

void HuffmanCode::HuffmanCodeCreator()
{
	HuffmanCodeCreator(HuffmanRoot, code);
}

void HuffmanCode::HuffmanCodeCreator(BinaryTreeNode* HuffmanRoot, string code)
{


		if (HuffmanRoot->get_left() != NULL)
		{
			HuffmanCodeCreator(HuffmanRoot->get_left(), code + "0" );
		}
		if (HuffmanRoot->get_right() != NULL)
		{
			HuffmanCodeCreator(HuffmanRoot->get_right(), code + "1");
		}
		if(HuffmanRoot->get_key() != NULL)
		cout << HuffmanRoot->get_key() << " | <-Symbol    Huffman Code-> | " << code <<endl;

}