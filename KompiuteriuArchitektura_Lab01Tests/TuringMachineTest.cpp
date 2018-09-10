#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.cpp"
#include "../KompiuteriuArchitektura_Lab01/InstructionLine.cpp"
#include "../KompiuteriuArchitektura_Lab01/Tape.cpp"
#include "../KompiuteriuArchitektura_Lab01/Character.cpp"
#include "../KompiuteriuArchitektura_Lab01/Program.cpp"
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
TEST(TuringMachine, headStartsAtZero) {
	TuringMachine turingMachine;
	ASSERT_EQ(turingMachine.head, 0);
}
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
TEST(Program, equals) {
	Program programA;
	programA.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0"));
	programA.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	programA.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));
	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0"));
	programB.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	programB.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	ASSERT_TRUE(programA.equals(programB));
}
TEST(Program, notEquals) {
	Program programA;
	programA.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0D"));
	programA.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	programA.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));
	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0"));
	programB.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	programB.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	ASSERT_FALSE(programA.equals(programB));
}
TEST(TuringMachineRun, emptyProgram) {
	TuringMachine turingMachine = createTuringMachine("B00");
	Program program;

	Tape resultingTape = turingMachine.run(program);

	ASSERT_TRUE(resultingTape.equals(createTuringMachine("B00").tape));
}
TEST(TuringMachineRun, oneLineProgram) {
	TuringMachine turingMachine = createTuringMachine("B00");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", 'B', 'A', 'r', "Halt"));

	TuringMachine expectedTuringMachine = createTuringMachine("A00");
	Tape resultingTape = turingMachine.run(program);

	ASSERT_TRUE(resultingTape.equals(expectedTuringMachine.tape));
	ASSERT_EQ(turingMachine.head, 1);
}
TEST(TuringMachineRun, twoLineProgramSameState) {
	TuringMachine turingMachine = createTuringMachine("010");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '1', 'r', "0"));
	program.instructionLines.push_back(InstructionLine("0", '1', '0', 'r', "Halt"));

	Tape resultingTape = turingMachine.run(program);

	ASSERT_TRUE(resultingTape.equals(createTuringMachine("100").tape));
	ASSERT_EQ(turingMachine.head, 2);
}
TEST(TuringMachineRun, twoLineProgramDiffState) {
	TuringMachine turingMachine = createTuringMachine("010");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '1', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", '1', '0', 'r', "Halt"));

	Tape resultingTape = turingMachine.run(program);

	ASSERT_TRUE(resultingTape.equals(createTuringMachine("100").tape));
	ASSERT_EQ(turingMachine.head, 2);
}
TEST(TuringMachineRun, programWhereOneLineNeedsToBeExecutedTwice) {
	TuringMachine turingMachine = createTuringMachine("01BA");
	Program program;
	program.instructionLines.push_back(InstructionLine("0", '0', '0', 'r', "0"));
	program.instructionLines.push_back(InstructionLine("0", '1', '0', 'l', "0"));
	program.instructionLines.push_back(InstructionLine("0", 'B', '0', 'r', "1"));
	program.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	Tape resultingTape = turingMachine.run(program);

	ASSERT_TRUE(resultingTape.equals(createTuringMachine("0000").tape));
	ASSERT_EQ(turingMachine.head, 3);
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
	TuringMachine turingMachineA;
	Program programA;
	std::stringstream stringstream("0\n1001001\n0 0 _ r 1o");
	programA = fileInteractor.getProgramFromStream(stringstream);

	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', '_', 'r', "1o"));
	ASSERT_TRUE(false);
	//ASSERT_TRUE(programA.equals(programB));
}
TEST(FileInteractor, getProgramFromStream0_1rHalt) {
	FileInteractor fileInteractor;
	Program programA;
	std::stringstream stringstream("-1\n10\n0 _ 1 r Halt");
	programA = fileInteractor.getProgramFromStream(stringstream);

	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '_', '1', 'r', "Halt"));
	ASSERT_TRUE(false);
	//ASSERT_TRUE(programA.equals(programB));
}