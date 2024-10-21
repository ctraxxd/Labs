#include <iostream>

const long double Pi = 3.14159265358979323846, eps = 1e-18;

long double sqrt(long double x) {
    long double l, r;
    if (x > 1)
        l = 1, r = x;
    else l = x, r = 1;
    for (int op = 0; op < 100; op++) {
        long double mid = (l + r) / 2;
        if (mid * mid <= x)
            l = mid;
        else r = mid;
    }
    return l;
}

long double arcsin(long double x) {
    if (x < 0)
        return -arcsin(-x);
    if (x * x > 0.5)
        return Pi / 2 - arcsin(sqrt(1 - x * x));
    long double res = x;
    long double lst = x;
    long double n = 0;
    while (lst > eps) {
        lst = lst * (2 * n + 1) * (2 * n + 2) * x * x / 4.0 / (n + 1) / (n + 1) * (2 * n + 1) / (2 * n + 3);
        res += lst;
        n++;
    }
    return res;
}

long double arccos(long double x) {
    return Pi / 2 - arcsin(x);
}

long double len(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    long double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите координаты вершин: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    long double l1 = len(x1, y1, x2, y2);
    long double l2 = len(x1, y1, x3, y3);
    long double l3 = len(x3, y3, x2, y2);
    long double cos1 = (l3 * l3 - l1 * l1 - l2 * l2) / (-2 * l1 * l2);
    long double cos2 = (l2 * l2 - l1 * l1 - l3 * l3) / (-2 * l1 * l3);
    long double cos3 = (l1 * l1 - l2 * l2 - l3 * l3) / (-2 * l2 * l3);
    long double sin1 = sqrt(1 - cos1 * cos1);
    long double sin2 = sqrt(1 - cos2 * cos2);
    long double sin3 = sqrt(1 - cos3 * cos3);
    long double h1 = sin1 * l2;
    long double h2 = sin1 * l1;
    long double h3 = sin3 * l2;
    long double m1 = sqrt((2 * l2 * l2 + 2 * l3 * l3 - l1 * l1) / 4);
    long double m2 = sqrt((2 * l1 * l1 + 2 * l3 * l3 - l2 * l2) / 4);
    long double m3 = sqrt((2 * l2 * l2 + 2 * l1 * l1 - l3 * l3) / 4);
    long double b1 = sqrt(l2 * l3 * (l1 + l2 + l3) * (l2 + l3 - l1)) / (l2 + l3);
    long double b2 = sqrt(l1 * l3 * (l1 + l2 + l3) * (l1 + l3 - l2)) / (l1 + l3);
    long double b3 = sqrt(l2 * l1 * (l1 + l2 + l3) * (l2 + l1 - l3)) / (l2 + l1);
    long double a1 = arccos(cos1);
    long double a2 = arccos(cos2);
    long double a3 = arccos(cos3);
    long double A1 = a1 / Pi * 180;
    long double A2 = a2 / Pi * 180;
    long double A3 = a3 / Pi * 180;
    long double p = (l1 + l2 + l3) / 2;
    long double r = sqrt((p - l1) * (p - l2) * (p - l3) / p);
    long double R = l2 / (2 * sin2);
    long double l = 2 * Pi * r;
    long double L = 2 * Pi * R;
    long double s = Pi * r * r;
    long double S = Pi * R * R;
    long double P = l1 + l2 + l3;
    long double S1 = sqrt(p * (p - l1) * (p - l2) * (p - l3));
    long double S2 = h1 * l1 / 2;
    long double S3 = l1 * l2 * sin1 / 2;
    std::cout << "Длины сторон треугольника: " << l1 << " " << l2 << " " << l3 << "\n";
    std::cout << "Длины высот треугольника: " << h1 << " " << h2 << " " << h3 << "\n";
    std::cout << "Длины медиан треугольника: " << m1 << " " << m2 << " " << m3 << "\n";
    std::cout << "Длины биссектрис треугольника: " << b1 << " " << b2 << " " << b3 << "\n";
    std::cout << "Градусная/радианная мера углов треугольника: " << A1 << "°/" << a1 << " " << A2 << "°/" << a2 << " "
              << A3 << "°/" << a3 << "\n";
    std::cout << "Радиусы вписанной и описанной окружностей треугольника: " << r << " " << R << "\n";
    std::cout << "Длины вписанной и описанной окружностей треугольника: " << l << " " << L << "\n";
    std::cout << "Площади вписанной и описанной окружностей треугольника: " << s << " " << S << "\n";
    std::cout << "Периметр и площадь треугольника тремя способами: " << P << "    " << S1 << " " << S2 << " " << S3
              << "\n";
    return 0;
}
