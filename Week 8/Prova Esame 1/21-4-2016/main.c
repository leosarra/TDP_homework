#include <stdio.h>
#include <stdlib.h>
#include "utils.h"





// Esercizi da svolgere nel file esercizi.c
void esercizio1(char *A, char *B, int n, char **C);
float esercizio2(float **mat, int n, int *r, int *c);

int main(int argc, char** argv) {

  char* filename = "m1.txt";
  if (argc>1)
      filename=argv[1];
  int num_rows,num_cols;
  float** mat = Matrix_readFromPath(filename, &num_rows, &num_cols);
  if (mat==NULL) return -1;
  
  printf("\n=== TEST Esercizio 1 ===\n");
  char *A = "ABDFHIJ";
  char *B = "JFBCAKN"; int n = 7;
  char *C; int nC=n*2;
  printf("\nIsdnput:  A = %s - B = %s\n",A,B);
  
  esercizio1(A, B, n, &C);
  printf("\nOutput: ");
  for (int i=0; i<nC;i++) printf("%c",C[i]);
  printf("\n");
  free(C);
  
  
  printf("\n=== TEST Esercizio 2 ===\n");
  printf("\nInput: \n");
  Matrix_write(stdout, mat, num_rows, num_cols);
  Matrix_writeOnPath("m1_out.txt", mat, num_rows, num_cols);

  int r,c;
  float v = esercizio2(mat,num_rows,&r,&c);
  
  printf("\nOutput: max value = %.2f, row = %d, col = %d\n",v,r,c);
    
  Matrix_free(mat,num_rows);
 
}
