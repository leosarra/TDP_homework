#include "esercizio2.h"
#include <stdlib.h>
TipoSCL lowerValues(Mat* m, float value) {
    TipoSCL elem=(TipoSCL)malloc(sizeof(NodoSCL));
    TipoSCL inizio=elem;
    TipoSCL fine=elem;
    int controllati=0;
    
    for (int i=0;i<m->rows;i++){
        for (int j=0;j<m->cols;j++){
            if (m->row_ptrs[i][j]<value){
                (*elem).v=m->row_ptrs[i][j];
                (*elem).row=i;
                (*elem).col=j;
                fine=elem;
                (*elem).next=(TipoSCL)malloc(sizeof(NodoSCL));
                elem=(*elem).next;
                controllati++;
            }
        }
    }
    (*fine).next=NULL;
    if (controllati==0){
        return NULL;}
    else {return inizio;}
}


