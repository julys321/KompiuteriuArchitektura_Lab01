#include "Character.h"



Character::Character() {
}

Character::Character(int position, char value) {
	this->position = position;
	this->value = value;
}


Character::~Character() {
}

bool Character::equals(Character character) {
	if (this->position != character.position)
		return false;
	else if (this->value != character.value)
		return false;
	else
		return true;
}
