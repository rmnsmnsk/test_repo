all: program

program: staples.c stack/STR.c stack/STR.h
	gcc staples.c stack/STR.c -o program

clean:
	rm -f *.o program

test:
	./program
