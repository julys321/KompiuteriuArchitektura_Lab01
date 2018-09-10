#include "Tape.h"
#include <algorithm>

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
		characters.push_back(Character(position, value));
	else
		for (int i = 0; i < characters.size(); i++) {
			if (characters[i].position == position) {
				characters[i].position = position;
				characters[i].value = value;
			}
		}
}

bool Tape::equals(Tape tape) {
	if (tape.characters.size() != characters.size())
		return false;
	for (int i = 0; i < characters.size(); i++) {
		if (!characters[i].equals(tape.characters[i])) {
			return false;
		}
	}
	return true;
}

std::string Tape::getAsString() {
	std::string string;
	Tape tape;
	tape.characters = this->characters;
	std::vector<int> positions = getCharactersPositions();
	for (int i = 0; i < positions.size(); i++) {
		int iPlus = i + 1;
		string.push_back(tape.getCharacterAtPosition(positions[i]).value);//to mutch 
		if (iPlus < positions.size()) {
			int n = positions[iPlus] - positions[i] - 1;
			for (int j = 0; j < n; j++) {
				string.push_back('_');
			}
		}
	}
	return string;
}

Character Tape::getFirstCharacter() {
	int firstCharacterPosition = characters[0].position;
	for (int i = 1; i < characters.size(); i++) {
		if (firstCharacterPosition > characters[i].position)
			firstCharacterPosition = characters[i].position;
	}
	return getCharacterAtPosition(firstCharacterPosition);
}

std::vector<int> Tape::getCharactersPositions() {
	std::vector<int> charactersPositions;
	for (int i = 0; i < characters.size(); i++) {
		charactersPositions.push_back(characters[i].position);
	}
	std::sort(charactersPositions.begin(), charactersPositions.end());
	return charactersPositions;
}
