#include "Cell.h"


Cell::Cell(void)
{
	state = false;
	nextState = false;
}

bool Cell::getState() {
	return state;
}

void Cell::setState(bool ns) {
	state = ns;
}

bool Cell::getNextState() {
	return nextState;
}

void Cell::setNextState(bool ns) {
	nextState = ns;
}

string Cell::toString() {
	stringstream s;
	if (state)
		s << "O";
	else
		s << "-";
	return s.str();
}

Cell::~Cell(void)
{
	state = false;
}
