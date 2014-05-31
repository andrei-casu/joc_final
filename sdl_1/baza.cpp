//
//  baza.cpp
//  sdl_1
//
//  Created by Casuneanu Andrei on 20/05/14.
//  Copyright (c) 2014 Casuneanu Andrei. All rights reserved.
//

#include "baza.h"
#include "player.h"
#include "surface.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

SDL_Renderer* renderer;
SDL_Window* window;
TTF_Font* font;
//SDL_Texture* maint;
//SDL_Rect piece[14];
//SDL_Rect per[4];

int SCREEN_FPS = 80;
int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


int WINDOW_W, WINDOW_H;

bool inter(SDL_Surface *unu, int x1, int y1, SDL_Surface *doi, int x2, int y2)
{
	Uint32 *p1, *p2;
	p1=(Uint32 *)unu->pixels;
	p2=(Uint32 *)doi->pixels;
	
	int xc1, yc1, xc2, yc2;
	
	xc1=x1; if (xc1<x2) xc1=x2;
	yc1=y1; if (yc1<y2) yc1=y2;
	
	xc2=x1+unu->w;
	if (xc2>x2+doi->w)
		xc2=x2+doi->w;
		
	yc2=y1+unu->h;
	if (yc2>y2+doi->h)
		yc2=y2+doi->h;
	
	int i, j;
	int a, b;
	for (i=xc1; i<=xc2; ++i)
		for (j=yc1; j<=yc2; ++j)
		{
			a=pixel(unu, i-x1, j-y1);
			b=pixel(doi, i-x2, j-y2);
			if (a==b && a && b)
				return true;
		}
	
	//false dac nu se intersecteaza
	return false;
}

Uint32 pixel(SDL_Surface *surface, int x, int y)
{
    Uint32 *pixels=(Uint32 *)surface->pixels;
    return pixels[x+(y*surface->w)];
}

bool intersectie(int x1, int y1, int r1, int x2, int y2, int r2)
{
	int dx, dy;
	dx=x1-x2;
	dy=y1-y2;
	int d=dx*dx+dy*dy;//distanta la patrat dintre cele 2 centre ale cercurilor
	return d<(r1+r2)*(r1+r2);
}