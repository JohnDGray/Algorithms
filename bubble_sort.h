void swap_int(int*, int*);

void bubble_sort(int *input, int length){
  for(int i = length-1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if (*(input+j) > *(input+j+1)) {
        swap_int(input+j, input+j+1);
      } 
    } 
  }
}
