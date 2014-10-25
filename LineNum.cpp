#include "LineNum.h"

/* 
 * Sai Kiran Vadlamudi  C05
 * Constructors 
 */
LineNum::LineNum() {
	this->lineNum = 0;
	this->next = NULL;
}

LineNum::LineNum(int lineNum) {
	this->lineNum = lineNum;
	this->next = NULL;
}
LineNum::LineNum(int lineNum, LineNum *next) {
	this->lineNum = lineNum;
	this->next = next;
}

/* 
 * Sai Kiran Vadlamudi  C05 
 * Accessors and Mutators
 */
int LineNum::getLineNum() {
	return this->lineNum;
}

LineNum** LineNum::getNext() {
	return &(this->next);
}

void LineNum::setLineNum(int lineNum) {
	this->lineNum = lineNum;
}

void LineNum::setNext(LineNum *next) {
	this->next = next;
}
