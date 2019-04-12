#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
void drawEnemy(Enemy enemy , Acteurs *acteurs)
{

/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = enemy.x - acteurs->camera.x;
dest.y = enemy.y ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

/* Blitte notre enemy sur l'écran aux coordonnées x et y */

SDL_BlitSurface(enemy.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite->format, 255, 255, 255));
SDL_Delay(15);
	
}


