#include "TuringMachine.h"



TuringMachine::TuringMachine() {
}


TuringMachine::~TuringMachine() {
}

int TuringMachine::makeStep(InstructionLine instructionLine) {//ugly int
	if (instructionLine.nextSymbol != '*')
		tape.setCharacterValueAtPosition(head, instructionLine.nextSymbol);
	if (instructionLine.headMovementDirection != '*') {
		if (instructionLine.headMovementDirection == 'r')
			head++;
		else if (instructionLine.headMovementDirection == 'l')
			head--;
	}

	return 0;
}
