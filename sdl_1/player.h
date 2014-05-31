//
//  player.h
//  sdl_1
//
//  Created by Casuneanu Andrei on 22/05/14.
//  Copyright (c) 2014 Casuneanu Andrei. All rights reserved.
//

#ifndef sdl_1_player_h
#define sdl_1_player_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "baza.h"
#include <cstring>
#include <fstream>
using namespace std;

class playerr;
class proiectil_c;

class proiectil_c
{
	public:
	int get_width() {return w;}
	int get_height() {return h;}
	void read(string);
	void render();
	void set_xxyy(int xx1, int yy1, int xx2, int yy2) {x1=xx1; x2=xx2; y1=yy1; y2=yy2;}
	void set_dmg(int x) {dmg=x;}
	void set_nr_sprites(int x) {nr_sprites=x;}
	void set_viteza(int x) {viteza=x;}
	void start();
	bool exista() {return active;}
	void set_multiplier(int x) {MULTIPLIER=x;}
	int get_multiplier() {return MULTIPLIER;}
	void set_bun(bool x) {bun=x;}
	bool get_bun() {return bun;}
	void set_radius(int x) {radius=x;}
	int get_radius() {return radius;}
	
	private:
	SDL_Surface* sur;
	SDL_Texture* tex;
	SDL_Rect poz;
	SDL_Rect sour[16];
	int radius;
	int xm, ym;
	bool active;
	bool bun;
	int x1, y1, x2, y2;
	int x, y;
	int w, h;
	int nr_sprites;
	int start_ticks, ticks, frames;
	int dmg;
	int MULTIPLIER;
	int viteza;
};

class enemy_c
{
	public:
	friend class proiectil_c;
	void read(string);
	void get_xy(int &a, int &b) {a=x; b=y;}
	void set_xy(int a, int b) {x=a; y=b; x2=a; y2=WINDOW_H; frames=0; start_ticks=ticks=SDL_GetTicks();}
	int get_viata() {return viata;}
	int get_viata_max() {return viata_max;}
	int get_viteza() {return viteza;}
	void handle_event(SDL_Event);
	void set_nr_s(int x) {nr_sprites=x;}
	void set_viteza(int x) {viteza=x;}
	void set_viata_max(int x) {viata_max=x;}
	void set_viata(int x) {if (x<=viata_max) viata=x; else viata=viata_max; if (x<0) viata=x;}
	void render();
	bool in_viata() {return alive;}
	void set_alive(bool a) {alive=a;}
	void set_radius(int x) {radius=x;}
	int get_radius() {return radius;}
	
	private:
	proiectil_c atac;
	SDL_Surface* sur;
	SDL_Texture* tex;
	SDL_Rect poz;
	SDL_Rect sour[16];
	SDL_Rect poz_viata;
	int radius;
	int xm, ym;
	int x, y;
	int x2, y2;
	int w, h;
	int nr_sprites;//current, numarul frameului curent si times de cate ori am facut un ciclu intreg
	int viteza, viata;
	int viata_max;
	int dmg;
	int frames;
	int start_ticks, ticks;
	int last_space;//ultim-ul hit
	bool alive;
};

class playerr
{
	public:
	void read(string);
	void get_xy(int &a, int &b) {a=x; b=y;}
	void set_xy(int a, int b) {x=a; y=b;}
	int get_viata() {return viata;}
	int get_viata_max() {return viata_max;}
	int get_mana() {return mana;}
	int get_mana_max() {return mana_max;}
	int get_viteza() {return viteza;}
	void handle_event(SDL_Event);
	void set_nr_s(int x) {nr_sprites=x;}
	void set_viteza(int x) {viteza=x;}
	void set_viata_max(int x) {viata_max=x;}
	void set_mana_max(int x) {mana_max=x;}
	void set_viata(int x) {if (x<=viata_max) viata=x; else viata=viata_max;}
	void set_mana(int x) {if (x<=mana_max) mana=x; else mana=mana_max;}
	void render();
	void set_dmg(int x) {dmg=x;}
	int get_dmg() {return dmg;}
	void set_radius(int x) {radius=x;}
	int get_radius() {return radius;}
	
	private:
	proiectil_c atac[12];
	SDL_Surface* sur;
	SDL_Texture* tex;
	SDL_Rect poz;
	SDL_Rect sour[16];
	SDL_Rect poz_viata, poz_mana;
	int radius;
	int xm, ym;
	int x, y;
	int w, h;
	int nr_sprites;//current, numarul frameului curent si times de cate ori am facut un ciclu intreg
	int viteza, viata, mana;
	int viata_max, mana_max;
	int dmg;
	int frames;
	int start_ticks, ticks;
	int last_space;//ultim-ul hit
};

#endif//am mai facut o modificare
