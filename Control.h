#pragma once
#include "Platform.h"
#include "GraphicInterface.h"
#include <time.h>
class Control
{
private:
	Platform * plat;
	GraphicInterface * gi;
public:
	enum MYKEYS {
		KEY_UP, KEY_DOWN
	};
	Control(void);
	int mapping(int, int, int, int, int);
	Control(int width, int height);
	void initializePlatform(int, int);
	void generateLife();
	void evolve(ALLEGRO_EVENT_QUEUE * event2);
	void evolve();
	int rows;
	int columns;
	int lateralNeighbords(int, int);
	int diagonalNeighbords(int, int);
	~Control(void);
};

#pragma once
