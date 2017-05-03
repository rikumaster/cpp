#include "Control.h"


Control::Control(int width, int height)
{
	gi = new GraphicInterface(width, height);
	rows = height;
	columns = width;
}

void Control::initializePlatform(int r, int c) {
	plat = new Platform(r, c);
}

void Control::generateLife() {
	initializePlatform(rows, columns);
	int row, column = 0;
	bool quit = false;
	bool evolving = false;
	bool activated = false;
	gi->start();
	//gi->music();
	ALLEGRO_EVENT_QUEUE *event = al_create_event_queue();
	al_register_event_source(event, al_get_mouse_event_source());
	al_register_event_source(event, al_get_display_event_source(gi->display));

	/*ALLEGRO_EVENT_QUEUE *evento2 = al_create_event_queue();
	al_register_event_source(evento2, al_get_mouse_event_source());
	al_register_event_source(evento2, al_get_display_event_source(gi->display));
	ALLEGRO_MOUSE_STATE mouseState;
	ALLEGRO_KEYBOARD_STATE keyboardState;*/

	al_register_event_source(event, al_get_keyboard_event_source());
	gi->printPlatform(plat->toString());
	
	while (!quit) {
		ALLEGRO_EVENT e;
		al_wait_for_event(event, &e);

		if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (e.mouse.button & 1) {
				row = e.mouse.y;
				column = e.mouse.x;
				row = mapping(row, 0, 600, 0, rows);
				column = mapping(column, 0, 800, 0, columns);
				if (row < rows && column < columns)
					plat->changeState(row, column);
				else
					plat->randomGrid();
				gi->printPlatform(plat->toString());
			}
		}
		else if (e.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (e.keyboard.keycode == ALLEGRO_KEY_SPACE)
			{	
				al_flush_event_queue(event);
				evolve(event);
				al_flush_event_queue(event);
			}

		}
		else if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { quit = true; }
	}
}

void Control::evolve(ALLEGRO_EVENT_QUEUE *event2) {
	ALLEGRO_TIMER *timer = NULL;
	bool redraw = false;
	bool con = false;
	float speed = 100.0;
	timer = al_create_timer(100/speed);
	
	al_start_timer(timer);
	al_register_event_source(event2, al_get_timer_event_source(timer));
	int x = 1;
		while (!con)
		{
			ALLEGRO_EVENT e2;
			al_wait_for_event(event2, &e2);

			if (e2.type == ALLEGRO_EVENT_TIMER) {
				redraw = true;
			}
			else if (e2.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (e2.keyboard.keycode) {
				case ALLEGRO_KEY_SPACE:
					while (1)
					{
						al_wait_for_event(event2, &e2);
						if (e2.type == ALLEGRO_EVENT_KEY_DOWN)
							break;
						else if (e2.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
							con = true;
							break;
						}
					}
					break;
				case ALLEGRO_KEY_UP:
						speed *= 2;
						al_set_timer_speed(timer, 100 / speed);
						break;
				case ALLEGRO_KEY_DOWN:
							speed /= 2;
							al_set_timer_speed(timer, 100 / speed);
							break;
				}
			}
			else if (e2.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				con = true;
			}
		
			if (redraw) {
				redraw = false;
				for (int i = 0; i < plat->getRows(); i++)
				{
					for (int j = 0; j < plat->getColumns(); j++)
					{
						int neighbords = lateralNeighbords(i, j) + diagonalNeighbords(i, j);
						if (neighbords < 2)
							plat->setNextState(i, j, false);
						if (neighbords > 3)
							plat->setNextState(i, j, false);
						if (plat->getState(i, j)) {
							if (neighbords == 3 || neighbords == 2)
								plat->setNextState(i, j, true);
						}
						else if (!plat->getState(i, j) && neighbords == 3)
							plat->setNextState(i, j, true);

					}
				}
					gi->timesLeft(x, speed);
					//gi->printPlatform(plat->toString());
					//Sleep(400);
					plat->update();
					gi->printPlatform(plat->toString());
					x++;
				
			}
		}
		
	al_destroy_timer(timer);
	
	gi->start();
	al_flip_display();
	
}

int Control::lateralNeighbords(int i, int j) {
	int result = 0;
	if (j - 1 >= 0)
		result += plat->getState(i, j - 1);
	if (j + 1 < plat->getColumns())
		result += plat->getState(i, j + 1);
	if (i - 1 >= 0)
		result += plat->getState(i - 1, j);
	if (i + 1 < plat->getRows())
		result += plat->getState(i + 1, j);
	return result;
}

int Control::diagonalNeighbords(int i, int j) {
	int result = 0;
	if (j - 1 >= 0 && i - 1 >= 0)
		result += plat->getState(i - 1, j - 1);
	if (j + 1 < plat->getColumns() && i - 1 >= 0)
		result += plat->getState(i - 1, j + 1);
	if (j - 1 >= 0 && i + 1 < plat->getRows())
		result += plat->getState(i + 1, j - 1);
	if (j + 1 < plat->getColumns() && i + 1 < plat->getRows())
		result += plat->getState(i + 1, j + 1);
	return result;
}


int Control::mapping(int num, int minin, int maxin, int minout, int maxout) {
	return (num - minin) * (maxout - minout) / (maxin - minin) + minout;
}


Control::~Control(void)
{
	delete plat;
	delete gi;
}
