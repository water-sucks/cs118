#include <stdio.h>
  
void merge(int collection[], int left_index, int middle_index, int r) {
  int i, j, k;
  int left_size = middle_index - left_index + 1;
  int right_size = r - middle_index;
  
  int left[left_size], right[right_size];
  
  for (i = 0; i < left_size; i++) {
    left[i] = collection[left_index + i];
  }

  for (j = 0; j < right_size; j++) {
    right[j] = collection[middle_index + 1 + j];
  }
  
  i = 0;
  j = 0;
  k = left_index;
  while (i < left_size && j < right_size) {
    if (left[i] <= right[j]) {
      collection[k] = left[i];
      i++;
    }
    else {
      collection[k] = right[j];
      j++;
    }
    k++;
  }
  
  while (i < left_size) {
    collection[k] = left[i];
    i++;
    k++;
  }
  
  while (j < right_size) {
    collection[k] = right[j];
    j++;
    k++;
  }
}
  
void merge_sort(int collection[], int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
  
    merge_sort(collection, left, middle);
    merge_sort(collection, middle + 1, right);
  
    merge(collection, left, middle, right);
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
  
  merge_sort(arr, 0, 5);
  
  printf("Sorted array: ");
  print_array(arr, 6);

  return 0;
}
