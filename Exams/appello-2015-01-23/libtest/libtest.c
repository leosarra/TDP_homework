#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtest.h"



void test_reset(){
	n_test = 0;
	n_success = 0;
}


void print_test_start(int id){
	printf("\n********** TEST %d **********\n", id);
}

void print_test_end(){
	printf("*****************************\n");
}



void print_test_result(char* msg){
	printf("\n%s %.2f%%\n\n", msg, n_success / (double) n_test *100.0);
}

void print_n_success(char* msg){
	printf("\n%s %d\n\n", msg, n_success);	
}


void test_compare_pointers(void* expected, void* given){
	printf("Risultato atteso: %p\n", expected);
	printf("Roisultato ttenuto: %p\n", given);
	
	n_test++;
	
	if (expected == given) {
		printf("Esito test: OK\n");
		n_success++;
	}
	else{
		printf("Esito test: ERRORE\n");		
	}	
}


void test_compare_array_int(int expected[], int n, int given[], int m){
	printf("Risultato atteso: ");
	print_array_int(expected, n);
	printf("\n");
	printf("Risultato ottenuto: ");
	print_array_int(given, m);
	printf("\n");
	
	n_test++;
	
	if (compare_array_int(expected, n, given, m)) {
		printf("Esito test: OK\n");
		n_success++;
	}
	else{
		printf("Esito test: ERRORE\n");		
	}
}

void test_compare_array_char(char expected[], int n, char given[], int m){
	printf("Risultato atteso: ");
	print_array_char(expected, n);
	printf("\n");
	printf("Risultato ottenuto: ");
	print_array_char(given, m);
	printf("\n");
	
	n_test++;
	
	if (compare_array_char(expected, n, given, m)) {
		printf("Esito test: OK\n");
		n_success++;
	}
	else{
		printf("Esito test: ERRORE\n");		
	}
}

void test_compare_strings(char* expected, char* given){
    printf("Risultato atteso: ");
    printf("%s\n",expected);
    printf("Risultato ottenuto: ");
    printf("%s\n",given);

    n_test++;

    if (strcmp(expected,given)==0) {
        printf("Esito test: OK\n");
        n_success++;
}
    else{
        printf("Esito test: ERRORE\n");
    }
}



void test_compare_mat_char(char** expected, int r, int c, char** given, int r2, int c2){
	printf("Risultato atteso:\n");
	print_mat_char(expected, r,c);
	printf("\n");
	printf("Risultato ottenuto:\n");
	print_mat_char(given, r2,c2);
	printf("\n");
	
	n_test++;
	
	if (compare_mat_char(expected, r, c, given, r2, c2)) {
		printf("Esito test: OK\n");
		n_success++;
	}
	else{
		printf("Esito test: ERRORE\n");
	}
}

void test_compare_mat_int(int** expected, int r, int c, int** given, int r2, int c2){
	printf("Risultato atteso:\n");
	print_mat_int(expected, r,c);
	printf("\n");
	printf("Risultato ottenuto:\n");
	print_mat_int(given, r2,c2);
	printf("\n");
	
	n_test++;
	
	if (compare_mat_int(expected, r, c, given, r2, c2)) {
		printf("Esito test: OK\n");
		n_success++;
	}
	else{
		printf("Esito test: ERRORE\n");
	}
}




int compare_array_int(int expected[], int n, int given[], int m){
	if (n!=m)
		return 0;
	if (n == 0 & m == 0)
		return 1;
	return (*expected == *given) && compare_array_int(expected+1,n-1,given+1,m-1);
	
}

int compare_array_char(char expected[], int n, char given[], int m){
	if (n!=m)
		return 0;
	if (n == 0 & m == 0)
		return 1;
	return (*expected == *given) && compare_array_char(expected+1,n-1,given+1,m-1);	
}



int compare_mat_char(char** expected, int r, int c, char** given, int r2, int c2){
    if (r != r2 || c != c2){
        return 0;
    }
    if (r == 0 || c == 0){
        return 1;
    }
    return compare_array_char(expected[0],c,given[0],c2) && compare_mat_char(expected+1,r-1,c,given+1,r2-1,c2);
}

int compare_mat_int(int** expected, int r, int c, int** given, int r2, int c2){
    if (r != r2 || c != c2){
        return 0;
    }
    if (r == 0 || c == 0){
        return 1;
    }
    return compare_array_int(expected[0],c,given[0],c2) && compare_mat_int(expected+1,r-1,c,given+1,r2-1,c2);
}




void test_compare_int(int expected, int given){
	printf("Risultato atteso: %d\n", expected);
	printf("Risultato ottenuto: %d\n", given);

	n_test++;
	if (expected == given) {
		printf("Esito test: OK\n");
		n_success++;
	}
	else{
		printf("Esito test: ERRORE\n");		
	}
}


void print_array_float(float* array, size_t size){
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%f",array[i]);
        if (i < size-1){
            printf(",");
        }
    }
    printf("]");
}

void print_array_int(int* array, size_t size){
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%d",array[i]);
        if (i < size-1){
            printf(",");
        }
    }
    printf("]");
}


void print_array_int_as_scl(int* array, size_t size){
    for (size_t i = 0; i < size; i++) {
        printf("->%d",array[i]);
    }
}



void print_array_char(char* array, size_t size){
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%c",array[i]);
        if (i < size-1){
            printf(",");
        }
    }
    printf("]");
}


void print_mat_char(char** mat, int n, int m){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%c ", mat[i][j]);
            if (j == m - 1){
                printf("\n");
            }
        }
    }
}


void print_mat_int(int** mat, int n, int m){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
            if (j == m - 1){
                printf("\n");
            }
        }
    }
}


