void print_int_array(int* input, int length){
  if (length < 1) {
    return;
  }
  for (int i = 0; i < length-1; i++) {
    printf("%d, ", *(input+i));
  }
  printf("%d\n", *(input+length-1));
}
