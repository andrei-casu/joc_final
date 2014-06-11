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
#include "skills.h"

buton b_start, b_shop, b_options, b_exit;
surface meniu_img;
// pentru joc
playerr player;
enemy_c fantoma_neagra[50];
enemy_c schelet[50];
enemy_c liliac[50];
surface fps;
SDL_Event e;
SDL_Color textcolor;
int last_enemy;

buton wrath_poza[3];
buton wrath_enhance_text[2];
buton haunt_poza[3];
buton haunt_enhance_text[2];
buton ghost_poza[3];
buton ghost_enhance_text[2];
buton terror_poza[3];
buton terror_enhance_text[2];

surface wrath_descr[3];
surface haunt_descr[3];
surface ghost_descr[3];
surface terror_descr[3];

buton start_text, instructiuni_text, back_text;

surface t_wrath, t_haunt, t_ghost, t_terror;

int wrath;
int haunt;
int ghost;
int terror;

surface select1, select2, select3, select4;


int wrath_enhance;
int haunt_enhance;
int ghost_enhance;
int terror_enhance;



void joc_c::instructiuni()
{
	int now, last;
	bool quit=false;
	
	SDL_Delay(100);
	
	while (!quit)
	{
		last=SDL_GetTicks();
		while (SDL_PollEvent(&e))
		{
			if (e.type==SDL_QUIT)
			{
				quit=true;
				exit(EXIT_SUCCESS);
			}
		}
		SDL_RenderClear(renderer);
		
		meniu_img.render();
		back_text.render();
		
		if (e.type==SDL_MOUSEBUTTONDOWN)
			if (back_text.hover())
			{
				SDL_Delay(100);
				return;
			}
		
		
		FPS.record();
		
		now=SDL_GetTicks();
		if (now-last<SCREEN_TICKS_PER_FRAME)
            SDL_Delay(SCREEN_TICKS_PER_FRAME-(now-last));
		
		SDL_RenderPresent(renderer);
	}
}



