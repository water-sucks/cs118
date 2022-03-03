#include <stdio.h>

extern void filter(int *array, int *even, int *odd, int size);

void print_array(char *title, int *array, int size);

int main() {
  int array[10] = {3, 8, 7, 6, 4, 3, 2, 16, 13, 14};
  int even[10] = {0};
  int odd[10] = {0};

  filter(array, even, odd, 10);

  print_array("Original array: ", array, 10);
  print_array("Even array: ", even, 10);
  print_array("Odd array: ", odd, 10);

  return 0;
}

void print_array(char *title, int *array, int size) {
  printf("%s: [ ", title);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("]\n");
}
