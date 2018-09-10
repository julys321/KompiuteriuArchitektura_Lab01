#pragma once
#include "TuringMachine.h"
class FileInteractor
{
public:
	FileInteractor();
	~FileInteractor();
	TuringMachine getTuringMashineFromStream(std::stringstream& in);
	TuringMachine getTuringMashineFromFile(std::string fileName);
	Program getProgramFromStream(std::stringstream& in);
	Program getProgramFromFile(std::string fileName);
};

