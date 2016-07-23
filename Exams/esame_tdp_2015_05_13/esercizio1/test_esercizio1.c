#include <stdio.h>

#include "../test_utils/test_utils.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int failures = 0, successes = 0;  
  int i;
  for(i = 0; i < 10; i++) {
    printf("\n");
    char file[1024];
    sprintf(file, "./test_examples/cards%d.txt", i);
    Card **input = NULL, **ground_truth = NULL;
    int size = 0;
    read_cards(&file[0], &size, &input, &ground_truth);
    printf("Input    ");
    print(input, size);
    printf("Expected ");
    print(ground_truth, size);
    swap_pairs(input, size);
    printf("Result   ");
    print(input, size);
    int result = compare(ground_truth, input, size);
    if(result > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
      failures++;
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(successes + failures));
    free_cards(input, size);
    free_cards(ground_truth, size);
    printf("\n*************************************************\n\n");
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(successes + failures));

  return 0;
}
