#ifndef MAT_H
#define MAT_H

typedef struct {
  int rows; 
  int cols;
  int **row_ptrs;
} Mat;

Mat* Mat_alloc(int rows, int cols);
Mat* Mat_read(char *filename);
void Mat_print(Mat *m);
void Mat_free(Mat *m);

#endif
