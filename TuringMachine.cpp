#include "TuringMachine.h"
#include "Instruction.h"
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>

void TuringMachine::buildMachine(const std::string & filePath)
{
	std::ifstream fin;
	fin.open(filePath);
	std::string line; 
	std::set<std::string> inStates;
	std::vector<Instruction> instructions;

	//Turn each line into an instruction
	while (std::getline(fin, line))
		instructions.push_back(Instruction(line)); 

	//build the states
	for (int i = 0; i < instructions.size(); ++i)
		mStates[instructions[i].getInState()].add(
			instructions[i].getInput(),
			instructions[i].getOutput(),
			instructions[i].getDirectionRight(),
			instructions[i].getOutState()); 

}

bool TuringMachine::advance() 
{
	char input = mOutput[mPos]; 

	//change the char at the head location
	if (mStates[mHead].getOutput(input) != '!')
		mOutput[mPos] = mStates[mHead].getOutput(input);
	else
		return false; 

	//move the head
	if (mStates[mHead].getDirection(input))
		mPos += 1;
	else
		mPos -= 1; 

	//set the next state
	mHead = mStates[mHead].getNextState(input); 

	//check to see if we've gone off the end
	if (mPos < 0)
	{
		mOutput = " " + mOutput;
		mPos = 0;
	}
	else if (mPos >= mOutput.size())
	{
		mOutput = mOutput + " ";
		mPos = mOutput.size() - 1;
	}

	if (mHead == "HALT")
		return false;
	else
		return true; 
}

std::string TuringMachine::getCurrentOutput()
{
	std::string line2 = "\n";
	for (int i = 0; i < mOutput.size(); ++i)
	{
		if (i == mPos)
			line2 += "-";
		else
			line2 += " ";
	}

	return mOutput + line2; 
}