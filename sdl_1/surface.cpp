//
//  surface.cpp
//  sdl_1
//
//  Created by Casuneanu Andrei on 20/05/14.
//  Copyright (c) 2014 Casuneanu Andrei. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "surface.h"
#include "baza.h"
using namespace std;

void frames_per_second::record()
{
	++frames;
	if (frames>2000000) frames-=1800000;
	now=SDL_GetTicks();
	if (now-last>1000)
	{
		fps=frames/(((double)now-last)/1000.f);
		last=now;
		frames=0;
	}
}

double frames_per_second::get_fps()
{
	return fps;
}

void surface::free()
{
	SDL_FreeSurface(sur);
	SDL_DestroyTexture(tex);
}

void surface::load_from_text(string text, SDL_Color color)
{
	sur=TTF_RenderText_Solid(font, text.c_str(), color);
	tex=SDL_CreateTextureFromSurface(renderer, sur);
	w=sur->w;
	h=sur->h;
}

bool surface::read(string name)
{
	SDL_Surface* sur;
	sur=IMG_Load(name.c_str());
	tex=SDL_CreateTextureFromSurface(renderer, sur);
	
	SDL_Rect dim;
	SDL_GetClipRect(sur, &dim);
	w=dim.w;
	h=dim.h;
	
	if (sur==NULL || tex==NULL) return false;
	return true;
}

bool surface::render()
{
	int curent;
	
	if (mx || my)
	{
		curent=SDL_GetTicks();
		
		if (!inceput) {inceput=curent;last_tick=curent;}
		
		x+=((curent-last_tick)*mx/1000);
		y+=((curent-last_tick)*my/1000);
		last_tick=curent;
		
		if ((curent-inceput)/1000>=sec)
		{
			inceput=0;
			mx=0; my=0;
			sec=0;
		}
	}
	
	poz={x, y, w, h};
	if (poz.w)
		SDL_RenderCopy(renderer, tex, NULL, &poz);
	else
		SDL_RenderCopy(renderer, tex, NULL, NULL);
	return true;
}

surface::~surface()
{
	//SDL_DestroyTexture(tex);
	//SDL_FreeSurface(sur);
}

frames_per_second FPS;
//perete wall;