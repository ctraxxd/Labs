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

int isLet(char x) {
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
        if (x == 'a' || x == 'o' || x == 'u' || x == 'i' || x == 'e' || x == 'y' ||
            x == 'A' || x == 'O' || x == 'U' || x == 'I' || x == 'E' || x == 'Y') {
            return 1;
        } else return -1;
    }
    return 0;
}

void Task() {
    char *c = new char[80];
    char C = getchar();
    int I = 0;
    while (C != '\n') {
        c[I] = C;
        C = getchar();
        I++;
    }
    int delta = 0;
    for (int i = 0; i < 80; i++)
        delta += isLet(c[i]);
    if (delta > 0)
        std::cout << "Гласных\n";
    else if (delta == 0)
        std::cout << "Поровну\n";
    else std::cout << "Согласных\n";
    delete[]c;
}