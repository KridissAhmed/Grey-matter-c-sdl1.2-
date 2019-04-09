#include "structs.h"

  /* Prototypes des fonctions utilisées */

 extern  SDL_Surface*  init(char * , SDL_Surface* screen);
  
  extern void cleanup(void);
  extern Input  getInput(Input input);
   extern SDL_Surface* drawImage(SDL_Surface *image,SDL_Surface *screen, int x, int y) ;
   extern SDL_Surface* menu_principale(SDL_Surface*, int *menuout);
  extern void delay(unsigned int);
 
 extern void loadGame(Gestion * jeu);
extern void initializehero(hero *he);
// extern void drawgame( );
 extern void dohero( hero *he , Input input);
extern SDL_Surface *drawhero(hero *he,SDL_Surface *screen);

  
