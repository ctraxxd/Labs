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
    std::cout << "Программа, для формирования транспонировнной матрицы и подсчета суммы определенных строк и столбцов \n";
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
        std::cout << "Введите размерность квадратной матрицы: ";
        int n = readInt();
        while (n < 1) {
            std::cout << "Введите размерность квадратной матрицы заново: ";
            n = readInt();
        }
        int **a = new int *[n];
        int **b = new int *[n];
        for (int i = 0; i < n; i++) {
            a[i] = new int[n];
            b[i] = new int[n];
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i <= 5)
                    a[i - 1][j - 1] = 2 * i * j * j - 2 * j;
                else a[i - 1][j - 1] = 3 * i * j - 3;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                b[i][j] = a[j][i];
        int sum1a = 0, sum2a = 0, sum1b = 0, sum2b = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i & 1)
                    sum1a += a[i][j];
                if (!(j & 1))
                    sum2a += a[i][j];
                if (j & 1)
                    sum1b += b[i][j];
                if (!(i & 1))
                    sum2b += b[i][j];
            }
        std::cout << "Матрица А:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                std::cout << a[i][j] << " ";
            std::cout << '\n';
        }
        std::cout << "Матрица B:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                std::cout << b[i][j] << " ";
            std::cout << '\n';
        }
        std::cout << '\n';
        std::cout << "Четные строки А: " << sum1a
        << "\nНечетные столбцы А: " << sum2a
        << "\nЧетные столбцы В: " << sum1b
        << "\nНечетные строки В: " << sum2b << "\n\n";
        for (int i = 0; i < n; i++) {
            delete[]a[i];
            delete[]b[i];
        }
        delete[]a;
        delete[]b;
    }
    return 0;
}
