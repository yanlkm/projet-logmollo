CC=gcc
CCFLAGS=-W -Wall -ggdb 

prog : main.o tree_etu.o list.o
	$(CC) main.o tree_etu.o list.o -o prog
main.o : list.h tree_etu.h main.c
	$(CC) -c $(CCFLAGS) main.c -o main.o
tree_etu.o : tree_etu.h tree_etu.c
	$(CC) -c $(CCFLAGS) tree_etu.c -o tree_etu.o
clear: 
	rm -f *.o prog	
