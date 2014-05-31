#ifndef sdl_1_skills_h
#define sdl_1_skills_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include "baza.h"
#include "surface.h"
#include "player.h"
using namespace std;

class skill_wrath_c
{
	public:
	void read(string);
	void render();
	void start();

	private:
	SDL_Surface* s_icon;
	SDL_Texture* t_icon;
	SDL_Rect poz;
	int w, h, x, y;
	int tip;//bolt, spread the dead, anger

};

#endif
