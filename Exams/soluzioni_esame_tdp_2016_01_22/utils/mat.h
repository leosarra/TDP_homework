#ifndef _MAT_H_
#define _MAT_H_

void   matrixc_print(char** mat, int rows, int cols);
char** matrixc_load(int* rows, int* cols, char* filename);
char** matrixc_alloc(int rows, int cols);
void   matrixc_free(char** mat, int rows);
int    matrixc_compare(char** src1, char** src2, int rows, int cols);

void  matrixi_print(int** mat, int rows, int cols);
int** matrixi_load(int* rows, int* cols, char* filename);
int** matrixi_alloc(int rows, int cols);
void  matrixi_free(int** mat, int rows);
int   matrixi_compare(int** src1, int** src2, int rows, int cols);

#endif
