//
//  player.cpp
//  sdl_1
//
//  Created by Casuneanu Andrei on 22/05/14.
//  Copyright (c) 2014 Casuneanu Andrei. All rights reserved.
//

#include "player.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include "baza.h"
#include "joc.h"
#include "surface.h"
using namespace std;

void proiectil_c::read(string nume)
{
	sur=IMG_Load(nume.c_str());
	tex=SDL_CreateTextureFromSurface(renderer, sur);
	w=sur->w/nr_sprites;
	h=sur->h;
	poz.w=w;
	poz.h=h;
	sour[0]={0, 0, w, h};
	int i;
	for (i=1; i<nr_sprites; ++i)
	{
		sour[i]=sour[0];
		sour[i].x=i*w;
	}
	active=false;
	
	xm=w/2;
	ym=h/2;
}

void proiectil_c::start()
{
	x=x1; y=y1;
	start_ticks=SDL_GetTicks();
	active=true;
}

void proiectil_c::render()
{
	//////////////
	ticks=SDL_GetTicks();
	int dd=viteza*((double)ticks-start_ticks)/100;
	int dx=x-x2, dy=y-y2;
	if (!dx) dx=1; if (!dy) dy=1;
	int d=sqrt((double)(dx*dx+dy*dy));
	int mx, my;
	mx=((double)dx*dd)/d;
	if (mx<0) mx=-mx;
	my=((double)dy*dd)/d;
	if (my<0) my=-my;
	
	if (x1<x2) x+=mx;
	else x-=mx;
	
	if (y1<y2) y+=my;
	else y-=my;
	
	poz.x=x;
	poz.y=y;
	SDL_RenderCopy(renderer, tex, &sour[(int)((double)frames*MULTIPLIER/(FPS.get_fps()))%nr_sprites], &poz);
	
	++frames;
	if (frames>2000000) frames-=1800000;
	start_ticks=ticks;
	
	mx=x-x2;
	if (mx<0) mx=-mx;
	my=y-y2;
	if (my<0) my=-my;
	
	if (mx<10 && my<10) active=false;
	
	///////verific daca a lovit ceva
	int i;
	int x_tinta, y_tinta;
	if (bun==true)
	{
		for (i=0; i<50; ++i)
			if (joc.fantoma_neagra[i].get_viata())
			{
				joc.fantoma_neagra[i].get_xy(x_tinta, y_tinta);
				//if (inter(joc.fantoma_neagra[i].sur_c, x_tinta, y_tinta, sur_c, x, y))
				//if (mx<10 && my<10)
				if (intersectie(x, y, radius, x_tinta, y_tinta, joc.fantoma_neagra[i].get_radius()))
				{
					joc.fantoma_neagra[i].set_viata(joc.fantoma_neagra[i].get_viata()-dmg);
					active=false;
				}
			}
	}
	//else
	//{
	//}
	
	
}

void playerr::read(string nume)
{
	sur=IMG_Load(nume.c_str());
	tex=SDL_CreateTextureFromSurface(renderer, sur);

	w=sur->w/nr_sprites;
	h=sur->h;
	
	//test.set_nr_sprites(4);
	//test.read("steluta.png");
	//test.set_viteza(50);
	
	int i;
	atac[0].set_nr_sprites(4);
	atac[0].set_radius(18);
	atac[0].read("atac.png");
	atac[0].set_viteza(50);
	atac[0].set_multiplier(24);
	atac[0].set_dmg(dmg);
	for (i=1; i<12; ++i)
		atac[i]=atac[0];
	
	sour[0]={0, 0, w, h};
	for (i=1; i<nr_sprites; ++i)
	{
		sour[i]=sour[0];
		sour[i].x=w*i;
	}
	xm=w/2;
	ym=h/2;
}

