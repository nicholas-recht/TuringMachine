#include "Instruction.h"
#include <iostream>
Instruction::Instruction(const std::string & codedString) throw(const char*)
{
	//need to skip first {
	int iBegin = 1;
	int iEnd = 1;

	//first get the instate
	while (codedString[iEnd] != ',')
		++iEnd;
	inState = codedString.substr(iBegin, iEnd - iBegin);
	iEnd += 1;
	iBegin = iEnd;

	//set the input
	input = codedString[iEnd]; 
	iEnd += 2;
	iBegin = iEnd; 

	//set the next state
	while (codedString[iEnd] != ',')
		++iEnd;
	outState = codedString.substr(iBegin, iEnd - iBegin);
	iEnd += 1;
	iBegin = iEnd;

	//set the direction
	if (codedString[iBegin] == 'R')
		goRight = true;
	else
		goRight = false;

	iEnd += 2;
	iBegin = iEnd;

	//set the outut
	output = codedString[iEnd]; 

}