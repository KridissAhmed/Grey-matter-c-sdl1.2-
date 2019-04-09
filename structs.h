#include "defs.h"

typedef struct Input
{

    int left, right, up, down, jump, attack, enter, erase, pause;

} Input;

typedef struct Gestion
{

    SDL_Surface *screen;
    SDL_Surface *background;
    int menuout;

} Gestion;

typedef struct menu
{

    SDL_Surface *background;
    SDL_Surface *rectangle;
    TTF_Font *police1 ;
    TTF_Font *police2 ;
    SDL_Surface *texte[6];
    SDL_Color noir ;
    SDL_Color blanc ;
    SDL_Rect pos_rectangle;
    int menuout ;
    Mix_Chunk * click_sound ;
    Mix_Music* soundtrack ;
} Menu;

typedef struct hero
{

    SDL_Surface *carreau;
    int x, y;


} hero;

