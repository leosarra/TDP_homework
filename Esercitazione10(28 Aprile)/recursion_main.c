#include <stdio.h>
#include <string.h>
#include "utils.c"
#include "recursion.h"

int main(int argc, char** argv) {  
  char data1[]  = "0000110111";
  char data2[]  = "110100001";
  char data3[]  = "0";
  BinSeq* bin_seq1 = allocBinSeq(1024);
  BinSeq* bin_seq2 = allocBinSeq(1024);
  BinSeq* bin_seq3 = allocBinSeq(1024);
  fillBinSeq(bin_seq1, &data1[0]);
  fillBinSeq(bin_seq2, &data2[0]);
  fillBinSeq(bin_seq3, &data3[0]);

  printBinSeq(bin_seq1);
  printf("e' lunga %d caratteri\n", length(bin_seq1));
  printBinSeq(bin_seq2);
  printf("e' lunga %d caratteri\n", length(bin_seq2));
  printBinSeq(bin_seq3);
  printf("e' lunga %d caratteri\n", length(bin_seq3));
  printf("-------------------------------------------\n");

  printf("Copio la prima sequenza binaria nella terza:\n");
  copy(bin_seq3, bin_seq1);
  printBinSeq(bin_seq3);
  printf("e' lunga %d caratteri\n", length(bin_seq3));
  printf("-------------------------------------------\n");

  printf("Concateno la seconda sequenza alla terza:\n");
  concatenate(bin_seq3, bin_seq2);
  printBinSeq(bin_seq3);
  printf("e' lunga %d caratteri\n", length(bin_seq3));
  printf("-------------------------------------------\n");

  int index = indexOf(bin_seq3, '1');
  printf("L'indice del primo carattere uguale a 1 nella sequenza appena concatenata e': %d\n", index);
  index = indexOf(bin_seq3, '0');
  printf("L'indice del primo carattere uguale a 0 nella sequenza appena concatenata e': %d\n", index);
  printf("-------------------------------------------\n");

  int bin_seq_equal = equal(bin_seq1, bin_seq2);
  if(bin_seq_equal == 0) { 
    printf("Le prime due sequenze binarie non sono uguali!!!\n");
  }
  else {
    printf("Le prime due sequenze binarie sono uguali!!!\n");
  }
  printf("-------------------------------------------\n");

  char data4[] = "0001";
  char data5[] = "11";
  BinSeq* bin_seq4 = allocBinSeq(1024);
  BinSeq* bin_seq5 = allocBinSeq(1024);
  fillBinSeq(bin_seq4, &data4[0]);
  fillBinSeq(bin_seq5, &data5[0]);
  printBinSeq(bin_seq4);
  int is_prefix = prefix(bin_seq1, bin_seq4);
  if(is_prefix == 0) {
    printf("non e' un prefisso di\n");
  }
  else {
    printf("e' un prefisso di\n");
  }
  printBinSeq(bin_seq1);
  printBinSeq(bin_seq5);
  is_prefix = prefix(bin_seq2, bin_seq5);
  if(is_prefix == 0) {
    printf("non e' un prefisso di\n");
  }
  else {
    printf("e' un prefisso di\n");
  }
  printBinSeq(bin_seq2);
  printf("-------------------------------------------\n");

  int max_sequence = lengthMaxSequence(bin_seq1, '1');
  printf("La più lunga sequenza di cifre pari a 1 nella prima sequenza binaria è: %d\n", max_sequence);
  max_sequence = lengthMaxSequence(bin_seq2, '0');
  printf("La più lunga sequenza di cifre pari a 0 nella seconda sequenza binaria è: %d\n", max_sequence);
  max_sequence = lengthMaxSequence(bin_seq3, '1');
  printf("La più lunga sequenza di cifre pari a 1 nella sequenza binaria concatenata è: %d\n", max_sequence);

  return 0;
}
