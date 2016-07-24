#include "esercizio1.h"
#include "mat.h"
#include "esercizio1.h"
#include "../utils/mat_struct.h"

float media(Mat* m,int block_size, int i, int j);

Mat* matrixScale(Mat* m, int block_size) {
    Mat* a=Mat_alloc(m->rows/block_size, m->cols/block_size);
    for (int r=0;r<a->rows;r++){
        for (int c=0;c<a->cols;c++){
            a->row_ptrs[r][c]=media(m,block_size,r,c);
        }
    }
    return a;}
float media(Mat* m,int block_size,int i,int j){
    float media=0;
    float somma=0;
    for (int r=(i*block_size);r<=(i+1)*block_size -1;r++){
        for (int c=j*block_size;c<=(j+1)*block_size -1;c++){
            media+=m->row_ptrs[r][c];
        }
    }

somma=media/block_size*(block_size);
return somma;
}
