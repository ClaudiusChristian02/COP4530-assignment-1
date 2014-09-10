#include "inputFileClass.h"
#include <list>




bool inputFileClass::openFile(string filename){

	// open file
	inputFile.open(filename.c_str());

	return !inputFile.fail();

} // end of void inputFileClass::openFile(string)

// reads the next word in the file
bool inputFileClass::readNextWord(string& nextWord, string& whiteSpace){

	char character;
	// string whiteSpace;

	// collects all the whitespace which is encountered
	whiteSpace = "";  


	// read in the file to get the next inputFileClass character until eof or non-inputFileClass character
	while(inputFile.get(character)){
		
		// checks to determine if the next character is inputFileClass
		if (isspace(character)){

			// adds character to inputFileClass buffer
			whiteSpace += character;
		}

		else{

			// returns the last character, but by using unget the stream remembers the last character
			inputFile.unget();
			break;
		}
	} // end of while( inputFile.get( character) )


	inputFile >> nextWord;

	// cannot use return inputFile >> next word because of a conversion problem but this is the equivalent
	return !inputFile.fail();

} // bool inputFileClass::readNextWord(string& nextWord )

