#pragma once
#include <string>
class InstructionLine
{
public:
	std::string currentState;
	char currentSymbol;
	char nextSymbol;
	char headMovementDirection;
	std::string nextState;
	InstructionLine();
	InstructionLine(std::string currentState, char currentSymbol, char nextSymbol, char headMovementDirection, std::string nextState);
	~InstructionLine();
	bool equals(InstructionLine instructionLine);
};

