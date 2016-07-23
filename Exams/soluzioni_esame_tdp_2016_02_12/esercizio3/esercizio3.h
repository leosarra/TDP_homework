#ifndef _ESERCIZIO3_H_
#define _ESERCIZIO3_H_

// element of a sparse matrix
struct SparseMatrixElement {
  int row;                    // row index in the matrix
  int col;                    // col index in the matrix
  float value;                // value
  SparseMatrixElement* next;  // next ptr
};
typedef struct SparseMatrixElement SparseMatrixElement;
typedef SparseMatrixElement* SparseMatrix;

int sparse_matrix_contains_element(SparseMatrix sparse_mat, float value);

#endif
