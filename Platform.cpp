#include "Platform.h"


Platform::Platform(int r, int c)
{
	matrix = new Cell**[rows = r];
	for (int i = 0; i < rows; i++)
	matrix[i] = new Cell *[columns = c];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			matrix[i][j] = new Cell();
	}
}

int Platform::getRows() { return rows; }

int Platform::getColumns() { return columns; }

void Platform::setRows(int nr) { rows = nr; }

void Platform::setColumns(int nc) { columns = nc; }

void Platform::activateCell(int r, int c) {
	matrix[r][c]->setState(true);
}

void Platform::disactivateCell(int r, int c) {
	matrix[r][c]->setState(false);
}
void Platform::randomGrid() {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int random = rand() % 9;
			if(random>5)
				matrix[i][j]->setState(true);
			else
				matrix[i][j]->setState(false);

		}
	}
}

bool Platform::getState(int r, int c) {
	return matrix[r][c]->getState();
}

void Platform::setNextState(int r, int c, bool ns) {
	matrix[r][c]->setNextState(ns);
}

void Platform::changeState(int r, int c) {
	matrix[r][c]->setState(!matrix[r][c]->getState());
}

string Platform::toString() {
	stringstream s;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] != NULL)
				s << matrix[i][j]->toString() << " ";
		s << endl;
	}
	return s.str();
}

void Platform::restart() {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] != NULL)
				disactivateCell(i, j);
}

int Platform::getPoupulation() {
	int result = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j]->getState())
				result++;
	return result;
}

void Platform::update() {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j] != NULL)
				matrix[i][j]->setState(matrix[i][j]->getNextState());
}

Platform::~Platform(void)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (matrix[i][j])
				delete matrix[i][j];
	for (int i = 0; i < rows; i++)
		if (matrix[i])
			delete[] matrix[i];
	if (matrix)
		delete[]matrix;
}
