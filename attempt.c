


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "deplac.h"



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
hero->y = 250 ;
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



/*void initializeEnemy(Enemy* enemy)
{
	SDL_Surface* tmp;

	tmp = SDL_LoadBMP("sprite_enemy_right.bmp");
	enemy->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(enemy->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(enemy->sprite->format, 255, 255, 255));


	//Indique l'état et la direction de notre enemy
	enemy->direction = RIGHT;
	enemy->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	enemy->frame_timer = TIME_BETWEEN_2_FRAMES;
	enemy->frame_number = 0;

	//Coordonnées de démarrage de notre enemies 
	enemy->x = 0 ;
	enemy->y = 0 ;

}

//---fontion pour afficher l'enemy ---

void drawEnemy(Enemy enemy , Acteurs *acteurs)
{

// Rectangle de destination à blitter 
SDL_Rect dest;
dest.x = enemy.x - acteurs->camera.x;
dest.y = enemy.y ;

SDL_Rect frame;
frame.x = enemy.frame_number*ENEMY_Width;
frame.y = 0;
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
SDL_Rect AnimationHero(Hero hero)
{
  int i;
  SDL_Rect frame;

    if(hero.etat == WALK_RIGHT)
    {
      i = 0;
        while(i<MAXF)
        {
          frame.x = i*PLAYER_WIDTH;
          frame.y = 0;
          frame.w = PLAYER_WIDTH;
          frame.h = PLAYER_HEIGHT;
          i++;
        }
      if(i = MAXF-1)
        i = 0;
    }
    else if(hero.etat == WALK_LEFT)
    {
      i = MAXF-1;
      while(i>=0)
        {
          frame.x = i*PLAYER_WIDTH;
          frame.y = 0;
          frame.w = PLAYER_WIDTH;
          frame.h = PLAYER_HEIGHT;
          i--;
        }
      if(i < 0)
        i = MAXF-1;
    }
    else if(hero.etat == IMMOBILE)
    {
      if(hero.direction == RIGHT)
      {

        frame.x = 0;
        frame.y = 0;
        frame.w = PLAYER_WIDTH;
        frame.h = PLAYER_HEIGHT;
      }
      else if(hero.direction == LEFT)
      {
        frame.x = MAXF-1;
        frame.y = 0;
        frame.w = PLAYER_WIDTH;
        frame.h = PLAYER_HEIGHT;
      }
    }
  return frame;
}

/*SDL_Rect AnimationHeroRight(Hero hero, Acteurs acteurs)
{
  int i;
  SDL_Rect FrameRight;
  if(acteurs.event.type == SDL_KEYDOWN)
  {
    if(acteurs.event.key.keysym.sym == SDLK_RIGHT)
    {
        for(i=0; i<MAXF; i++)
        {
          FrameRight.x = i*PLAYER_WIDTH;
          FrameRight.y = 0;
          FrameRight.w = PLAYER_WIDTH;
          FrameRight.h = PLAYER_HEIGHT;
        }
    }
  }
  return FrameRight;
}


SDL_Rect AnimationHeroLeft(Hero hero, Acteurs acteurs)
{
  int i;
  SDL_Rect FrameLeft;
  if(acteurs.event.type == SDL_KEYDOWN)
  {
    if(acteurs.event.key.keysym.sym == SDLK_LEFT)
    {
        for(i=(MAXF-1); i>=0; i--)
        {
          FrameLeft.x = i*PLAYER_WIDTH;
          FrameLeft.y = 0;
          FrameLeft.w = PLAYER_WIDTH;
          FrameLeft.h = PLAYER_HEIGHT;
        }
    }
  }
  return FrameLeft;
}*/
int collision(Hero *hero,Enemy* enemy)
{ 
//on teste pour voir s'il n'ya pas collision ,si c'est le cas , on revoie 0
if((hero->x >= enemy ->x + enemy-> w)||(hero->x + hero-> w >= enemy ->x)||(hero->y >= enemy ->y + enemy->h)||(hero->y + hero-> h >= enemy ->y))
return 0;
// si non,il y'a collision ,si le joueur est au dessus du enemy(avec une marge
//de 10 pixel pour eviter les frustrations dues au pixel perfect),on devra alors tuer l'enemy et on fera rebondir le joueur
else if(hero->y + hero->h <= enemy -> y +10)
{
hero -> direction  = -JUMP_HEIGHT;
return 2;
}
//
return 1;
} 

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "deplac.h"


int main(int argc, char const *argv[])
{

  Acteurs acteurs;
  Boutons boutons;
  Hero hero ;
  SDL_Rect camera;
  SDL_Rect frame;


   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }


/* appel des fonctions */
#include "deplac.h"

acteurs.screen= SDL_SetVideoMode(1080,400,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "Tunisia", NULL );

    initializeHero(&hero);
    initialisation(&acteurs, &camera, &frame);
    /*SDL_BlitSurface(backg,NULL , acteurs.screen, &camera);
    SDL_Flip(acteurs.screen);*/

    drawHero(hero, acteurs, camera, frame);

int carryon = 1;
while(carryon)
{
    SDL_PollEvent(&acteurs.event);
    updatePlayer(&hero , &acteurs, camera, &frame) ;
    frame = AnimationHero(hero);
    centerScrollingOnPlayer(hero, &acteurs, &camera);
    drawHero(hero , acteurs, camera, frame) ;

  switch(acteurs.event.type)
  {
    case SDL_QUIT:
             carryon = 0;
      case SDL_KEYDOWN:
      if(acteurs.event.key.keysym.sym == SDLK_ESCAPE)
        {
          carryon= 0;
        }
      break;

  }


}

    //LIB
  SDL_Quit();
  return 0 ;

}






