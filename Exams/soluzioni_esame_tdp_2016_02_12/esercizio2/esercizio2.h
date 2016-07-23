#ifndef _ESERCIZIO2_H_
#define _ESERCIZIO2_H_

// element of a sparse matrix
struct SparseMatrixElement {
  int row;                    // row index in the matrix
  int col;                    // col index in the matrix
  float value;                // value
  SparseMatrixElement* next;  // next ptr
};
typedef struct SparseMatrixElement SparseMatrixElement;
typedef SparseMatrixElement* SparseMatrix;

float** sparse_to_dense_matrix(SparseMatrix sparse_mat, int rows, int cols);

#endif
