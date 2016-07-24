#pragma once

// Struttura per la rappresentazione di una sequenza binaria
typedef struct BinSeq {
  char* data;    // la sequenza binaria è rappresentata come un array di caratteri '0' e '1'
  int dimension; // dimensione dell'array contenente la sequenza binaria, non è la lunghezza della sequenza
} BinSeq;

BinSeq* allocBinSeq(int dimension);

void resizeBinSeq(BinSeq* bin_seq, int dimension);

void freeBinSeq(BinSeq* bin_seq);

void fillBinSeq(BinSeq* bin_seq, char* data);

void printBinSeq(BinSeq* bin_seq);
