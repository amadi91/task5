// TASK5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HuffmanCode.h"


int main()
{
	HuffmanCode* objectHuffmanCode = new HuffmanCode;

	objectHuffmanCode->HuffmanTreeBuilder();
	objectHuffmanCode->HuffmanCodeCreator();

	return 0;
}

//I need to pop 2 of them of then merge it to new parent node and then do that until I have 1 node left in my priority queue