CC=g++
CFLAGS=-std=c++11 -Wall

all: main

main: src/main.o src/todo.o
	$(CC) $(CFLAGS) -o main src/main.o src/todo.o

src/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

src/todo.o: src/todo.cpp src/todo.h
	$(CC) $(CFLAGS) -c src/todo.cpp

clean:
	rm -f src/*.o main
