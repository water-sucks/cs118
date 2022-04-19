#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <smmintrin.h>

float sum(float *array, size_t size);
float standard_deviation(float *array, size_t size);

int main(int argc, char **argv) {
  float data[31] = {
      11, 14, 15, 11, 12, 13, 14, 17, 18, 19, 22, 13, 14, 15, 16, 26,
      15, 14, 13, 24, 25, 65, 27, 18, 28, 16, 15, 13, 34, 33, 44,
  };
  printf("standard deviation: %f\n", standard_deviation(data, 31));
  return 0;
}

float sum(float *array, size_t size) {
  __m128 acc = _mm_setzero_ps();
  size_t i = 0;

  for (; i < ((size) & ~((4) - 1)); i += 4) {
    acc = _mm_add_ps(acc, _mm_loadu_ps(array + i));
  }
  acc = _mm_hadd_ps(acc, acc);
  acc = _mm_hadd_ps(acc, acc);

  for (; i < size; i++) {
    acc = _mm_add_ss(acc, _mm_load_ss(array + i));
  }

  return _mm_cvtss_f32(acc);
}

float standard_deviation(float *array, size_t size) {
  float average = sum(array, size) / size;
  const __m128 diff = _mm_set1_ps(average);

  __m128 acc = _mm_setzero_ps();
  size_t i = 0;

  for (; i < ((size) & ~((4) - 1)); i += 4) {
    __m128 sub = _mm_sub_ps(_mm_loadu_ps(array + i), diff);
    acc = _mm_add_ps(acc, _mm_mul_ps(sub, sub));
  };

  acc = _mm_hadd_ps(acc, acc);
  acc = _mm_hadd_ps(acc, acc);

  float deviations = _mm_cvtss_f32(acc);

  for (; i < size; i++) {
    float sub = array[i] - average;
    deviations += sub * sub;
  }

  return sqrt(deviations / size);
}
