#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#define info_t int

struct cell
{
    int value;
    struct cell *next;
};

typedef struct cell Cell;

Cell *create_cell(info_t info){
    Cell *c = (Cell*)malloc(sizeof(Cell));
    c->next = NULL;
    c->value = info;
    return c;
}

void print_cell(Cell *c){
    printf("%d ", c->value);
}

void free_cell(Cell *c){
    free(c);
}