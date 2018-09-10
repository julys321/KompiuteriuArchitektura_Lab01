#include "FileInteractor.h"
#include <fstream>


FileInteractor::FileInteractor()
{
}


FileInteractor::~FileInteractor()
{
}

TuringMachine FileInteractor::getTuringMashineFromFile(std::string fileName){
	TuringMachine turingMachine;
	std::string tape;
	std::ifstream in(fileName);
	in>>turingMachine.head;
	in >> tape;
	in.close();
	turingMachine.tape.fill(tape);
	return turingMachine;
}

Program FileInteractor::getProgramFromFile(std::string fileName){
	Program program;
	std::string temp;
	std::ifstream in(fileName);
	getline(in, temp);
	getline(in, temp);
	while (!in.eof()) {
		InstructionLine instructionLine;
		in>>instructionLine.currentState;
		in >> instructionLine.currentSymbol;
		in >> instructionLine.nextSymbol;
		in >> instructionLine.headMovementDirection;
		in >> instructionLine.nextState;
		program.instructionLines.push_back(instructionLine);
	}
	in.close();
	return program;
}
