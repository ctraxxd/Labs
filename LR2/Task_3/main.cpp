#include <iostream>

int main() {
    const int n = 9;
    double b1, q = 1.0 / (n + 1);
    std::cout << "Введите b1: ";
    std::cin >> b1;
    std::cout << (b1 / (1 - q));
    return 0;
}