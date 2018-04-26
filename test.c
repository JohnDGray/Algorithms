#include <stdio.h>
#include <stdlib.h>
#include "swap_int.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "int_array_utils.h"

void test_sort(void(*)(int*, int));

int main(int argc, char *argv[])
{
  printf("selection sort\n");
  test_sort(selection_sort);
  printf("insertion sort\n");
  test_sort(insertion_sort);
  printf("bubble sort\n");
  test_sort(bubble_sort);
  printf("shell sort\n");
  test_sort(shell_sort);
  printf("merge sort\n");
  test_sort(merge_sort);

  return 0;
}

void test_sort(void (*sort)(int*, int)){
  int large_number = 20000;
  int *big = malloc(sizeof(int) * large_number);
  if(!big){
    printf("Could not get large array");
    exit(1);
  }
  for (int i = 0; i < large_number; i++) {
    *(big+i) = rand() % large_number;
  }
  int values[] = {0, 1, -1, 25, -25, 500, -500};  
  int one_value[] = {666};
  int empty[] = {};

  printf("before sort:\n");
  print_int_array(big, 10);
  print_int_array(values, 7);
  print_int_array(one_value, 1);
  print_int_array(empty, 0);
  printf("\n");

  (*sort)(big, large_number);
  (*sort)(values, 7);
  (*sort)(one_value, 1);
  (*sort)(empty, 0);

  printf("after sort:\n");
  print_int_array(big, 10);
  print_int_array(values, 7);
  print_int_array(one_value, 1);
  print_int_array(empty, 0);
  printf("\n");

  int success = int_array_is_sorted(big, large_number) && int_array_is_sorted(values, 7) && int_array_is_sorted(one_value, 1) && int_array_is_sorted(empty, 0);
  if (success) {
    printf("sort successful!\n"); 
  }
  else{
    printf("sort FAILED!!!\n"); 
  }
  printf("\n");

  free(big);
}
