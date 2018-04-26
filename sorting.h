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

void insertion_sort(int *input, int length){
  for (int i = 1; i < length; ++i) {
    for (int j = i; j > 0; --j){
      if(*(input + j) < *(input + j - 1)){
        swap_int(input+j, input+j-1);
      }
    }
  }
}

void merge(int *input, int start, int middle, int end){
  int length = end-start;
  int *temp = malloc(sizeof(int) * length);
  if(!temp){
    exit(1);
  }
  int i = start, j = middle, temp_index = 0;
  while(1){
    if(i == middle){
      while(j < end){
        *(temp+temp_index) = *(input+j);
        j++;
        temp_index++;
      }
      break;
    }
    if(j == end){
      while(i < middle){
        *(temp+temp_index) = *(input+i);
        i++;
        temp_index++;
      }
      break;
    }
    if(*(input+j) < *(input+i)){
      *(temp+temp_index) = *(input+j);
      j++;
    }
    else{
      *(temp+temp_index) = *(input+i);
      i++;
    }
    temp_index++;
  }
  for(i = 0; i < length; ++i){
    *(input+i+start) = *(temp+i); 
  }
  free(temp);
}

void merge_sort_helper(int *input, int start, int end){
  if (start >= end-1) {
    return;
  }
  int middle = (start+end)/2;
  merge_sort_helper(input, start, middle);
  merge_sort_helper(input, middle, end);
  merge(input, start, middle, end);
}

void merge_sort(int *input, int length){
  merge_sort_helper(input, 0, length);
}

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

void shell_sort_at_level(int *input, int length, int level){
  for(int low = 0; low < level; low++){
    for(int start = low+level; start < length; start += level){
      for(int index = start; index > low; index -= level){
        if (*(input+index) >= *(input+index-level)) {
          break;
        }
        swap_int(input+index, input+index-level);
      }
    }
  }
}

void shell_sort(int *input, int length){
  int level = 1;
  while(level < length/3){
    level = 3 * level + 1;
  }
  while(level > 0){
    shell_sort_at_level(input, length, level);
    level /= 3;
  }
}
