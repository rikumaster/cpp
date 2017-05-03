#pragma once
#include "Cell.h"
class Platform
{
private:
	Cell *** matrix;
	int rows;
	int columns;
public:
	Platform(int, int);
	int getRows();
	int getColumns();
	int getPoupulation();
	void setRows(int);
	void setColumns(int);
	void activateCell(int, int);
	void disactivateCell(int, int);
	void randomGrid();
	void setNextState(int, int, bool);
	bool getState(int, int);
	void restart();
	void update();
	void changeState(int, int);
	string toString();
	~Platform(void);
};

