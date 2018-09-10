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
	FileInteractor fileInteractor;
	TuringMachine turingMachine;
	turingMachine = fileInteractor.getTuringMashineFromFile("5.txt");

//	turingMachine.run(fileInteractor.getProgramFromFile("0.txt"));
	std::cout << turingMachine.tape.getAsString() << "\n";
}