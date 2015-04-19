#include "TuringMachine.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	string filepath = argv[1];
	string input = argv[2];
	string startState = argv[3];

	TuringMachine tm(filepath, input, startState);

	cout << tm.getCurrentOutput() << endl;

	while (tm.advance())
		cout << tm.getCurrentOutput() << endl;

	
}