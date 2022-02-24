#include <bitset>
#include <iostream>

int main() {
  double d = -7.75;

  uint64_t p = *(uint64_t *)&d;
  std::cout << "Bit representation of double: " << std::bitset<64>(p) << "\n";
  std::cout << "Decimal uint64_t representation of double: " << p << "\n";

  uint64_t mantissa = 0;
  for (uint64_t i = 0ull; i < 52; i++) {
    uint64_t mask = 1ull << i;
    mantissa += p & mask;
  }

  std::cout << "Mantissa (in binary): " << std::bitset<64>(mantissa) << "\n";
  std::cout << "Mantissa (in decimal): " << mantissa << "\n";

  uint64_t exponent = 0;
  for (uint64_t i = 52ull; i < 63; i++) {
    uint64_t mask = 1ull << i;
    exponent += p & mask;
  }

  std::cout << "Exponent (in binary): " << std::bitset<64>(exponent) << "\n";
  std::cout << "Exponent (in decimal): " << exponent << "\n";

  uint64_t sign = p & (1ull << 63ull);

  std::cout << "Sign: " << (sign == 0 ? "Positive" : "Negative") << "\n";

  return 0;
}
