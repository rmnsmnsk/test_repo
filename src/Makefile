all: program

program: dj.c stack/STR.c stack/STR.h
	gcc dj.c stack/STR.c -o program

clean:
	rm -f *.o program

test:
	./program