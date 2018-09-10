#pragma once
#include "TuringMachine.h"
class FileInteractor
{
public:
	FileInteractor();
	~FileInteractor();
	TuringMachine getTuringMashineFromFile(std::string fileName);
	Program getProgramFromFile(std::string fileName);
};

