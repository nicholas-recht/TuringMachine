#include <string>
#include <map>
#include "State.h"
class TuringMachine
{
public:

	TuringMachine(const std::string & filePath, const std::string & input, std::string & startState) 
		: mHead(startState), mPos(0), mOutput(input) { buildMachine(filePath); }

	//Advance the machine one step, returns false if the machine is halted
	bool advance();

	//Display the current state of the Turing Machine
	std::string getCurrentOutput();

private:

	void buildMachine(const std::string & filePath);

	std::map<std::string, State> mStates; 
	std::string mHead;
	int mPos; 
	std::string mOutput; 
};