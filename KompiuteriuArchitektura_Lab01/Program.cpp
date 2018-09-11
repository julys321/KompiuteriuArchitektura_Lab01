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
InstructionLine Program::findInstructionline(char currentCharacter,std::string state) {//TODO: unit tests
	for (InstructionLine instructionLine : instructionLines) {
		if (currentCharacter == instructionLine.currentSymbol && (state.compare(instructionLine.currentState) == 0)) {
			return instructionLine;
		}
	}
	std::string string;
	string.push_back(currentCharacter);
	throw  "Exception cought at findInstructionline: No instructions exist for state: " + state + " character at head: " + string + "\n";
}
