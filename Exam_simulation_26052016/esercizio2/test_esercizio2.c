#include <stdio.h>
#include <stdlib.h>

#include "esercizio2.h"
#include "correttore_esercizio2.h"
#include "../utils/mat_struct.h"
#include "../utils/list.h"

int main(int argc, char** argv) {
  int total_test_number = 10, successes = 0;
  float values_thresholds[10] = { 1, 2, 0, 4, -3, 4, 2, 3, 1, 100 };
  char buffer[1024];
  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    sprintf(buffer, "data/source_mat_%d.txt", i);
    Mat* source_mat = Mat_load(buffer);
    printf("src ");
    Mat_print(source_mat);

    printf("Create a list containing matrix values lower than %f\n",
	   values_thresholds[i]);

    TipoSCL expected_list = ground_truth(source_mat, values_thresholds[i]);
    printf("expected ");
    TipoSCL_print(expected_list);

    TipoSCL output_list = lowerValues(source_mat, values_thresholds[i]);
    printf("output   ");
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

    Mat_free(source_mat);
    TipoSCL_free(expected_list);
    TipoSCL_free(output_list);
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n",
	 (float)(successes) * 100.0f / (float)(total_test_number));

  return 0;
}
