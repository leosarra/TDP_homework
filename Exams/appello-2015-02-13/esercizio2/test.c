#include <stdlib.h>
#include <string.h>
#include "../libtest/libtest.h"
#include "test.h"
#include "esercizio.h"


#define NTEST 8

TipoSCL input[NTEST];
int shift[NTEST] = {0,1,2,1,2,1,2,3};
TipoSCL expected[NTEST];


int main(int argc, char** argv){
    
    
    input[0] = NULL;
    
    input[1] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[1] -> info = 1;
    input[1] -> next = NULL;
    
    input[2] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[2] -> info = 1;
    input[2] -> next = NULL;
    
    input[3] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[3] -> info = 1;
    input[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[3] -> next -> info = 2;
    input[3] -> next -> next = NULL;
    
    input[4] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[4] -> info = 1;
    input[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[4] -> next -> info = 2;
    input[4] -> next -> next = NULL;
    
    input[5] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[5] -> info = 1;
    input[5] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[5] -> next -> info = 2;
    input[5] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[5] -> next -> next -> info = 3;
    input[5] -> next -> next -> next = NULL;
    
    input[6] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[6] -> info = 1;
    input[6] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[6] -> next -> info = 2;
    input[6] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[6] -> next -> next -> info = 3;
    input[6] -> next -> next -> next = NULL;

    input[7] = (TipoSCL) malloc(sizeof(NodoSCL));
    input[7] -> info = 1;
    input[7] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[7] -> next -> info = 2;
    input[7] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[7] -> next -> next -> info = 3;
    input[7] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[7] -> next -> next -> next ->info = 4;
    input[7] -> next -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    input[7] -> next -> next -> next -> next -> info = 5;
    input[7] -> next -> next -> next -> next -> next = NULL;
    
    
    expected[0] = NULL;
    
    expected[1] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[1] -> info = 1;
    expected[1] -> next = NULL;
    
    expected[2] = expected[1];
    
    expected[3] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[3] -> info = 2;
    expected[3] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[3] -> next -> info = 1;
    expected[3] -> next -> next = NULL;
    
    expected[4] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[4] -> info = 1;
    expected[4] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[4] -> next -> info = 2;
    expected[4] -> next -> next = NULL;
    
    expected[5] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[5] -> info = 2;
    expected[5] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[5] -> next -> info = 3;
    expected[5] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[5] -> next -> next -> info = 1;
    expected[5] -> next -> next -> next = NULL;

    expected[6] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[6] -> info = 3;
    expected[6] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[6] -> next -> info = 1;
    expected[6] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[6] -> next -> next -> info = 2;
    expected[6] -> next -> next -> next = NULL;

    expected[7] = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[7] -> info = 4;
    expected[7] -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[7] -> next -> info = 5;
    expected[7] -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[7] -> next -> next -> info = 1;
    expected[7] -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[7] -> next -> next -> next ->info = 2;
    expected[7] -> next -> next -> next -> next = (TipoSCL) malloc(sizeof(NodoSCL));
    expected[7] -> next -> next -> next -> next -> info = 3;
    expected[7] -> next -> next -> next -> next -> next = NULL;

    test_reset();
	
	for (int i = 0; i < NTEST; i++) {
		print_test_start(i+1);
		printf("Funzione: ruota\n");
        printf("Input: scl = %s, k = %d\n", toString(input[i]),shift[i]);
        
        ruota(&input[i],shift[i]);

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
            sprintf(buf,"->%d",aux -> info);
            strcat(res,buf);
            aux = aux -> next;
        }
        while(aux != NULL);
    }
    strcat(res,"]");
    return res;
}


