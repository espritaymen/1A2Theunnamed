#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "aide.h"

void initaide(aide* a)
{
a->imgaide[0]=IMG_Load("frame 1.png");
a->imgaide[1]=IMG_Load("frame 2.png");
a->imgaide[2]=IMG_Load("frame 3.png");
a->imgaide[3]=IMG_Load("frame 4.png");
a->imgaide[4]=IMG_Load("frame 5.png");
a->imgaide[5]=IMG_Load("frame 6.png");
a->i=0;
a->aidepos.x=200;
a->aidepos.y=340;
}


void affichezaide(aide* a,SDL_Surface* screen)
{
if(a->i>5)
{
a->i=0;
}
SDL_BlitSurface(a->imgaide[a->i],NULL,screen,&a->aidepos);
a->i++;

}

