#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "obstacle.h"

image init_image(char nameofpicture[100],int x,int y)
{
image image;
image.back=IMG_Load(nameofpicture);//load image
image.posPicture.x=x;//position x de bg
image.posPicture.y=y;//position y de bg
return image;
}
void affichage(SDL_Surface *ecran,image image)
{
SDL_BlitSurface(image.back,NULL,ecran,&image.posPicture);
}

void librer_image(image image)
{
 SDL_FreeSurface(image.back);//Liberer memoire
}


