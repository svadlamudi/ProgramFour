// Importing Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Word.h"
#include "BinaryTreeWord.h"

using namespace std;

// Prototypes
string cleanString(string original);

/*
 * Sai Kiran Vadlamudi  C05
 * Main Method
 */
int main(const int argc, const char *argv[])												
{	
	FILE *output;			
	int lineNum = 1, countWord = 0;
	stringstream current_line_stream, current_word_temp;
	string current_line;
	string current_word, current_word_lower, current_word_string;
	Word *root = NULL;
	BinaryTreeWord treeRoot;
	
	if (argc == 2)																	/*** Begin If check for correct number arguments ***/
	{		
		ifstream input(argv[1], ios::in);														// Open input file
		if (input.is_open())																/** Begin If check for successfully opening **/
		{
			while (getline(input, current_line, '\n'))													/* Begin While - Read in current line */
			{
				current_line_stream.str(current_line);														// Convert line from string to stringstream
				
				while (current_line_stream >> current_word)													// Begin While - Read current word (delimiter ' ') //
				{
					while (current_word.find('"') != string::npos)													// Search for '"' in word and split word if found
					{
						current_word_string = current_word.substr(0, current_word.find('"'));
						current_word_lower = cleanString(current_word_string);
						
						if (current_word_lower.empty()) {
							break;
						}
						
						treeRoot.insertWord(&root, current_word_string, current_word_lower, lineNum, countWord);
						current_word = current_word.substr(current_word.find('"'), string::npos);
					}					
					while (current_word.find('-') != string::npos)													// Separate hyphenated words
					{
						current_word_string = current_word.substr(0, current_word.find('-'));
						current_word_lower = cleanString(current_word_string);

						if (current_word_lower.empty()) {
							break;
						}

						treeRoot.insertWord(&root, current_word_string, current_word_lower, lineNum, countWord);
						current_word = current_word.substr(current_word.find('-'), string::npos);
					}

					current_word_lower = cleanString(current_word);													// Remove punctuation and convert to lowercase
					if (current_word_lower.empty() != true && current_word_lower != "eof") {				
						treeRoot.insertWord(&root, current_word, current_word_lower, lineNum, countWord);								// Insert word into tree		
					}																								
				}																		// Walk to next word - End While //

				current_line_stream.str("");															// Set current stream to empty
				current_line_stream.clear();															// Reset the EOF, and other counters of the stringstream

				lineNum++;																	// Increment line counter
			}																		/* Walk to next line  - End While */
			
			input.close();																	// Close input file
			
			output = fopen("words.txt", "w");														// Open output file
			treeRoot.printHeading(output);															// Print column labels
			treeRoot.printTree(output, root);														// Print tree
			treeRoot.printWordCount(output, countWord);													// Print # of unique words
		
			return 0;
		}																		/** End If **/
		else																		/** Begin Else **/
		{
			printf("Error Opening File");															// Unsuccessful opening of input file
			return 1;
		}																		/** End Else **/
	}																		/*** End If ***/
	else																		/*** Begin Else **/
	{
		printf("Correct Usage is: ./prog4 input_file\n\n");												// Incorrect # of command line arguments
		return 1;
	}                                                                                       							/*** End Else ***/
}						

/*
 * Sai Kiran Vadlamudi  C05
 * Remove punctuation and newline characters from the given string ('.', ',', '\n')
 */
string cleanString(string original)                                                         								/** Begin Function **/
{
	int i = 0;																		// Iterating Variable
	while (original[i] != '\0')																/* Iterate till the end character is reached */
	{
		if (original[i] == '\\' || original[i] == '/')														// Remove all '\' and '/' character from given string
		{
			original.erase(i, 1);                           
		}
		else if (original[i] == '.' || original[i] == ',')													// Remove all '.'  and ',' character from given string
		{
			original.erase(i, 1);																	
		}
		else if (original[i] == ';' || original[i] == ':')													// Remove all ',' and ':' character from given string
		{
			original.erase(i, 1);																	
		}
		else if (original[i] == '(' || original[i] == ')')													// Remove all '('  and ')' character from given string
		{
			original.erase(i, 1);																	
		}
		else if (original[i] == '"' || original[i] == '-')													// Remove all '"' and '-' character from given string
		{
			original.erase(i, 1);
		}
		else																			// Convert given string to lower case
		{
			original[i] = tolower(original[i]);
			++i;																		// Walk to next character
		}
	}																			/* End While Loop */

	return original;
}                                                                                            								/** End Function **/
