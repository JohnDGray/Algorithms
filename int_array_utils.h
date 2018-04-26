void print_int_array(int *input, int length){
  if (length < 1) {
    return;
  }
  for (int i = 0; i < length-1; i++) {
    printf("%d, ", *(input+i));
  }
  printf("%d\n", *(input+length-1));
}

int int_array_is_sorted(int *input, int length){
  for(int i = 0; i < length-1; ++i){
    if (*(input+i) > *(input+i+1)) {
      return 0; 
    }
  }
  return 1;
}
