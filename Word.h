#ifndef _WORD_H
#define _WORD_H

// Import Libraries and Header Files
#include <string>
#include "LineNum.h"
#include "ListLineNum.h"

using namespace std;

class Word
{
	public:
		// Constructors
		Word();
		Word(string word, string wordLower, int lineNum);
		
		// Accessors and Mutators
		string getWord();
		string getWordLower();
		int getCount();
		LineNum** getListOfLine();
		Word** getLeft();
		Word** getRight();
		void setWord(string word);
		void setWordLower(string wordLower);
		void setCount(int count);
		void setListOfLine(LineNum *listOfLine);
		void setLeft(Word* left);
		void setRight(Word* right);
		
		// Object Functions
		void insert(Word **root, string word, string wordLower, int lineNum, int &countWord);

	private:
		// Object Fields
		string word;
		string wordLower;
		int count;
		LineNum *listOfLine;
		Word *left;
		Word *right;
};

#endif
