all: program

program: 4.o sort.o
	gcc -o program 4.o sort.o

4.o: 4.c
	gcc -c 4.c

sort.o: sort.s
	as -o sort.o sort.s

clean:
	rm -f *.o program

test:
	./program