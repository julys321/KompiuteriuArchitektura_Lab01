#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/Tape.cpp"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.cpp"

TEST(Tape, getCharacterValueAtPosition) {
	TuringMachine turingMachine;
	turingMachine.tape.characters.push_back(Character(2, 'i'));

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, 'i');
}
TEST(Tape, getEmptyCharacterValue) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '_');
}
TEST(Tape, fillZeroes) {
	Tape tape;
	tape.fill("000");

	ASSERT_EQ(tape.getCharacterAtPosition(0).value, '0');
	ASSERT_EQ(tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(tape.getCharacterAtPosition(2).value, '0');
}
TEST(Tape, setCharacterAtMinusTen) {
	Tape tape;
	tape.setCharacterValueAtPosition(-10, 'g');
	ASSERT_EQ(tape.getCharacterAtPosition(-10).value, 'g');
}
TEST(Tape, setCharacterAtMinusTenWhenValueExists) {
	Tape tape;
	tape.setCharacterValueAtPosition(-10, 'g');
	tape.setCharacterValueAtPosition(-10, 'a');
	ASSERT_EQ(tape.getCharacterAtPosition(-10).value, 'a');
}
TEST(Tape, fillRandom) {
	Tape tape;
	tape.fill("AD0");

	ASSERT_EQ(tape.getCharacterAtPosition(0).value, 'A');
	ASSERT_EQ(tape.getCharacterAtPosition(1).value, 'D');
	ASSERT_EQ(tape.getCharacterAtPosition(2).value, '0');
}
TEST(Tape, notEqual) {
	Tape tapeA;
	tapeA.fill("AD0");
	Tape tapeB;
	tapeB.fill("AP0");
	ASSERT_FALSE(tapeA.equals(tapeB));
}
TEST(Tape, equal) {
	Tape tapeA;
	tapeA.fill("AD0");
	Tape tapeB;
	tapeB.fill("AD0");

	ASSERT_TRUE(tapeA.equals(tapeB));
}
TEST(Tape, notEqualEmptyTape) {
	Tape tapeA;
	Tape tapeB;
	tapeB.fill("AD0");

	ASSERT_FALSE(tapeA.equals(tapeB));
}
TEST(Tape, getFirstCharacter) {
	Tape tape;
	tape.fill("AD0");
	tape.setCharacterValueAtPosition(-10, 'k');

	ASSERT_TRUE(tape.getFirstCharacter().equals(Character(-10, 'k')));
	system("pause");
}
TEST(Tape, getCharactersPositions) {
	Tape tape;
	tape.fill("AD0");
	tape.setCharacterValueAtPosition(-2, 'k');

	std::vector<int> positions = tape.getCharactersPositions();
	ASSERT_EQ(positions[0], -2);
	ASSERT_EQ(positions[1], 0);
	ASSERT_EQ(positions[2], 1);
	ASSERT_EQ(positions[3], 2);
}
TEST(Tape, convertToString) {
	Tape tape;
	tape.fill("AD0");
	tape.setCharacterValueAtPosition(-2, 'k');

	ASSERT_EQ(tape.getAsString(), "k_AD0");
}