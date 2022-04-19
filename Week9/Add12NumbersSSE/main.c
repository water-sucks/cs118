#include <stdio.h>

extern float add_sse(float array[], size_t size);

int main(int argc, char *argv[]) {
  float ary[12] = {1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.1, 2.2};

  float sum = add_sse(ary, 12);

  printf("%f\n", sum);

  return 0;
}
