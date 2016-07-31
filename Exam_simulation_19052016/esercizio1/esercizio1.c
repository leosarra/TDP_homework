#include "esercizio1.h"

int matrix_block_sum(Mat* dest, Mat* src, int start_row, int start_col) {
    int rows_src=src->rows;
    int cols_src=src->cols;
    int changed=0;
    if (start_row+rows_src<0 || start_col+cols_src <0){
        return 0;}
    if (start_row+rows_src>dest->rows || start_col+cols_src>dest->cols){
        return 0;}
    int riga=0;
    int colonna=0;
    for (int i=start_row;i<start_row+rows_src;i++){
        for (int j=start_col;j<start_col+rows_src;j++){
            dest->row_ptrs[i][j]+=src->row_ptrs[riga][colonna];
            colonna++;
            changed++;}
            colonna=0;
            riga++;

            }
    return changed;
}
