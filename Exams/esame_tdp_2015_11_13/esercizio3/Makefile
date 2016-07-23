UTILS_DIR=../utils
LIBS=-lm
CPPC=g++
CPPFLAGS=-Wall

all: test_esercizio3

test_esercizio3: test_esercizio3.c esercizio3.c $(UTILS_DIR)/list.c $(UTILS_DIR)/vec.c
	$(CPPC) $(CPPFLAGS) $(LIBS) test_esercizio3.c esercizio3.c $(UTILS_DIR)/list.c $(UTILS_DIR)/vec.c -o test_esercizio3 -DESERCIZIO_3=1

clean:
	rm -rf *.o test_esercizio3
