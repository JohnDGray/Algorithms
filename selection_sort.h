void swap_int(int*, int*);

void selection_sort(int *input, int length){
  for (int i = 0; i < length; ++i) {
    int min_index = i;
    for (int j = i+1; j < length; j++) {
      if (*(input+j) < *(input+min_index)){
        min_index = j;
      } 
    }
    swap_int(input+i, input+min_index);
  } 
}
