#pragma once
#include <vector>
#include "InstructionLine.h"
#include "Tape.h"
#include "Program.h"
class TuringMachine
{
public:
	Tape tape;
	int head = 0;
	TuringMachine();
	~TuringMachine();
	void runLine(InstructionLine instructionLine);
	Tape run(Program program);
};

