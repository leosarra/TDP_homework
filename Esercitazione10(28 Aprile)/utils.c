#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

BinSeq* allocBinSeq(int dimension) {
  if(dimension == 0) { 
    return 0; 
  }
  BinSeq* bin_seq = (BinSeq*) malloc(sizeof(BinSeq));
  char* data = (char*) malloc(sizeof(char) * dimension);
  bin_seq->data = data;
  bin_seq->dimension = dimension;  
  return bin_seq;
}

void resizeBinSeq(BinSeq* bin_seq, int dimension) {
  if(bin_seq == 0 || dimension == 0) {
    return;
  }
  char* data = (char*)realloc(bin_seq->data, dimension);
  bin_seq->data = data;
  bin_seq->dimension = dimension;
}

void freeBinSeq(BinSeq* bin_seq) {
  if(bin_seq == 0) {
    return;
  } 
  free(bin_seq->data);
  free(bin_seq);
}

void fillBinSeq(BinSeq* bin_seq, char* data) {
  if(bin_seq == 0 || data == 0) {
    return;
  }
  if(strlen(data) + 1 > bin_seq->dimension) {
    resizeBinSeq(bin_seq, strlen(data) + 1);
  }
  strcpy(bin_seq->data, data);
}

void printBinSeq(BinSeq* bin_seq) {
  if(bin_seq == 0) {
    return;
  } 
  int i;
  int size = strlen(bin_seq->data);
  printf("Binary Sequence: ");
  for(i = 0; i < size; i++) {
    printf("%c ", (bin_seq->data)[i]);
  }
  printf("\n");
}

