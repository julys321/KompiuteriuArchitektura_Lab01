#include "pch.h"
#include "../Turing-machine/InstructionLine.cpp"

TEST(InstructionLine, conststructorZeroes) {
	InstructionLine instructionLine("0", '0', '0', '*', "0");
	ASSERT_EQ(instructionLine.currentState, "0");
	ASSERT_EQ(instructionLine.currentSymbol, '0');
	ASSERT_EQ(instructionLine.nextSymbol, '0');
	ASSERT_EQ(instructionLine.headMovementDirection, '*');
	ASSERT_EQ(instructionLine.nextState, "0");
}
TEST(InstructionLine, conststructorOnes) {
	InstructionLine instructionLine("01", '1', '1', '*', "01");
	ASSERT_EQ(instructionLine.currentState, "01");
	ASSERT_EQ(instructionLine.currentSymbol, '1');
	ASSERT_EQ(instructionLine.nextSymbol, '1');
	ASSERT_EQ(instructionLine.headMovementDirection, '*');
	ASSERT_EQ(instructionLine.nextState, "01");
}
TEST(InstructionLine, equals) {
	InstructionLine instructionLineA("01", '1', '1', '*', "01");
	InstructionLine instructionLineB("01", '1', '1', '*', "01");

	ASSERT_TRUE(instructionLineA.equals(instructionLineB));
}
TEST(InstructionLine, notEquals) {
	InstructionLine instructionLineA("01", '1', '1', '*', "05");
	InstructionLine instructionLineB("01", '1', '1', '*', "01");

	ASSERT_FALSE(instructionLineA.equals(instructionLineB));
}