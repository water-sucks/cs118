#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubble_sort(int collection[], size_t size) {
  size_t i, j;
  for (i = 0; i < size - 1; i++) {
    bool swapped = false;
    for (j = 0; j < size - i - 1; j++) {
      if (collection[j] > collection[j+1]) {
        swap(&collection[j], &collection[j+1]);
        swapped = true;
      }
    }

    if (swapped == false) {
      break;
    }
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
  
  bubble_sort(arr, 6);
  
  printf("Sorted array: ");
  print_array(arr, 6);

  return 0;
}
