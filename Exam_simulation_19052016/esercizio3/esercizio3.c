#include "esercizio3.h"
#include <stdlib.h>
#include <stdio.h>
 
float sparse_matrix_diagonal_sum(SparseMatrix sparse_mat) {

    if (sparse_mat==NULL){
        return 0;
    }
    else if(sparse_mat->row != sparse_mat->col) {
        return sparse_matrix_diagonal_sum(sparse_mat->next);    
    }
    else {
        return sparse_mat->value + sparse_matrix_diagonal_sum(sparse_mat->next);            
    } 
}
