#include "Program.h"



Program::Program()
{
}


Program::~Program()
{
}

std::vector<InstructionLine> Program::getLinesOfState(std::string state){
	std::vector<InstructionLine> linesOfState;
	for (InstructionLine instructionLine : instructionLines) 
		if (instructionLine.currentState == state)
			linesOfState.push_back(instructionLine);
	return linesOfState;
}
bool Program::equals(Program program) {
	return false;
}
