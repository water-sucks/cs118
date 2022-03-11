#include <iostream>

extern "C" void fibonacci(unsigned int *arr, int size);

int main() {
  unsigned int nums[11] = {0};

  fibonacci(nums, 11);

  std::cout << "Fibonacci until 100: [ ";

  for (int i = 0; i < 11; i++) {
    std::cout << nums[i] << " ";
  }

  std::cout << "]\n";

  return 0;
}
