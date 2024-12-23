#include <iostream>

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
    std::cout << "Программа, формирующая два массива: с отрицательными числами и с остальными\n";
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
        int k = readInt();
        while (k < 1) {
            std::cout << "Введите количество чисел в массиве заново: ";
            k = readInt();
        }
        int a[k];
        int sz1 = 0, sz2 = 0;
        for (int i = 0; i < k; i++) {
            std::cout << "Введите a[" << i << "]: ";
            a[i] = readInt();
            while (a[i] == -2147483648) {
                std::cout << "Введите a[" << i << "] заново: ";
                a[i] = readInt();
            }
            if (a[i] < 0)
                sz1++;
            else sz2++;
        }
        int f[sz1], s[sz2];
        int i1 = 0, i2 = 0;
        for (int i = 0; i < k; i++) {
            if (a[i] < 0)
                f[i1] = a[i], i1++;
            else s[i2] = a[i], i2++;
        }
        std::cout << "Первый массив: ";
        for (int i = 0; i < sz1; i++)
            std::cout << f[i] << " ";
        std::cout << "\nВторой массив: ";
        for (int i = 0; i < sz2; i++)
            std::cout << s[i] << " ";
        std::cout << "\n";
    }
    return 0;
}
