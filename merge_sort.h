void swap_int(int*, int*);

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
