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
	void read();
	void render();
	void start();
	bool get_in_action() {return in_action;}
	void handle_event(SDL_Event&);
	
	void setxpyp(int x, int y) {xp=x; yp=y;}

	private:
	proiectil_c bolt;
	int enhance;
	SDL_Rect poz;
	SDL_Texture* icon_bolt;
	int x, y;
	int xp, yp;//x si y player
	int dmg;
	int tip;//bolt, spread the dead, anger
	bool in_action;//daca se intampla
	int ticks_end;
	int cooldown;//in ticks

};

#endif
