//
//  joc.h
//  sdl_1
//
//  Created by Casuneanu Andrei on 25/05/14.
//  Copyright (c) 2014 Casuneanu Andrei. All rights reserved.
//

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


class joc_c//modifiiiiiic
{
	public:
	friend class proiectil_c;
	void init();
	void start();
	
	private:
	playerr player;
	enemy_c fantoma_neagra[50];
	surface fps;
	SDL_Event e;
	SDL_Color textcolor;
	int last_enemy;
};

extern joc_c joc;

#endif
