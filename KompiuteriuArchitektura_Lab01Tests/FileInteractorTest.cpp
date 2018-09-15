#include "pch.h"
#include "../Turing-machine/FileInteractor.cpp"
TEST(FileInteractor, getTuringMashineFromStringStream1001001) {
	FileInteractor fileInteractor;
	TuringMachine turingMachineA;
	std::stringstream stringstream("0\n1001001\n0 0 _ R 1o");
	turingMachineA = fileInteractor.getTuringMashineFromStream(stringstream);

	TuringMachine turingMachineB;
	turingMachineB.tape.fill("1001001");

	ASSERT_TRUE(turingMachineA.tape.equals(turingMachineB.tape));
	ASSERT_EQ(turingMachineA.head, 0);
}
TEST(FileInteractor, getTuringMashineFromStringStream10) {
	FileInteractor fileInteractor;
	TuringMachine turingMachineA;
	std::stringstream stringstream("-1\n10\n0 _ 1 R Halt");
	turingMachineA = fileInteractor.getTuringMashineFromStream(stringstream);

	TuringMachine turingMachineB;
	turingMachineB.tape.fill("10");

	ASSERT_TRUE(turingMachineA.tape.equals(turingMachineB.tape));
	ASSERT_EQ(turingMachineA.head, -1);
}
TEST(FileInteractor, getProgramFromStream00_r1o) {
	FileInteractor fileInteractor;
	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', '_', 'R', "1o"));

	Program programA;
	std::stringstream stringstream("0\n1001001\n0 0 _ R 1o");

	programA = fileInteractor.getProgramFromStream(stringstream);

	ASSERT_TRUE(programA.equals(programB));
}
TEST(FileInteractor, getProgramFromStream0_1rHalt) {
	FileInteractor fileInteractor;
	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '_', '1', 'R', "Halt"));

	Program programA;
	std::stringstream stringstream("-1\n10\n0 _ 1 R Halt");

	programA = fileInteractor.getProgramFromStream(stringstream);

	ASSERT_TRUE(programA.equals(programB));
}