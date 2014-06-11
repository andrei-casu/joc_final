#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>

#include "baza.h"
#include "buton.h"
using namespace std;


void buton::select()
{
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(texture, (Uint8)a);
}

void buton::unselect()
{
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(texture, (Uint8)b);
}


buton::buton()
{
    surface = NULL;
    texture = NULL;
    nume="";
    x=0, y=0;
    w=0, h=0;
    hov=false;
    v=false;
    click=false;
}

buton::~buton()
{
    free();
}

void buton::free()
{
    SDL_FreeSurface(surface);
    SDL_DestroyTexture (texture);
    nume="";
    texture = NULL; w = 0; h = 0;
}

void buton::readf(string path)
{
    free();

    surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface (renderer, surface);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    w = surface->w;
    h = surface->h;
}

void buton::create(string path)
{
    free();
    color = { 0, 0, 0 };
    font = TTF_OpenFont( "font.ttf", 72 );

    surface = TTF_RenderText_Solid(font, path.c_str(), color);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    nume+=path;
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    w = surface->w;
    h = surface->h;

    hov=false;
}

bool buton::hover()
{
    int mouse_x, mouse_y;
    SDL_GetMouseState( &mouse_x, &mouse_y );
    if (x<=mouse_x && mouse_x<=x+w && y<=mouse_y && mouse_y<=y+h) return true;
    return false;
}

void buton::render()
{
    if (hover() && !hov) {hov=true; select();}
    if (!hover() && hov) {hov=false; unselect();}

    SDL_Rect render_q = {x, y, w, h};
    SDL_RenderCopy (renderer, texture, NULL, &render_q);
}

void buton::create_hover()
{
    color = { 255, 255, 255 };
    font = TTF_OpenFont( "font.ttf", 72 );

    surface = TTF_RenderText_Solid(font, nume.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    hov=true;
}

void buton::create_no_hover()
{
    color = { 0, 0, 0 };
    font = TTF_OpenFont( "font.ttf", 72 );

    surface = TTF_RenderText_Solid(font, nume.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    hov=false;
}

void buton::on_click()
{
	return;
}
