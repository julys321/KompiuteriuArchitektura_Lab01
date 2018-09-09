#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.h"
#include "../KompiuteriuArchitektura_Lab01/InstructionLine.h"

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
TEST(TuringMachine, headStartsAtZero) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.head, 0);
}
TEST(TuringMachineFillTape, Zeroes) {
	TuringMachine turingMachine;
	turingMachine.fillTape("000");

	ASSERT_EQ(turingMachine.tape[0], '0');
	ASSERT_EQ(turingMachine.tape[1], '0');
	ASSERT_EQ(turingMachine.tape[2], '0');
}
TEST(TuringMachineMakeStep, MakeStepThatDoesNothing) {
	TuringMachine turingMachine;
	turingMachine.fillTape("000");
	InstructionLine instructionLine("0", '0', '0', '*', "0");

	turingMachine.makeStep(instructionLine);

	ASSERT_EQ(turingMachine.tape[0], '0');
	ASSERT_EQ(turingMachine.tape[1], '0');
	ASSERT_EQ(turingMachine.tape[2], '0');
}
TEST(TuringMachineMakeStep, changeZeroToOne) {
	TuringMachine turingMachine;
	turingMachine.fillTape("000");
	InstructionLine instructionLine("0", '0', '1', '*', "0");

	turingMachine.makeStep(instructionLine);

	ASSERT_EQ(turingMachine.tape[0], '1');
	ASSERT_EQ(turingMachine.tape[1], '0');
	ASSERT_EQ(turingMachine.tape[2], '0');
}
TEST(TuringMachineMakeStep, leaveZeroAsZero) {
	TuringMachine turingMachine;
	turingMachine.fillTape("000");
	InstructionLine instructionLine("0", '0', '*', '*', "0");

	turingMachine.makeStep(instructionLine);

	ASSERT_EQ(turingMachine.tape[0], '0');
	ASSERT_EQ(turingMachine.tape[1], '0');
	ASSERT_EQ(turingMachine.tape[2], '0');
}
TEST(TuringMachineMakeStep, leaveBAsB) {
	TuringMachine turingMachine;
	turingMachine.fillTape("B00");
	InstructionLine instructionLine("0", 'B', '*', '*', "0");

	turingMachine.makeStep(instructionLine);

	ASSERT_EQ(turingMachine.tape[0], 'B');
	ASSERT_EQ(turingMachine.tape[1], '0');
	ASSERT_EQ(turingMachine.tape[2], '0');
}