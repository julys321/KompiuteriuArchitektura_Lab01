#pragma once
#include <vector>
#include "InstructionLine.h"
class TuringMachine
{
public:
	std::vector<char> tape;
	int head = 0;
	TuringMachine();
	~TuringMachine();
	int makeStep(InstructionLine instructionLine);
	void fillTape(std::string tape);
};

