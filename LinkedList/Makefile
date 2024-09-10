#variables
CC = gcc  #compiler
CFLAGS = -Wall -g  #Flags (Wall : shows warnings, g: for debugging)

#target for final executable
all : linkedlist

#rule to bulid final executable
linkedlist: main.o linkedlist.o
	$(CC) $(CFLAGS) -o linkedlist main.o linkedlist.o

#rule to compile main.c into main.o
main.o: main.c linkedlist.h
	$(CC) $(CFLAGS) -c main.c

#rule to compile linkedlist.c into linkedlist.o
linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

#clean up object files and executable
clean:
	rm -f *.o linkedlist