#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "list.h"

#ifdef ESERCIZIO_2

void TipoSCL_print(TipoSCL l) {
    printf("list: ");
    while(l != NULL) {
        printf("[v = %.3f, row = %d, col = %d] ", l->v, l->row, l->col);
        l = l->next;
    }
    printf("\n");
}

TipoSCL TipoSCL_load(char* filename) {
    FILE* f = fopen(filename, "r");
    if(f == NULL) {
        printf("Error while opening file %s... aborting!\n", filename);
        exit(-1);
    }

    char buffer[1024];
    TipoSCL gen_node = TipoSCL_alloc();
    gen_node->next = NULL;
    TipoSCL list = gen_node;
    int i = 0;
    while(fscanf(f, "%s", buffer) == 1) {
        if(i % 3 == 0) {
            list->next = TipoSCL_alloc();
            list = list->next;
            list->v = atof(buffer);
            list->next = NULL;
        }
        else if(i % 3 == 1) {
            list->row = atoi(buffer);
        }
        else {
            list->col = atoi(buffer);
        }
        i++;
    }
    list = gen_node->next;
    free(gen_node);

    return list;
}

TipoSCL TipoSCL_alloc() {
    return (TipoSCL) calloc(1, sizeof(NodoSCL));
}

void TipoSCL_free(TipoSCL l) {
    while(l != NULL) {
        TipoSCL tmp = l;
        l = l->next;
        free(tmp);
    }
}

int TipoSCL_compare(TipoSCL src1, TipoSCL src2) {
    while(src1 != NULL && src2 != NULL) {
        if(fabs(src1->v - src2->v) > 1e-3) { return 0; }
        if(src1->row != src2->row) { return 0; }
        if(src1->col != src2->col) { return 0; }
        src1 = src1->next;
        src2 = src2->next;
    }
    if(src1 != NULL || src2 != NULL) { return 0; }

    return 1;
}

#endif

#ifdef ESERCIZIO_3

void TipoSCL_print(TipoSCL l) {
    printf("list: ");
    while(l != NULL) {
        printf("%d ", l->info);
        l = l->next;
    }
    printf("\n");
}

TipoSCL TipoSCL_load(char* filename) {
    FILE* f = fopen(filename, "r");
    if(f == NULL) {
        printf("Error while opening file %s... aborting!\n", filename);
        exit(-1);
    }

    char buffer[1024];
    TipoSCL gen_node = TipoSCL_alloc();
    gen_node->next = NULL;
    TipoSCL list = gen_node;
    while(fscanf(f, "%s", buffer) == 1) {
        list->next = TipoSCL_alloc();
        list = list->next;
        list->info = atoi(buffer);
        list->next = NULL;
    }
    list = gen_node->next;
    free(gen_node);

    return list;
}

TipoSCL TipoSCL_alloc() {
    return (TipoSCL) malloc(sizeof(NodoSCL));
}

void TipoSCL_free(TipoSCL l) {
    while(l != NULL) {
        TipoSCL tmp = l;
        l = l->next;
        free(tmp);
    }
}

int TipoSCL_compare(TipoSCL src1, TipoSCL src2) {
    while(src1 != NULL && src2 != NULL) {
        if(src1->info != src2->info) { return 0; }
        src1 = src1->next;
        src2 = src2->next;
    }
    if(src1 != NULL || src2 != NULL) { return 0; }

    return 1;
}

#endif
