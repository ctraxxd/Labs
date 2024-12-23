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
    std::cout << "Программа, для нахождения максимального среди элементов, лежащих выше побочной диагонали\n";
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
        std::cout << "Введите размерность магического квадрата: ";
        int n = readInt();
        while (n < 1) {
            std::cout << "Введите размерность магического квадрата заново: ";
            n = readInt();
        }
        int **a = new int *[n];
        for (int i = 0; i < n; i++)
            a[i] = new int[n];
        bool *used = new bool[n * n + 1];
        for (int i = 0; i <= n * n; i++)
            used[i] = false;
        bool b = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                std::cout << "Введите a[" << i << "][" << j << "]: ";
                a[i][j] = readInt();
                while (a[i][j] < 0) {
                    std::cout << "Введите a[" << i << "][" << j << "] заново: ";
                    a[i][j] = readInt();
                }
                if (a[i][j] > n * n)
                    b = false;
                else used[a[i][j]] = true;
            }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i][0];
        int sum1 = 0, sum2 = 0;
        if (b)
            for (int i = 0; i < n; i++) {
                int sumi = 0, sumj = 0;
                for (int j = 0; j < n; j++)
                    sumi += a[i][j], sumj += a[j][i];
                if (sumi != sum || sumj != sum) {
                    b = false;
                    break;
                }
                sum1 += a[i][i];
                sum2 += a[i][n - i - 1];
            }
        if (sum1 != sum || sum2 != sum)
            b = false;
        if (b)
            std::cout << "Матрица является магическим квадратом\n";
        else std::cout << "Матрица не является магическим квадратом\n";
        delete[] used;
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
        std::cout << '\n';
    }
    return 0;
}
