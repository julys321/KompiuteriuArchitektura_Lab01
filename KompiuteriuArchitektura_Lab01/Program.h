#pragma once
#include <vector>
#include "../KompiuteriuArchitektura_Lab01/InstructionLine.h"
class Program
{
public:
	std::vector<InstructionLine> instructionLines;
	Program();
	~Program();
	std::vector<InstructionLine> getLinesOfState(std::string state);
};

