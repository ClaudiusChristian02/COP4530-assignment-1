#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <iterator>
#include "dictionary.h"
#include "inputFileClass.h"
using namespace std;

// write vector to file





int main(int argc, char **argv){

	string word,                         // stores the word read in
		   substituteWord,               // stores the new correctly spelled wor
		   homeDirectory,                // stores the name of the home directory
		   whiteSpace,                   // stores the white space
		   response;                     // stores the users response

	dictionary systemDictionary,         // declares dictionary class to be used in main
		       ignoreWords,              // declares the ignore words class for words that are to be ignored
		       userDictionary;           // declares the user dictionary class

	map <string, string> swapWords;      // declares the map word object with two strings to replace the first string with the second string

	vector<string> outputString;         // collects all preserved whitespace and words for later output

	//<string> ignoreWords;              // words to ignore

	

	// checks to determine if user gives less than two
	if (argc < 2)
	{
		cout << " not enough arguements" << endl;

		return 1;
	} // end of if (argc < 2)

	// read in input stream and argv gives the 
	// the name of the file
	// ifstream input(argv[1]);

	// inPutFile is now the input stream
	inputFileClass input;

	// checks to see if the file opened and returns error message if file didn't open correctly
	if (input.openFile(argv[1]) == false){

		cout << "File did not open" << endl;

		return 1;
	} // end of if (!input)

	// read in the file name for the system dictionary
	systemDictionary.readDictionaryFile("/usr/share/dict/words");

	// initializes home directory by reading the home environment
	homeDirectory = getenv("HOME");

	// reads user dictionary in the home directory
	userDictionary.readDictionaryFile(homeDirectory + "/_Dictionary");

	// reads words in a loop till the end of file
	while (input.readNextWord(word, whiteSpace)){

		// compares the word with the system dictionary and the user dictionary if the word is not there
		// return and error message
		if ( (!systemDictionary.compareWord(word)) && (!userDictionary.compareWord(word)) && 
		   (!ignoreWords.compareWord(word) )){

			// looks for the misspelled word in swap words if it is there
			// replace it with the correct spelling
			map<string, string>::iterator i = swapWords.find(word);

			/*
			looks for the misspelled word in ignore words if it is there ignore the word
			set< string >::iterator j = ignoreWords.find( word );
			
			if ( j != ignoreWords.end() ){

				// do nothing

			} // end of if (j != ignoreWords.end())
			*/
			
			// if it is not equal to end the word has been found and it is ok to replace
			if (i != swapWords.end()){

				// dereferences iterator
				word = i ->second;

			} // end of if (i != swapWords.end())


			// look for replacement is above if there is none ask the user for a replacement or another
			// response
			else{


				cout << "Wrong Spelling: " << word << endl;

				cin >> response;

				if (response == "s"){

					cin >> substituteWord;

					//cout << substituteWord;

					word = substituteWord;

				} // end of if (response == "s")

				else if (response == "S"){

					cin >> substituteWord;

					//cout << substituteWord;

					// assigns substitute word to misspelled word
					swapWords[word] = substituteWord;

					word = substituteWord;

				} // end else if

				else if (response == "i"){

					// do nothing
				}

				// if user types "I" insert the word into ignore words set and ignore the word
				else if (response == "I"){

					ignoreWords.addWord(word);

				} // end of else if (response == "I"){

				// Add wrong-word to _Dictionary in the user's home directory
				else if (response == "a"){

					userDictionary.addWord(word);

				} // end of else if (response "a")
			} // end else

			
		} // end of if ( !systemDictionary.compareWord( word ) )

		outputString.push_back(whiteSpace);
		
		outputString.push_back(word);

	} // end of while (input >> word)

	// add trailing whitespace
	outputString.push_back(whiteSpace);

	ofstream outputFile(argv[1]);

	copy(outputString.begin(), outputString.end(), ostream_iterator<string>(outputFile));
	/*
	/ reads throught the vector and prints it out
	for (int n = 0; n < outputString.size(); n++){

		outfile.write(outputString[n] << endl;
		
	} // end of for (int n = 0; n < outputString.size(); n++)
	*/
	
	userDictionary.saveDictionaryFile(homeDirectory + "/_Dictionary");

	// end of the program and singals everything worked ok
	return 0;


} // end of file