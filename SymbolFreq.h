#ifndef SymbolFreq_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class SymbolFreq
{
public:
	SymbolFreq();
	~SymbolFreq();
	string readFromFile();
	void vecmapCreator();
	void output();
	map <char, int>* get_myMap(void);

private:
	map <char, int>* myMap;
	string* textfile;
	vector<pair<char, int>>* myVector;
};

#endif // SymbolFreq_H