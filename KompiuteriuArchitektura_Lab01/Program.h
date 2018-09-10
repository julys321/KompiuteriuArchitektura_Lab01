#pragma once
#include <vector>
#include "../KompiuteriuArchitektura_Lab01/InstructionLine.h"
#include "../KompiuteriuArchitektura_Lab01/Tape.h"
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

