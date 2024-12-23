#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

int main(void) {
    printf("Программа, для нахождения диагонали с наибольшей суммой чисел\n");
    printf("Выполнил Ефременко Валерий, группа 453502, вариант 9\n\n");
    while (true) {
        printf("Введите 1, чтобы выполнить программу, или введите 2, чтобы закончить работу программы: ");
        int type = readInt();
        if (type != 1 && type != 2) {
            printf("Неправильный формат ввода.\n\n");
            continue;
        }
        if (type == 2) {
            printf("Выполнение программы завершено.\n");
            break;
        }
        printf("Введите размерность трехмерного массива n: ");
        int n = readInt();
        while (n < 1) {
            printf("Введите размерность трехмерного массива n заново: ");
            n = readInt();
        }
        int ***a = (int ***) malloc(n * sizeof(int **));
        for (int i = 0; i < n; i++)
            a[i] = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n * n; i++)
            a[i / n][i % n] = (int *) malloc(n * sizeof(int));
        for (int i = 0; i < n * n * n; i++) {
            printf("Введите a[%d][%d][%d]: ", i / n / n, i / n % n, i % n);
            a[i / n / n][i / n % n][i % n] = readInt();
            while (a[i / n / n][i / n % n][i % n] == -2147483648) {
                printf("Введите a[%d][%d][%d] заново: ", i / n / n, i / n % n, i % n);
                a[i / n / n][i / n % n][i % n] = readInt();
            }
        }
        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += a[i][i][i];
            sum2 += a[n - i - 1][i][i];
            sum3 += a[i][n - i - 1][i];
            sum4 += a[n - i - 1][n - i - 1][i];
        }
        int ans = sum1;
        if (sum2 > ans)
            ans = sum2;
        if (sum3 > ans)
            ans = sum3;
        if (sum4 > ans)
            ans = sum4;
        for (int i = 0; i < n * n; i++)
            free(a[i / n][i % n]);
        for (int i = 0; i < n; i++)
            free(a[i]);
        free(a);
        printf("Диагональ с наибольшей суммой чисел равна %d\n\n", ans);
    }
    return 0;
}