void joc_c::picks()
{
	int now, last;
	bool quit=false;
	t_wrath.load_from_text("Wrath", textcolor);
	t_haunt.load_from_text("Haunt", textcolor);
	t_ghost.load_from_text("Ghost", textcolor);
	t_terror.load_from_text("Terror", textcolor);
	
	int d, x;
	x=t_wrath.geth();
	d=(WINDOW_H-(4*x))/5;
	
	t_wrath.set_xy(10, d);
	t_haunt.set_xy(10, 2*d+x);
	t_ghost.set_xy(10, 3*d+2*x);
	t_terror.set_xy(10, 4*d+3*x);
	
	int y, s;
	s=t_terror.getw();
	x=wrath_poza[0].get_h();
	y=wrath_poza[0].get_w();
	d=(WINDOW_H-(4*x))/5;
	
	wrath_poza[0].set_x(20+s+0*y);
	wrath_poza[1].set_x(20+s+1*y);
	wrath_poza[2].set_x(20+s+2*y);
	
	haunt_poza[0].set_x(20+s+0*y);
	haunt_poza[1].set_x(20+s+1*y);
	haunt_poza[2].set_x(20+s+2*y);
	
	ghost_poza[0].set_x(20+s+0*y);
	ghost_poza[1].set_x(20+s+1*y);
	ghost_poza[2].set_x(20+s+2*y);
	
	terror_poza[0].set_x(20+s+0*y);
	terror_poza[1].set_x(20+s+1*y);
	terror_poza[2].set_x(20+s+2*y);
	
	wrath_poza[0].set_y(d);
	wrath_poza[1].set_y(d);
	wrath_poza[2].set_y(d);
	
	haunt_poza[0].set_y(2*d+x);
	haunt_poza[1].set_y(2*d+x);
	haunt_poza[2].set_y(2*d+x);
	
	ghost_poza[0].set_y(3*d+2*x);
	ghost_poza[1].set_y(3*d+2*x);
	ghost_poza[2].set_y(3*d+2*x);
	
	terror_poza[0].set_y(4*d+3*x);
	terror_poza[1].set_y(4*d+3*x);
	terror_poza[2].set_y(4*d+3*x);
	
	wrath_descr[0].set_xy(100+s+3*y, d);
	wrath_descr[1].set_xy(100+s+3*y, d);
	wrath_descr[2].set_xy(100+s+3*y, d);
	
	haunt_descr[0].set_xy(100+s+3*y, d);
	haunt_descr[1].set_xy(100+s+3*y, d);
	haunt_descr[2].set_xy(100+s+3*y, d);
	
	ghost_descr[0].set_xy(100+s+3*y, d);
	ghost_descr[1].set_xy(100+s+3*y, d);
	ghost_descr[2].set_xy(100+s+3*y, d);
	
	terror_descr[0].set_xy(100+s+3*y, d);
	terror_descr[1].set_xy(100+s+3*y, d);
	terror_descr[2].set_xy(100+s+3*y, d);
	
	int i;
	
	while (!quit)
	{
		last=SDL_GetTicks();
		while (SDL_PollEvent(&e))
		{
			if (e.type==SDL_QUIT)
			{
				quit=true;
				exit(EXIT_SUCCESS);
			}
		}
		SDL_RenderClear(renderer);
		
		meniu_img.render();
		
		start_text.render();
		instructiuni_text.render();
		
		t_wrath.render();
		t_haunt.render();
		t_ghost.render();
		t_terror.render();
		
		wrath_poza[0].render();
		wrath_poza[1].render();
		wrath_poza[2].render();
		
		haunt_poza[0].render();
		haunt_poza[1].render();
		haunt_poza[2].render();
		
		ghost_poza[0].render();
		ghost_poza[1].render();
		ghost_poza[2].render();
		
		terror_poza[0].render();
		terror_poza[1].render();
		terror_poza[2].render();
		
		select1.render();
		select2.render();
		select3.render();
		select4.render();
		
		if (e.type==SDL_MOUSEBUTTONDOWN)
			for (i=0; i<3; ++i)
			{
				if (e.button.button!=SDL_BUTTON_LEFT) break;
				if (wrath_poza[i].hover())
				{
					select1.set_xy(wrath_poza[i].get_x(), wrath_poza[i].get_y());
					wrath=i;
				}
				else if (haunt_poza[i].hover())
				{
					select2.set_xy(haunt_poza[i].get_x(), haunt_poza[i].get_y());
					haunt=i;
				}
				else if (ghost_poza[i].hover())
				{
					select3.set_xy(ghost_poza[i].get_x(), ghost_poza[i].get_y());
					ghost=i;
				}
				else if (terror_poza[i].hover())
				{
					select4.set_xy(terror_poza[i].get_x(), terror_poza[i].get_y());
					terror=i;
				}
				else if (start_text.hover())
				{
					start();
				}
				else if (instructiuni_text.hover())
				{
					instructiuni();
				}
			}
		
		for (i=0; i<3; ++i)
		{
			if (wrath_poza[i].hover()) {wrath_descr[i].render();}
			else if (haunt_poza[i].hover()) {haunt_descr[i].render();}
			else if (ghost_poza[i].hover()) {ghost_descr[i].render();}
			else if (terror_poza[i].hover()) {terror_descr[i].render();}
		}
		
		
		FPS.record();
		
		now=SDL_GetTicks();
		if (now-last<SCREEN_TICKS_PER_FRAME)
            SDL_Delay(SCREEN_TICKS_PER_FRAME-(now-last));
		
		SDL_RenderPresent(renderer);
	}
}



