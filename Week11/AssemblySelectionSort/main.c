#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

extern void selection_sort(int *array, size_t size);

void print_array(int *array, size_t size);

int main() {
  int array[SIZE] = {0};

  for (int i = 0; i < SIZE; i++) {
    array[i] = (rand() % (9999 + 1)) + 1;
  }

  selection_sort(array, SIZE);

  print_array(array, SIZE);
  return 0;
}

void print_array(int *array, size_t size) {
  printf("[ ");
  for (size_t i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}
