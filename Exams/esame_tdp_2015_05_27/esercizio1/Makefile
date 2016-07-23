TEST_UTILS_DIR=../test_utils
LIBS=-lm
CC=c99
CFLAGS=

all: test_esercizio1

test_esercizio1: esercizio1.o test_esercizio1.o
	$(CC) $(CFLAGS) -o test_esercizio1 esercizio1.o test_esercizio1.o $(LIBS)

esercizio.o: esercizio1.h esercizio1.c
	$(CC) $(CFLAGS) -c esercizio1.c

clean:
	rm -rf *.o test_esercizio1
