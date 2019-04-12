prog :init.o anima.o depla.o enemy.o 
	gcc init.o anima.o depla.o enemy.o -o prog -lSDL -lSDL_image -lSDL_mixer 
anima.o : anima.c
	gcc -c anima.c
enemy.o: enemy.c
	gcc -c enemy.c
depla.o: depla.c
	gcc -c depla.c
init.o: init.c
	gcc -c init.c
