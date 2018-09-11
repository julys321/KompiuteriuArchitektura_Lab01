#include "TuringMachineFactory.h"
#include <windows.h>
#include <iostream>
#include <string>


TuringMachineFactory::TuringMachineFactory()
{
}


TuringMachineFactory::~TuringMachineFactory()
{
}

TuringMachineFactory TuringMachineFactory::makeStepForAllMachines(std::vector<Program> programs) {
	for (int i = 0; i < programs.size(); i++) {
		if (machines[i].state != "Halt") {
			try {
				machines[i].makeStep(programs[i]);
			}
			catch (std::string message) {
				throw "Exception cought at Program "+ std::to_string(i)+": "+message;
			}
		}
	}

	TuringMachineFactory turingMachineFactory;
	turingMachineFactory.machines = this->machines;
	return turingMachineFactory;
}

void TuringMachineFactory::runAllMachines(std::vector<Program> programs) {
	while (isAnyProgramStillRunning()) {
		system("cls");
		try {
			makeStepForAllMachines(programs);
		}
		catch (std::string message) {
			std::cout<< message<<'\n';
			return;
		}
		Sleep(60);
	}

}

bool TuringMachineFactory::isAnyProgramStillRunning() {
	for (int i = 0; i < machines.size(); i++)
		if (machines[i].state != "Halt")
			return true;
	return false;
}