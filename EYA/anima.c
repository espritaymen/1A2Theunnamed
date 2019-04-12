#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

void animationEnemy(Enemy* enemy, Acteurs acteurs)
{		
			if(enemy->frame_timer <= 0)
			{
				enemy->frame_number++;
				SDL_Delay(15);
			if(enemy->frame_number > MAXF_ENEMY-1)
				enemy->frame_number = 0;
			}
		else
		enemy->frame_timer--;
		SDL_Delay(15);	
	
}
