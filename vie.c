#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "vie.h"



void Initvie(vie* v)
{
v->heart[0]=IMG_Load("heart1.png");
v->heart[1]=IMG_Load("heart2.png");
v->heart[2]=IMG_Load("heart3.png");
v->heartpos.x=580;
v->heartpos.y=20;
v->i=0;	
}
void affichezvie(vie* v,SDL_Surface* screen,int *collision)
{
if(*collision==1)
{
v->i++;
*collision=0;
if(v->i>2)
{
v->i=0;	
}
}
SDL_BlitSurface(v->heart[v->i],NULL,screen,&v->heartpos);
}

