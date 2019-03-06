#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct hero
{
	int changervie1;
int changervie2;
int changervie3;

int nombre_vie;

SDL_Surface *affichage_vie;
SDL_Surface *affichage_vie2;

SDL_Rect position_vie;
SDL_Rect position_vie2;


int score;

SDL_Surface *score_affichage;
SDL_Rect position_score ;
SDL_Rect position_score2 ;

TTF_Font *policescore;
TTF_Font *policegame;
char scorechaine[25];
int aux;
SDL_Rect position_hero;
SDL_Surface *affichage_hero;



} hero;



#endif // PERSO_H_INCLUDED
