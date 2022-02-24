#include <bitset>
#include <iostream>

int main() {
  float f = -7.75;

  // The magic part! This could result in undefined behavior on
  // some systems, so be careful when using it. I'm using uint32_t
  // to ensure that it is 32 bits, but for all intents and purposes,
  // it is the same as `unsigned int`
  uint32_t p = *(uint32_t *)&f;
  std::cout << "Bit representation of float: " << std::bitset<32>(p) << "\n";
  std::cout << "Decimal uint32_t representation of float: " << p << "\n";

  // Extracting mantissa
  uint32_t mantissa = 0;
  for (int i = 0; i < 23; i++) {
    mantissa += p & (1 << i);
  }

  std::cout << "Mantissa (in binary): " << std::bitset<32>(mantissa) << "\n";
  std::cout << "Mantissa (in decimal): " << mantissa << "\n";

  uint32_t exponent = 0;
  for (int i = 23; i < 31; i++) {
    exponent += p & (1 << i);
  }

  std::cout << "Exponent (in binary): " << std::bitset<32>(exponent) << "\n";
  std::cout << "Exponent (in decimal): " << exponent << "\n";

  // Extracting sign
  uint32_t sign = p & (1u << 31u);

  std::cout << "Sign: " << (sign == 0 ? "Positive" : "Negative") << "\n";
  return 0;
}
