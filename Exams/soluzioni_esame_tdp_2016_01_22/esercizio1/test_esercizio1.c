#include <stdio.h>
#include <stdlib.h>

#include "../utils/mat.h"
#include "../utils/vec.h"
#include "esercizio1.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;
    
  char buffer[1024];
  int i, rows, cols, n;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    sprintf(buffer, "data/source_mat_%d.txt", i);
    int** source_mat = matrixi_load(&rows, &cols, buffer);
    printf("source matrix ");
    matrixi_print(source_mat, rows, cols);

    sprintf(buffer, "data/source_vec_%d.txt", i);
    char* source_vec = vectorc_load(&n, buffer);
    printf("source vector ");
    vectorc_print(source_vec, n);

    sprintf(buffer, "data/expected_mat_%d.txt", i);
    char** expected_mat = matrixc_load(&rows, &cols, buffer);
    printf("expected matrix ");
    matrixc_print(expected_mat, rows, cols);

    char** output_mat = translate_matrix(rows, cols, source_mat, source_vec);
    printf("output matrix ");
    matrixc_print(output_mat, rows, cols);

    int cmp = matrixc_compare(expected_mat, output_mat, rows, cols);
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

    matrixi_free(source_mat, rows);
    vectorc_free(source_vec);
    matrixc_free(expected_mat, rows);
    matrixc_free(output_mat, rows);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
	 (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
