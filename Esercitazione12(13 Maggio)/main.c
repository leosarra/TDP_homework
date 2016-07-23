#include <stdio.h>

#include "set.h"


int main(int argc, char **argv) {
  char set_filename1[] = "set_1.txt";
  char set_filename2[] = "set_2.txt";
  char set_filename3[] = "set_3.txt";
  char set_filename4[] = "set_4.txt";
  SetElem *set1 = set_load(set_filename1);
  SetElem *set2 = set_load(set_filename2);
  SetElem *set3 = set_load(set_filename3);
  SetElem *set4 = set_load(set_filename4);
  
  /* Test print */
  printf("*** Test print ***\n");
  printf("set1: ");
  set_print(set1);
  printf("set2: ");
  set_print(set2);
  printf("set3: ");
  set_print(set3);
  printf("set4: ");
  set_print(set4);
  printf("\n");    
  
  /* Test is_empty */
  printf("*** Test is_empty ***\n");
  if(is_empty(set1)) {
    printf("set1 e' vuoto\n");    
  }
  else {
    printf("set1 non e' vuoto\n");    
  }
  if(is_empty(set2)) {
    printf("set2 e' vuoto\n");    
  }
  else {
    printf("set2 non e' vuoto\n");
  }
  if(is_empty(set3)) {
    printf("set3 e' vuoto\n");    
  }
  else {
    printf("set3 non e' vuoto\n");
  }
  printf("\n");    

  /* Test is_element */
  printf("*** Test is_element ***\n");
  if(is_element(set1, 5)) {
    printf("set1 contiene l'elemento 5\n");
  }
  else {
    printf("set1 non contiene l'elemento 5\n");
  }
  if(is_element(set2, 0)) {
    printf("set2 contiene l'elemento 0\n");
  }
  else {
    printf("set2 non contiene l'elemento 0\n");
  }
  if(is_element(set3, 8)) {
    printf("set3 contiene l'elemento 8\n");
  }
  else {
    printf("set3 non contiene l'elemento 8\n");
  }
  printf("\n");
  
  /* Test is_set */
  printf("*** Test is_set ***\n");
  if(is_set(set1)) {
    printf("set1 e' un insieme\n");
  }
  else {
    printf("set1 non e' un insieme\n");
  }
  if(is_set(set2)) {
    printf("set2 e' un insieme\n");
  }
  else {
    printf("set2 non e' un insieme\n");
  }
  if(is_set(set3)) {
    printf("set3 e' un insieme\n");
  }
  else {
    printf("set3 non e' un insieme\n");
  }
 
  if(is_set(set4)) {
    printf("set4 e' un insieme\n");
  }
  else {
    printf("set4 non e' un insieme\n");
  }
  printf("\n");

  /* Test is_subset */
  printf("*** Test is_subset ***\n");
  if(is_subset(set1, set2)) {
    printf("set1 e' un sotto insieme di set2\n");
  }
  else {
    printf("set1 non e' un sotto insieme di set2\n");
  }
  if(is_subset(set2, set3)) {
    printf("set2 e' un sotto insieme di set3\n");
  }
  else {
    printf("set2 non e' un sotto insieme di set3\n");
  }
  if(is_subset(set3, set2)) {
    printf("set3 e' un sotto insieme di set2\n");
  }
  else {
    printf("set3 non e' un sotto insieme di set2\n");
  }
  printf("\n");  

  /* Test set_add */
  printf("*** Test set_add ***\n");
  printf("aggiungo l'elemento 5 a set1: ");
  set_add(&set1, 5);
  set_print(set1);
  printf("aggiungo l'elemento 0 a set1: ");
  set_add(&set1, 0);
  set_print(set1);
  printf("aggiungo l'elemento 4 a set2: ");
  set_add(&set2, 4);
  set_print(set2);
  printf("aggiungo l'elemento 9 a set3: ");
  set_add(&set3, 9);
  set_print(set3);
  printf("aggiungo l'elemento 0 a set3: ");
  set_add(&set3, 0);
  set_print(set3);
  printf("\n");  

  /* Test set_del */
  printf("*** Test set_del ***\n");
  printf("rimuovo l'elemento 5 da set1: ");
  set_del(&set1, 5);
  set_print(set1);
  printf("rimuovo l'elemento 0 da set1: ");
  set_del(&set1, 0);
  set_print(set1);
  printf("rimuovo l'elemento 4 da set2: ");
  set_del(&set2, 4);
  set_print(set2);
  printf("rimuovo l'elemento 9 da set3: ");
  set_del(&set3, 9);
  set_print(set3);
  printf("rimuovo l'elemento 7 da set3: ");
  set_del(&set3, 7);
  set_print(set3);
  printf("\n");  

  /* Test set_union */
  printf("*** Test set_union ***\n");
  printf("unisco gli insiemi set1 e set2 e il risultato lo metto in set2: ");
  set_union(set1, &set2);
  set_print(set2);
  printf("unisco gli insiemi set2 e set3 e il risultato lo metto in set2: ");
  set_union(set3, &set2);
  set_print(set2);
  printf("\n");

  /* Test set_difference */
  printf("*** Test set_difference ***\n");
  printf("faccio la differenza tra gli insiemi set1 e set2 e il risultato lo metto in set1: ");
  set_difference(set2, &set1);
  set_print(set1);
  printf("faccio la differenza tra gli insiemi set2 e set3 e il risultato lo metto in set3: ");
  set_difference(set2, &set3);
  set_print(set3);
  printf("\n");  
  
  return 0;
}
