#include <stdio.h>

int binary_search(int collection[], int left, int right, int element) {
  if (right >= left) {
    int middle = left + (right - left) / 2;

    if (collection[middle] == element) {
      return middle;
    }

    if (collection[middle] > element) {
      return binary_search(collection, left, middle - 1, element);
    }

    return binary_search(collection, middle + 1, right, element);
  }

  return -1;
}

int main() {
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int element = 38;

  int index = binary_search(arr, 0, 9, element);

  if (index < 0) {
    printf("%d not found\n", element);
  } else {
    printf("%d found at index %d\n", element, index);
  }

  return 0;
}
