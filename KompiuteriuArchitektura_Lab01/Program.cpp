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
	if (program.instructionLines.size() != instructionLines.size())
		return false;
	for (int i = 0; i < instructionLines.size(); i++) {
		if (!instructionLines[i].equals(program.instructionLines[i])) {
			return false;
		}
	}
	return true;
}
