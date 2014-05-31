#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include "baza.h"
#include "surface.h"
#include "player.h"
#include "joc.h"
using namespace std;

surface test;

int main(int argc, char* args[])
{
	joc.init();
	joc.start();
	return 0;
}
//okay, se compileaza deci e bine
