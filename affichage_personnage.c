#include "PERSO.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void Afficher_Personnage (hero Alex[] , SDL_Surface *ecran)
{
	
SDL_BlitSurface(Alex[0].affichage_hero,&Alex[0].frame,ecran,&Alex[0].position_hero);
SDL_BlitSurface(Alex[0].affichage_vie,NULL,ecran,&Alex[0].position_vie);

SDL_BlitSurface(Alex[1].affichage_hero,&Alex[1].frame,ecran,&Alex[1].position_hero);
SDL_BlitSurface(Alex[1].affichage_vie,NULL,ecran,&Alex[1].position_vie);

}


