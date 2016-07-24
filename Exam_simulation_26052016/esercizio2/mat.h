#ifndef _MAT_H_
#define _MAT_H_

typedef struct Mat {
  int rows;         // number of rows
  int cols;         // number of cols
  float** row_ptrs; // pointers to the rows
} Mat;

#endif
