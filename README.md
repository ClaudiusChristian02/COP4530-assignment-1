COP4530-assignment-1
====================

Educational objectives: Review C++ material that you have learned, such as implementing classes, using templates, I/O, etc. Use of STL classes (which you will learn in Lecture 4) and algorithms. Use of makefiles. Use of a debugger. Use of optimization flags with g++.

Statement of work: Develop a software that uses STL classes and algorithms, such as (linked) list, to implement a simple spell checking program, as described below. You must use at least one templated STL container and use its iterator.

Deliverables: Turn in a makefile and all header (*.h) and cpp (*.cpp) files that are needed to build your software. Turn in your development log too, which should be a plain ASCII text file called LOG.txt in your project directory. You will submit all of these as described in www.cs.fsu.edu/~asriniva/courses/DS14/HWinstructions.html.

Requirements:

    Create a subdirectory called proj1.
    You will need to have a makefile in this directory. In addition, all the header and cpp files needed to build your software must be present here, as well as the LOG.txt file.
    You should implement appropriate classes for the software. Your code should be well designed and object oriented.
    Your software will check the spellings of words in an input document, and enable a user to correct errors.
    The software is run by the user on the command line, as follows:
        Spell Filename, where Filename is the name of the file whose spelling should be checked. Note that the first letter of Spell is capitalized.
    The software checks the spelling of each word in the file, starting from the first word and ending at the last word. (A suitable error message should be given if the file does not exist.) A word is defined as a sequences of adjacent characters in the input file, separated by whitespace (blanks, tabs, and newlines). A word is considered valid if it occurs in either (i) /usr/share/dict/words (assuming you are running on the machine linprog) or (ii) _Dictionary in the user's home directory, if the latter exists. Note that a word should be considered correct if is identical to one in the above dictionaries, except that its first letter may be capitalized. However, capitalization differences at other locations should not be accepted. For example, the word Abandon should be considered correct if the dictionary contains abandon. However, abAndon should not be considered correct, unless one of the above dictionary contains the exact word abAndon. Each time an incorrect word is encountered, the software presents the word to the user in the following format:
    Wrong spelling: wrong-word
    where wrong-word is the wrongly spelled word, and waits for a user response. The user may respond as given below, and the software should take the actions as specified below.

    Once all words have been processed, the software saves the corrected file, over-writing the original file. (Note that the corrected version is written back to disk only at this point.) The software should preserve all whitespaces of the original file.

    Possible user responses:
        s corrected-word Swap wrong-word with corrected-word (even if the latter is wrong).
        S corrected-word Swap the current and all future occurrences of wrong-word with corrected-word (even if the latter is wrong).
        i Ignore wrong-word (that is, treat it as correct) for the current occurrence alone.
        I Ignore wrong-word (that is, treat it as correct) for the current occurrence and all future ones.
        a Add wrong-word to _Dictionary in the user's home directory, creating this file if it is not already present. Also, treat wrong-word as correct.

Sample file and executable: A sample executable and input files are available at ~cop4530/fall14/solutions/proj1 on linprog. The first person to find errors in our program will get a bonus point!
