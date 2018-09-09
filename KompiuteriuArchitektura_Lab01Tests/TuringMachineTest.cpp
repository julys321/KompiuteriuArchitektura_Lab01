#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.h"
TEST(TuringMachine, doNothing) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.doNothing(), 0);
}
TEST(TuringMachine, headStartsAtZero) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.head, 0);
}