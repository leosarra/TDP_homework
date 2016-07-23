#include <stdio.h>

#include "../test_utils/test_utils.h"
#include "esercizio1.h"

int main(int argc, char** argv) {  
  int failures = 0, successes = 0;
  int matrix_rows, matrix_cols, square_row, square_col, result;
  
  int** matrix = matrixiLoad(&matrix_rows, &matrix_cols, "./matrix_test_examples/matrix.txt");

  findSquare(&square_row, &square_col, matrix, matrix_rows, matrix_cols, 1, 6);
  printf("Input ");
  matrixiPrint(matrix, matrix_rows, matrix_cols); 
  printf("Searching for a square submatrix of dimension 1 containing values equal to 6\n");
  printf("Expected: -1, -1\n");
  printf("Result: %d, %d\n", square_row, square_col);      
  if(square_row == -1 && square_col == -1) { 
    printf("OK\n");
    successes++; 
  }
  else {
    printf("FAIL\n");
    failures++; 
  }
  printf("---------------------------------\n");

  findSquare(&square_row, &square_col, matrix, matrix_rows, matrix_cols, 1, 4);
  printf("Input ");
  matrixiPrint(matrix, matrix_rows, matrix_cols);
  printf("Searching for a square submatrix of dimension 1 containing values equal to 4\n");
  printf("Expected: 0, 2\n");
  printf("Result: %d, %d\n", square_row, square_col);      
  if(square_row == 0 && square_col == 2) { 
    printf("OK\n");
    successes++; 
  }
  else {
    printf("FAIL\n");
    failures++; 
  }
  printf("---------------------------------\n");

  findSquare(&square_row, &square_col, matrix, matrix_rows, matrix_cols, 3, 2);
  printf("Input ");
  matrixiPrint(matrix, matrix_rows, matrix_cols);
  printf("Searching for a square submatrix of dimension 3 containing values equal to 2\n");
  printf("Expected: 2, 0\n");
  printf("Result: %d, %d\n", square_row, square_col);
  if(square_row == 2 && square_col == 0) {
    printf("OK\n");
    successes++;
  }
  else {
    printf("FAIL\n");
    failures++;
  }
  printf("---------------------------------\n");

  findSquare(&square_row, &square_col, matrix, matrix_rows, matrix_cols, 2, 3);
  printf("Input ");
  matrixiPrint(matrix, matrix_rows, matrix_cols);
  printf("Searching for a square submatrix of dimension 2 containing values equal to 3\n");
  printf("Expected: 5, 0\n");
  printf("Result: %d, %d\n", square_row, square_col);
  if(square_row == 5 && square_col == 0) {
    printf("OK\n");
    successes++;
  }
  else {
    printf("FAIL\n");
    failures++;
  }
  printf("---------------------------------\n");

  findSquare(&square_row, &square_col, matrix, matrix_rows, matrix_cols, 4, 1);
  printf("Input ");
  matrixiPrint(matrix, matrix_rows, matrix_cols);
  printf("Searching for a square submatrix of dimension 4 containing values equal to 1\n");
  printf("Expected: 2, 3\n");
  printf("Result: %d, %d\n", square_row, square_col);
  if(square_row == 2 && square_col == 3) {
    printf("OK\n");
    successes++;
  }
  else {
    printf("FAIL\n");
    failures++;
  }
  printf("---------------------------------\n");

  printf("Success rate: %0.02f\n", (float) successes * 100.0f / (successes + failures));

  return 0;
}
