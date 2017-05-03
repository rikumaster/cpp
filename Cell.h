#pragma once
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
class Cell
{
private:
	bool state;
	bool nextState;
public:
	Cell(void);
	bool getState();
	void setState(bool);
	bool getNextState();
	void setNextState(bool);
	string toString();
	~Cell(void);
};

#pragma once
