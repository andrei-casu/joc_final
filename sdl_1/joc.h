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
#include "buton.h"

class joc_c
{
	public:
	friend class proiectil_c;
	void init();
	void meniu();
	void start();
	void shop();
	void options();
	void exit_game();

	private:

    // pentru meniu
    buton b_start, b_shop, b_options, b_exit;
    surface meniu_img;
//////
    // pentru joc
	playerr player;
	enemy_c fantoma_neagra[50];
	surface fps;
	SDL_Event e;
	SDL_Color textcolor;
	int last_enemy;
};

extern joc_c joc;

#endif
