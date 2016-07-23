#include <stdlib.h>

#include "esercizio2.h"

float** sparse_to_dense_matrix(SparseMatrix sparse_mat, int rows, int cols) {  
  float** mat = (float**)calloc(rows + 1, sizeof(float*));
  for(int r = 0; r < rows; ++r) {
    mat[r] = (float*)calloc(cols, sizeof(float));
  }

  while(sparse_mat != NULL) {
    mat[sparse_mat->row][sparse_mat->col] = sparse_mat->value;
    sparse_mat = sparse_mat->next;
  }

  return mat;
}
