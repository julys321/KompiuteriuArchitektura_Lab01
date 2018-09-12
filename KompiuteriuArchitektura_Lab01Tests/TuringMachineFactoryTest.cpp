#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachine.h"
#include "../KompiuteriuArchitektura_Lab01/TuringMachineFactory.cpp"

TEST(TuringMachineFactory, makeStepForTwoTuringMachines) {
	TuringMachine turingMachineA;
	turingMachineA.tape.fill("0A00");
	TuringMachine turingMachineB;
	turingMachineB.tape.fill("0A00");

	Program programA;
	programA.instructionLines.push_back(InstructionLine("0", '0', 'B', 'R', "1"));
	programA.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', 'A', 'L', "1"));
	programB.instructionLines.push_back(InstructionLine("1", '_', '0', 'R', "Halt"));

	std::vector<Program> programs;
	programs.push_back(programA);
	programs.push_back(programB);

	TuringMachineFactory turingMachineFactory;
	turingMachineFactory.machines.push_back(turingMachineA);
	turingMachineFactory.machines.push_back(turingMachineB);

	turingMachineFactory = turingMachineFactory.makeStepForAllMachines(programs);

	ASSERT_TRUE(turingMachineFactory.machines[0].tape.equals(Tape("BA00")));
	ASSERT_EQ(turingMachineFactory.machines[0].head, 1);

	ASSERT_TRUE(turingMachineFactory.machines[1].tape.equals(Tape("_AA00")));
	ASSERT_EQ(turingMachineFactory.machines[1].head, -1);
}
TEST(TuringMachineFactory, isAnyProgramStillRunningTrue) {
	TuringMachine turingMachineA;
	turingMachineA.tape.fill("0A00");
	TuringMachine turingMachineB;
	turingMachineB.tape.fill("0A00");

	Program programA;
	programA.instructionLines.push_back(InstructionLine("0", '0', 'B', 'R', "1"));
	programA.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', 'A', 'L', "1"));
	programB.instructionLines.push_back(InstructionLine("1", '_', '0', 'R', "Halt"));

	std::vector<Program> programs;
	programs.push_back(programA);
	programs.push_back(programB);

	TuringMachineFactory turingMachineFactory;
	turingMachineFactory.machines.push_back(turingMachineA);
	turingMachineFactory.machines.push_back(turingMachineB);

	turingMachineFactory = turingMachineFactory.makeStepForAllMachines(programs);

	ASSERT_TRUE(turingMachineFactory.isAnyProgramStillRunning());
}
TEST(TuringMachineFactory, isAnyProgramStillRunningFalse) {
	TuringMachine turingMachineA;
	turingMachineA.tape.fill("0A00");
	TuringMachine turingMachineB;
	turingMachineB.tape.fill("0A00");

	Program programA;
	programA.instructionLines.push_back(InstructionLine("0", '0', 'B', 'R', "1"));
	programA.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', 'A', 'L', "1"));
	programB.instructionLines.push_back(InstructionLine("1", '_', '0', 'R', "Halt"));

	std::vector<Program> programs;
	programs.push_back(programA);
	programs.push_back(programB);

	TuringMachineFactory turingMachineFactory;
	turingMachineFactory.machines.push_back(turingMachineA);
	turingMachineFactory.machines.push_back(turingMachineB);

	turingMachineFactory = turingMachineFactory.makeStepForAllMachines(programs);
	turingMachineFactory = turingMachineFactory.makeStepForAllMachines(programs);

	ASSERT_FALSE(turingMachineFactory.isAnyProgramStillRunning());
}
TEST(TuringMachineFactory, runTwoTuringMachines) {
	TuringMachine turingMachineA;
	turingMachineA.tape.fill("0A00");
	TuringMachine turingMachineB;
	turingMachineB.tape.fill("0A00");

	Program programA;
	programA.instructionLines.push_back(InstructionLine("0", '0', 'B', 'R', "1"));
	programA.instructionLines.push_back(InstructionLine("1", 'A', '0', '*', "Halt"));

	Program programB;
	programB.instructionLines.push_back(InstructionLine("0", '0', 'A', 'L', "1"));
	programB.instructionLines.push_back(InstructionLine("1", '_', '0', 'R', "Halt"));

	std::vector<Program> programs;
	programs.push_back(programA);
	programs.push_back(programB);

	TuringMachineFactory turingMachineFactory;
	turingMachineFactory.machines.push_back(turingMachineA);
	turingMachineFactory.machines.push_back(turingMachineB);

	turingMachineFactory.runAllMachines(programs, 0);

	ASSERT_TRUE(turingMachineFactory.machines[0].tape.equals(Tape("B000")));
	ASSERT_EQ(turingMachineFactory.machines[0].head, 1);

	ASSERT_TRUE(turingMachineFactory.machines[1].tape.equals(Tape("0AA00")));
	ASSERT_EQ(turingMachineFactory.machines[1].head, 0);
}
