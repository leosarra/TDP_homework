#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

// Matrix utils
void matrixiPrint(int** m, int rows, int cols);
void matrixfPrint(float** m, int rows, int cols);

/* 
Expected file format:
row_number columns_number
value value value ... value
value value value ... value
.
.
.
value value value ... value
*/
int** matrixiLoad(int* rows, int* cols, char* filename);
float** matrixfLoad(int* rows, int* cols, char* filename);

int** matrixiAlloc(int rows, int cols);
float** matrixfAlloc(int rows, int cols);

void matrixiFree(int** m, int rows);
void matrixfFree(float** m, int rows);

int matrixiCmp(int** src1, int** src2, int rows, int cols);
int matrixfCmp(float** src1, float** src2, int rows, int cols);

#endif



