void swap_int(int*, int*);

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
