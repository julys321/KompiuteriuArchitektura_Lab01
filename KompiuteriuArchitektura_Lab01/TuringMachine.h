#pragma once
#include <vector>
#include "InstructionLine.h"
#include "Tape.h"
class TuringMachine
{
public:
	Tape tape;
	int head = 0;
	TuringMachine();
	~TuringMachine();
	int makeStep(InstructionLine instructionLine);
};

