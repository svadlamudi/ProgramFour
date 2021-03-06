#ifndef _BINARYTREEWORD_H
#define _BINARYTREEWORD_H

#include "Word.h"
#include "ListLineNum.h"
#include <cstdio>

class BinaryTreeWord 
{	
	public:
		// Functions to manipulate Binary Tree of Words
		void insertWord(Word **root, string word, string wordLower, int lineNum, int &countWord);
		void printHeading(FILE *output);
		void printTree(FILE *output, Word *root);
		void printWordCount(FILE *output, int countWord);

	private:

};

#endif
