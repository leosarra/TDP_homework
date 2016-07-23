TEST_UTILS_DIR=../test_utils
LIBS=-lm
CC=c99
CFLAGS=

all: test_esercizio1

test_esercizio1: esercizio1.o test_esercizio1.o test_utils.o
	$(CC) $(CFLAGS) -o test_esercizio1 esercizio1.o test_esercizio1.o test_utils.o $(LIBS)

esercizio.o: esercizio1.h esercizio1.c
	$(CC) $(CFLAGS) -c esercizio1.c

test.o: test_esercizio1.c esercizio1.h
	$(CC) $(CFLAGS) -c test_esercizio1.c

test_utils.o: $(TEST_UTILS_DIR)/test_utils.c $(TEST_UTILS_DIR)/test_utils.h
	$(CC) $(CFLAGS) -c $(TEST_UTILS_DIR)/test_utils.c

clean:
	rm -rf *.o test_esercizio1
