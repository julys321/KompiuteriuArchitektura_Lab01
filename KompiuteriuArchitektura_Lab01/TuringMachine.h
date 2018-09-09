#pragma once
#include <vector>
#include "InstructionLine.h"
#include "Tape.h"
class TuringMachine
{
public:
	Tape tape;
	int head = 0;
	std::string state = "0";
	TuringMachine();
	~TuringMachine();
	void makeStep(InstructionLine instructionLine);
	Tape run(std::vector<InstructionLine> program);
};

