void swap_int(int*, int*);

void insertion_sort(int *input, int length){
  for (int i = 1; i < length; ++i) {
    for (int j = i; j > 0; --j){
      if(*(input + j) < *(input + j - 1)){
        swap_int(input+j, input+j-1);
      }
    }
  }
}
