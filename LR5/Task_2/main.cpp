#include <iostream>
#include <cmath>

double rec(int l, int r, int *a) {
    if (r - l + 1 == 1)
        return std::sin(a[l]) - std::cos(a[l]);
    else if (r - l + 1 == 2)
        return (std::sin(a[l]) - std::cos(a[l])) * (std::sin(a[r]) - std::cos(a[r]));
    int m = l + (r - l + 1) / 3;
    return rec(l, m, a) * rec(m + 1, r, a);
}

int readInt() {
    int input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -2147483648;
    }
    return input;
}



int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, вычисляющая формулу рекурсивно\n";
    std::cout << "Выполнил Ефременко Валерий, группа 453502, вариант 9\n\n";
    while (true) {
        std::cout << "Введите 1, чтобы выполнить программу, или введите 2, чтобы закончить работу программы: ";
        int type = readInt();
        if (type != 1 && type != 2) {
            std::cout << "Неправильный формат ввода.\n\n";
            continue;
        }
        if (type == 2) {
            std::cout << "Выполнение программы завершено.\n";
            break;
        }
        std::cout << "Введите количество чисел в массиве: ";
        int n = readInt();
        while (n < 1) {
            std::cout << "Введите количество чисел в массиве заново: ";
            n = readInt();
        }
        auto *c = new double[n];
        for (int j = 0; j < n; j++) {
            std::cout << "Введите с[" << j << "]: ";
            c[j] = readInt();
            while (c[j] == -2147483648) {
                std::cout << "Введите с[" << j << "] заново: ";
                c[j] = readInt();
            }
        }
        std::cout << "Результат равен: " << rec(0, n - 1, c) << "\n\n";
        delete[]c;
    }
}