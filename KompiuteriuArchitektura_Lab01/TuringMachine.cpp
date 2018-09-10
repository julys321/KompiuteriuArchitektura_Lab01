#include "TuringMachine.h"
#include <iostream>
#include <windows.h>
TuringMachine::TuringMachine() {
}


TuringMachine::~TuringMachine() {
}

void TuringMachine::runLine(InstructionLine instructionLine) {
	if (instructionLine.nextSymbol != '*')
		tape.setCharacterValueAtPosition(head, instructionLine.nextSymbol);
	if (instructionLine.headMovementDirection != '*') {
		if (instructionLine.headMovementDirection == 'r')//make move head
			head++;
		else if (instructionLine.headMovementDirection == 'l')
			head--;
		tape.getCharacterAtPosition(head);
	}
}
void TuringMachine::makeStep(Program program) {
	system("cls");
	InstructionLine instructionLine;
	try {
		instructionLine = program.findInstructionline(tape.getCharacterAtPosition(head).value, state);
	}
	catch (std::string message) {
		throw message;
	}
	runLine(instructionLine);
	state = instructionLine.nextState;
	std::cout << tape.getAsString() << "\n";
	std::cout << getHeadString() << "\n";
	Sleep(120);
}

void TuringMachine::run(Program program) {
	if (program.instructionLines.size() > 0) {
		for (int i = 0; state != "Halt"; i++) {
			try {
				makeStep(program);
			}
			catch (std::string message) {
				std::cout << message;
				return;
			}
		}
	}
}

std::string TuringMachine::getHeadString() {
	std::string string;
	std::vector<int> positions = tape.getCharactersPositions();
	int front = positions.front();
	int back = positions.back();
	for (int i = positions.front(); i <= positions.back(); i++) {
		if (head == i)
			string.push_back('^');
		else
			string.push_back('_');
	}
	return string;
}


