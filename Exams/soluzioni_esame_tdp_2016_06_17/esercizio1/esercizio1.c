#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "esercizio1.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "esercizio1.h"


double diff(int row, int col, Mat* src, double value){
  int r_min=row-1;
  if (r_min<0)
    r_min=0;
  int r_max=row+1;
  if (r_max>=src->rows)
    r_max=src->rows-1;
  int c_min=col-1;
  if (c_min<0)
    c_min=0;
  int c_max=col+1;
  if (c_max>=src->cols)
    c_max=src->cols-1;

double diff=0;
double  maxdiff=0;
for (int r=r_min; r<=r_max; r++){
  for (int c=c_min; c<=c_max; c++){
    diff=fabs(src->row_ptrs[r][c]-value);
    if (diff>maxdiff){
      maxdiff=diff;
    }
  }
}
return maxdiff;
  }


void matrix_compute_gradients(Mat* dest, Mat* src) {
 if (src==NULL){
   dest=NULL;
 }
 else{
   for(int i=0;i<src->rows;i++){
     for (int j=0;j<src->cols;j++){
       double result= diff(i,j,src,src->row_ptrs[i][j]);
       dest->row_ptrs[i][j]=result;
     }
   }

 }
}

