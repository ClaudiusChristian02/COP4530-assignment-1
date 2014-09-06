#include <fstream>
#include <iostream>
#include <string>
#include "dictionary.h"
using namespace std;

int main(int argc, char **argv){

	string word;
	dictionary systemDictionary; // class dictionary

	if (argc < 2)
	{
		cout << " not enough arguements" << endl;

		return 1;
	}

	// read in input stream and argv gives the 
	// the name of the file
	ifstream input(argv[1]);

	// return error message if file didn't open correctly
	if (!input){

		cout << "File did not open" << endl;

		return 1;
	}

	// read in the file name for the system dictionary
	systemDictionary.readDictionaryFile( "/usr/share/dict/words");

	// reads words in a loop till the end of file
	while (input >> word){

		// compares the word with the system dictionary if the word is not there
		// return and error message
		if ( !systemDictionary.compareWord( word )){

			cout << "Wrong spelling:" << word;

		}

	} // end of while (input >> word)


	// end of the program and singals every
	// thing worked ok
	return 0;


} // end of file