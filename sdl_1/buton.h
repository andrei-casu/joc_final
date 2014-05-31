#ifndef BUTON
#define BUTON


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

        void set_x(int);
        void set_y(int);
        void set_w(int);
        void set_h(int);
        void set_v(bool);
        void set_click(bool);

        int get_x();
        int get_y();
        int get_w();
        int get_h();
        bool get_v();
        bool get_click();

        void render();
        void on_click();

    private:
        SDL_Surface* surface;
        SDL_Texture* texture;
        int x, y;
        int w, h;
        bool v, click;
};


#endif