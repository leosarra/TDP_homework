//File libtest.h

#ifndef LIBTEST_H
#define LIBTEST_H

#include <stdio.h>
#include <stdarg.h>

int n_test; // nr. of tests in current series
int n_success; // nr. of successfull tests in current series

void test_reset(); // resets nr. of tests and successfull tests

void print_test_start(int id);
void print_test_end();


void print_test_result(char* msg);

void print_n_success(char* msg);

// ********* Functions to compare results and record outcome ********* 

// Test functions:

void test_compare_pointers(void* expected, void* given);

void test_compare_array_int(int expected[], int n, int given[], int m);

void test_compare_array_char(char expected[], int n, char given[], int m);

void test_compare_strings(char* expected, char* given);

void test_compare_mat_char(char** expected, int r, int c, char** given, int r2, int c2);

void test_compare_mat_int(int** expected, int r, int c, int** given, int r2, int c2);

void test_compare_int(int expected, int given);

void test_compare_char(char expected, char given);

// Comparison functions:

int compare_array_int(int expected[], int n, int given[], int m);

int compare_array_char(char expected[], int n, char given[], int m);

int compare_mat_char(char** expected, int r, int c, char** given, int r2, int c2);

int compare_mat_int(int** expected, int r, int c, int** given, int r2, int c2);

// ********* Print functions ********* 

void print_array_float(float* array, size_t size);

void print_array_int(int* array, size_t size);

void print_array_int_as_scl(int* array, size_t size);

void print_array_char(char* array, size_t size);

void print_mat_char(char** mat, int n, int m);

void print_mat_int(int** mat, int n, int m);


#endif



