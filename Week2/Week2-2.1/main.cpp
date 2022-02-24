#include <iostream>
#include <bitset>

unsigned int set_bit(unsigned int, char);
unsigned int clear_bit(unsigned int, char);

void print_bin(std::string, unsigned int);

int main() {
    std::cout << "Setting bit examples" << "\n";
    print_bin("10", 10);
    unsigned int x1 = set_bit(10, 0);
    print_bin("x1", x1);
    unsigned int x2 = set_bit(10, 2);
    print_bin("x2", x2);
    unsigned int x3 = set_bit(x1, 0);
    print_bin("x3", x3);
    unsigned int x4 = set_bit(x2, 2);
    print_bin("x4", x4);

    std::cout << "\n";

    std::cout << "Clearing bit examples" << "\n";
    print_bin("10", 10);
    x1 = clear_bit(10, 1);
    print_bin("x1", x1);
    x2 = clear_bit(10, 3);
    print_bin("x2", x2);
    x3 = clear_bit(x1, 1);
    print_bin("x3", x3);
    x4 = clear_bit(x2, 3);
    print_bin("x4", x4);

    return 0;
}

unsigned int set_bit(unsigned int n, char p) {
    unsigned int mask = 1 << p;
    return n | mask;
}

unsigned int clear_bit(unsigned int n, char p) {
    unsigned int mask = ~(1 << p);
    return n & mask;
}

void print_bin(std::string name, unsigned int n) {
    std::cout << name << ": " << std::bitset<32>(n) << "\n";
}
