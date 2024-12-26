#include <iostream>
#include <string>
#include <algorithm>

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

bool checkNumber(std::string &s1, int x) {
    for (char &i: s1) { // O(n)
        if (i >= '0' && i <= '9')
            i = char(int(i) - '0');
        else if (i >= 'A' && i <= 'A' - 11 + x)
            i = char(int(i) - 'A' + 10);
        else return false;
    }
    return true;
}

void outputArray(std::string &s1) {
    for (char i: s1) { // O(n)
        if (i <= 9)
            std::cout << char(i + '0');
        else std::cout << char(i + 'A' - 10);
    }
}

void sum(std::string &s1, std::string &s2, int x) {
    s1.insert(0, 1, 0);
    int q = (int) s1.size() - 1;
    for (auto i = (int) s2.size() - 1; i >= 0; i--) { // O(n)
        s1[q] = char(s1[q] + s2[i]);
        int k = q - 1;
        if (s1[q] >= x) {
            while (s1[k + 1] >= x && k >= 0) {
                s1[k + 1] = char(int(s1[k + 1]) % x);
                s1[k]++;
                k--;
            }
        }
        q--;
    }
}

void minus(std::string &s1, std::string &s2, int x) {
    auto k1 = (int) s1.size() - 1, k2 = (int) s2.size() - 1;
    for (auto i = 0; i < s2.size(); i++) { // O(n)
        if (s2[k2 - i] > s1[k1 - i]) {
            s1[k1 - i - 1]--;
            s1[k1 - i] = char(s1[k1 - i] + x);
        }
        s1[k1 - i] = char(s1[k1 - i] - s2[k2 - i]);
    }
}

bool isS1Minus = false, isS2Minus = false;

bool TODO(std::string s1, std::string s2, int x) {
    if (isS1Minus == isS2Minus) {
        if (s2.size() > s1.size())
            std::swap(s1, s2);
        sum(s1, s2, x);
        if (isS1Minus)
            std::cout << "-";
    } else {
        if (s2.size() > s1.size()) {
            std::swap(s1, s2);
            if (isS2Minus)
                std::cout << "-";
        } else if (s2.size() == s1.size()) {
            if (s2 > s1) {
                std::swap(s1, s2);
                if (isS2Minus)
                    std::cout << "-";
            } else if (s2 == s1) {
                std::cout << 0;
                return 0;
            } else {
                if (isS1Minus)
                    std::cout << "-";
            }
        } else {
            if (isS1Minus)
                std::cout << "-";
        }
        minus(s1, s2, x);
    }
    reverse(s1.begin(), s1.end()); // O(n)
    while (*s1.rbegin() == 0)
        s1.pop_back(); // O(n)
    reverse(s1.begin(), s1.end()); // O(n)
    outputArray(s1);
    std::cout << "_" << x;
}

void Task() {
    int x;
    while (true) {
        std::cout << "Введите систему счисления от 2 до 36: ";
        x = readInt();
        if (x >= 2 && x <= 36)
            break;
        std::cout << "Неверный формат ввода. ";
    }
    std::cout << "Введите первое число: ";
    std::string s1;
    do {
        std::cin >> s1;
        if (s1[0] == '-') {
            isS1Minus = true;
            s1.erase(0, 1);
        }
    } while (!checkNumber(s1, x));
    std::cout << "Введите второе число: ";
    std::string s2;
    do {
        std::cin >> s2;
        if (s2[0] == '-') {
            isS2Minus = true;
            s2.erase(0, 1);
        }
    } while (!checkNumber(s2, x));
    std::cout << "+: ";
    TODO(s1, s2, x);
    std::cout << "\n";
    std::cout << "-: ";
    isS2Minus = !isS2Minus;
    TODO(s1, s2, x);
    std::cout << '\n';
}