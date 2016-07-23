all:    main 

clean:	
	rm -rf *~ *.o main

esercizi.o: esercizi.c
	gcc -g -std=c99 -c $<

utils.o: utils.c utils.h
	gcc -g -std=c99 -c $<

main.o: main.c
	gcc -g -std=c99 -c $<

main:  utils.o esercizi.o main.o
	gcc -g  -o $@ $^

