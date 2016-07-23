#include <stdio.h>
#include <stdlib.h>

#include "../utils/mat_struct.h"
#include "correttore_esercizio1.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int total_test_number = 10, successes = 0;
  int scaling_factors[10] = { 2, 4, 1, 3, 1, 2, 3, 2, 6, 1};

  char buffer[1024];
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    sprintf(buffer, "data/source_mat_%d.txt", i);
    Mat* source_mat = Mat_load(buffer);
    printf("src ");
    Mat_print(source_mat);

    printf("Scaling the input matrix of a factor of %d\n", scaling_factors[i]);

    Mat* expected_mat = ground_truth(source_mat, scaling_factors[i]);
    printf("expected ");
    Mat_print(expected_mat);

    Mat* output_mat =  matrixScale(source_mat, scaling_factors[i]);
    printf("output ");
    Mat_print(output_mat);

    int cmp = Mat_compare(expected_mat, output_mat);
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

    Mat_free(source_mat);
    Mat_free(expected_mat);
    Mat_free(output_mat);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
	 (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
