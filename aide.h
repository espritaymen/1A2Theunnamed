#ifndef AIDE_H_INCLUDED
#define AIDE_H_INCLUDED
typedef struct
{

SDL_Surface* imgaide[7];
SDL_Rect aidepos;
int i;
}aide;



void initaide(aide* a);
void affichezaide(aide* a,SDL_Surface* screen);












#endif 
