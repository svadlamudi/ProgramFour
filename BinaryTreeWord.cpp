#include "BinaryTreeWord.h"

// Create List object to manipulate list of line numbers
ListLineNum listLine;

/*
 * Sai Kiran Vadlamudi  C05
 * Create/Insert new word into tree of words
 */
void BinaryTreeWord::insertWord(Word **root, string word, string wordLower, int lineNum, int &countWord)								    /*** Begin Function ***/
{
	if (*root == NULL)																			/** Begin If check for empty tree **/
	{
		*root = new Word(word, wordLower, lineNum);																// Create new word
		countWord++;																				// Increment # of unique words
	}																					/** End If **/
	else																					/** Begin Else **/
	{
		if (wordLower < (*root)->getWordLower())																/* Begin If given word is smaller than root */
		{
			insertWord((*root)->getLeft(), word, wordLower, lineNum, countWord);													// Walk to next node on the left
		}																					/* End If */
		else if (wordLower >(*root)->getWordLower())																/* Begin Else If given word is bigger than root  */
		{
			insertWord((*root)->getRight(), word, wordLower, lineNum, countWord);													// Walk to next node on the right
		}																					/* End Else  */
		else																					/* Begin Else (Word already exists) */
		{
			(*root)->setCount(1 + (*root)->getCount());																// Increment word count
			listLine.addLineNum((*root)->getListOfLine(), lineNum);															// Add line number of the new occurrence
		}																					/* End Else */
	}																					/** End Else **/
}																					   /*** End Function ***/

/*
 * Sai Kiran Vadlamudi  C05
 * Print column labels
 */
void BinaryTreeWord::printHeading(FILE *output)      														          /* Begin Function */
{
	fprintf(output, "Name: Sai Kiran Vadlamudi    Section: C05\n\n");													// Print Author names
	fprintf(output, "+--------------------+--------------------+--------------------------------------------------+\n");
	fprintf(output, "|        Word        |        Count       |                      Lines                       |\n");							// Print the column titles to the given output file
	fprintf(output, "+--------------------+--------------------+--------------------------------------------------+\n");
}																					  /* End Function */

/*
 * Sai Kiran Vadlamudi  C05
 * Print the tree of words
 */
void BinaryTreeWord::printTree(FILE *output, Word *root)                                                                                				  /** Begin Function **/
{
	if (root != NULL)																			/* Begin If tree is not empty */
	{
		printTree(output, *(root->getLeft()));																	// Walk to smallest word (print alphabetical order)
		fprintf(output, "|%-20s|%-20d|", (char *)root->getWordLower().c_str(), root->getCount());										// Print the word and its info
		listLine.printListLine(output, *(root->getListOfLine()));                                                                                       			// Print list of lines the word is found on
		fprintf(output, "\n+--------------------+--------------------+--------------------------------------------------+\n");							// Print separator
		printTree(output, *(root->getRight()));																	// Walk to biggest word (print last)
	}																					/* End If */
}                                                                                                                                                			  /** End Function **/

/*
 * Sai Kiran Vadlamudi  C05
 * Print the number of unique words in the text
 */
void BinaryTreeWord::printWordCount(FILE *output, int countWord)                                                                                			  /* Begin Function */
{
	fprintf(output, "|Total Unique Words  |%-4d                |                                                  |\n", countWord);						// Print # of unique words
	fprintf(output, "+--------------------+--------------------+--------------------------------------------------+\n");							// Print separator
}                                                                                                                                                			  /* End Function */
