#include "TuringMachine.h"



TuringMachine::TuringMachine() {
}


TuringMachine::~TuringMachine() {
}

void TuringMachine::makeStep(InstructionLine instructionLine) {//ugly int
	if (instructionLine.nextSymbol != '*')
		tape.setCharacterValueAtPosition(head, instructionLine.nextSymbol);
	if (instructionLine.headMovementDirection != '*') {
		if (instructionLine.headMovementDirection == 'r')
			head++;
		else if (instructionLine.headMovementDirection == 'l')
			head--;
	}
}

Tape TuringMachine::run(std::vector<InstructionLine> program){
	for (InstructionLine instructionLine : program) {
		makeStep(instructionLine);
	}
	return this->tape;
}
