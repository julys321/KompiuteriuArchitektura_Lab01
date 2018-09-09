#pragma once
class Character
{
public:
	int position;
	char value;
	Character();
	Character(int position, char value);
	~Character();
	bool equals(Character character);
};

