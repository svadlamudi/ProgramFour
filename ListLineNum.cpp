#include "ListLineNum.h"

using namespace std;

/*
* Sai Kiran Vadlamudi  C05
* Returns true if given line number exists in the given list
*/
bool ListLineNum::checkLineExists(LineNum *head, int lineNum)							/** Begin Function **/
{
	LineNum *temp = head;												// Create pointer to head of list
	bool check = false;												// Declare/Initialize variable to store result
	while (temp != NULL)												/* While list is not empty */
	{
		if (temp->getLineNum() == lineNum)										// Check if current number is equal to given line
			check = true;

		temp = *(temp->getNext());											// Walk to next node
	}														/* End While */
	return check;
}														/** End Function **/

/*
* Sai Kiran Vadlamudi  C05
* Adds given line to the list if it doesn't exist already
*/
void ListLineNum::addLineNum(LineNum **head, int lineNum)							/**** Begin Function ****/
{
	if (checkLineExists(*head, lineNum) == false)									/*** Begin If line doesnt exist in the list ***/
	{
		LineNum **temp = head;												// Create pointer to head of the list
		while (*temp != NULL)												/** Begin While list is not empty **/
		{
			if ((*temp)->getLineNum() > lineNum)										/* Begin If current node is greater than the given number */
			{
				break;														// Insert given number before the current number
			}														/* End If */
			temp = (*temp)->getNext();											// Walk to next node
		}														/** End While **/
		LineNum *new_line = new LineNum(lineNum, *temp);				
		*temp = new_line;												// Set current node to new node
	}														/*** End If ***/
}														/**** End Function ****/

/*
* Sai Kiran Vadlamudi  C05
* Returns a string of given list of line numbers
*/
void ListLineNum::printListLine(FILE *output, LineNum *head)							/*** Begin Function ***/
{
	int i = 0, j = 1;												// Declare/Initialize counter variables
	LineNum *temp = head;												// Create pointer to the head of the list
	string temp_s;
	stringstream temp_ss;
	while (temp != NULL)												/** Begin While list is not empty **/
	{
		if (i == 0)													/* Begin If first time through */
		{
			fprintf(output, "%4d", temp->getLineNum());									// Print first number in the list
		}														/* End If */
		else if (i % 10 == 0)												/* Begin Else If */
		{
			fprintf(output, " |\n");											// End previous line and go to next
			fprintf(output, "|%-20s", " ");											// Print empty word column
			fprintf(output, "|%-20s|", " ");										// Print empty count column
			fprintf(output, "%4d", temp->getLineNum());									// Begin printing 10 numbers before going to next line
			j = 1;
		}														/* End Else If*/
		else														/* Begin Else */
		{
			fprintf(output, ",%4d", temp->getLineNum());									// Print line number
			j++;														// Increment count of word printed on current line
		}														/* End Else */
		++i;														// Increment iterator
		temp = *(temp->getNext());											// Walk to next node
	}														/** End While **/

	if (j != 10) {
		fprintf(output, "%*s", (10 - (j % 10)) * 5 + 2, " |");
	}														// Print ending '|'				
	else {
		fprintf(output, " |");
	}

}														/*** End Function ***/
