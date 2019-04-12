#include "main.h"

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    Input input;
    Monstre monstre;
    Enigme enigme ; 
int go = 1 ;
int alea = 0 ;
char image[50];
int solution=0;
int r=0;
int run = 1 ;
    Gestion jeu;    
    loadGame(&jeu); 
    hero he ;
    vie v[4];
    object o[5];
    init("GREY MATTER",&jeu);
  
    atexit(cleanup);
    jeu.screen= menu_principale(jeu.screen,&jeu.menuout);
  
     init("GREY MATTER",&jeu);
     
      initializehero(&he);
      initializeEnnemy(&monstre);
  initialiservie(v);
  initialiserobject(o);
  
  
       while (jeu.menuout==0)
        {
    input=getInput(input); 
    drawhero(&he,&jeu);  
    dohero(&he,input,&jeu); 
    
    drawanimatedplayer(&he,&jeu);
     if (jeu.camera.x<=2400)  drawanimatedEnnemy(&monstre ,he ,&jeu);    
     
    jeu.screen=draw_vie (jeu.screen,v,he.hvie);
    dovie(&he, o,v,jeu.camera,monstre);
    draw_object (&jeu,o);         
    delay(frameLimit);
    SDL_Flip(jeu.screen);
    frameLimit = SDL_GetTicks() + 16;
    if (jeu.camera.x>=2850) jeu.menuout=1;
       drawanimatedplayer(&he,&jeu);
       
} 
reset(&he,&monstre,v,o);
 init("GREY MATTER",&jeu);
while(go == 1) 
{
run=1;
init_enigme(&enigme);
generate_afficher(jeu.screen,image,&enigme,&alea);
while(run==1){r=resolution(&go,&run);}

solution=solution_e(image);
afficher_resultat (jeu.screen,solution,r,&enigme); 
SDL_Delay(200);
  
}

/* Exit */
exit(0);

}

