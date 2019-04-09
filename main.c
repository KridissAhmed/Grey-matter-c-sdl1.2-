#include "main.h"

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    Input input;
    Gestion jeu; 
    jeu.screen=NULL;
    hero he ;
    //int go;
    jeu.screen = init("GREY MATTER",jeu.screen);
    atexit(cleanup);
    //go = 1;
    jeu.screen= menu_principale(jeu.screen,&jeu.menuout);
   /* Boucle infinie, principale, du jeu */
    jeu.screen = init("GREY MATTER",jeu.screen);
    loadGame(&jeu);
    initializehero(&he);
       while (jeu.menuout==0)
        {
    input=getInput(input);
    
    dohero(&he,input); 
    jeu.screen=drawImage(jeu.background,jeu.screen, 0, 20); 
    jeu.screen=drawhero(&he,jeu.screen);  
    delay(frameLimit);
    SDL_Flip(jeu.screen);
    frameLimit = SDL_GetTicks() + 16;
}


/* Exit */
exit(0);

}

