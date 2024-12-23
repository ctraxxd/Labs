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
    std::cout << "Программа, для создания масиива из нечетных чисел четных столбцов\n";
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
        auto **a = new int *[n];
        for (int i = 0; i < n; i++) {
            a[i] = new int[m];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                std::cout << "Введите a[" << i << "][" << j << "]: ";
                a[i][j] = readInt();
                while (a[i][j] == -2147483648) {
                    std::cout << "Введите a[" << i << "][" << j << "] заново: ";
                    a[i][j] = readInt();
                }
            }
        int size = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j += 2)
                if (a[i][j] & 1)
                    size++;
        int *b = new int[size];
        int k = 0, sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j += 2)
                if (a[i][j] & 1)
                    b[k] = a[i][j], k++, sum += a[i][j];
        std::cout << "Массив из нечетных чисел в четных столбцах:\n";
        for (int i = 0; i < size; i++)
            std::cout << b[i] << " ";
        std::cout << "\nСреднее арифмитическое чисел в массиве: " << 1.0 * sum / size;
        for (int i = 0; i < n; i++) {
            delete[]a[i];
        }
        delete[]a;
        delete[]b;
    }
    return 0;
}
