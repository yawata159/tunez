#include <stdio.h>
#include <stdlib.h>

#include "list.h"


int main() {

  node *list = 0;

  print_list( list );

  int i;
  for (i=0; i < 10; i++)
    list = insert_front( list, i);

  print_list( list );

  list = free_list( list );

  print_list( list );
  
  return 0;
}
