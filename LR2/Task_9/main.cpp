#include <iostream>
#include <cmath>

int type;

double f(double x) {
    switch (type) {
        case 1:
            return 2 * x;
        case 2:
            return pow(x, 3);
        case 3:
            return x / 3;
        default:
            std::cout << "ERROR";
            exit(0);
    }
}

int main() {
    double z, x, y, b, a;
    std::cout << "Введите z, a, b, type:\n";
    std::cin >> z >> a >> b >> type;
    if (z <= 0)
        x = z * z / 2;
    else x = sqrt(z);
    y = b * f(x) / cos(x) + a * log(fabs(tan(x / 2)));
    std::cout << y;
    return 0;
}