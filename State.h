#include <map>
#include <string>

class State
{ 
public:
	//constructor
	State() : outputs(), directions(), nextState() { }

	//add new output
	void add(char input, char output, bool isRight, std::string nextState) {
		outputs[input] = output;
		directions[input] = isRight;
		this->nextState[input] = nextState;
	}

	//get next state
	std::string getNextState(char input)
	{
		if (nextState.find(input) != nextState.end())
			return nextState[input];
		else
			return "HALT";
	}

	//get direction
	bool getDirection(char input) { return directions[input]; }

	//get the output
	char getOutput(char input) { return outputs[input]; }

private:
	//The following correspond to to each input using the map
	//outputs
	std::map<char, char> outputs;
	
	//go Right?
	std::map<char, bool> directions;

	//next state
	std::map<char, std::string> nextState;
};