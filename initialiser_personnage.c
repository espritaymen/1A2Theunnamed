#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "PERSO.h"
#include <string.h>



hero Initialiser_Personnage (hero Alex[] )
{

Alex[0].position_hero.x=300;
Alex[0].position_hero.y=275;



Alex[0].nombre_vie=3;

Alex[0].score=0;
Alex[0].score_affichage=NULL;
Alex[0].position_score.x= 0 ;
Alex[0].position_score.y=0 ;


Alex[0].button=0;
Alex[0].affichage_hero=NULL;

Alex[0].affichage_hero=IMG_Load("1.jpg");
Alex[0].affichage_vie=NULL;
Alex[0].affichage_vie=IMG_Load("vie3.png");


Alex[0].position_vie.x=300;
Alex[0].position_vie.y=0;





Alex[0].changervie1=0;
Alex[0].changervie2=0;
Alex[0].changervie3=0;
Alex[0].policescore=TTF_OpenFont("arial.ttf",22);
Alex[0].policegame=TTF_OpenFont("arial.ttf",80);
Alex[0].win_or_lose=NULL;
Alex[0].win_or_lose_position.x=200;
Alex[0].win_or_lose_position.y=200;
strcpy(Alex[0].scorechaine,"000");




/*
-----------------------------------------------------
*/

Alex[1].position_hero.x=905; //610+1200/2
Alex[1].position_hero.y=275;



Alex[1].nombre_vie=3;

Alex[1].score=0;
Alex[1].score_affichage=NULL;
Alex[1].position_score.x= 620 ;
Alex[1].position_score.y=0 ;


Alex[1].button=0;
Alex[1].affichage_hero=NULL;

Alex[1].affichage_hero=IMG_Load("1.jpg");
Alex[1].affichage_vie=NULL;
Alex[1].affichage_vie=IMG_Load("vie3.png");


Alex[1].position_vie.x=800;
Alex[1].position_vie.y=0;






Alex[1].curframe=0;
Alex[1].maxframe=5;
Alex[1].changervie1=0;
Alex[1].changervie2=0;
Alex[1].changervie3=0;
Alex[1].policescore=TTF_OpenFont("arial.ttf",22);
Alex[1].policegame=TTF_OpenFont("arial.ttf",80);
strcpy(Alex[1].scorechaine,"000");

return *Alex ;
}
