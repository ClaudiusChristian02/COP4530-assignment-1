#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <set>
#include <iterator>
using namespace std;




// class will be used to read in dictionary file and then compare the words with each other
class dictionary{

public:

	bool readDictionaryFile(const string &filename);    // use bool so that true false is returned if the word is found
	bool compareWord(const string &word);               // use bool so that true false is returned if the word is spelled correctly
	void addWord(string);                               // add a new word to the user dictionary
	void saveDictionaryFile(const string& filename);

private:
	
	set <string> dictionaryWords;                       // set that contains strings which are all the words from the 
	                                                    // dictionary file

}; // end of class dictionary

#endif