CC = gcc
AR = ar
FLAGS = -Wall -g -fPIC

all: StrList

StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c StrList.c

main.o: main.c StrList.h
	$(CC) $(FLAGS) -c main.c

StrList: main.o StrList.o
	$(CC) $(FLAGS) -o StrList main.o StrList.o


.PHONY: clean all

clean:
	rm -f *.o StrList