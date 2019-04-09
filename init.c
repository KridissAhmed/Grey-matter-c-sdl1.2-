#include "init.h"

/* Fonction qui initialise le jeu */

SDL_Surface* init(char *title, SDL_Surface *screen )
{


    if (SDL_Init(SDL_INIT_VIDEO  ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }


    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    /* Si on y arrive pas, on quitte */

    if (screen == NULL)
    {
        printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }


    /* On entre le titre de la fenêtre */

    SDL_WM_SetCaption(title, NULL);

    /* initialiser ttf */

    if (TTF_Init() == -1)
    {
        printf("Could not initialize SDL ttf : %s\n", SDL_GetError());
        exit(1);
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
{
   printf("%s", Mix_GetError());
}

    /* On cache le curseur de la souris */

    //  SDL_ShowCursor(SDL_DISABLE);
     return screen ;

}

void initmenu(Menu *menu)
{
    menu->background=NULL;
    menu->rectangle=NULL;
    menu->police1=NULL;
    menu->menuout=4;
}


void loadMenu(Menu *menu)
{

    /* Charge l'image du fond */
    menu->background = loadImage("graphics/backsmenu.png");
    menu->rectangle= loadImageN("graphics/rectangle.png");
    /*charger police */
    menu->police1=TTF_OpenFont("graphics/Trajan Pro Regular.ttf", 20);
    menu->police2=TTF_OpenFont("graphics/Trajan Pro Regular.ttf", 14);
    menu->blanc.r = 255;
    menu->blanc.g = 255;
    menu->blanc.b = 255;
    menu->noir.r = 0;
    menu->noir.g = 0;
    menu->noir.b = 0;
    menu->texte[0] = TTF_RenderText_Blended(menu->police1, "NEW GAME", menu->noir);
    menu->texte[1] = TTF_RenderText_Blended(menu->police1, "LOAD GAME", menu->blanc);
    menu->texte[2] = TTF_RenderText_Blended(menu->police1, "SETTING", menu->blanc);
    menu->texte[3] = TTF_RenderText_Blended(menu->police1, "QUIT", menu->blanc);
     menu->texte[4] = TTF_RenderText_Blended(menu->police1, "TEAM", menu->blanc);
    menu->pos_rectangle.x=-45;
    menu->pos_rectangle.y=147;


}




void loadGame(Gestion* jeu )
{

    /* Charge l'image du fond */
    jeu->background = loadImage("graphics/background+.png");

}

/* Fonction qui quitte le jeu proprement */
void cleanup_menu(Menu *menu )
{
   SDL_FreeSurface(menu->background);
    SDL_FreeSurface(menu->rectangle);
    SDL_FreeSurface(menu->texte[0]);
    SDL_FreeSurface(menu->texte[1]);
    SDL_FreeSurface(menu->texte[2]);
    SDL_FreeSurface(menu->texte[3]);
    TTF_CloseFont(menu->police1);
    Mix_FreeChunk(menu->click_sound);
    Mix_FreeMusic(menu->soundtrack);
}
void cleanup()
{

    /* Quitte la SDL */
    TTF_Quit();
    SDL_Quit();
    Mix_CloseAudio();

}

