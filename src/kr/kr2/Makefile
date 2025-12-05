all: main test

main: main.c list.c list.h
	gcc -Wall -Wextra -o main main.c list.c

test: test.c list.c list.h
	gcc -Wall -Wextra -o test test.c list.c

clean:
	rm -f main test