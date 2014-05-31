#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <fstream>

#include "baza.h"
#include "surface.h"
#include "player.h"
#include "joc.h"

void joc_c::meniu()
{
    textcolor={255, 255, 255, 255};
	int now, last;

    bool quit=false;
    int next=0;

    //int mouse_x, mouse_y;
    SDL_Event* e_click;

    while(!quit && !next)
	{
		last=SDL_GetTicks();
		while(SDL_PollEvent(&e))
		{
			if(e.type==SDL_QUIT)
			{
				quit=true;
				exit(EXIT_SUCCESS);
			}
		}

		now=SDL_GetTicks();
		if (now-last<SCREEN_TICKS_PER_FRAME)
            SDL_Delay(SCREEN_TICKS_PER_FRAME-(now-last));

        SDL_RenderClear(renderer);
		meniu_img.render();

		b_start.render();
        b_shop.render();
        b_options.render();
        b_exit.render();

        e_click=&e;
        if(e_click->type == SDL_MOUSEBUTTONDOWN)
        {
            if (b_start.get_hov()) start();
            if (b_shop.get_hov()) shop();
            if (b_options.get_hov()) options();
            if (b_exit.get_hov()) exit_game();
        }

		FPS.record();
		// fps.load_from_text(to_string((int)FPS.get_fps()), textcolor);
		fps.render();
		fps.free();
		SDL_RenderPresent(renderer);
	}
}

void joc_c::start()
{
	bool quit=false;

	int i;
	textcolor={255, 255, 255, 255};
	int now, last;
	while( !quit )
	{
		last=SDL_GetTicks();
		while(SDL_PollEvent(&e))
		{
			if(e.type==SDL_QUIT)
			{
				quit=true;
				exit(EXIT_SUCCESS);
			}
		}
		SDL_SetRenderDrawColor(renderer, 53, 50, 50, 255);
		SDL_RenderClear(renderer);
		FPS.record();


		player.handle_event(e);
		player.render();

		for (i=0; i<50; ++i)
			if (fantoma_neagra[i].in_viata())
				fantoma_neagra[i].render();

		if (last-last_enemy>4000)
		{
			//sansa 50% dupa 2 secunda sa fie un inamic
			for (i=0; i<50; ++i)
				if (!fantoma_neagra[i].in_viata())
				{
					//o aduc la viata
					fantoma_neagra[i].set_viata(fantoma_neagra[i].get_viata_max());
					fantoma_neagra[i].set_xy(rand()%WINDOW_W, 0);
					fantoma_neagra[i].set_alive(true);
					last_enemy=last;
					break;
				}
		}

		now=SDL_GetTicks();
		if (now-last<SCREEN_TICKS_PER_FRAME)
			SDL_Delay(SCREEN_TICKS_PER_FRAME-(now-last));

		//fps.load_from_text(to_string((int)FPS.get_fps()), textcolor);
		fps.render();
		fps.free();
		SDL_RenderPresent(renderer);
	}
}

void joc_c::shop() {}
void joc_c::options() {}
void joc_c::exit_game() {exit(EXIT_SUCCESS);}

void joc_c::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	window=SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H,SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_GetWindowSize(window, &WINDOW_W, &WINDOW_H);

	renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );

	font=TTF_OpenFont("lazy.ttf", 28);

	player.set_nr_s(8);
	player.set_dmg(50);
	player.read("player.png");
	player.set_xy(200, WINDOW_H-150);
	player.set_viteza(400);
	player.set_mana_max(300);
	player.set_viata_max(1200);
	player.set_mana(300);
	player.set_viata(1200);
	player.set_radius(25);
	fantoma_neagra[0].set_nr_s(8);
	fantoma_neagra[0].set_radius(25);
	fantoma_neagra[0].read("fantoma_neagra.png");
	//fantoma_neagra[0].set_xy(rand()%WINDOW_W, 0);
	fantoma_neagra[0].set_viata_max(200);
	fantoma_neagra[0].set_viata(200);
	fantoma_neagra[0].set_viteza(8);
	int i;
	for (i=1; i<50; ++i)
	{
		fantoma_neagra[i]=fantoma_neagra[0];
		//fantoma_neagra[i].set_xy(0);
	}

	//pentru meniu
	b_start.create("START");
	b_shop.create("SHOP");
	b_options.create("OPTIONS");
	b_exit.create("EXIT");

	b_start.set_x(150); b_start.set_y(150);
	b_shop.set_x(150); b_shop.set_y(250);
	b_options.set_x(150); b_options.set_y(350);
	b_exit.set_x(150); b_exit.set_y(450);

	meniu_img.read("meniu.png");
	meniu_img.set_wh(WINDOW_W, WINDOW_H);
}

joc_c joc;
