#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include "../esercizio1/esercizio1.h"

void print(Card** cards, int size);

void read_cards(char* file, int* size, Card*** input, Card*** ground_truth);

Card** alloc_cards(int size);

void free_cards(Card** cards, int size);

int compare(Card** ground_truth, Card** result, int size);

#endif



