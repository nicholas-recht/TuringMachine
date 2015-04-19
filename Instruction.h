#include <string>

class Instruction
{
public:
	Instruction(const std::string & codedString) throw(const char*);

	//Getters
	std::string getInState() { return inState; }
	std::string getOutState() { return outState; }
	bool getDirectionRight() { return goRight; }
	char getOutput() { return output; }
	char getInput() { return input; }

private:
	std::string inState; 
	char input;
	char output;
	bool goRight;
	std::string outState; 
};