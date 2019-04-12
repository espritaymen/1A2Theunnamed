#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

typedef struct
{
SDL_Surface *Star[7];
SDL_Rect Starpos;
int i;
}star; 

typedef struct
{
SDL_Surface* coin[6];
SDL_Rect coinpos;
SDL_Surface* scoreboard[10];
SDL_Surface* cross;
SDL_Rect scoreboardpos;
SDL_Rect crosspos;
int i;
}coin;

void initscoreboard(coin *co);
int affichezscoreboard(coin* co,SDL_Surface* screen,int scorenb,int *collision);

#endif 
