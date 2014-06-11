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

void skill_wrath_c::read()
{
	bolt.set_nr_sprites(1);
	bolt.read("bolt.png");
	bolt.set_bun(true);
	bolt.set_dmg(dmg);
	bolt.set_radius(30);
}

void skill_wrath_c::handle_event(SDL_Event &e)
{
	const Uint8* keys=SDL_GetKeyboardState(NULL);
	int ticks=SDL_GetTicks();
	if (keys[SDL_SCANCODE_Q] && ticks>ticks_end+cooldown)
	{
		
	}
}