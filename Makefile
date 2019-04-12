prog:main.o vie.o score.o aide.o collision.o
	gcc main.o vie.o score.o aide.o collision.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main:main.c vie.h score.h	
	gcc -c main.c vie.h score.h
personnage:vie.c  vie.h	
	gcc -c vie.c vie.h
jump:score.c score.h 	
	gcc -c score.c score.h
aide:aide.c aide.h
	gcc -c aide.c aide.h
collision:collision.c collision.h
	gcc -c collision.c collision.h
