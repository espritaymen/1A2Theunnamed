#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "vie.h"
#include "score.h"
#include "aide.h"



int collide(aide* a,SDL_Rect fpos)
{
if((fpos.x >= a->aidepos.x+a->aidepos.w)
|| (fpos.x + fpos.w  <= a->aidepos.x)
|| (fpos.y >= a->aidepos.y + a->aidepos.h)
||(fpos.y+fpos.h <= a->aidepos.y))
return 0;
else
return 1;
}
int collide2(SDL_Rect backpos,SDL_Rect fpos)
{
if((fpos.x >= backpos.x+backpos.w)
|| (fpos.x + fpos.w  <= backpos.x)
|| (fpos.y >= backpos.y + backpos.h)
||(fpos.y+fpos.h <= backpos.y))
return 0;
else
return 1;




}
