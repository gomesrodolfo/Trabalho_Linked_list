#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"
#define info_t int


struct cell
{
    int value;
    struct cell *next;
};

typedef struct cell Cell;

struct list
{
    Cell *first;
    Cell *last;
    int size;
};

List *create_list()
{
    List *lst = (List *)malloc(sizeof(List));
    lst->size = 0;
    lst->first = NULL;
    lst->last = NULL;
    return lst;
}

int size_list(List *lst)
{
    return lst->size;
}

// void insert_first(List *lst, info_t info)
// {
//     Cell *c = create_cell(info);
//     lst->first = c;
// }

// void insert_last(List *lst, info_t info)
// {
// }

void insert_list(List *lst, info_t info, int pos)
{
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->value = info;
    int old_size = lst->size++;

    // We have to test several cases.

    // Empty list.
    if (old_size == 0)
    {
        // Argument pos is ignored... :P
        //c->prev = c->next = NULL;
        lst->first = lst->last = c;
        return;
    }

    // Not empty, inserting at first.
    if (pos <= 0)
    {
        //c->prev = NULL;
        //lst->first->prev = c;
        c->next = lst->first;
        lst->first = c;
        return;
    }

    // Not empty, inserting at last.
    if (pos >= old_size)
    {
        c->next = NULL;
        lst->last->next = c;
        //c->prev = lst->last;
        lst->last = c;
        return;
    }

    // Not empty, inserting in the middle.
    Cell *t = lst->first;
    int i;
    for (i = 0; i < pos; i++)
    {
        t = t->next;
    }
    Cell *p;
    p->next = c;
    //c->prev = p;
    c->next = t;
    //t->prev = c;
}

void remove_list(List *lst, int pos)
{
    if (lst->size == 0)
    {
        return;
    }

    if (pos < 0)
    {
        lst->size = 0;
    }

    Cell *c = lst->first;
    int i;

    for (i = 0; i < pos; i++)
    {
        c = c->next;
    }

    // Cell *p = c->prev;
    Cell *n = c->next;

    // if (p != NULL)
    // {
    //     p->next = n;
    // }
    // if (n != NULL)
    // {
    //     n->prev = p;
    // }

    if (lst->first == c)
    {
        lst->first = n;
    }

    if (lst->last == c)
    {
        lst->last = NULL;
    }

    free(c);
    lst->size--;
}

void print_list(List *lst)
{
    Cell *c;
    int i;
    c = lst->first;
    printf("[");
    for (i = 0; i < lst->size; i++)
    {
        print_cell(c);
        if (i != lst->size - 1)
        {
            printf(", ");
        }
        c = c->next;
    }
    printf("]");
}

void free_list(List *lst)
{
    int i;
    Cell *c = lst->first;
    Cell *t;
    for (i = 0; i < lst->size; i++)
    {
        t = c->next;
        free_cell(c);
        c = t;
    }
    free(lst);
}
