#include <cstdio>

extern "C" int average(int *arr, int size);

int main() {
  int nums[10] = {12, 45, 23, 14, 15, 17, 36, 38, 33, 23};

  int ans = average(nums, 10);

  printf("Average is: %d\n", ans);

  return 0;
}
