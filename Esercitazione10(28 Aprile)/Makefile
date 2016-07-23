all: 	recursion_main

utils.o:	utils.c utils.h 
		g++ -c -o utils.o utils.c

recursion.o:	recursion.c recursion.h
		g++ -c -o recursion.o recursion.c


recursion_main: recursion_main.c recursion.o utils.o
		g++ -o recursion_main recursion_main.c recursion.o utils.o

clean:
		rm -rf *.o *.exe *~ recursion_main
