#include "utils.h"
#include <math.h>
#include <stdlib.h>


/* esegue l'allocazione di un blocco conttiguo di memoria su cui genera
   un array di puntatori alle righr
*/

float** Matrix_allocContiguous(int num_rows, int num_cols){
  float* data= (float*) malloc(sizeof(float)*num_rows*num_cols);
  float** row_ptrs=(float**)malloc(sizeof(float*)*num_rows);
  
  for (int r=0; r<num_rows; r++){
    row_ptrs[r]=data+num_cols*r;
  }
  return row_ptrs;
}


/* esegue la deallocazione di un blocco contiguo a partire dai puntatori alle righe.
   1. cerca la riga piu bassa, che si rigerisce al blocco contiguo
   2. elimina le righe
*/
void Matrix_freeContiguous(float**m, int num_rows){
  float* m_data=m[0];
  // find start row, as the smaller pointer in m
  for (int r=1; r<num_rows; r++)
    if (m[r]<m_data)
      m_data=m[r];
  // free the pointer array
  free(m);
  // free the data
  free(m_data);
}




float**  Matrix_alloc(int num_rows, int num_cols){
  return Matrix_allocContiguous(num_rows, num_cols);
  //return Matrix_allocArrayOfArray(num_rows, num_cols); //<<< dopo aver scritto Matrix_allocArrayOfArray(...) usare questa chiamata
}

void Matrix_free(float** m, int num_rows){
  Matrix_freeContiguous(m, num_rows);
  //Matrix_freeArrayOfArray(m, num_rows); //<<< dopo aver scritto Matrix_freeArrayOfArray(...) usare questa chiamata
}


void Matrix_write(FILE* f, float** m, int num_rows, int num_cols){
  fprintf(f,"%d %d\n", num_rows, num_cols);
  for (int r=0; r<num_rows; r++){
    for (int c=0; c<num_cols; c++)
      fprintf(f,"%.3f ",m[r][c]);
    fprintf(f, "\n");
  }
}

float** Matrix_read(FILE* f, int* num_rows, int* num_cols){
  int num_tokens=fscanf(f, "%d %d",num_rows, num_cols);
  if (num_tokens<2)
    return 0;
  float** m=0;
  m=Matrix_alloc(*num_rows, *num_cols);
  for (int r=0; r<*num_rows; r++)
    for (int c=0; c<*num_cols; c++) {
      if (feof(f)){
	Matrix_free(m, *num_rows);
	return 0;
      }
      fscanf(f,"%f",&m[r][c]);
    }
  return m;
}

void Matrix_writeOnPath(const char* filename, float** m, int num_rows, int num_cols) {
  FILE* f = fopen(filename, "w");
  if (!f)
    return;
  Matrix_write(f,m,num_rows,num_cols);
  fclose(f);
}

float** Matrix_readFromPath(const char* filename, int* num_rows, int* num_cols){
  FILE* f = fopen(filename, "r");
  if (!f)
    return NULL;
  float** m=Matrix_read(f,num_rows,num_cols);
  fclose(f);
  return m;
}
