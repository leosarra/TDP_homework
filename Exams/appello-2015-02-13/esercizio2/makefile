TEST_DIR=../libtest
LIBS=-lm
CC=gcc
CFLAGS=-Werror -std=c99

all: test

test: esercizio.o test.o libtest.o
	$(CC) $(CFLAGS) -o test esercizio.o test.o libtest.o $(LIBS)

esercizio.o: esercizio.h esercizio.c
	$(CC) $(CFLAGS) -c esercizio.c

test.o: test.c test.h esercizio.h
	$(CC) $(CFLAGS) -c test.c

libtest.o: $(TEST_DIR)/libtest.c $(TEST_DIR)/libtest.h
	$(CC) $(CFLAGS) -c $(TEST_DIR)/libtest.c

clean:
	rm -f *.o test