#include "hero.h"


void initializehero(hero *he)
{

    /* Charge le sprite de notre héros */
    he->carreau = loadImage("graphics/_IDLE_001.png");

    /* Coordonnées de démarrage de notre héros */
    he->x = 50;
    he->y = 104;


}

SDL_Surface *drawhero(hero *he,SDL_Surface *screen)
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = he->x;
    dest.y = he->y;
    dest.w = 50;
    dest.h = 60;


    /* Blitte notre héros sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(he->carreau,NULL, screen, &dest);
return screen ; 

}
void dohero(hero *he, Input input)
{
    if (input.up == 1)
    {
        he->y -= 3;

    }

    if (input.down == 1)
    {
        he->y += 3;


    }

    if (input.left == 1)
    {
        he->x -= 3;


    }

    if (input.right == 1)
    {
        he->x += 3;

    }
}

