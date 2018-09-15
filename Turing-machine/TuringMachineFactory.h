#pragma once
#include <vector>
#include "TuringMachine.h"
class TuringMachineFactory
{
public:
	std::vector<TuringMachine> machines;
	TuringMachineFactory();
	~TuringMachineFactory();
	TuringMachineFactory makeStepForAllMachines(std::vector<Program> programs);
	void runAllMachines(std::vector<Program> programs, bool requareUserInputToContinue);
	bool isAnyProgramStillRunning();
};

