#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "../utils/mat.h"
#include "../utils/sparse_matrix.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;

  char buffer[1024];
  int i, rows, cols;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    sprintf(buffer, "data/source_sparse_mat_%d.txt", i);
    SparseMatrix source_sparse_mat = SparseMatrix_load(buffer);
    printf("source sparse matrix: ");
    SparseMatrix_print(source_sparse_mat);

    sprintf(buffer, "data/expected_mat_%d.txt", i);
    float** expected_mat = matrixf_load(&rows, &cols, buffer);
    printf("expected matrix ");
    matrixf_print(expected_mat, rows, cols);
    
    float** output_mat = sparse_to_dense_matrix(source_sparse_mat, rows, cols);
    printf("output mat ");
    matrixf_print(output_mat, rows, cols);

    int cmp = matrixf_compare(expected_mat, output_mat, rows, cols);
    if(cmp > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n",
    	   (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");

    matrixf_free(output_mat, rows);
    matrixf_free(expected_mat, rows);
    SparseMatrix_free(source_sparse_mat);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
  	 (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
