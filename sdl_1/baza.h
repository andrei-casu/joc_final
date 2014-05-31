#ifndef sdl_1_baza_h
#define sdl_1_baza_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern TTF_Font* font;
//extern SDL_Rect piece[14];
//extern SDL_Rect per[4];

bool inter(SDL_Surface*, int, int, SDL_Surface*, int , int);
bool intersectie(int, int, int, int, int, int);
Uint32 pixel(SDL_Surface*, int, int);

extern int SCREEN_FPS;
extern int SCREEN_TICKS_PER_FRAME;

extern int WINDOW_W, WINDOW_H;
//extern SDL_Texture* maint;

#endif
