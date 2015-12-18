CC = gcc
CFLAGS = -c -Wall

all:array

array: main.o array.o
		$(CC) -o array main.o array.o
main.o:main.c
	$(CC) $(CFLAGS) main.c
array.o:array.c
	$(CC) $(CFLAGS) array.c

clean:
	rm -rf *.o
	rm -rf array