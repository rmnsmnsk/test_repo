all: prog test

prog: main.c cyclic.c cyclic.h
	gcc -Wall -Wextra -o main main.c cyclic.c

test: test.c cyclic.c cyclic.h
	gcc -Wall -Wextra -o test test.c cyclic.c

clean:
	rm -f main test