void joc_c::meniu()
{
    textcolor={255, 255, 255, 255};
	int now, last;

    bool quit=false;
    int next=0;

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

        SDL_RenderClear(renderer);
		meniu_img.render();

		b_start.render();
        b_shop.render();
        b_options.render();
        b_exit.render();

        e_click=&e;
        if(e_click->type == SDL_MOUSEBUTTONDOWN)
        {
            if (b_start.get_hov()) picks();
            if (b_shop.get_hov()) shop();
            if (b_options.get_hov()) options();
            if (b_exit.get_hov()) exit_game();
        }

		FPS.record();
		
		now=SDL_GetTicks();
		if (now-last<SCREEN_TICKS_PER_FRAME)
            SDL_Delay(SCREEN_TICKS_PER_FRAME-(now-last));

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
		for (i=0; i<50; ++i)
			if (schelet[i].in_viata())
				schelet[i].render();
				
		for (i=0; i<50; ++i)
			if (liliac[i].in_viata())
				liliac[i].render();

		if (last-last_enemy>4000)
		{
			//sansa 50% dupa 2 secunda sa fie un inamic
			if ((last-last_enemy)%3==0)
			for (i=0; i<50; ++i)
			{
				if (!fantoma_neagra[i].in_viata())
				{
					//o aduc la viata
					fantoma_neagra[i].set_viata(fantoma_neagra[i].get_viata_max());
					fantoma_neagra[i].set_xy((rand())%(WINDOW_W-100), 0);
					fantoma_neagra[i].set_alive(true);
					last_enemy=last;
					break;
				}
			}
			else if ((last-last_enemy)%3==2)
			for (i=0; i<50; ++i)
			{
				if (!schelet[i].in_viata())
				{
					//o aduc la viata
					schelet[i].set_viata(schelet[i].get_viata_max());
					schelet[i].set_xy((rand())%(WINDOW_W-100), 0);
					schelet[i].set_alive(true);
					last_enemy=last;
					break;
				}
			}
			else if ((last-last_enemy)%3==1)
				for (i=0; i<50; ++i)
				{
					if (!liliac[i].in_viata())
					{
						//o aduc la viata
						liliac[i].set_viata(liliac[i].get_viata_max());
						liliac[i].set_xy((rand())%(WINDOW_W-100), 0);
						liliac[i].set_alive(true);
						last_enemy=last;
						break;
					}
				}
		}
		
		FPS.record();

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

	font=TTF_OpenFont("font.ttf", 28);
	font_normal=TTF_OpenFont("font.ttf", 20);

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
	fantoma_neagra[0].set_radius(30);
	fantoma_neagra[0].read("fantoma_neagra.png");
	//fantoma_neagra[0].set_xy(rand()%WINDOW_W, 0);
	fantoma_neagra[0].set_viata_max(200);
	fantoma_neagra[0].set_viata(200);
	fantoma_neagra[0].set_viteza(20);
	int i;
	for (i=1; i<50; ++i)
	{
		fantoma_neagra[i]=fantoma_neagra[0];
		//fantoma_neagra[i].set_xy(0);
	}
	
	schelet[0].set_nr_s(8);
	schelet[0].set_radius(30);
	schelet[0].read("schelet.png");
	//fantoma_neagra[0].set_xy(rand()%WINDOW_W, 0);
	schelet[0].set_viata_max(200);
	schelet[0].set_viata(200);
	schelet[0].set_viteza(15);
	for (i=1; i<50; ++i)
	{
		schelet[i]=schelet[0];
		//fantoma_neagra[i].set_xy(0);
	}
	
	liliac[0].set_nr_s(8);
	liliac[0].set_radius(40);
	liliac[0].read("liliac.png");
	//fantoma_neagra[0].set_xy(rand()%WINDOW_W, 0);
	liliac[0].set_viata_max(200);
	liliac[0].set_viata(200);
	liliac[0].set_viteza(15);
	for (i=1; i<50; ++i)
	{
		liliac[i]=liliac[0];
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
	
	wrath_poza[0].readf("wrath1.png");
	wrath_poza[1].readf("wrath2.png");
	wrath_poza[2].readf("wrath3.png");
	
	haunt_poza[0].readf("haunt1.png");
	haunt_poza[1].readf("haunt2.png");
	haunt_poza[2].readf("haunt3.png");
	
	ghost_poza[0].readf("ghost1.png");
	ghost_poza[1].readf("ghost2.png");
	ghost_poza[2].readf("ghost3.png");
	
	terror_poza[0].readf("terror1.png");
	terror_poza[1].readf("terror2.png");
	terror_poza[2].readf("terror3.png");
	
	select1.read("select.png");
	select2.read("select.png");
	select3.read("select.png");
	select4.read("select.png");
	
	select1.set_xy(-100, -100);
	select2.set_xy(-100, -100);
	select3.set_xy(-100, -100);
	select4.set_xy(-100, -100);
	
	
	SDL_Color color={255, 255, 255, 255};
	
	start_text.create("Start");
	start_text.set_x(20); start_text.set_y(20);
	instructiuni_text.create("Instructiuni");
	instructiuni_text.set_x(20);
	instructiuni_text.set_y(WINDOW_H-20-instructiuni_text.get_h());
	
	SDL_Surface* aux=TTF_RenderText_Blended_Wrapped(font_normal, "BOLT\n    Skill ranged care da DMG\n\nEnhance-uri:\n    ->efect de lifesteal si DMG crescut\n    ->la fiecare kill facut cu acest skill iti\ncreste DMG-ul skillului\n\nCooldown:  cost mana: ", color, WINDOW_W/2-150);
	
	wrath_descr[0].tex=SDL_CreateTextureFromSurface(renderer, aux);
	wrath_descr[0].w=aux->w;
	wrath_descr[0].h=aux->h;
	SDL_FreeSurface(aux);
	
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "SPREAD THE DEAD\n    Lanseaza o sfera catre cel mai apropiat inamic\nDupa impact, sfera va lovi un alt inamic si tot asa\nSfera poate lovi un inamic o singura data\n\nEnhance-uri:\n    ->DMG mai putin dar un inamic va putea fi lovit de 2 ori de aceeasi sfera\n    ->sfera va face inamicii vulnerabili la urmatoarele atacuri si skill-uri\n\nCooldown:  cost mana: \n", color, WINDOW_W/2-150);
	
	wrath_descr[1].tex=SDL_CreateTextureFromSurface(renderer, aux);
	wrath_descr[1].w=aux->w;
	wrath_descr[1].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "ANGER\nPasiv: Primesti bonus DMG cu cat HP-ul este mai mic\nActiv: Dai DMG in toti inamicii de pe ecran\n\nEnhance-uri:\n    ->Pasiva da si Attackspeed\n    ->DMG din pasiva este scazut, cost: HP total, ramai cu 1HP, primesti bonus lifesteal si nu poti sa mori pentru   secunde\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	wrath_descr[2].tex=SDL_CreateTextureFromSurface(renderer, aux);
	wrath_descr[2].w=aux->w;
	wrath_descr[2].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "HAUNT\n\nPentru o perioada de timp, de fiecare data cand vei lua DMG, vei lua mai putin, diferenta de x% scazandu-se din mana\n\nEnhance-uri\n    ->x% crescut\n    ->x% scazut, dar care ii este returnat si sursei ca DMG\n\nCooldown:   cost mana: 0 ", color, WINDOW_W/2-150);
	
	haunt_descr[0].tex=SDL_CreateTextureFromSurface(renderer, aux);
	haunt_descr[0].w=aux->w;
	haunt_descr[0].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "HEARTLESS YELL\n\nTipi si dai freeze si putin DMG la toti inamicii de pe ecran\n\nEnhance-uri\n    ->dai slow, 0 DMG, dar primesti pentru 5 sec mai multa viata maxima in functie de cati inamici ai lovit\n    ->Reduci DMG-ul inamicilor pentru 5 sec, dai DMG mai mic si mana cost redus\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	haunt_descr[1].tex=SDL_CreateTextureFromSurface(renderer, aux);
	haunt_descr[1].w=aux->w;
	haunt_descr[1].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "CHILLING PRESENCE\n\nPasiv: Inamicii de pe ecran au movement speed redus si attack speed redus.\nActiv: Dai DMG si freeze de fiecare data cand un inamic foloseste un atac\n\nEnhance-uri\n    ->Efectul de incetinire este redus\n    ->Iei damage redus cu 20%\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	haunt_descr[2].tex=SDL_CreateTextureFromSurface(renderer, aux);
	haunt_descr[2].w=aux->w;
	haunt_descr[2].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "PHASE WALK\nDevii transparent si inamicii nu te pot vedea ca sa te loveasca, dar lovesc random asa ca fii atent la atacuri pentru ca ele inca te pot lovi\n\nEnhance-uri\n    ->Skill-ul costa mai putin\n    ->Dai damage in plus tuturor inamicilor in functie de cata mana ai\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	ghost_descr[0].tex=SDL_CreateTextureFromSurface(renderer, aux);
	ghost_descr[0].w=aux->w;
	ghost_descr[0].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "SOUL PACT\n\nPasiv: Primesti 8% din mana ta maxima cand omori un inamic\nActiv: Transferi o portiune de mana la viata ca heal\n\nEnhance-uri\n    ->Schimba pasiva cu activa\n    ->Primesti 4% mana si 4%HP cand omori\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	ghost_descr[1].tex=SDL_CreateTextureFromSurface(renderer, aux);
	ghost_descr[1].w=aux->w;
	ghost_descr[1].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "PEEK-A-BOO\n\nDevii invizibil si primesti bonus movement speed pentru o scurta perioada de timp. Daca atingi un inamic, acesta se va speria, luand damage si intorcandu-se de unde a venit\n\nEnhance-uri\n    ->Inamicul isi va lua DMG mai putin dar va fi mai vulnerabil la urmatoarele atacuri\n    ->Nu dai DMG, dar ai 20% sansa sa-l sperii de moarte. Daca nu moare este vulnerabil la urmatoarele atacuri\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	ghost_descr[2].tex=SDL_CreateTextureFromSurface(renderer, aux);
	ghost_descr[2].w=aux->w;
	ghost_descr[2].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "CONSUME\n\nOmori instant cel mai apropiat inamic\n\nEnhance-uri\n    ->Efectul are ca target cei mai apropiati 2 inamici, dar cate o sansa de 50% la fiecare in loc de 100%\n    ->Ai o sansa de 30% ca efectul sa treaca la urmatorul inamic si tot asa\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	terror_descr[0].tex=SDL_CreateTextureFromSurface(renderer, aux);
	terror_descr[0].w=aux->w;
	terror_descr[0].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "SPECTRAL FORM\n\nPentru cateva secunda atacurile tale dau bonus 70% DMG si toate costurile mana devin 0\n\nEnhance-uri\n    ->Costurile normale, dar bonusul de DMG este 150%\n    ->Cooldown-uri 0, dar costurile mana sunt duble\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	terror_descr[1].tex=SDL_CreateTextureFromSurface(renderer, aux);
	terror_descr[1].w=aux->w;
	terror_descr[1].h=aux->h;
	SDL_FreeSurface(aux);
	
	aux=TTF_RenderText_Blended_Wrapped(font_normal, "DISPAIR\n\nLa fiecare 2 secunda dai DMG in toti inamicii de pe ecran, se consuma mana la fiecare instant de DMG, toggle cost mare\n\nEnhance-uri\n    ->Cost mana redus, dar ti se consuma si o parte de HP la fiecare instanta de DMG\n    ->In loc de 2 secunde, efectul se repeta la fiecare secunda\n\nCooldown:   cost mana:  ", color, WINDOW_W/2-150);
	
	terror_descr[2].tex=SDL_CreateTextureFromSurface(renderer, aux);
	terror_descr[2].w=aux->w;
	terror_descr[2].h=aux->h;
	SDL_FreeSurface(aux);
	
	textcolor={255, 255, 255, 255};
	t_wrath.load_from_text("Wrath", textcolor);
	t_haunt.load_from_text("Haunt", textcolor);
	t_ghost.load_from_text("Ghost", textcolor);
	t_terror.load_from_text("Terror", textcolor);
	
	back_text.create("BACK");
	back_text.set_x(40+instructiuni_text.get_w());
	back_text.set_y(WINDOW_H-20-instructiuni_text.get_h());
	
}

joc_c joc;
