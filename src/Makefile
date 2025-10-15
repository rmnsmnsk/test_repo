all: program

program: 5_c_skobki.c stack/STR.c stack/STR.h
	gcc 5_c_skobki.c stack/STR.c -o program

clean:
	rm -f program

test: program
	./program