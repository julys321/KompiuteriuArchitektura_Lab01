#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.h"
#include "../KompiuteriuArchitektura_Lab01/InstructionLine.h"
#include "TuringMachineTest.h"

TEST(TuringMachine, makeStepThatDoesNothing) {
	TuringMachine turingMachine;
	//tape mock
	turingMachine.tape.push_back('0');
	turingMachine.tape.push_back('0');
	turingMachine.tape.push_back('0');
	//instruction line mock
	InstructionLine instructionLine("0",'0','0','*',"0");

	turingMachine.makeStep();
	ASSERT_EQ(turingMachine.tape[0], '0');
	ASSERT_EQ(turingMachine.tape[1], '0');
	ASSERT_EQ(turingMachine.tape[2], '0');
}
TEST(TuringMachine, headStartsAtZero) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.head, 0);
}
TEST(InstructionLine, conststructor) {
	InstructionLine instructionLine("0", '0', '0', '*', "0");
	ASSERT_EQ(instructionLine.currentState, "0");
	ASSERT_EQ(instructionLine.currentSymbol, '0');
	ASSERT_EQ(instructionLine.nextSymbol, '0');
	ASSERT_EQ(instructionLine.headMovementDirection, '*');
	ASSERT_EQ(instructionLine.nextState, "0");
}