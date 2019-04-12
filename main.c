#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "vie.h"
#include "score.h"
#include "aide.h"
#include "collision.h"


int main()
{
vie v;
aide a;
initaide(&a);

int scorenb=0;
int collision=0;
int i=0;
coin co;
int pause=0;
int quit=1;
int collision2=0;
SDL_Surface* screen;
SDL_Surface* background;
background=IMG_Load("stage-1-1.png");
SDL_Surface* perso;
SDL_Rect persopos;
SDL_Rect backpos;
backpos.y=350;
backpos.x=500;
int t=0;
persopos.y=340;
SDL_Surface* obstacle;
perso=IMG_Load("12.png");
obstacle=IMG_Load("14.png");
Initvie(&v);
initscoreboard(&co);
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(800,561,32,SDL_HWSURFACE);
SDL_EnableKeyRepeat(50,50);
while(quit==1)
{
SDL_BlitSurface(background,NULL,screen,NULL);
collision2=collide2(backpos,persopos);
collision=collide(&a,persopos);
t=collision2;
scorenb=affichezscoreboard(&co,screen,scorenb,&collision);
affichezvie(&v,screen,&collision2);
if(t==1)
{
persopos.x=0;
t=0;
}
affichezaide(&a,screen);
persopos.x=persopos.x+20;
if(persopos.x>800)
{
persopos.x=0;
}
SDL_BlitSurface(obstacle,NULL,screen,&backpos);
SDL_BlitSurface(perso,NULL,screen,&persopos);
SDL_Delay(130);
 	
SDL_Flip(screen);
}




}
