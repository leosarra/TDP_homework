#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "mat.h"

// Data in input una liste list, e due caratteri new e old, aggiorna gli
// elementi di list contenenti il carattere old con new.
void str_update(TipoSCL list, char new, char old);

// Data in input una matrice di dimensione rows x cols e un valore intero
// value, crea e restituisce un vettore contenente gli indici lineari
// degli elementi di mat che sono maggiori di value. Si ricorda che
// l'indice lineare di un elemento (r, c) di una matrice di dimension
// rows x cols e' uguale a r * cols + j. La funzione deve scrivere la 
// dimensione del vettore di output nel parametro n.
int* mat_find(Mat *mat, int value, int *n);

// Dato in input un vettore v di dimension n e un intero value, scriva
// ricorsivamente zero negli elementi di v che sono minori di value. 
void vec_wipe(int *v, int n, int value);

int main(int argc, char** argv) {
  // test str_update
  TipoSCL l1 = TipoSCL_load("list_1.txt");
  TipoSCL l2 = TipoSCL_load("list_2.txt");
  printf("l1: ");
  TipoSCL_print(l1);
  printf("Sostituisco in l1 il carattere \'o\' con il carattere \'u\'...\n");
  str_update(l1, 'u', 'o');
  printf("l1: "); 
  TipoSCL_print(l1);
  printf("\n\n");

  printf("l2: ");
  TipoSCL_print(l2);
  printf("Sostituisco in l2 il carattere \'a\' con il carattere \'z\'...\n");
  str_update(l2, 'z', 'a');
  printf("l2: "); 
  TipoSCL_print(l2);
  printf("\n\n");
  TipoSCL_free(l1);
  TipoSCL_free(l2);
  
  // test mat_find
  Mat *mat = Mat_read("mat_1.txt");
  printf("mat:\n");
  Mat_print(mat);
  printf("Cerco valori maggiori di 4...\n");
  int n;
  int *idxs = mat_find(mat, 4, &n);
  printf("idxs: ");
  for(int i = 0; i < n; ++i) {
    printf("%d ", idxs[i]);
  }
  printf("\n\n");
  Mat_free(mat);
  
  // test vec_wipe
  int v[10] = { 2, 4, 8, 1, 3, 6, 8, 0, 9, 7 };
  printf("v: ");
  for(int i = 0; i < 10; ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
  printf("Cerco e azzero i valori minori di 5...\n");
  vec_wipe(v, 10, 5);
  printf("v: ");
  for(int i = 0; i < 10; ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}


