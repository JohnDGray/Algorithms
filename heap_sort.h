void swap_int(int*, int*);

void sink(int *heap, int length, int index){
  int child1 = 2*index+1;
  int child2 = 2*index+2;
  if (child1 >= length) {
    return;
  }
  int child_to_use = child1;
  if (child2 < length && *(heap+child1) < *(heap+child2)) {
    child_to_use = child2;
  }
  if (*(heap+child_to_use) > *(heap+index)){
    swap_int(heap+index, heap+child_to_use);
    sink(heap, length, child_to_use);
  }
}

void swim(int *heap, int index){
  if (index < 1) {
    return;
  }
  int parent = (index-1)/2;
  if (*(heap+parent) < *(heap+index)) {
    swap_int(heap+parent, heap+index);
    swim(heap, parent);
  }
}

int remove_max(int *heap, int length){
  int max = *heap;
  *heap = *(heap+length-1);
  sink(heap, length-1, 0);
  return max;
}

void heapify(int *input, int length){
  int index = length/2-1;
  while(index >= 0){
    sink(input, length, index);
    --index;
  }
}

void heap_sort(int *input, int length){
  heapify(input, length);
  while(length > 1){
    int max = remove_max(input, length);
    *(input+length-1) = max;
    --length;
  }
}
