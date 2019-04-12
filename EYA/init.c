#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
void initialisation(Acteurs* acteurs, SDL_Rect* camera, SDL_Rect* frame)
{
  acteurs->backg = IMG_Load("stage 1.jpg");
  camera->x = 0;
  camera->y = 0;
  camera->w = SCREEN_WIDTH;
  camera->h = SCREEN_HEIGHT;

  frame->x = 0;
  frame->y = 0;
  frame->w = PLAYER_WIDTH;
  frame->h = PLAYER_HEIGHT;
}
