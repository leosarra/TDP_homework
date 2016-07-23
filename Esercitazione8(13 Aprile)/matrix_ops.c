#include "matrix_ops.h"
#include "vec_ops.h"
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
float  vec_dot(float *src1, float *src2, int dim){
    float* vettore;
    float ris=0;
    vettore=(float *)malloc(sizeof(float)*dim);
        for (int i=0;i<dim;i++){
        vettore[i]=((src2[i])*(src1[i]));
        }
        for (int i=0;i<dim;i++){
        ris+=vettore[i];
        }
    return ris;
        
}


/* esegue la deallocazione di un blocco contiguo a partire dai puntatori alle righe.
   1. cerca la lriga piu bassa, che si rigerisce al blocco contiguo
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



int Matrix_zeroColumn(float**m, int num_rows, int num_cols, int col){
  int pivot_idx=Matrix_findMaxIdxInCol(m, num_rows, col);
  if (m[pivot_idx][col]==0)
    return 0;
  Matrix_exchangeRows(m, 0, pivot_idx);
  float pivot_value=m[0][col];
  for (int r=1; r<num_rows; r++){
    float element=m[r][col];
    float scale=-element/pivot_value;
    Matrix_sumAndScaleRows(m, r, 0,  num_cols,  scale);
  }
  return 1;
}


void Matrix_triangularize(float**m, int num_rows, int num_cols) {
  int r=0;
  for (int c=0; c<num_cols && r<num_rows; c++){
    int increment_row=Matrix_zeroColumn(m+r, num_rows-r, num_cols, c);
    r+=increment_row;
  }
}

float** Matrix_allocArrayOfArray(int num_rows, int num_cols){
    float** mat;
    mat=(float**)calloc(num_rows,sizeof(float*));
    for (int i=0;i<num_rows;i++){
        mat[i]=(float*)calloc(num_cols,sizeof(float));}
    return mat;
  /* PRIMO ESERCIZIO COMPLETATO */
}

void Matrix_freeArrayOfArray(float** m, int num_rows){
    for (int i=0;i<num_rows;i++){
        free(m[i]);
        }
    free(m);
     /* SECONDO ESERCIZIO COMPLETATO */
    
}


float**  Matrix_alloc(int num_rows, int num_cols){
  return Matrix_allocArrayOfArray(num_rows, num_cols);
  //return Matrix_allocArrayOfArray(num_rows, num_cols); //<<< dopo aver scritto Matrix_allocArrayOfArray(...) usare questa chiamata
}

void Matrix_free(float** m, int num_rows){
  Matrix_freeArrayOfArray(m, num_rows);
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


float** Matrix_clone(float** src, int num_rows, int num_cols){
    float** copy=Matrix_alloc(num_rows,num_cols);
    for (int i=0;i<num_rows;i++){
        for (int j=0;j<num_cols;j++){
            copy[i][j]=src[i][j];
            }
        }
  return copy;
  /* TERZO ESERCIZIO COMPLETATO */
}

float** Matrix_copyTransposed(float** src, int num_rows, int num_cols){
  float** copia=Matrix_alloc(num_cols,num_rows);
    for (int i=0;i<num_rows;i++){
        for (int j=0;j<num_cols;j++){
            copia[j][i]=src[i][j];
            }
  
}
return copia;
/* QUARTO ESERCIZIO COMPLETATO */
}

int  Matrix_extractBlock(float** dest, float** src, 
		  int num_rows, int num_cols, 
		   int block_start_row, int block_start_col,
		   int block_num_rows, int block_num_cols){
int conto=0;
int valorerow,valorecol;
if (block_start_row>num_rows || block_num_rows>num_rows) { 
    return -1;}
else if ((block_start_row>num_cols) or (block_num_cols>num_cols)) { 
    return -1;}
for (int i=block_start_row;i<=block_num_rows;i++){ 
    for (int j=block_start_col;j<=block_num_cols;j++){
       // printf("I valori di righe e colonne sono %d e %d e la mat � %lf",i,j,src[i][j]);
        dest[valorerow][valorecol]=src[i][j];
       // printf("I valori di valori di row  e col sono %d e %d e la mat vale %lf",valorerow,valorecol,dest[valorerow][valorecol]);
        valorecol++;   
        
        }
    valorecol=0;
    valorerow++;
    conto++;
    }
return conto;

    
        
        
    }
    /* QUINTO ESERCIZIO COMPLETATO */

  /*
  dest[0][0]=7.000;
  dest[0][1]=12.000;
  dest[1][0]=8.000;
  dest[1][1]=13.000;
  return 4;   QUESTI ERANO I RISULTATI GIUSTI*/


void Matrix_vectorProduct(float* dest, float** m, int num_rows, int num_cols, float* v) {
    for (int i=0;i<num_rows;i++){
            dest[i]+=vec_dot(m[i],v,num_cols);
            }
    
}
/* SESTO ESERCIZIO COMPLETATO */

/*
scambia la riga r1 ed r2 nella matrice m
*/
void Matrix_exchangeRows(float**m , int r1, int r2){
float* save;
save=m[r1];
m[r1]=m[r2];
m[r2]=save;

}
/* SETTIMO ESERCIZIO COMPLETATO */
 
/*
  somma alla riga r1+=r2*scale
*/
void Matrix_sumAndScaleRows(float** m, int r1, int  r2, int num_cols, float scale){
        for (int j=0;j<num_cols;j++){
            m[r1][j]+=(m[r2][j])*scale;
            }
  /*esercizio*/
}
/* OTTAVO ESERCIZIO COMPLETATO */

/*
  trova l'indice di riga che contiene il massimo valore (in modulo),
  considerando solo la colonna col
*/
int  Matrix_findMaxIdxInCol(float**m, int num_rows, int col) {
    float max=m[0][col];
    int risultato=0;
    for (int j=1;j<num_rows;j++){
        if (m[j][col]>max){
			max=m[j][col];
            risultato=j;
            }
        }
  /*esercizio*/
  return risultato;}
/* NONO ESERCIZIO COMPLETATO */

