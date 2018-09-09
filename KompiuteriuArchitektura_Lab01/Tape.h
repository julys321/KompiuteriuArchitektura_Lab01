#pragma once
#include <vector>
#include "Character.h"
class Tape
{
public:
	std::vector<Character> characters;
	Tape();
	~Tape();
	void fill(std::string characters);
	Character getCharacterAtPosition(int position);
	void setCharacterValueAtPosition(int position, char value);
	bool equals(Tape tape);
	std::string getAsString();
	Character getFirstCharacter();
	std::vector<int> getCharactersPositions();
};

