#include <iostream>

int main() {
    double a, b, c, Y;
    int N;
    std::cout << "Введите a, b, c, N: ";
    std::cin >> a >> b >> c >> N;
    switch (N) {
        case 2:
            Y = b * c - a * a;
            break;
        case 56:
            Y = b * c;
            break;
        case 7:
            Y = a * a + c;
            break;
        case 3:
            Y = a - b * c;
            break;
        default:
            Y = (a + b) * (a + b) * (a + b);
            break;
    }
    std::cout << Y;
    return 0;
}