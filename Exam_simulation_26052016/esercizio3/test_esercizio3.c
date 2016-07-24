#include <stdio.h>
#include <stdlib.h>

#include "esercizio3.h"
#include "correttore_esercizio3.h"
#include "../utils/list.h"
#include "../utils/vec.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;
  char buffer[1024];
  int i, expected_dim, output_dim;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    sprintf(buffer, "data/source_list_%d.txt", i);
    TipoSCL source_list = TipoSCL_load(buffer);
    printf("source   ");
    TipoSCL_print(source_list);

    int* expected_vec = ground_truth(&expected_dim, source_list);
    printf("expected ");
    vectori_print(expected_vec, expected_dim);

    int* output_vec = integralVector(&output_dim, source_list);
    printf("output   ");
    vectori_print(output_vec, output_dim);

    if(expected_dim == output_dim &&
       vectori_compare(expected_vec, output_vec, expected_dim)) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");

    TipoSCL_free(source_list);
    vectori_free(expected_vec);
    vectori_free(output_vec);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
