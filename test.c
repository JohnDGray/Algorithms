#include <stdio.h>
#include <stdlib.h>
#include "swap_int.h"
#include "int_array_utils.h"
#include "sorting.h"

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
  printf("quick sort\n");
  test_sort(quick_sort);
  printf("heap sort\n");
  test_sort(heap_sort);

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
  int two_unsorted[] = {5, 4};
  int two_sorted[] = {4, 5};
  int three_unsorted[] = {5, 4, 3};
  int three_sorted[] = {3, 4, 5};
  int four_unsorted[] = {0, 1, -1, 2};  
  int four_sorted[] = {-1, 0, 1, 2};  
  int five_unsorted[] = {0, 1, -1, 2, -2};  
  int five_sorted[] = {-2, -1, 0, 1, 2};  
  int one_value[] = {666};
  int empty[] = {};

  printf("before sort:\n");
  print_int_array(big, 10);
  print_int_array(two_unsorted, 2);
  print_int_array(two_sorted, 2);
  print_int_array(three_unsorted, 3);
  print_int_array(three_sorted, 3);
  print_int_array(four_unsorted, 4);
  print_int_array(four_sorted, 4);
  print_int_array(five_unsorted, 5);
  print_int_array(five_sorted, 5);
  print_int_array(one_value, 1);
  print_int_array(empty, 0);
  printf("\n");

  (*sort)(big, large_number);
  (*sort)(two_unsorted, 2);
  (*sort)(two_sorted, 2);
  (*sort)(three_unsorted, 3);
  (*sort)(three_sorted, 3);
  (*sort)(four_unsorted, 4);
  (*sort)(four_sorted, 4);
  (*sort)(five_unsorted, 5);
  (*sort)(five_sorted, 5);
  (*sort)(one_value, 1);
  (*sort)(empty, 0);

  printf("after sort:\n");
  print_int_array(big, 10);
  print_int_array(two_unsorted, 2);
  print_int_array(two_sorted, 2);
  print_int_array(three_unsorted, 3);
  print_int_array(three_sorted, 3);
  print_int_array(four_unsorted, 4);
  print_int_array(four_sorted, 4);
  print_int_array(five_unsorted, 5);
  print_int_array(five_sorted, 5);
  print_int_array(one_value, 1);
  print_int_array(empty, 0);
  printf("\n");

  int success = int_array_is_sorted(big, large_number) 
                && int_array_is_sorted(two_unsorted, 2) && int_array_is_sorted(two_sorted, 2) 
                && int_array_is_sorted(three_unsorted, 3) && int_array_is_sorted(three_sorted, 3) 
                && int_array_is_sorted(four_unsorted, 4) && int_array_is_sorted(four_sorted, 4) 
                && int_array_is_sorted(five_unsorted, 5) && int_array_is_sorted(five_sorted, 5) 
                && int_array_is_sorted(one_value, 1) && int_array_is_sorted(empty, 0);
  if (success) {
    printf("sort successful!\n"); 
  }
  else{
    printf("sort FAILED!!!\n"); 
  }
  printf("\n");

  free(big);
}
