#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.h"
#include <vector>

TEST(TuringMachine, headStartsAtZero) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.head, 0);
}

TEST(TuringMachine, headString) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("000");
	ASSERT_EQ(turingMachine.getHeadString(),"^__");
}
TEST(TuringMachine, headStringPos2) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("000");
	turingMachine.head = 2;
	ASSERT_EQ(turingMachine.getHeadString(), "__^");
}
TEST(TuringMachineRunLine, RunLineThatDoesNothing) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("000");
	InstructionLine instructionLine("0", '0', '0', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(0).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '0');
}
TEST(TuringMachineRunLine, changeZeroToOne) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("000");
	InstructionLine instructionLine("0", '0', '1', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(0).value, '1');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '0');
}
TEST(TuringMachineRunLine, leaveZeroAsZero) {
	TuringMachine turingMachine;
	turingMachine.tape.fill( "000");
	InstructionLine instructionLine("0", '0', '*', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(0).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '0');
}
TEST(TuringMachineRunLine, leaveBAsB) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("B00");
	InstructionLine instructionLine("0", 'B', '*', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(0).value, 'B');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '0');
}
TEST(TuringMachineRunLine, moveHeadRight) {
	TuringMachine turingMachine;
	InstructionLine instructionLine("0", 'B', '*', 'r', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.head, 1);
}
TEST(TuringMachineRunLine, moveHeadLeft) {
	TuringMachine turingMachine;
	InstructionLine instructionLine("0", 'B', '*', 'l', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.head, -1);
}
TEST(TuringMachineRunLine, headStaysInPlace) {
	TuringMachine turingMachine;
	InstructionLine instructionLine("0", 'B', '*', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.head, 0);
}
TEST(Program, getLinesOfState) {
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0"));
	program.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	std::vector<InstructionLine> linesOfState = program.getLinesOfState("0");

	ASSERT_EQ(linesOfState.size(), 2);
}
TEST(TuringMachineRun, emptyProgram) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("B00");
	Program program;

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(Tape("B00")));
}
TEST(TuringMachineRun, oneLineProgram) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("B00");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", 'B', 'A', 'r', "Halt"));

	TuringMachine expectedTuringMachine;
	expectedTuringMachine.tape.fill("A00");

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(expectedTuringMachine.tape));
	ASSERT_EQ(turingMachine.head, 1);
}
TEST(TuringMachineRun, twoLineProgramSameState) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("010");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '1', 'r', "0"));
	program.instructionLines.push_back(InstructionLine("0", '1', '0', 'r', "Halt"));

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(Tape("100")));
	ASSERT_EQ(turingMachine.head, 2);
}
TEST(TuringMachineRun, twoLineProgramDiffState) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("010");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '1', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", '1', '0', 'r', "Halt"));

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(Tape("100")));
	ASSERT_EQ(turingMachine.head, 2);
}
TEST(TuringMachineRun, programWhereOneLineNeedsToBeExecutedTwice) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("01BA");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0"));
	program.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	program.instructionLines.push_back(InstructionLine("0", 'B', '0', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(Tape("0000")));
	ASSERT_EQ(turingMachine.head, 3);
}
TEST(TuringMachine, MakeStep) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("0A00");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', 'B', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	turingMachine.makeStep(program);

	ASSERT_TRUE(turingMachine.tape.equals(Tape("BA00")));
	ASSERT_EQ(turingMachine.head, 1);
}
TEST(TuringMachine, MakeStepTwice) {
	TuringMachine turingMachine;
	turingMachine.tape.fill("0A00");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', 'B', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', 'r', "Halt"));

	turingMachine.makeStep(program);
	turingMachine.makeStep(program);

	ASSERT_TRUE(turingMachine.tape.equals(Tape("B000")));
	ASSERT_EQ(turingMachine.head, 2);
}