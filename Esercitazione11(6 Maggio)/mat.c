#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mat.h"

Mat* Mat_alloc(int rows, int cols) {
  Mat* m = (Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (int**)malloc(rows * sizeof(int*));
  for(int i = 0; i < m->rows; ++i) {
    m->row_ptrs[i] = (int*)malloc(m->cols * sizeof(int));
  }
  return m;
}

Mat* Mat_read(char *filename) {
  FILE *fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("Errore nell'apertura del file %s... esco!\n", filename);
    exit(-1);
  }

  int rows, cols;
  char buffer[1024];  
  if(fscanf(fp, "%s", buffer) == 1) { rows = atoi(buffer); }
  else {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di righe... esco!\n", filename);
    exit(-1);
  }
  if(rows == 0) {
    return NULL;
  }

  if(fscanf(fp, "%s", buffer) == 1) { cols = atoi(buffer); }
  else {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di colonne... esco!\n", filename);
    exit(-1);
  }
  if(cols == 0) {
    return NULL;
  }

  int i = 0;
  Mat *m = Mat_alloc(rows, cols);
  while(i < (m->rows * m->cols) && fscanf(fp, "%s", buffer) == 1) {
    int row = i / (m->cols);
    int col = i % (m->cols);
    m->row_ptrs[row][col] = atoi(buffer);
    i++;
  }
  if(i != (m->rows * m->cols)) {
    printf("Errore durante la lettura del file %s, non riesco a leggere tutti gli elementi... esco!\n", filename);
    exit(-1);
  }

  fclose(fp);

  return m;
}

void Mat_print(Mat *m) {
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {
      printf("%d ", m->row_ptrs[r][c]);
    }
    printf("\n");
  }
}

void Mat_free(Mat *m) {  
  for(int i = 0; i < m->rows; ++i) {
    free(m->row_ptrs[i]);
  }
  free(m->row_ptrs);
  free(m);
}
