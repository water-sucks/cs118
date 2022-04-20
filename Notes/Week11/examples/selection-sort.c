#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selection_sort(int collection[], size_t size) {
  size_t i, j;

  for (i = 0; i < size - 1; i++) {
    size_t minimum_index = i;

    for (j = i + 1; j < size; j++) {
      if (collection[j] < collection[minimum_index]) {
        minimum_index = j;
      }
    }

    swap(&collection[minimum_index], &collection[i]);
  }
}

void print_array(int array[], size_t size) {
  printf("[ ");

  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("]\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  
  printf("Original array: ");
  print_array(arr, 6);
  
  selection_sort(arr, 6);
  
  printf("Sorted array: ");
  print_array(arr, 6);

  return 0;
}
