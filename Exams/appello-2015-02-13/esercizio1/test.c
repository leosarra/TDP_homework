#include <stdlib.h>
#include <string.h>
#include "../libtest/libtest.h"
#include "esercizio.h"


int expected[10][15] ={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,2,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,2,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,3,6,0,0,0,0,0,0,0,0,0,0,0,3},
    {1,3,6,7,0,0,0,0,0,0,0,0,0,0,4},
    {1,3,6,10,15,21,0,0,0,0,0,0,0,0,6},
    {1,3,6,10,15,21,0,0,0,0,0,0,0,0,6},
    {1,3,6,10,15,21,0,0,0,0,0,0,0,0,6},
    {1,3,6,10,15,21,0,0,0,0,0,0,0,0,6}
};


int main(int argc, char** argv){
	test_reset();
	
	for (int i = 1; i <= 10; i++) {
		print_test_start(i);
		printf("Funzione: accumulaArray\n");
        char filename[20];
        sprintf(filename,"file%d.txt", i);
		printf("Input: %s\n", filename);
        int n;
        int* ris = accumulaArray(filename,&n);
        test_compare_array_int(expected[i-1], expected[i-1][14], ris, n);
        
		print_test_end();
		print_n_success("#Test superati: ");
	}
	print_test_result("Percentuale test corretti:");
}
