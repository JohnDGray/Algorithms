#include <stdio.h>
#include "selection_sort.h"
#include "print_int_array.h"

int main(int argc, char *argv[])
{
  int values[] = {1, 53, 42, 3, 100};  
  print_int_array(values, 5);
  selection_sort(values, 5);
  print_int_array(values, 5);
  return 0;
}
