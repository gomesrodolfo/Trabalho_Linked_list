#ifndef _list_h_
#define _list_h_

typedef struct list List;

List* create_list();

int size_list(List *lst);

void insert_first(List *lst, info_t info);

void insert_last(List *lst, info_t info);

void insert_list(List *lst, info_t info, int pos);

void remove_list(List *lst, int pos);

void print_list(List *lst);

void free_list(List *lst);

#endif

