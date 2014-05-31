#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>
#include "baza.h"
#include "buton.h"

#include <iostream>
using namespace std;

buton::buton()
{
    surface = NULL;
    texture = NULL;
    x=0, y=0;
    w=0, h=0;
    v=false, click=false;
}

buton::~buton()
{
    SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void buton::free()
{
    SDL_DestroyTexture (texture);
    texture = NULL; w = 0; h = 0;
}

void buton::readf(string path)
{
    free();

    surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface (renderer, surface);
    w = surface->w;
    h = surface->h;
}

void buton::create(string path)
{
    free();
    SDL_Color color; color = { 0, 0, 0 };
    TTF_Font* font; font = TTF_OpenFont( "lazy.ttf", 28 );

    surface = TTF_RenderText_Solid(font, path.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    w = surface->w;
    h = surface->h;
}

void buton::set_x(int val)
{
    x=val;
}
void buton::set_y(int val)
{
    y=val;
}
void buton::set_w(int val)
{
    w=val;
}
void buton::set_h(int val)
{
    h=val;
}
void buton::set_v(bool val)
{
    v=val;
}
void buton::set_click(bool val)
{
    click=val;
}

int buton::get_x()
{
    return x;
}
int buton::get_y()
{
    return y;
}
int buton::get_w()
{
    return w;
}
int buton::get_h()
{
    return h;
}
bool buton::get_v()
{
    return v;
}
bool buton::get_click()
{
    return click;
}

void buton::render()
{
    SDL_Rect render_q = {x, y, w, h};
    SDL_RenderCopy (renderer, texture, NULL, &render_q);
}

void buton::on_click()
{
	return;
}
