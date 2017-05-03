#pragma once
#include <Windows.h>
#define ALLEGRO_STATICLINK
#include <iostream>
#include <string>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
//#define ALLEGRO_STATICLINK
using namespace std;

class GraphicInterface
{
public:
	ALLEGRO_DISPLAY * display;
	GraphicInterface(void);
	void timesLeft(int tl, float speed);
	void printPlatform(string);
	void header();
	void level1();
	void level2();
	int width, height, rows, columns;
	GraphicInterface(int width, int height);
	void start();
	void timesLeft(int);
	//void music();
	ALLEGRO_DISPLAY getDisplay();
	~GraphicInterface(void);
};

#pragma once
