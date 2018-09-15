#include "FileInteractor.h"
#include <fstream>
#include <sstream>


FileInteractor::FileInteractor()
{
}


FileInteractor::~FileInteractor()
{
}

TuringMachine FileInteractor::getTuringMashineFromStream(std::stringstream& in){
	TuringMachine turingMachine;
	std::string tape;
	in>>turingMachine.head;
	in >> tape;
	turingMachine.tape.fill(tape);
	return turingMachine;
}
TuringMachine FileInteractor::getTuringMashineFromFile(std::string fileName){//TODO:cover in unit tests
	std::ifstream in(fileName);
	std::stringstream buffer;
	if (in) {
		buffer << in.rdbuf();
		in.close();
	}
	return getTuringMashineFromStream(buffer);
}
Program FileInteractor::getProgramFromStream(std::stringstream & in){
	Program program;
	std::string temp;
	getline(in, temp);
	getline(in, temp);
	while (!in.eof()) {
		InstructionLine instructionLine;
		in >> instructionLine.currentState;
		in >> instructionLine.currentSymbol;
		in >> instructionLine.nextSymbol;
		in >> instructionLine.headMovementDirection;
		in >> instructionLine.nextState;
		program.instructionLines.push_back(instructionLine);
	}
	return program;
}
Program FileInteractor::getProgramFromFile(std::string fileName){//TODO:cover in unit tests
	std::ifstream in(fileName);
	std::stringstream buffer;
	if (in) {
		buffer << in.rdbuf();
		in.close();
	}
	return getProgramFromStream(buffer);
}
