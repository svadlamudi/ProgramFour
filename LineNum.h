#ifndef _LINENUM_H
#define _LINENUM_H

// Include Libraries
#include <iostream>

class LineNum
{
	public:
		// Constructors
		LineNum();
		LineNum(int lineNum);
		LineNum(int lineNum, LineNum *next);
		
		// Accessors and Mutators
		int getLineNum();
		LineNum** getNext();
		void setLineNum(int lineNum);
		void setNext(LineNum *next);

	private:
		// Object Fields
		int lineNum;
		LineNum *next;
};

#endif
