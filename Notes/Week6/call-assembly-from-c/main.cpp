#include <iostream>

extern "C" int comp(int a, int b);

int main(int argc, char *argv[]) {
  std::cout << comp(2, 1) << std::endl;
  return 0;
}
