#include "esercizio2.h"
#include <stdlib.h>


SparseMatrix dense_to_sparse_matrix(float** mat, int rows, int cols) {
SparseMatrix mat2;
mat2=(SparseMatrix)malloc(sizeof(SparseMatrixElement));
SparseMatrix start=mat2;
mat2->next=NULL;
for (int i=0;i<rows;i++){
    for (int j=0;j<cols;j++){
        if (mat[i][j]!=0){
        mat2->value=mat[i][j];
        mat2->row=i;
        mat2->col=j;
        mat2->next=(SparseMatrix)malloc(sizeof(SparseMatrixElement));
        mat2=mat2->next;}
    }
}
mat2->next=NULL;
        
    return start;
}
