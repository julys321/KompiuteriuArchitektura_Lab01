#pragma once
#include <vector>
#include "InstructionLine.h"
#include "Tape.h"
class Program
{
public:
	std::vector<InstructionLine> instructionLines;
	Program();
	~Program();
	std::vector<InstructionLine> getLinesOfState(std::string state);
	bool equals(Program program);
	InstructionLine findInstructionline(char currentCharacter, std::string state);
};

