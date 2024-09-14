#variables
CC=gcc	#Compiler
CFLAGS= -Wall -g	#Flags ( Wall : for warnings , g : for debugging )

#target for final executable
all : darray

#rule to bulid final executable
darray: main.o darray.o
	$(CC) $(CFLAGS) -o darray main.o darray.o

#rule to bulid main.c into main.o
main.o: main.c darray.h
	$(CC) $(CFLAGS) -c main.c

#rule to bulid darray.c into darray.o
darray.o: darray.c darray.h
	$(CC) $(CFLAGS) -c darray.c

#rule to bulid clean
clean:
	rm -f *.o darray