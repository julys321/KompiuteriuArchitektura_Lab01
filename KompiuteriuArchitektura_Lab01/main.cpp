#include <iostream>
#include <vector>
#include <fstream>
#include "../KompiuteriuArchitektura_Lab01/Tape.h"
#include "../KompiuteriuArchitektura_Lab01/Character.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.h"
#include "../KompiuteriuArchitektura_Lab01/Character.h"
#include "../KompiuteriuArchitektura_Lab01/FileInteractor.h"
int main()
{
	std::string fileName = "2.txt";
	FileInteractor fileInteractor;
	TuringMachine turingMachine;
	Program program;

	turingMachine = fileInteractor.getTuringMashineFromFile(fileName);
	program = fileInteractor.getProgramFromFile(fileName);

	turingMachine.run(program);
	//turingMachine.runStepByStep(program);
	return 0;
}