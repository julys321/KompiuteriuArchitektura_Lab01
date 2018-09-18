#include <iostream>
#include <vector>
#include <fstream>
#include "TuringMachineFactory.h"
#include "FileInteractor.h"
void runOneFile(std::string fileName, bool requareUserInputToContinue);
void runAllFiles(bool requareUserInputToContinue);
int main(){
	std::string userInput;
	int requareUserInputToContinue;
	std::cout << "Run all or run one? 0 - all, 1 - one\n";
	std::cin >> userInput;
	if (userInput.compare("0") == 0) {
		std::cout << "Wait for your input after a step is made? 1 - yes, 0 - no\n";
		std::cin >> requareUserInputToContinue;
		runAllFiles(requareUserInputToContinue);
	}
	else if (userInput.compare("1") == 0) {
		std::cout << "Enter file name: //.fileType requared\n";
		std::cin >> userInput;
		std::cout << "Wait for your input after a step is made? 1 - yes, 0 - no\n";
		std::cin >> requareUserInputToContinue;
		runOneFile(userInput, requareUserInputToContinue);
	}
	return 0;
}
void runOneFile(std::string fileName, bool requareUserInputToContinue) {
	FileInteractor fileInteractor;
	TuringMachine turingMachine;
	Program program;

	turingMachine = fileInteractor.getTuringMashineFromFile(fileName);
	program = fileInteractor.getProgramFromFile(fileName);

	turingMachine.run(program,requareUserInputToContinue);
}
void runAllFiles(bool requareUserInputToContinue) {
	FileInteractor fileInteractor;
	std::string fileNameA = "1.txt";
	TuringMachine turingMachineA;
	Program programA;

	turingMachineA = fileInteractor.getTuringMashineFromFile(fileNameA);
	programA = fileInteractor.getProgramFromFile(fileNameA);

	std::string fileNameB = "2.txt";
	TuringMachine turingMachineB;
	Program programB;

	turingMachineB = fileInteractor.getTuringMashineFromFile(fileNameB);
	programB = fileInteractor.getProgramFromFile(fileNameB);

	std::string fileNameC = "3.txt";
	TuringMachine turingMachineC;
	Program programC;

	turingMachineC = fileInteractor.getTuringMashineFromFile(fileNameC);
	programC = fileInteractor.getProgramFromFile(fileNameC);

	std::string fileNameD = "4.txt";
	TuringMachine turingMachineD;
	Program programD;

	turingMachineD = fileInteractor.getTuringMashineFromFile(fileNameD);
	programD = fileInteractor.getProgramFromFile(fileNameD);

	std::vector<Program> programs;
	programs.push_back(programA);
	programs.push_back(programB);
	programs.push_back(programC);
	programs.push_back(programD);

	TuringMachineFactory turingMachineFactory;
	turingMachineFactory.machines.push_back(turingMachineA);
	turingMachineFactory.machines.push_back(turingMachineB);
	turingMachineFactory.machines.push_back(turingMachineC);
	turingMachineFactory.machines.push_back(turingMachineD);

	turingMachineFactory.runAllMachines(programs,requareUserInputToContinue);
}