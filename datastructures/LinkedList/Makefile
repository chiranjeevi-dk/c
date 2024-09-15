#variables
CC=gcc	#Compiler
CFLAGS= -Wall -g	#Flags ( Wall : for warnings , g : for debugging )

#target for final executable
all : linkedlist

#rule to bulid final executable
linkedlist: main.o linkedlist.o
	$(CC) $(CFLAGS) -o linkedlist main.o linkedlist.o

#rule to bulid main.c into main.o
main.o: main.c linkedlist.h
	$(CC) $(CFLAGS) -c main.c

#rule to bulid darray.c into darray.o
linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

#rule to bulid clean
clean:
	rm -f *.o linkedlist