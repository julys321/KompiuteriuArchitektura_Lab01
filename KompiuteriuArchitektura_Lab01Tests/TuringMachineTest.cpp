#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/FileInteractor.cpp"
#include <vector>

TuringMachine createTuringMachine(std::string tape) {
	TuringMachine turingMachine;
	turingMachine.tape.fill(tape);
	return turingMachine;
}
TuringMachine createTuringMachine(std::string tape, int headPosition) {
	TuringMachine turingMachine;
	turingMachine.tape.fill(tape);
	turingMachine.head = headPosition;
	return turingMachine;
}

TEST(TuringMachine, headStartsAtZero) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.head, 0);
}

TEST(TuringMachine, headString) {
	TuringMachine turingMachine = createTuringMachine("000");
	ASSERT_EQ(turingMachine.getHeadString(),"^__");
}
TEST(TuringMachine, headStringPos2) {
	TuringMachine turingMachine = createTuringMachine("000");
	turingMachine.head = 2;
	ASSERT_EQ(turingMachine.getHeadString(), "__^");
}
TEST(TuringMachineRunLine, RunLineThatDoesNothing) {
	TuringMachine turingMachine = createTuringMachine("000");
	InstructionLine instructionLine("0", '0', '0', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(0).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '0');
}
TEST(TuringMachineRunLine, changeZeroToOne) {
	TuringMachine turingMachine = createTuringMachine("000");
	InstructionLine instructionLine("0", '0', '1', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(0).value, '1');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '0');
}
TEST(TuringMachineRunLine, leaveZeroAsZero) {
	TuringMachine turingMachine = createTuringMachine("000");
	InstructionLine instructionLine("0", '0', '*', '*', "0");

	turingMachine.runLine(instructionLine);

	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(0).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(1).value, '0');
	ASSERT_EQ(turingMachine.tape.getCharacterAtPosition(2).value, '0');
}
TEST(TuringMachineRunLine, leaveBAsB) {
	TuringMachine turingMachine = createTuringMachine("B00");
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
	TuringMachine turingMachine = createTuringMachine("B00");
	Program program;

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(createTuringMachine("B00").tape));
}
TEST(TuringMachineRun, oneLineProgram) {
	TuringMachine turingMachine = createTuringMachine("B00");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", 'B', 'A', 'r', "Halt"));

	TuringMachine expectedTuringMachine = createTuringMachine("A00");
	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(expectedTuringMachine.tape));
	ASSERT_EQ(turingMachine.head, 1);
}
TEST(TuringMachineRun, twoLineProgramSameState) {
	TuringMachine turingMachine = createTuringMachine("010");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '1', 'r', "0"));
	program.instructionLines.push_back(InstructionLine("0", '1', '0', 'r', "Halt"));

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(createTuringMachine("100").tape));
	ASSERT_EQ(turingMachine.head, 2);
}
TEST(TuringMachineRun, twoLineProgramDiffState) {
	TuringMachine turingMachine = createTuringMachine("010");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '1', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", '1', '0', 'r', "Halt"));

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(createTuringMachine("100").tape));
	ASSERT_EQ(turingMachine.head, 2);
}
TEST(TuringMachineRun, programWhereOneLineNeedsToBeExecutedTwice) {
	TuringMachine turingMachine = createTuringMachine("01BA");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0"));
	program.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	program.instructionLines.push_back(InstructionLine("0", 'B', '0', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	turingMachine.run(program);

	ASSERT_TRUE(turingMachine.tape.equals(createTuringMachine("0000").tape));
	ASSERT_EQ(turingMachine.head, 3);
}
TEST(TuringMachine, MakeStep) {
	TuringMachine turingMachine = createTuringMachine("0A00");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', 'B', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	turingMachine.makeStep(program);

	ASSERT_TRUE(turingMachine.tape.equals(createTuringMachine("BA00").tape));
	ASSERT_EQ(turingMachine.head, 1);
}
TEST(TuringMachine, MakeStepTwice) {
	TuringMachine turingMachine = createTuringMachine("0A00");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', 'B', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', 'r', "Halt"));

	turingMachine.makeStep(program);
	turingMachine.makeStep(program);

	ASSERT_TRUE(turingMachine.tape.equals(createTuringMachine("B000").tape));
	ASSERT_EQ(turingMachine.head, 2);
}
TEST(FileInteractor, getTuringMashineFromStringStream1001001) {
	FileInteractor fileInteractor;
	TuringMachine turingMachineA;
	std::stringstream stringstream("0\n1001001\n0 0 _ r 1o");
	turingMachineA  = fileInteractor.getTuringMashineFromStream(stringstream);

	TuringMachine turingMachineB = createTuringMachine("1001001");

	ASSERT_TRUE(turingMachineA.tape.equals(turingMachineB.tape));
	ASSERT_EQ(turingMachineA.head, 0);
}
TEST(FileInteractor, getTuringMashineFromStringStream10) {
	FileInteractor fileInteractor;
	TuringMachine turingMachineA;
	std::stringstream stringstream("-1\n10\n0 _ 1 r Halt");
	turingMachineA = fileInteractor.getTuringMashineFromStream(stringstream);

	TuringMachine turingMachineB = createTuringMachine("10");

	ASSERT_TRUE(turingMachineA.tape.equals(turingMachineB.tape));
	ASSERT_EQ(turingMachineA.head, -1);
}
TEST(FileInteractor, getProgramFromStream00_r1o) {
	FileInteractor fileInteractor;
	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', '_', 'r', "1o"));

	Program programA;
	std::stringstream stringstream("0\n1001001\n0 0 _ r 1o");

	programA = fileInteractor.getProgramFromStream(stringstream);

	ASSERT_TRUE(programA.equals(programB));
}
TEST(FileInteractor, getProgramFromStream0_1rHalt) {
	FileInteractor fileInteractor;
	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '_', '1', 'r', "Halt"));

	Program programA;
	std::stringstream stringstream("-1\n10\n0 _ 1 r Halt");

	programA = fileInteractor.getProgramFromStream(stringstream);

	ASSERT_TRUE(programA.equals(programB));
}