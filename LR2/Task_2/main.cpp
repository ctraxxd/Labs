#include <iostream>

int main() {
    long double x, y, z;
    std::cout << "Введите x, y, z: ";
    std::cin >> x >> y >> z;
    long double len = std::max(x, std::max(y, z));
    if (len < x + y + z - len)
        std::cout << "Треугольник существует";
    else std::cout << "Треугольник не существует";
    return 0;
}