#include <iostream>
#include <vector>
#include "../KompiuteriuArchitektura_Lab01/Tape.h"
#include "../KompiuteriuArchitektura_Lab01/Character.h"
int main()
{
	Tape tape;
	tape.fill("AD0");
	tape.setCharacterValueAtPosition(-2, 'k');

	std::string haaa = tape.getAsString();
	std::cout << "Hello world!\n";
}