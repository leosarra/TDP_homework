#include <stdio.h>
#include <stdlib.h>
#include "esercizio1.h"

int compare(TipoSCL scl1, TipoSCL scl2) {
  if(scl1 == NULL && scl2 == NULL) { return 1; }
  if(scl1 == NULL && scl2 != NULL) { return 0; }
  if(scl1 != NULL && scl2 == NULL) { return 0; }

  while(scl1 != NULL && scl2 != NULL) {
    if(scl1->info != scl2->info) { return 0; }
    scl1 = scl1->next;
    scl2 = scl2->next;
  }

  if(scl1 != NULL || scl2 != NULL) { return 0; }

  return 1;
}

void print(TipoSCL scl) {
  if(scl == NULL) { 
    printf("[ ]\n"); 
    return;
  }
  
  printf("[ ");
  while(scl->next != NULL) {
    printf("%d -> ", scl->info);
    scl = scl->next;
  }
  printf("%d ]\n", scl->info);
}

int main(int argc, char** argv) {  
  int successes = 0, total_test_number = 10;  
  int i, expected_deleted[10] = {0, 1, 0, 1, 0, 1, 2, 2, 2, 4};
  
  TipoSCL input[total_test_number];
  TipoSCL expected[total_test_number];

  input[0] = NULL;
    
  input[1] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[1] -> info = 1;
  input[1] -> next = NULL;

  input[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[2] -> info = 2;
  input[2] -> next = NULL;
    
  input[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[3] -> info = 1;
  input[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[3] -> next -> info = 4;
  input[3] -> next -> next = NULL;

  input[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[4] -> info = 2;
  input[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[4] -> next -> info = 4;
  input[4] -> next -> next = NULL;
    
  input[5] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[5] -> info = 5;
  input[5] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[5] -> next -> info = 1;
  input[5] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[5] -> next -> next -> info = 3;
  input[5] -> next -> next -> next = NULL;
    
  input[6] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[6] -> info = 1;
  input[6] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[6] -> next -> info = 7;
  input[6] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[6] -> next -> next -> info = 1;
  input[6] -> next -> next -> next = NULL;

  input[7] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[7] -> info = 1;
  input[7] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[7] -> next -> info = 9;
  input[7] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[7] -> next -> next -> info = 1;
  input[7] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[7] -> next -> next -> next -> info = 2;
  input[7] -> next -> next -> next -> next = NULL;

  input[8] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[8] -> info = 7;
  input[8] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[8] -> next -> info = 1;
  input[8] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[8] -> next -> next -> info = 1;
  input[8] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[8] -> next -> next -> next -> info = 6;
  input[8] -> next -> next -> next -> next = NULL;

  input[9] = (TipoSCL) malloc(sizeof(NodoSCL));
  input[9] -> info = 1;
  input[9] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[9] -> next -> info = 4;
  input[9] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[9] -> next -> next -> info = 1;
  input[9] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[9] -> next -> next -> next -> info = 1;
  input[9] -> next -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[9] -> next -> next -> next -> next -> info = 3;
  input[9] -> next -> next -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  input[9] -> next -> next -> next -> next -> next -> info = 1;
  input[9] -> next -> next -> next -> next -> next ->next = NULL;
    
  expected[0] = NULL;
    
  expected[1] = NULL;

  expected[2] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[2] -> info = 2;
  expected[2] -> next = NULL;
    
  expected[3] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[3] -> info = 4;
  expected[3] -> next = NULL;

  expected[4] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[4] -> info = 2;
  expected[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[4] -> next -> info = 4;
  expected[4] -> next -> next = NULL;
    
  expected[5] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[5] -> info = 5;
  expected[5] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[5] -> next -> info = 3;
  expected[5] -> next -> next = NULL;
    
  expected[6] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[6] -> info = 7;
  expected[6] -> next = NULL;

  expected[7] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[7] -> info = 9;
  expected[7] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[7] -> next -> info = 2;
  expected[7] -> next -> next = NULL;

  expected[8] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[8] -> info = 7;
  expected[8] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[8] -> next -> info = 6;
  expected[8] -> next -> next = NULL;

  expected[9] = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[9] -> info = 4;
  expected[9] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
  expected[9] -> next -> info = 3;
  expected[9] -> next ->next = NULL;

  printf("\n");
  for(i = 0; i < total_test_number; ++i) { 
    printf("Delete all occurences of 1 inside the input list\n");
    printf("Input   : ");
    print(input[i]); 
    printf("Expected: ");
    print(expected[i]); 
    int deleted = delete_occurrences(&input[i], 1);
    printf("Result  : ");
    print(input[i]);
    printf("Number of deleted elements: %d\n", deleted);
    int result = compare(input[i], expected[i]);
    if(result > 0 && deleted == expected_deleted[i]) {
      printf("SUCCESS\n");
      successes++;
    }
    else { printf("FAILURE\n"); }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
