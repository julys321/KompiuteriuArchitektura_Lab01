#include "TuringMachine.h"
#include <iostream>
#include <windows.h>
TuringMachine::TuringMachine() {
}


TuringMachine::~TuringMachine() {
}

void TuringMachine::runLine(InstructionLine instructionLine) {
	tape.setCharacterValueAtPosition(head, instructionLine.nextSymbol);
	if (instructionLine.headMovementDirection != '*') {
		if (instructionLine.headMovementDirection == 'R')//TODO: refactor to moveHead()
			head++;
		else if (instructionLine.headMovementDirection == 'L')
			head--;
		tape.getCharacterAtPosition(head);
	}
}
void TuringMachine::makeStep(Program program) {
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
}

void TuringMachine::run(Program program, bool requareUserInputToContinue) {
	if (program.instructionLines.size() > 0) {
		for (int i = 0; state != "Halt"; i++) {
			system("cls");
			try {
				makeStep(program);
			}
			catch (std::string message) {
				std::cout << message;
				return;
			}
			Sleep(120);
			if (requareUserInputToContinue)
				system("pause");
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


