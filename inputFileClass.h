#ifndef INPUTFILECLASS_H
#define INPUTFILECLASS_H

#include <string>
#include <fstream>
using namespace std;




// class will be used to read in dictionary file and then compare the words with each other
class inputFileClass{

public:

	bool openFile(string);  
	bool readNextWord(string&, string&);    // indicates if there is another word to read

private:

	ifstream inputFile;

}; // end of class dictionary

#endif