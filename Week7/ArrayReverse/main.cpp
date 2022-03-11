#include <iostream>

extern "C" void reverse(int *arr, unsigned int size);

void print_array(const char *title, int *arr, const int size);

int main() {
  int nums[10] = {12, 45, 23, 14, 15, 17, 36, 38, 33, 23};

  print_array("Original", nums, 10);

  reverse(nums, 10);

  print_array("Reversed", nums, 10);

  return 0;
}

void print_array(const char *title, int *arr, const int size) {
  std::cout << title << ": [ ";

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << "]\n";
}
