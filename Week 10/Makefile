all: mat.o list.o esercizi.o main.o
	gcc --std=gnu99 -Wall -o main $^

#mat.o:
#	gcc --std=gnu99 -Wall -c -o mat.o mat.c

#list.o:
#	gcc --std=gnu99 -Wall -c -o list.o list.c

#esercizi.o:
#	gcc --std=gnu99 -Wall -c -o esercizi.o esercizi.c

%.o: %.c
	gcc --std=gnu99 -Wall -c -o $@ $<

clean:
	rm *.o main
