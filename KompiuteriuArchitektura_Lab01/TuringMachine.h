#pragma once
#include <vector>
class TuringMachine
{
public:
	std::vector<char> tape;
	int head = 0;
	TuringMachine();
	~TuringMachine();
	int makeStep();
};

