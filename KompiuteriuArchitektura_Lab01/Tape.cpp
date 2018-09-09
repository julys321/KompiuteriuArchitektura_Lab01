#include "Tape.h"


Tape::Tape()
{
}


Tape::~Tape()
{
}

void Tape::fill(std::string characters) {
	for (int i = 0; i < characters.size(); i++) {
		this->characters.push_back(Character(i, characters[i]));
	}
}

Character Tape::getCharacterAtPosition(int position) {
	for (Character character : characters) {
		if (character.position == position) {
			return character;
		}
	}
	return Character(position, '_');
}

void Tape::setCharacterValueAtPosition(int position, char value) {
	if (getCharacterAtPosition(position).value == '_')
		characters.push_back(Character(position,value));
	else
		for (int i = 0; i < characters.size(); i++) {
			if (characters[i].position == position) {
				characters[i].position = position;
				characters[i].value = value;
			}
		}
}
