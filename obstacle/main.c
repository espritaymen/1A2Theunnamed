#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "obstacle.h"
int main()
{
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
    SDL_Surface *ecran =NULL;
    SDL_Event event;
    ecran=SDL_SetVideoMode(900, 600, 32, SDL_HWSURFACE); 
    image obstacle1,obstacle2,background;
    int continuer=1;

    background=init_image("background.jpg",0,0);
    obstacle1=init_image("obstacle1.png",100,350);
    obstacle2=init_image("obstacle2.png",500,0);

    affichage(ecran,background);
    affichage(ecran,obstacle1);
    affichage(ecran,obstacle2);
    SDL_Flip(ecran);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        }
    }
    librer_image(background);
    librer_image(obstacle1);
    librer_image(obstacle2);

   return EXIT_SUCCESS;
}







