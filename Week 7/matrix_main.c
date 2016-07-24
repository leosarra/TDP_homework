#include <stdio.h>
#include "matrix_ops.h"
#include "vec_ops.h"

int main(int argc, char** argv){


  /*TEST VETTORE*/
  FILE* f=fopen("v.txt","r");
  if  (! f){
    printf("file non esiste");
    return 0;
  }
  int v_dim;
  float* v=Vec_read(f, &v_dim);
  if (!v){
    printf("problema nel caricamento del vettore");
    return 0;
  }
  
  Vec_write(stdout, v, v_dim);

  fclose(f);


  /*TEST LETTURA (chiama la Matrix_alloc)*/
  
  // riuso lo stesso file
  f=fopen("m1.txt","r");
  if  (! f){
    printf("file non esiste");
    return 0;
  }
  int m_rows, m_cols;
  float ** m=Matrix_read(f,&m_rows,&m_cols);
  if (!m){
    printf("problema nel caricamento della matrice");
    return 0;
  }
  fclose(f);
  

  printf("TEST WRITE\n");
  Matrix_write(stdout, m, m_rows, m_cols);

  printf("TEST CLONE\n");
  float** m_cloned=Matrix_clone(m,m_rows,m_cols);
  Matrix_write(stdout, m_cloned, m_rows, m_cols);

  printf("TEST FREE\n");
  /*cancello la vecchia copia di m*/
  Matrix_free(m,m_rows);
  /*rimpiazzo m con la sua nuova copia*/
  m=m_cloned;

  printf("TEST Matrix_copyTransposed\n");
  int mt_rows=m_cols, mt_cols=m_rows;
  float** mt=Matrix_copyTransposed(m, m_rows, m_cols);
  Matrix_write(stdout, mt, mt_rows, mt_cols);

  printf("TEST Matrix_extractBlock\n");
  int mb_rows=2;
  int mb_cols=2;
  float** mb=Matrix_alloc(2,2);
  int extract_block_result=Matrix_extractBlock(mb, mt, mt_rows, mt_cols,
					       1, 1,
					       mb_rows, mb_cols);

  Matrix_write(stdout, mb, mb_rows, mb_cols);

  printf("TEST Matrix_vectorProduct\n");
  float* prod=Vec_alloc(m_rows);
  Matrix_vectorProduct(prod, m, m_rows, m_cols, v);
  Vec_write(stdout, prod, m_rows);
  
  printf("TEST Matrix_exchangeRows\n");
  Matrix_write(stdout, mb, mb_rows, mb_cols);
  Matrix_exchangeRows(mb, 0,1);
  Matrix_write(stdout, mb, mb_rows, mb_cols);

  printf("TEST Matrix_sumAndScaleRows\n");
  Matrix_write(stdout, mb, mb_rows, mb_cols);
  Matrix_sumAndScaleRows(mb, 0,1, mb_cols, 0.5);
  Matrix_write(stdout, mb, mb_rows, mb_cols);

  printf("TEST Matrix_findMaxIdxInCol\n");
  int col_num=2;
  int idx=Matrix_findMaxIdxInCol(m, m_rows, col_num);
  Matrix_write(stdout, mb, mb_rows, mb_cols);
  printf("max idx in col %d is: %d\n",col_num,idx);


  printf("IF ALL IS RIGHT WE CAN TRIANGULARIZE\n");
  float** mc=Matrix_clone(m, m_rows, m_cols);
  Matrix_triangularize(mc, m_rows, m_cols);
  Matrix_write(stdout, mc, m_rows, m_cols);

  Matrix_free(mb,mb_rows);
  Matrix_free(mt,mt_rows);
  Matrix_free(m, m_rows);
  Vec_free(v);
  Vec_free(prod);

 
}
