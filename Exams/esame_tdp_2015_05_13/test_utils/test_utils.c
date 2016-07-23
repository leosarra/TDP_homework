#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "test_utils.h"

void print(Card** cards, int size) {
  if(cards == NULL) {
    printf("{ }\n");
    return;
  }
  int i;
  printf("Cards: { ");
  for(i = 0; i < size; i++) {
    printf("%s %d", cards[i]->seed, cards[i]->number);
    if(i != size - 1) {
      printf(", ");
    }
    else {
      printf(" ");
    }
  }
  printf("}\n");
}

void read_cards(char* file, int* size, Card*** input, Card*** ground_truth) {
  *size = 0;
  *input = NULL;
  *ground_truth = NULL;

  FILE* f = fopen(file, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", file);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f,"%s", buffer) == 1) { 
    *size = atoi(buffer); 
  }
  else {
    printf("Error while reading file %s, cannot read the size of the array of cards... aborting!\n", file);
    exit(-1);
  }

  if(*size == 0) { 
    return;
  }

  *input = alloc_cards(*size);
  *ground_truth = alloc_cards(*size);
  int i = 0;  
  while(i < *size) {
    int result;
    result = fscanf(f, "%s", buffer);
    if(result != 1) {
      printf("Error while reading file %s, cannot read %d-th input card seed... aborting!\n", file, i);
      exit(-1);
    }
    strcpy((*input)[i]->seed, buffer);

    result = fscanf(f, "%s", buffer);
    if(result != 1) {
      printf("Error while reading file %s, cannot read %d-th input card number... aborting!\n", file, i);
      exit(-1);
    }
    (*input)[i]->number = atoi(buffer);

    result = fscanf(f, "%s", buffer);
    if(result != 1) {
      printf("Error while reading file %s, cannot read %d-th ground truth card seed... aborting!\n", file, i);
      exit(-1);
    }
    strcpy((*ground_truth)[i]->seed, buffer);

    result = fscanf(f, "%s", buffer);
    if(result != 1) {
      printf("Error while reading file %s, cannot read %d-th ground truthcard number... aborting!\n", file, i);
      exit(-1);
    }
    (*ground_truth)[i]->number = atoi(buffer);
    i++;
  }
}
 
Card** alloc_cards(int size) {
  Card* data = (Card*)malloc(size * sizeof(Card));
  Card** row_ptrs = (Card**)malloc(size * sizeof(Card*));
  int i;
  for (i = 0; i < size; i++) {
    row_ptrs[i] = data + i;
  }
  return row_ptrs;
}

void free_cards(Card** cards, int size) {
  if(size == 0) { return; }
  Card* data_ptr = cards[0];
  int i;
  for(i = 0; i < size; i++) {
    if(data_ptr > cards[i]) {
      data_ptr = cards[i];
    }
  }
  free(data_ptr);
  free(cards);
}

int compare(Card** ground_truth, Card** result, int size) {
  int i;
  for(i = 0; i < size; i++) {
    if(strcmp(result[i]->seed, ground_truth[i]->seed) != 0 ||
       result[i]->number != ground_truth[i]->number) {
      return 0;
    }
  } 
  return 1;
}
