#include <stdio.h>
#include "list.h"

int main() {
  List *lst = create_list();

  insert_list(lst, 2, 0);
  insert_list(lst, 1, 0);

  printf("Size = %d\n", size_list(lst));
  print_list(lst);
  printf("\n");

  remove_list(lst, 1);
  printf("Size = %d\n", size_list(lst));
  print_list(lst);
  printf("\n");

  insert_list(lst, 3, 1);
  printf("Size = %d\n", size_list(lst));
  print_list(lst);
  printf("\n");

  remove_list(lst, 0);
  printf("Size = %d\n", size_list(lst));
  print_list(lst);
  printf("\n");

  remove_list(lst, 0);
  printf("Size = %d\n", size_list(lst));
  print_list(lst);
  printf("\n");

  free_list(lst);

  return 0;
}