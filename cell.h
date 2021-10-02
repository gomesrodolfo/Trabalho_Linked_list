#ifndef _cell_h_
#define _cell_h_

typedef int info_t;

typedef struct cell Cell;

Cell *create_cell(info_t info);

void print_cell(Cell *c);

void free_cell(Cell *c);

#endif