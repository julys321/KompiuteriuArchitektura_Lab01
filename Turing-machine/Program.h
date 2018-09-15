#pragma once
#include <vector>
#include "../Turing-machine/InstructionLine.h"
#include "../Turing-machine/Tape.h"
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

