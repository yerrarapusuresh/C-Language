CC = gcc
CFLAGS = -c -Wall

all: hello

hello: hello.o function1.o function2.o
	$(CC) hello.o function1.o function2.o -o hello

hello.o: hello.c
	$(CC) $(CFLAGS) hello.c
function1.o: function1.c
	$(CC) $(CFLAGS) function1.c
function2.o: function2.c
	$(CC) $(CFLAGS) function2.c
clean:
	rm -rf *o hello



