#include <fstream>
#include <iostream>
#include <string>
#include "dictionary.h"
using namespace std;



bool dictionary::readDictionaryFile(const string &filename){

	// read in input stream and argv gives the 
	// the name of the file
	ifstream input( filename.c_str() );

	// return error message if file didn't open correctly
	if (!input){

		cout << "File did not open" << endl;

		return false;

	} // end of if (!input)

	string word;
	// reads words in a loop till the end of file
	while (input >> word){

		// insert words into a set
		dictionaryWords.insert(word);

	} // end of while (input >> word)

	return true;

} // end of bool readDictionaryFile(const string &filename)

bool dictionary::compareWord(const string &word){

	// looks inside the set to see if the word exists
	// return value is an iterator
	set<string>::iterator i = dictionaryWords.find(word);

	// determines if the iterator is valid or not
	if (i == dictionaryWords.end()){

		// if the word is not found return false
		return false;
	}

	else{

		// return true if the iterator is valid
		return true;
	}


} // end of bool dictionary::compareWord(const string &word)

