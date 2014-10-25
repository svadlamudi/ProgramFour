#ifndef _LISTLINENUM_H
#define _LISTLINENUM_H

// Import Libraries and Headers
#include "LineNum.h"
#include <string>
#include <sstream>
#include <cstdio>

class ListLineNum
{
	public:
		// Functions to maipulate Linked List of Line numbers
		bool checkLineExists(LineNum *head, int lineNum);
		void addLineNum(LineNum **head, int lineNum);
		void printListLine(FILE *output, LineNum *head);

	private:
};

#endif
