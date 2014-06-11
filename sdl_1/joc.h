#ifndef sdl_1_joc_h
#define sdl_1_joc_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include "baza.h"
#include "surface.h"
#include "player.h"
#include "skills.h"
#include "buton.h"

class joc_c
{
	public:
	friend class proiectil_c;
	friend class skill_wrath_c;
	void init();
	void meniu();
	void picks();
	void start();
	void shop();
	void options();
	void exit_game();
	void instructiuni();

	private:
};

extern joc_c joc;

extern buton b_start, b_shop, b_options, b_exit;
extern surface meniu_img;
// pentru joc
extern playerr player;
extern enemy_c fantoma_neagra[50];
extern enemy_c schelet[50];
extern enemy_c liliac[50];
extern surface fps;
extern SDL_Event e;
extern SDL_Color textcolor;
extern int last_enemy;

extern buton wrath_poza[3];
extern buton wrath_enhance_text[2];
extern buton haunt_poza[3];
extern buton haunt_enhance_text[2];
extern buton ghost_poza[3];
extern buton ghost_enhance_text[2];
extern buton terror_poza[3];
extern buton terror_enhance_text[2];

extern buton start_text, instructiuni_text, back_text;

extern surface wrath_descr[3];
extern surface haunt_descr[3];
extern surface ghost_descr[3];
extern surface terror_descr[3];

extern surface t_wrath, t_haunt, t_ghost, t_terror;

extern int wrath;
extern int haunt;
extern int ghost;
extern int terror;

extern int wrath_enhance;
extern int haunt_enhance;
extern int ghost_enhance;
extern int terror_enhance;


extern surface select1, select2, select3, select4;

#endif
