#ifndef OBSTACLE_H_
#define OBSTACLE_H_

typedef struct image
{
	SDL_Surface *back;//wyn chnachargo image
	SDL_Rect posPicture;// Position mta3 background
}image;




image init_image(char nameofpicture[100],int x,int y);
void affichage(SDL_Surface *ecran,image img);
void Music_enigme();
void sound_wrong();
void sound_correct();
void sound_win();
int verif_enigme();
void librer_image(image img);


#endif
