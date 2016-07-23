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

    sprintf(buffer, "data/source_mat_a_%d.txt", i);
    int** source_mat_a = matrixi_load(&rows, &cols, buffer);
    printf("source matrix a ");
    matrixi_print(source_mat_a, rows, cols);

    sprintf(buffer, "data/source_mat_b_%d.txt", i);
    int** source_mat_b = matrixi_load(&rows, &cols, buffer);
    printf("source matrix b ");
    matrixi_print(source_mat_b, rows, cols);

    sprintf(buffer, "data/expected_vec_%d.txt", i);
    int* expected_vec = vectori_load(&n, buffer);
    printf("expected vector: ");
    vectori_print(expected_vec, n);
    printf("expected returned vector size: %d\n", n);

    int* output_vec;
    int dim = matrix_min(&output_vec, source_mat_a, source_mat_b, rows, cols);
    printf("output vector:   ");
    vectori_print(output_vec, dim);
    printf("output vector size: %d\n", dim);

    int cmp = vectori_compare(expected_vec, output_vec, n);
    if(n == dim && cmp > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n",
    	   (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");

    matrixi_free(source_mat_a, rows);
    matrixi_free(source_mat_b, rows);
    vectori_free(expected_vec);
    vectori_free(output_vec);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
	 (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
