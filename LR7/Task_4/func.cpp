#include <iostream>

int readInt() {
    int c = getchar();
    while (c == ' ' || c == '\n')
        c = getchar();
    int sign = 1;
    long long x = 0;
    if (c == '-')
        sign = -1, c = getchar();
    bool b = false;
    while (c != '\n') {
        if (c < '0' || c > '9') {
            if (c == ' ') {
                b = true;
                c = getchar();
                continue;
            } else {
                x = -2147483648;
                sign = 1;
                break;
            }
        }
        if (b) {
            x = -2147483648;
            sign = 1;
            break;
        }
        x = (x << 3) + (x << 1) + (c - '0');
        if (x > 2147483647) {
            x = -2147483648;
            sign = 1;
            break;
        }
        c = getchar();
    }
    while (c != '\n')
        c = getchar();
    return x * sign;
}

bool check(int a, int k) {
    int add = (k + 1) >> 1;
    while (a > k) // O(log(n))
        a = (a >> 1) + ((a & 1) ? add : 0);
    return (a == k || a == 0);
}

void Task() {
    int a;
    while (true) {
        std::cout << "Введите целое число для проверки: ";
        a = readInt();
        if (a != -2147483648)
            break;
        std::cout << "Неверный формат ввода. ";
    }
    int A = a;
    if (a < 0)
        A = ~a + 1;
    std::cout << a << " ⋮ 7  \t- " << (check(A, 7) ? "Правда" : "Ложь") << "\n"
              << a << " ⋮ 73 \t- " << (check(A, 73) ? "Правда" : "Ложь") << "\n"
              << a << " ⋮ 109\t- " << (check(A, 109) ? "Правда" : "Ложь") << "\n";
}