#include <iostream>

int main() {
    int h1, min1, h2, min2;
    std::cin >> h1 >> min1 >> h2 >> min2;
    min1 += h1 * 60;
    min2 += h2 * 60;
    int dt;
    if (min1 <= min2)
        dt = min2 - min1;
    else dt = min2 + 24 * 60 - min1;
    std::cout << dt / 60 << ":" << dt % 60;
    return 0;
}