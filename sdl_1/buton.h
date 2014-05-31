#ifndef sdl_1_buton_h
#define sdl_1_buton_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
using namespace std;

class buton
{
    public:
        buton();
        ~buton();

        void free();
        void readf(string);
        void create(string);

        void set_x(int val) {x=val;};
        void set_y(int val) {y=val;};
        void set_w(int val) {w=val;};
        void set_h(int val) {h=val;};
        void set_v(bool val) {v=val;};
        void set_click(bool val) {click=val;};
        void set_hov(bool val) {hov=val;};

        int get_x() {return x;};
        int get_y() {return y;};
        int get_w() {return w;};
        int get_h() {return h;};
        bool get_v() {return v;};
        bool get_click() {return click;};
        bool get_hov() {return hov;}

        bool hover(); //returneaza daca mouse.ul este sau nu pe buton
        void create_hover();
        void create_no_hover();

        void render();
        void on_click();

    private:
        SDL_Surface* surface;
        SDL_Texture* texture;
        int x, y;
        int w, h;
        bool v, click, hov;
        string nume;

        SDL_Color color;
        TTF_Font* font = TTF_OpenFont( "font.ttf", 72 );
};

#endif
