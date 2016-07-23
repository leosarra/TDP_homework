#include <stdlib.h>
#include <stdio.h>

#include "esercizio1.h"

char** translate_matrix(int rows, int cols, int** input, char* v) {
  char** output = (char**)malloc(rows * sizeof(char*));
  for(int i = 0; i < rows; ++i) {
    output[i] = (char*)malloc(cols * sizeof(char));
  }
  
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      output[r][c] = v[input[r][c]];
    }
  }

  return output;
}
