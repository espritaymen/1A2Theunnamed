#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "deplac.h"
#include "aide.h"
#include "vie.h"
#include "score.h"
#include "enig.h"

int main(int argc, char const *argv[])
{

  Acteurs acteurs;
  Boutons boutons;
  Hero hero ;
  SDL_Rect camera;
  SDL_Rect frame;


   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }


/* appel des fonctions */

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "A Journey In Tunisia", NULL );

    initializeHero(&hero);
    initialisation(&acteurs, &camera, &frame);
    /*SDL_BlitSurface(backg, , acteurs.screen, NULL);
    SDL_Flip(acteurs.screen);*/

    drawHero(hero, acteurs, camera, frame);

int carryon = 1;
while(carryon)
{
    SDL_PollEvent(&acteurs.event);
    updatePlayer(&hero , &acteurs, camera, &frame) ;
    
    centerScrollingOnPlayer(hero, &acteurs, &camera);
    drawHero(hero , acteurs, camera, frame) ;
/*Intvie(v);
affichevie(v,&screen,&collision);
intaide(a);
afficheaide(a,&screen);
intscoreboard(&co);
affichescoreboard(&co,&screen,&screnb,collision);
collide(a,&f);
collide2(&backpos,&fpos);
initialiser_enigme(x1,y1,x2,y2,x3,y3);
generation_aleatoire(nbalea);
afficher_enigme(image[20]);
resolution_enigme(image[20]);
*/
  switch(acteurs.event.type)
  {
    case SDL_QUIT:
             carryon = 0;
      case SDL_KEYDOWN:
      if(acteurs.event.key.keysym.sym == SDLK_ESCAPE)
        {
          carryon= 0;
        }
      break;

  }


}

    //LIB
  SDL_Quit();
  return 0 ;

}


