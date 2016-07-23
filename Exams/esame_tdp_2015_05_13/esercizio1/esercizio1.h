#ifndef _ESERCIZIO1_H_
#define _ESERCIZIO1_H_

typedef struct Card {
  char seed[1024];
  int number;
} Card;

void swap_pairs(Card** cards, int size);

#endif
