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
    std::cout << "Программа, для создания динамического массива из четных элементов главной диагонали\n";
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
        std::cout << "Введите размерность матрицы: ";
        int n = readInt();
        while (n < 1) {
            std::cout << "Введите размерность матрицы заново: ";
            n = readInt();
        }
        int **a = new int *[n];
        for (int i = 0; i < n; i++) {
            a[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                std::cout << "Введите a[" << i << "][" << j << "]: ";
                a[i][j] = readInt();
                while (a[i][j] == -2147483648) {
                    std::cout << "Введите a[" << i << "][" << j << "] заново: ";
                    a[i][j] = readInt();
                }
            }
        int size = 0;
        for (int i = 0; i < n; i++)
            if (a[i][i] % 2 == 0)
                size++;
        int *b = new int[size];
        long long j = 0, res = 1;
        for (int i = 0; i < n; i++)
            if (a[i][i] % 2 == 0)
                b[j] = a[i][i], j++, res *= a[i][i];
        std::cout << "Динамический массив b: ";
        for (int i = 0; i < size; i++)
            std::cout << b[i] << " ";
        std::cout << "\nПроизведение чисел массива: " << res;
        for (int i = 0; i < n; i++) {
            delete[]a[i];
        }
        delete[]a;
        delete[]b;
        std::cout << '\n';
    }
    return 0;
}
