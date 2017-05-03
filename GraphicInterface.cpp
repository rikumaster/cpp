#include "GraphicInterface.h"
#include <memory>

GraphicInterface::GraphicInterface(int width,int height)
{
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	//al_install_audio();
	//al_init_acodec_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED);
	columns = height;
	columns = width;
	
	rows = 800/columns;
	
	//columns = (width - 500) / 20;
	display = al_create_display(1300, 600);
	al_set_window_title(display, "GRA W ZYCIE");
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
}

void GraphicInterface::start() {
	//unique_ptr <const ALLEGRO_FONT> font_48(al_load_font("Black.ttf", 36, NULL);
	ALLEGRO_FONT * font_48 = al_load_font("Black.ttf", 36, NULL);
	al_draw_filled_rectangle(800, 0, 1300, 600, al_map_rgb(0, 0, 0));
	al_draw_text(font_48, al_map_rgb(255, 255, 255), 1050, 150, ALLEGRO_ALIGN_CENTRE, "Gra w zycie");
	al_draw_text(font_48, al_map_rgb(255, 255, 255), 1050, 200, ALLEGRO_ALIGN_CENTRE, "spacja by rozpaczac");
	al_draw_text(font_48, al_map_rgb(255, 255, 255), 1050, 300, ALLEGRO_ALIGN_CENTRE, "[Losuj]");
	//delete font_48;
	al_destroy_font(font_48);
}

//void GraphicInterface::music() {
//	ALLEGRO_SAMPLE * song = al_load_sample("Lost_Time.wav");
//	al_reserve_samples(1);
//	ALLEGRO_SAMPLE_INSTANCE * songInstance = al_create_sample_instance(song);
//	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
//	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
//	al_play_sample_instance(songInstance);
//}

void GraphicInterface::timesLeft(int tl, float speed) {
	stringstream convert;
	convert << tl;
	string r = convert.str();
	convert.str(string());
	convert << speed;
	convert << " %";
	string spd = convert.str();
	al_draw_filled_rectangle(800, 0, 1300, 600, al_map_rgb(0, 0, 0));
	ALLEGRO_FONT * font_48 = al_load_font("Black.ttf", 36, NULL);
 	al_draw_text(font_48, al_map_rgb(255, 255, 255), 1050, 150, ALLEGRO_ALIGN_CENTRE, "Wykonane iteracje");
	al_draw_text(font_48, al_map_rgb(255, 255, 255), 1050, 200, ALLEGRO_ALIGN_CENTRE, r.c_str());
	al_draw_text(font_48, al_map_rgb(255, 255, 255), 1050, 250, ALLEGRO_ALIGN_CENTRE, "Aktualna predkosc");
	al_draw_text(font_48, al_map_rgb(255, 255, 255), 1050, 300, ALLEGRO_ALIGN_CENTRE, spd.c_str());
	//delete font_48;
	al_destroy_font(font_48);
}


void GraphicInterface::printPlatform(string plat) {
	int r = 0; int c = 0;
	int aux = plat.length();

	for (int i = 0; i < plat.length(); i++)
		if (plat[i] == 'O') {
			al_draw_rectangle(r * rows, c * rows, r * rows + rows, c * rows + rows, al_map_rgb(0, 0, 0), 1);
			al_draw_filled_rectangle(r * rows, c * rows, r * rows + rows, c * rows + rows, al_map_rgb(255, 255, 255));
			r++;
		}
		else if (plat[i] == '-') {
			al_draw_rectangle(r * rows, c * rows, r * rows + rows, c * rows + rows, al_map_rgb(0, 0, 0), 1);
			al_draw_filled_rectangle(r * rows, c * rows, r * rows + rows, c * rows + rows, al_map_rgb(0, 0, 0));
			r++;

		}
		else if (plat[i] == '\n') {
			r = 0;
			c++;
		}
		al_flip_display();
}

GraphicInterface::~GraphicInterface(void)
{
	al_destroy_display(display);
}
