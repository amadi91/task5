#include "stdafx.h"
#include "SymbolFreq.h"
using namespace std;

SymbolFreq::SymbolFreq()						//Creating data members of the class dynamically
{
	textfile = new string;
	myMap = new map <char, int>;
	myVector = new vector<pair<char, int>>;
}
SymbolFreq::~SymbolFreq()						// Deleting members to prevent memory leaks
{
	delete textfile;
	delete myMap;
	delete myVector;
}

bool comparator(const pair<char, int>& first, const pair<char, int>& second)		//comparator function
{
	return first.second > second.second;
}

string SymbolFreq::readFromFile() //Function readFromFile() is responsible for reading data from external file and storing it in dynamically allocated tring.
{
	ifstream myfile("ToCompress.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, *textfile)) {} 
	}
	
	return *textfile;
}

void SymbolFreq::vecmapCreator()	//Function mapCreator() is responsible for creating an instance of the map, populating it and sorting it according to spec.
{
	//cout << "The lenght of the text is:" << textfile->length()<< endl;

	for (int i = 0; i < textfile->length(); i++)
	{																	   
		map<char, int>::iterator it0 = (*myMap).find(textfile->at(i)); //!Looking through the map and setting itterator to find() key funtion
			if (it0 != (*myMap).end())							//if key already exists before map ends increment second val
			{
				it0->second = it0->second + 1;					//if the key is not found before map ends put the key in to the map and obiously set char to 1
			}
			else											
			{
				(*myMap)[textfile->at(i)] = 1;					//if the key doesn't exist populate the map with it and set value to 1.
			}	
	}
	
	for (map<char, int>::iterator it = myMap->begin(); it != myMap->end(); ++it)	//iterating through the map and populating vector
	{
		pair<char, int> val(it->first, it->second);			//what ever is on the 'first and 'second position gets pushed on the vector
		myVector->push_back(val);
	}
															
	sort(myVector->begin(), myVector->end(), comparator);	//calling sort function 

}
void SymbolFreq::output()
{
	for (vector<pair<char, int>>::iterator it = myVector->begin(); it != myVector->end(); ++it) //printing the content using iterator
		cout << "Symbol: " << it->first << "  Frequency:" << it->second << endl;
}

map <char, int>* SymbolFreq::get_myMap(void)
{
	return myMap;
}
//(*textfile) Puting *textile in to the brackets dereferences it to normal string//
// another way is (textfile->at(i)) just using -> + at !!!USED FOR ITTERATION!!!//
//myMap->end(); [for dynamic], myMap.end(); [for static]