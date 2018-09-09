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
