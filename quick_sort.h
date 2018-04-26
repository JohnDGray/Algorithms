void swap_int(int*, int*);

int median_three(int *input, int first, int second, int third){
  int a = *(input+first);
  int b = *(input+second);
  int c = *(input+third);
  if ((a < b && b < c) || (c < b && b < a)) {
    return second;
  }
  if ((b < a && a < c) || (c < a && a < b)) {
    return first;
  }
  return third;
}

void quick_sort_helper(int *input, int start, int end){
  if (start >= end-1) {
    return;
  }
  int middle = (start+end-1)/2;
  int pivot = median_three(input, start, middle, end-1);
  if (start != pivot) {
    swap_int(input+start, input+pivot);
    pivot = start;
  }
  int low = start+1;
  int high = end-1;
  while(low <= high){
    while(low < end && *(input+low) <= *(input+pivot)){
      ++low;
    }
    while(high > start && *(input+high) > *(input+pivot)) {
      --high;
    }
    if(low < high){
      swap_int(input+low, input+high);
    }
  }
  swap_int(input+pivot, input+low-1);
  pivot = low-1;
  quick_sort_helper(input, start, pivot);
  quick_sort_helper(input, pivot+1, end);
}

void quick_sort(int *input, int length){
  quick_sort_helper(input, 0, length);
}
