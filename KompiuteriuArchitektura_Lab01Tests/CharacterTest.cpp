#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/Character.cpp"


TEST(Character, constructor) {
	Character character(0, '0');
	ASSERT_EQ(character.position, 0);
	ASSERT_EQ(character.value, '0');
}
TEST(Character, equal) {
	Character character(0, '0');
	ASSERT_TRUE(character.equals(character));
}
TEST(Character, notEqual) {
	Character characterA(0, '0');
	Character characterB(1, '0');
	Character characterC(0, '1');
	ASSERT_FALSE(characterA.equals(characterB));
	ASSERT_FALSE(characterA.equals(characterC));
}