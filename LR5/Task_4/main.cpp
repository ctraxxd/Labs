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

double readDouble() {
    double input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -2147483648;
    }
    return input;
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, для записи массива в обратном порядке\n";
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
        std::cout << "Введите количество строк матрицы: ";
        int n = readInt();
        while (n < 1) {
            std::cout << "Введите количество строк матрицы заново: ";
            n = readInt();
        }
        std::cout << "Введите количество столбцов матрицы: ";
        int m = readInt();
        while (m < 1) {
            std::cout << "Введите количество столбцов матрицы заново: ";
            m = readInt();
        }
        auto **a = new double *[n];
        for (int i = 0; i < n; i++) {
            a[i] = new double[m];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                std::cout << "Введите a[" << i << "][" << j << "]: ";
                a[i][j] = readDouble();
                while (a[i][j] == -2147483648) {
                    std::cout << "Введите a[" << i << "][" << j << "] заново: ";
                    a[i][j] = readDouble();
                }
            }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 0)
                    cnt++;
        auto **b = new double *[n];
        for (int i = 0; i < n; i++) {
            b[i] = new double[m];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                b[i][j] = a[n - i - 1][m - j - 1];
        std::cout << "Матрица записаная в обратном порядке:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                std::cout << b[i][j] << " ";
            std::cout << '\n';
        }
        std::cout << "Количество чисел равных 0 и их индексы:";
        std::cout << '\n' << cnt << '\n';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 0)
                    std::cout << i << " " << j << '\n';
        for (int i = 0; i < n; i++) {
            delete[]a[i];
            delete[]b[i];
        }
        delete[]a;
        delete[]b;
    }
    return 0;
}
