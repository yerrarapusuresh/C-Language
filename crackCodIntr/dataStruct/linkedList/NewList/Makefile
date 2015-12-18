CC = gcc
#CFLAGS = -Wall

all:	list

list:	MainList.o LinkedList.o
	$(CC) MainList.o LinkedList.o -o list
MainList.o:    MainList.c
	$(CC) -c -Wall MainList.c
LinkedList.o:	LinkedList.c
	$(CC) -c -Wall LinkedList.c
clean:
	rm -rf *.o list
    