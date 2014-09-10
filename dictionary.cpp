#include <fstream>
#include <iostream>
#include <string>
#include "dictionary.h"
using namespace std;





bool dictionary::readDictionaryFile(const string &filename){

	string word; // declares word to be used in the while ( input >> word ) loop

	// read in input stream and argv gives the 
	// the name of the file
	ifstream input(filename.c_str());

	// return error message if file didn't open correctly
	if (!input){

		//cout << "File did not open" << endl;

		return false;

	} // end of if (!input)

	
	// reads words in a loop till the end of file
	while (input >> word){

		// insert words into a set
		dictionaryWords.insert(word);

	} // end of while (input >> word)

	return true;

} // end of bool readDictionaryFile(const string &filename)



bool dictionary::compareWord(const string &word){

	string temporaryWord = word;

	// turns the first letter and makes it lowercase and then
	// assigns it back to the word
	temporaryWord[0] = tolower(temporaryWord[0]);

	// looks inside the set to see if the word exists
	// return value is an iterator
	set<string>::iterator i = dictionaryWords.find(temporaryWord);



	// determines if the iterator is valid or not
	if (i == dictionaryWords.end()){


		//cout << endl << endl << "inside ifstatement:  " << temporaryWord << endl << endl;

		// if the word is not found return false
		return false;
	}

	else{

		// return true if the iterator is valid
		return true;

	} // end of else
} // end of bool dictionary::compareWord(const string &word)

void dictionary::addWord(string word){

	dictionaryWords.insert(word);
}

void dictionary::saveDictionaryFile(const string& filename){

	ofstream _Dictionary(filename.c_str());

	copy(dictionaryWords.begin(), dictionaryWords.end(), ostream_iterator<string>(_Dictionary, "\n"));
	
}

