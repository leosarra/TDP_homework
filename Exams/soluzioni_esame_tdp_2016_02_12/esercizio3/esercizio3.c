#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "esercizio3.h"

int sparse_matrix_contains_element(SparseMatrix sparse_mat, float value) {
  if(sparse_mat == NULL) { 
    return 0;
  }
  else if(sparse_mat->value == value) {
    return 1;
  }
  else {
    return sparse_matrix_contains_element(sparse_mat->next, value);
  }
}
