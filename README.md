# TuringMachine
A simple Turing Machine program

This program simulates a Turing Machine. Machines are created from a series of steps given in a simple .txt document.

The steps are defined in the following format:
  {state,input,next state,direction(R, L),output}
  
e.g.
  {s0,0,s0,R,1}
  {s0, ,s1,R,1}
  {s0,1,s0,L,1}
  
If no instructions are given for a given state, such as for s1 in the previous example, then it is assumed to be an ending
state and the machine will stop. You can explicitly define a halting point by setting the "next state" to HALT.

The test program is run with the following command line arguments:

PROGRAM_NAME file_path_of_machine input_string starting_state

e.g. 
  TuringMachine.exe instructions.txt 00000000000000001 s0


