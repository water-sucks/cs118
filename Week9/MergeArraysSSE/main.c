#include <stdio.h>
#include <stdlib.h>

extern void add_sse(float one[], float other[], float dest[], size_t size);

void print_array(float array[], size_t size);

int main(int argc, char *argv[]) {
  float one[] = {1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8,
                 1.9, 2.0, 2.1, 2.2, 2.3, 2.4};
  float other[] = {2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8,
                   2.9, 3.0, 3.1, 3.2, 3.3, 3.4};
  float dest[13] = {0};

  add_sse(one, other, dest, 13);

  print_array(dest, 13);

  return 0;
}

void print_array(float array[], size_t size) {
  printf("[ ");
  for (size_t i = 0; i < size; i++) {
    printf("%f ", array[i]);
  }
  printf("]\n");
}
