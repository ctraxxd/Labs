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
        std::cout << "Введите количество строк в матрице: ";
        int m = readInt();
        while (m < 1) {
            std::cout << "Введите количество строк в массиве заново: ";
            m = readInt();
        }
        std::cout << "Введите количество столбцов в матрице: ";
        int n = readInt();
        while (n < 1 || n != m) {
            if (n != m && n >= 1)
                std::cout << "Введённый размеры массива не являются квадратной матрицей\n";
            std::cout << "Введите количество строк в массиве заново: ";
            n = readInt();
        }
        int a[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                std::cout << "Введите a[" << i << "][" << j << "]: ";
                a[i][j] = readInt();
                while (a[i][j] == -2147483648) {
                    std::cout << "Введите a[" << i << "][" << j << "] заново: ";
                    a[i][j] = readInt();
                }
            }
        if (m == n) {
            int ans = 0;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    ans = std::max(ans, a[i][j]);
            std::cout << "Максимальный элемент равен " << ans;
        }
        std::cout << '\n';
    }
    return 0;
}
