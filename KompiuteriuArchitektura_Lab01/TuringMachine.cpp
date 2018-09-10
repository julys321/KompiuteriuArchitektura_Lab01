#include "TuringMachine.h"



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
	}
}

Tape TuringMachine::run(Program program) {//needs to made into make step function
	if (program.instructionLines.size() > 0) {
		std::string state = "0";
		for (int i = 0; state != "Halt"; i++) {
			std::vector<InstructionLine> linesOfCurrentState = program.getLinesOfState(state);
			for (InstructionLine instructionLine : linesOfCurrentState) {
				if (tape.getCharacterAtPosition(head).value == instructionLine.currentSymbol) {
					runLine(instructionLine);
					state = instructionLine.nextState;
					break;
				}
			}
		}
	}
	return this->tape;
}


