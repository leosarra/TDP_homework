#include <stdlib.h>
#include <string.h>
#include "../libtest/libtest.h"
#include "test.h"
#include "esercizio.h"


const int NTEST=5;

TipoSCL input[5];
int add[5] = {1,2,3,4,5};
TipoSCL expected[5];


int main(int argc, char** argv){
    
    
    input[0] = NULL;
    
    input[1] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[1] -> info = 1;
    input[1] -> next = input[1];
    
    input[2] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[2] -> info = 1;
    input[2] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[2] -> next -> info = 2;
    input[2] -> next -> next = input[2];
    
    input[3] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[3] -> info = 1;
    input[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[3] -> next -> info = 2;
    input[3] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[3] -> next -> next -> info = 3;
    input[3] -> next -> next -> next = input[3];
    
    input[4] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[4] -> info = 1;
    input[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[4] -> next -> info = 2;
    input[4] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[4] -> next -> next -> info = 3;
    input[4] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[4] -> next -> next -> next -> info = 4;
    input[4] -> next -> next -> next -> next = input[4];
    
    expected[0] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[0] -> info = 1;
    expected[0] -> next = expected[0];
    
    expected[1] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[1] -> info = 1;
    expected[1] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[1] -> next -> info = 2;
    expected[1] -> next -> next = expected[1];
    
    expected[2] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[2] -> info = 1;
    expected[2] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[2] -> next -> info = 2;
    expected[2] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[2] -> next -> next -> info = 3;
    expected[2] -> next -> next -> next = expected[2];
    
    expected[3] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[3] -> info = 1;
    expected[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[3] -> next -> info = 2;
    expected[3] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[3] -> next -> next -> info = 3;
    expected[3] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[3] -> next -> next -> next -> info = 4;
    expected[3] -> next -> next -> next -> next = expected[3];
    
    expected[4] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[4] -> info = 1;
    expected[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[4] -> next -> info = 2;
    expected[4] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[4] -> next -> next -> info = 3;
    expected[4] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[4] -> next -> next -> next -> info = 4;
    expected[4] -> next -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[4] -> next -> next -> next -> next -> info = 5;
    expected[4] -> next -> next -> next -> next  -> next = expected[4];
    
    
    
    
	test_reset();
	
	for (int i = 0; i < NTEST; i++) {
		print_test_start(i+1);
		printf("Funzione: accoda\n");
        printf("Input: %s\n", toString(input[i]));
        
        accoda(&input[i],add[i]);

		test_compare_strings(toString(expected[i]),toString(input[i]));
        
		print_test_end();
		print_n_success("#Test superati: ");
	}
	print_test_result("Percentuale test corretti:");
}


char* toString(TipoSCL scl){
    char* res = (char*) malloc(200*sizeof(char));
    res[0] = '[';
    res[1] = '\0';
    TipoSCL aux = scl;
    if (aux != NULL) {
        char buf[10];
        do{
            sprintf(buf,"%d->",aux -> info);
            strcat(res,buf);
            aux = aux -> next;
        }
        while(aux != scl);
        sprintf(buf,"|%d",aux -> info);
        strcat(res,buf);
        aux = aux -> next;
    }
    strcat(res,"]");
    return res;
}