void playerr::render()
{
	poz={x, y, w, h};
	poz_viata={x, y-20, (viata*w)/viata_max, 10};//latime drept viata=20
	
	int i;
	for (i=0; i<12; ++i)
		if (atac[i].exista())
			atac[i].render();
			
	poz_mana={x, y-20+10, (mana*w)/mana_max, 5};
	SDL_RenderCopy(renderer, tex, &sour[(int)((double)frames*10/(FPS.get_fps()))%nr_sprites], &poz);
	//verde
	SDL_SetRenderDrawColor(renderer, 50, 255, 50, 255);
	SDL_RenderFillRect(renderer, &poz_viata);
	
	//albastru
	SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);
	SDL_RenderFillRect(renderer, &poz_mana);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	//if (test.exista())
	//	test.render();
	
	++frames;
	if (frames>2000000) frames-=1800000;
}

void playerr::handle_event(SDL_Event e)
{
	int i, d_pana_mij;
	const Uint8* keys=SDL_GetKeyboardState(NULL);
	ticks=SDL_GetTicks();
	int d=viteza*((double)ticks-start_ticks)/1000;
	if (keys[SDL_SCANCODE_LEFT])
		x-=d;
	else if (keys[SDL_SCANCODE_RIGHT])
		x+=d;
	else if (keys[SDL_SCANCODE_SPACE])
	{
		if (ticks-last_space>400)
			for (i=0; i<12; ++i)
				if (!atac[i].exista())
				{
					d_pana_mij=(w-atac[i].get_width())/2;
					atac[i].set_xxyy(x+d_pana_mij, y, x+d_pana_mij, 0);
					atac[i].set_bun(true);
					atac[i].start();
					last_space=ticks;
					break;
				}
	}
	
	if (x+w>WINDOW_W) x=WINDOW_W-w;
	if (x<0) x=0;
		
	start_ticks=SDL_GetTicks();
}


void enemy_c::read(string nume)
{
	sur=IMG_Load(nume.c_str());
	tex=SDL_CreateTextureFromSurface(renderer, sur);
	
	w=sur->w/nr_sprites;
	h=sur->h;
	
	atac.set_nr_sprites(1);
	atac.read("atac_fantoma_neagra.png");
	atac.set_viteza(50);
	atac.set_multiplier(24);
	
	sour[0]={0, 0, w, h};
	int i;
	for (i=1; i<nr_sprites; ++i)
	{
		sour[i]=sour[0];
		sour[i].x=w*i;
	}
	xm=w/2;
	ym=h/2;
}

void enemy_c::render()
{
	
	if (!viata)
	{
		//a murit
		alive=false;
		return;
	}
	
	poz={x, y, w, h};
	poz_viata={x, y-20, (viata*w)/viata_max, 10};//latime drept viata=20
	
	if (atac.exista())
		atac.render();
	
	ticks=SDL_GetTicks();
	int dd=viteza*((double)ticks-start_ticks)/100;
	int dx=x-x2, dy=y-y2;
	if (!dx) dx=1; if (!dy) dy=1;
	int d=sqrt((double)(dx*dx+dy*dy));
	int mx, my;
	mx=((double)dx*dd)/d;
	if (mx<0) mx=-mx;
	my=((double)dy*dd)/d;
	if (my<0) my=-my;
	
	if (x<x2) x+=mx;
	else x-=mx;
	
	if (y<y2) y+=my;
	else y-=my;
	
	poz.x=x;
	poz.y=y;
	
	++frames;
	if (frames>2000000) frames-=1800000;
	start_ticks=ticks;
	
	mx=x-x2;
	if (mx<0) mx=-mx;
	my=y-y2;
	if (my<0) my=-my;
	
	if (mx<10 && my<10) alive=false;
	
	SDL_RenderCopy(renderer, tex, &sour[(int)((double)frames*10/(FPS.get_fps()))%nr_sprites], &poz);
	//verde
	SDL_SetRenderDrawColor(renderer, 50, 255, 50, 255);
	SDL_RenderFillRect(renderer, &poz_viata);
	
	//albastru
	SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	++frames;
	if (frames>2000000) frames-=1800000;
}