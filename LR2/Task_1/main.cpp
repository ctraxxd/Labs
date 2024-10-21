#include <iostream>

int main() {
    double a, b, c, x;
    std::cout << "Введите x: ";
    std::cin >> x;
    c = 23 * x * x;
    a = x * (c + 32);
    b = 3 * c + 8;
    std::cout << a + b << "\n" << b - a << "\n";
    return 0;
}
//a = 23x^3 + 32x
//b = 69x^2 + 8