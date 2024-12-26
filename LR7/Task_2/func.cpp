#include <iostream>
#include <string>

int readInt() {
    int input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -2147483648;
    }
    return input;
}

int *transfer(std::string s, int n, int &sz) {
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = s[n - i - 1] - '0';
    int *b = new int[4 * n];
    int *c = new int[n];
    int I = 0;
    while (true) {
        b[I] = a[0] & 1;
        I++;
        int J = n - 1;
        a[0] -= (a[0] & 1);
        for (int i = n - 1; i >= 0; i--) {
            c[J] = a[i] / 2;
            a[i - 1] += (a[i] % 2) * 10;
            J--;
        }
        J++;
        bool B = true;
        for (int j = J; j < n; j++) {
            a[j - J] = c[j];
            if (c[j])
                B = false;
        }
        for (int j = n - J; j < n; j++)
            a[j] = 0;
        if (B)
            break;
    }
    while (I % 8 != 7)
        I++;
    sz = I + 1;
    delete[]a;
    delete[]c;
    return b;
}

void Task() {
    std::cout << "Введите первое число в естественной форме: ";
    std::string s1;
    std::cin >> s1;
    bool b1 = true;
    int sign1 = 0;
    while (b1) {
        sign1 = 0;
        if (s1[0] == '-')
            sign1 = 1, s1.erase(s1.begin());
        int n = s1.size();
        for (int i = 0; i < n; i++)
            if (s1[i] < '0' || s1[i] > '9') {
                std::cout << "Неверный формат ввода. Введите число в естественной форме: ";
                std::cin >> s1;
                break;
            }
        b1 = false;
    }
    int n = s1.size();
    int I;
    auto a = transfer(s1, n, I);
    if (sign1) {
        for (int i = 0; i < I; i++)
            a[i] ^= 1;
        a[0]++;
        for (int i = 0; i < I - 1; i++) {
            a[i + 1] += a[i] / 2;
            a[i] %= 2;
        }
        a[I - 1] %= 2;
    }
    std::cout << "Введите второе число в естественной форме: ";
    std::string s2;
    std::cin >> s2;
    bool b2 = true;
    int sign2 = 0;
    while (b2) {
        sign2 = 0;
        if (s2[0] == '-')
            sign2 = 1, s2.erase(s2.begin());
        int m = s2.size();
        for (int i = 0; i < m; i++)
            if (s2[i] < '0' || s2[i] > '9') {
                std::cout << "Неверный формат ввода. Введите число в естественной форме: ";
                std::cin >> s2;
                break;
            }
        b2 = false;
    }
    int m = s2.size();
    int J;
    auto b = transfer(s2, m, J);
    if (sign2) {
        for (int i = 0; i < J; i++)
            b[i] ^= 1;
        b[0]++;
        for (int i = 0; i < J - 1; i++) {
            b[i + 1] += b[i] / 2;
            b[i] %= 2;
        }
        b[J - 1] %= 2;
    }
    int l = std::max(I, J);
    int c[l + 1];
    int add = 0;
    for (int i = 0; i < l; i++) {
        c[i] = add;
        if (i >= I)
            c[i] += sign1;
        else c[i] += a[i];
        if (i >= J)
            c[i] += sign2;
        else c[i] += b[i];
        add = c[i] / 2;
        c[i] %= 2;
    }
    c[l] = 1;
    for (int i = 0; i <= l; i++)
        if (c[i]) {
            for (int j = 0; j <= i; j++)
                c[j] ^= 1;
            break;
        }
    for (int i = 0; i < l; i++)
        c[i] ^= 1;
    for (int i = l - 1; i >= 0; i--)
        std::cout << c[i];
}