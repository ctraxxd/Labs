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

bool isPal(char *a, int size) {
    int i = 0, j = size - 1;
    while (i < j) {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void Task() {
    std::cout << "Введите количество строк: ";
    int n = readInt();
    char **c = new char *[n];
    for (int i = 0; i < n; i++) {
        c[i] = new char[1000];
        char C = getchar();
        int I = 0;
        while (C != '\n') {
            c[i][I] = C;
            C = getchar();
            I++;
        }
        for (int j = 0; j < I; j++)
            std::cout << c[i][j];
        std::cout << (isPal(c[i], I) ? " - палиндром" : " - не палиндром") << '\n';
    }
}