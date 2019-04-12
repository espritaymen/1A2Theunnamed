#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
void depla(Enemy* enemy)
{
for(i = 0; i<MAX_FRAMES; i++)
		{
			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;

			enemy.dst.x += i*SPEED;

			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteright, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			enemy.dst.x -= i*SPEED;

			enemy.frame.x = i*(Sint16)SPRITE_W;
			enemy.frame.y = 0;
			enemy.frame.w = SPRITE_W;
			enemy.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(enemy.spriteleft, &enemy.frame, screen, &enemy.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}

}
