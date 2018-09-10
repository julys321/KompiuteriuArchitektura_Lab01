#include "InstructionLine.h"



InstructionLine::InstructionLine()
{
}

InstructionLine::InstructionLine(std::string currentState, char currentSymbol, char nextSymbol, char headMovementDirection, std::string nextState) {
	this->currentState = currentState;
	this->currentSymbol = currentSymbol;
	this->nextSymbol = nextSymbol;
	this->headMovementDirection = headMovementDirection;
	this->nextState = nextState;
}


InstructionLine::~InstructionLine()
{
}

bool InstructionLine::equals(InstructionLine instructionLine) {
	if (this->currentState==instructionLine.currentState)
		return false;
	if (this->currentSymbol != instructionLine.currentSymbol)
		return false;
	if (this->nextSymbol != instructionLine.nextSymbol)
		return false;
	if (this->headMovementDirection != instructionLine.headMovementDirection)
		return false;
	if (this->nextState==instructionLine.nextState)
		return false;
	return true;
}
