#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "../utils/vec.h"
#include "../utils/list.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;
  char buffer[1024];
  int i, n;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    sprintf(buffer, "data/source_list_%d.txt", i);
    TipoSCL source_list = TipoSCL_load(buffer);
    printf("source list ");
    TipoSCL_print(source_list);

    sprintf(buffer, "data/source_vec_%d.txt", i);
    char* source_vec = vectorc_load(&n, buffer);
    printf("source vector ");
    vectorc_print(source_vec, n);

    sprintf(buffer, "data/expected_list_%d.txt", i);
    TipoSCL expected_list = TipoSCL_load(buffer);
    printf("expected list ");
    TipoSCL_print(expected_list);

    TipoSCL output_list =  fetch_elements(source_list, source_vec, n);
    printf("output list ");
    TipoSCL_print(output_list);

    int cmp = TipoSCL_compare(expected_list, output_list);
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

    vectorc_free(source_vec);
    TipoSCL_free(expected_list);
    TipoSCL_free(output_list);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
	 (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
