#include <iostream>
#include <bitset>

bool read_bit(unsigned int n, char p);

int main() {
    std::cout << std::boolalpha; // Prints true/false instead of 0/1

    std::cout << "10 in binary: " << std::bitset<32>(10) << "\n";

    bool x1 = read_bit(10, 0);
    std::cout << "Set at position 0: " << x1 << "\n";
    bool x2 = read_bit(10, 1);
    std::cout << "set at position 1: " << x2 << "\n";
    bool x3 = read_bit(10, 2);
    std::cout << "set at position 2: " << x3 << "\n";
    bool x4 = read_bit(10, 3);
    std::cout << "set at position 3: " << x4 << "\n";
    bool x5 = read_bit(10, 4);
    std::cout << "set at position 4: " << x5 << "\n";

    return 0;
}

bool read_bit(unsigned int n, char p) {
    unsigned int mask = 1 << p;
    return n & mask;
}
