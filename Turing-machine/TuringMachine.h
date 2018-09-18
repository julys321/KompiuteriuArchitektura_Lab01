#pragma once
#include <vector>
#include "Program.h"
class TuringMachine
{
public:
	Tape tape;
	int head = 0;
	std::string state = "0";
	TuringMachine();
	~TuringMachine();
	void runLine(InstructionLine instructionLine);
	void makeStep(Program program);
	void run(Program program, bool requareUserInputToContinue);
	std::string getHeadString();
};

