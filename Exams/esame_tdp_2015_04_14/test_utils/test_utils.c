#include <stdlib.h>
#include <stdio.h>

#include "test_utils.h"

void matrixiPrint(int** m, int rows, int cols) {
  printf("Matrix %dx%d:\n", rows, cols);
  int r, c;
  for(r = 0; r < rows; r++) {
    for(c = 0; c < cols; c++) {
      printf("%d\t", m[r][c]);
    }
    printf("\n");
  }
}

void matrixfPrint(float** m, int rows, int cols) {
  printf("Matrix %dx%d:\n", rows, cols);
  int r, c;
  for(r = 0; r < rows; r++) {
    for(c = 0; c < cols; c++) {
      printf("%.03f\t", m[r][c]);
    }
    printf("\n");
  }
}

int** matrixiLoad(int* rows, int* cols, char* filename) {
  *rows = 0;
  *cols = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f,"%s", buffer) == 1) { *rows = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of rows... aborting!\n", filename);
    exit(-1);
  }
  if(fscanf(f,"%s", buffer) == 1) { *cols = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of cols... aborting!\n", filename);
    exit(-1);
  }
  if(*rows == 0 || *cols == 0) { 
    printf("Error while reading file %s, either rows or columns number is zero... aborting!\n", filename);
    exit(-1);
  }
  int i = 0;  
  int** m = matrixiAlloc(*rows, *cols);
  while(i < (*rows) * (*cols) && fscanf(f,"%s", buffer) == 1){
    int row = i / (*cols);
    int col = i % (*cols);
    m[row][col] = atoi(buffer);
    i++;
  }
  if(i != (*rows) * (*cols)) {
    printf("Error while reading file %s, cannot read all matrix values... aborting!\n", filename);
    exit(-1);
  }
  return m;
}

float** matrixfLoad(int* rows, int* cols, char* filename) {
  *rows = 0;
  *cols = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f,"%s", buffer) == 1) { *rows = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of rows... aborting!\n", filename);
    exit(-1);
  }
  if(fscanf(f,"%s", buffer) == 1) { *cols = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of cols... aborting!\n", filename);
    exit(-1);
  }
  if(*rows == 0 || *cols == 0) { 
    printf("Error while reading file %s, either rows or columns number is zero... aborting!\n", filename);
    exit(-1);
  }
  int i = 0;  
  float** m = matrixfAlloc(*rows, *cols);
  while(i < (*rows) * (*cols) && fscanf(f,"%s", buffer) == 1){
    int row = i / (*cols);
    int col = i % (*cols);
    m[row][col] = atof(buffer);
    i++;
  }
  if(i != (*rows) * (*cols)) {
    printf("Error while reading file %s, cannot read all matrix values... aborting!\n", filename);
    exit(-1);
  }
  return m;
}

int** matrixiAlloc(int rows, int cols) {
  int* data = (int*) malloc(rows * cols * sizeof(int));
  int** row_ptrs = (int**) malloc(rows * sizeof(int*));
  int i;
  for (i = 0; i < rows; i++) {
    row_ptrs[i] = data + (i * cols);
  }
  return row_ptrs;
}

float** matrixfAlloc(int rows, int cols) {
  float* data = (float*) malloc(rows * cols * sizeof(float));
  float** row_ptrs = (float**) malloc(rows * sizeof(float*));
  int i;
  for (i = 0; i < rows; i++) {
    row_ptrs[i] = data + (i * cols);
  }
  return row_ptrs;
}

void matrixiFree(int** m, int rows) {
  int* data_ptr = m[0];
  int i;
  for(i = 0; i < rows; i++) {
    if(data_ptr > m[i])
      data_ptr = m[i];
  }
  free(data_ptr);
  free(m);
}

void matrixfFree(float** m, int rows) {
  float* data_ptr = m[0];
  int i;
  for(i = 0; i < rows; i++) {
    if(data_ptr > m[i])
      data_ptr = m[i];
  }
  free(data_ptr);
  free(m);
}

int matrixiCmp(int** src1, int** src2, int rows, int cols) {
  int r, c;
  for(r = 0; r < rows; r++) {
    for(c = 0; c < cols; c++) {
      if(src1[r][c] != src2[r][c]) { return 0; }
    }
  }
  return 1;
}

int matrixfCmp(float** src1, float** src2, int rows, int cols) {
  int r, c;
  for(r = 0; r < rows; r++) {
    for(c = 0; c < cols; c++) {
      if(src1[r][c] != src2[r][c]) { return 0; }
    }
  }
  return 1;
}
