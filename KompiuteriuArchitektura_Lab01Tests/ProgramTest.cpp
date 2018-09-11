#include "pch.h"
#include "../KompiuteriuArchitektura_Lab01/Program.cpp"
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