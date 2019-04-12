


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "deplac.h"
#include "ennemi.h"


void initialisation(Acteurs* acteurs, SDL_Rect* camera, SDL_Rect* frame)
{
  acteurs->backg = IMG_Load("stage1.jpg");
  camera->x = 0;
  camera->y = 0;
  camera->w = SCREEN_WIDTH;
  camera->h = SCREEN_HEIGHT;

  frame->x = 0;
  frame->y = 0;
  frame->w = PLAYER_WIDTH;
  frame->h = PLAYER_HEIGHT;
}




/*---fonction d initialisation de l hero---*/






void initializeHero(Hero* hero)
{

hero->sprite = SDL_LoadBMP("Right.bmp");
SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));


//Indique l'état et la direction de notre héros
hero->direction = RIGHT;
hero->etat = IMMOBILE;

//Réinitialise le timer de l'animation et la frame


/* Coordonnées de démarrage de notre héros */
hero->x = 48 ;
hero->y = 450 ;
hero->Ysaut = 0;
}

/*---fontion pour afficher l'hero ---*//////////////////////////

void drawHero(Hero hero , Acteurs acteurs, SDL_Rect camera, SDL_Rect frame)
{


/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = hero.x - camera.x;
dest.y = hero.y ;

/* Blitte notre héros sur l'écran aux coordonnées x et y */
SDL_BlitSurface(acteurs.backg, &camera, acteurs.screen, NULL);
SDL_BlitSurface(hero.sprite , &frame , acteurs.screen , &dest) ;
SDL_SetColorKey(hero.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero.sprite->format, 255, 255, 255));
SDL_Flip(acteurs.screen);

}





/*________________________________________________________________________________________*/



/* plus tard */

/*---fonction pour faire le scrolling---*//////////////////////////








void centerScrollingOnPlayer(Hero hero, Acteurs* acteurs, SDL_Rect* camera)
{
  if(acteurs->event.type == SDL_KEYDOWN)
  {
    if(acteurs->event.key.keysym.sym == SDLK_RIGHT)
  {
    if((hero.x + PLAYER_WIDTH/2) > SCREEN_WIDTH/2)
      {
        camera->x += PLAYER_SPEED;
      }
    if(camera->x > Backg_W - SCREEN_WIDTH)
      {
        camera->x = Backg_W - SCREEN_WIDTH;
      }
  }
  else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
  {

        camera->x -= PLAYER_SPEED;
    if((hero.x + PLAYER_WIDTH/2) > (Backg_W - SCREEN_WIDTH/2))
    {
      camera->x = Backg_W - SCREEN_WIDTH;
    }

    if(camera->x < 0)
      {
        camera->x = 0;
      }
  }
  }
}

/*________________________________________________________________________________________*/



/*---fonction de deplacement de l hero---*/

void updatePlayer(Hero* hero , Acteurs* acteurs, SDL_Rect camera, SDL_Rect* frame)
{
  if(acteurs->event.type == SDL_KEYDOWN)
  {
    if(acteurs->event.key.keysym.sym == SDLK_RIGHT)
    {
      if(hero->etat == IMMOBILE || hero->etat == WALK_LEFT)
      {
        hero->etat = WALK_RIGHT;
      }
      if(hero->direction == LEFT)
        {
          hero->direction = RIGHT ;
        }
      hero->sprite = SDL_LoadBMP("Right.bmp") ;
      SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
      hero->x += PLAYER_SPEED ;
      //*frame = AnimationHeroRight(*hero, *acteurs);

      if (hero->x + PLAYER_WIDTH >= Backg_W)
        {
          hero->x = Backg_W - PLAYER_WIDTH ;
        }
    }
    else if(acteurs->event.key.keysym.sym == SDLK_LEFT)
    {
      if(hero->etat == IMMOBILE || hero->etat == WALK_RIGHT)
      {
        hero->etat = WALK_LEFT;
      }
      if(hero->direction == RIGHT)
        {
          hero->direction = LEFT ;
        }
      hero->sprite = SDL_LoadBMP("Left.bmp") ;
      SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
      hero->x -= PLAYER_SPEED ;
      //*frame = AnimationHeroLeft(*hero, *acteurs);
            if (hero->x < 0)
        {
          hero->x = 0 ;
        }
      if (hero->y < 0)
        {
          hero->y = 0 ;
        }
    }
  }
  else if(acteurs->event.type == SDL_KEYUP)
  {
    if(hero->etat != IMMOBILE)
    {
      hero->etat = IMMOBILE;
    }
  }
  //centerScrollingOnPlayer(*hero, acteurs, &camera);

}
/*void init_ennemi(ennemi *e)
{

	e->position.x = 100;
	e->position.y = 0;
	e->vie=1;
	e.image = IMG_Load("ennemi.png");
	SDL_Surface *screen = NULL;
	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

	SDL_BlitSurface(e.image, NULL, screen, e->position);
	SDL_Flip(screen); 
	

}*/

//---fontion pour afficher l'enemy ---

/*void drawEnemy(Enemy enemy , Acteurs *acteurs)
{

// Rectangle de destination à blitter 
SDL_Rect dest;
dest.x = enemy.x - acteurs->camera.x;
dest.y = enemy.y ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 450;
frame.w = ENEMY_Width;
frame.h = ENEMY_Height;

// Blitte notre enemy sur l'écran aux coordonnées x et y 
SDL_BlitSurface(enemy.sprite , &frame , acteurs->screen , &dest) ;
SDL_SetColorKey(enemy.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy.sprite->format, 255, 255, 255));
SDL_Delay(15);
	
}

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
	
}*/
