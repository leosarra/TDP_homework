#include <stdlib.h>
#include <stdio.h>

#include "esercizio1.h"

int matrix_min(int** dest, int** a, int** b, int rows, int cols) {
  int dest_size = 0;
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      if(a[r][c] <= b[r][c]) {
	dest_size++;
      }
    }
  }

  if(dest_size == 0) {
    *dest = NULL;
    return dest_size;
  }

  int i = 0;
  *dest = (int*)malloc(dest_size * sizeof(int));
  for(int r = 0; r < rows; ++r) {
    for(int c = 0; c < cols; ++c) {
      if(a[r][c] <= b[r][c]) {
	(*dest)[i] = a[r][c];
	i++;
      }
    }
  }

  return dest_size;
}
