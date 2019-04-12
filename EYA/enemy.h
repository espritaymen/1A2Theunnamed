#define W_Screen 800
#define H_Screen 600
#define CMode 32
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600
#define SPEED 5
#define PLAYER_HEIGHT 600
#define PLAYER_WIDTH 600
#define SPRITE_H 148
#define SPRITE_W 102
#define MAX_FRAMES 6 
#define W_BackgImg 259
#define H_BackgImg 194
typedef struct Acteurs Acteurs;
struct Acteurs
{
	  SDL_Surface *screen;
    SDL_Event event ;

	//fond
	SDL_Surface *fond ;
	SDL_Rect posFond;

  //fond noir
  SDL_Surface* backg;
};

typedef struct Enemy Enemy ;
struct Enemy 
{

SDL_Surface *sprite;

/* Coordonnées de l'enemy */
int x , y ;

/* Variables utiles pour l'animation */
int frame_timer, frame_number;
int etat  , direction ; 

};
void initialisation(Acteurs* acteurs, SDL_Rect* camera, SDL_Rect* frame);
void drawEnemy(Enemy enemy , Acteurs *acteurs) ;
void animationEnemy(Enemy* enemy, Acteurs acteurs) ;
void depla(Enemy* enemy);
#endif
