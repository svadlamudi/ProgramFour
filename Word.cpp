// Import Header File with Declarations
#include "Word.h"

using namespace std;

// Create a ListLineNum object to access the object functions
ListLineNum listLineWord;

/* 
 * Sai Kiran Vadlamudi  C05							
 * Constructors 
 */

Word::Word() {									/* Default Constructor */
	this->word = "";
	this->wordLower = "";
	this->count = 0;
	this->listOfLine = NULL;
	this->left = NULL;
	this->right = NULL;
}										

Word::Word(string word, string wordLower, int lineNum) {			/* Constructor with Params */
	this->word = word;
	this->wordLower = wordLower;
	this->count = 1;
	this->listOfLine = new LineNum(lineNum);
	this->left = NULL;
	this->right = NULL;
}										

/* 
 * Sai Kiran Vadlamudi  C05							
 * Accessors and Mutators 
 */

string Word::getWord() {							/* Getter for Word::word */		
	return this->word;
}

string Word::getWordLower() {							/* Getter for Word::wordLower */
	return this->wordLower;
}

int Word::getCount() {								/* Getter for Word::count */
	return this->count;
}	

LineNum** Word::getListOfLine() {						/* Getter for Word::listOfLine */ 
	return &(this->listOfLine);
}

Word** Word::getLeft() {							/* Getter for Word::left */
	return &(this->left);
}

Word** Word::getRight() {							/* Getter for Word::right */
	return &(this->right);
}

void Word::setWord(string word){						/* Setter for Word::word */
	this->word = word;
}

void Word::setWordLower(string wordLower) {					/* Setter for Word::wordLower */
	this->wordLower = wordLower;
}

void Word::setCount(int count) {						/* Setter for Word::count */
	this->count = count;
}

void Word::setListOfLine(LineNum *listOfLine) {					/* Setter for listOfLines */
	this->listOfLine = listOfLine;
}

void Word::setLeft(Word* left) {						/* Setter for left */
	this->left = left;
}

void Word::setRight(Word* right) {						/* Setter for right */
	this->right = right;
}

