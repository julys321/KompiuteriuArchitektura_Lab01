#include <iostream>
#include "../KompiuteriuArchitektura_Lab01/Tape.h"
#include "../KompiuteriuArchitektura_Lab01/Character.h"
int main()
{
	Tape tape;
	tape.setCharacterValueAtPosition(-10, 'g');
	tape.setCharacterValueAtPosition(-10, 'a');
	char papa = tape.getCharacterAtPosition(-10).value;
	std::cout << "Hello world!\n";
}