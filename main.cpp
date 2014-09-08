#include <fstream>
#include <iostream>
#include <string>
#include "dictionary.h"
#include <map>
using namespace std;





int main( int argc, char **argv ){

	string word,
		   substituteWord,
		   response;
	dictionary systemDictionary;         // declares dictionary class to be used in main
	map < string, string > swapWords;
	set<string> ignoreWords;             // words to ignore

	// checks to determine if user gives less than two
	if ( argc < 2 )
	{
		cout << " not enough arguements" << endl;

		return 1;
	} // end of if ( argc < 2 )

	// read in input stream and argv gives the 
	// the name of the file
	ifstream input(argv[1]);

	// return error message if file didn't open correctly
	if ( !input ){

		cout << "File did not open" << endl;

		return 1;
	} // end of if ( !input )

	// read in the file name for the system dictionary
	systemDictionary.readDictionaryFile( "/usr/share/dict/words");

	// reads words in a loop till the end of file
	while ( input >> word ){

		// compares the word with the system dictionary if the word is not there
		// return and error message
		if ( !systemDictionary.compareWord( word ) ){

			// looks for the misspelled word in swap words if it is there
			// replace it with the correct spelling
			map< string, string >::iterator i = swapWords.find( word );

			// looks for the misspelled word in ignore words if it is there
			// ignore the word
			set< string >::iterator j = ignoreWords.find( word );


			if ( j != ignoreWords.end() ){

				// do nothing

			} // end of if (j != ignoreWords.end())


			// if it is not equal to end the word has been found and it is ok to replace
			else if ( i != swapWords.end() ){

				// dereferences iterator
				word = i ->second;

			}

			// look for replacement is above if there is none ask the user for a replacement or another
			// response
			else{


				cout << "Wrong spelling: " << word;

				cin >> response;

				if (response == "s"){

					cin >> substituteWord;

					cout << substituteWord;
				}

				else if (response == "S"){

					cin >> substituteWord;

					cout << substituteWord;

					// assigns substitute word to misspelled word
					swapWords[word] = substituteWord;

				} // end else if

				else if (response == "i"){

					// do nothing
				}

				// if user types "I" insert the word into ignore words set and ignore the word
				else if (response == "I"){
					

					ignoreWords.insert( word );


				} // end of else if (response == "I"){
			} // end else

			
		} // end of if ( !systemDictionary.compareWord( word ) )

	} // end of while (input >> word)


	// end of the program and singals every
	// thing worked ok
	return 0;


} // end of file