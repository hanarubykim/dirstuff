all: main.o
	gcc -o testing main.o

main.o: main.c
	gcc -c main.c

run:
	./testing

clean:
	rm *.o
	rm *~
