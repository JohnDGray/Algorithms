void swap_int(int*, int*);

void quick_sort_helper(int *input, int start, int end){
  if (start >= end) {
    return; 
  }
  int low = start+1;
  int high = end;
  int partition = *(input+start);
  while(1){
    while(low <= end && *(input+low) <= partition){
      ++low;
    }
    while(high >= start && *(input+high) > partition){
      --high;
    }
    if (low > high) {
      break;
    }
    swap_int(input+low, input+high);
  }
  swap_int(input+start, input+low-1);
  quick_sort_helper(input, start, low-2);
  quick_sort_helper(input, low, end);
}

void quick_sort(int *input, int length){
  quick_sort_helper(input, 0, length-1);
}
