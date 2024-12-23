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
    printf("Программа, для нахождния магического квадрата\n");
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
        printf("Введите размерность магического квадрата n: ");
        int n = readInt();
        while (n < 1) {
            printf("Введите размерность магического квадрата n заново: ");
            n = readInt();
        }
        int **a = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
            a[i] = (int *) malloc(n * sizeof(int));
        if (n % 4 == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i % 2 == j % 2 && ((i < n / 2 && j < n / 2) || (i >= n / 2 && j >= n / 2)))
                        a[i][j] = (i * n) + j + 1;
                    else if (i % 2 != j % 2 && !((i < n / 2 && j < n / 2) || (i >= n / 2 && j >= n / 2)))
                        a[i][j] = (i * n) + j + 1;
                    else a[i][j] = n * n - ((i * n) + j);
                }
            }
        } else if (n % 2 == 1) {
            int x = n / 2, y = -n / 2;
            for (int i = 0; i < n; i++) {
                for (int j = 1, x1 = x, y1 = y; j <= n; j++, x1--, y1++) {
                    a[(x1 + n) % n][(y1 + n) % n] = i * n + j;
                }
                x++;
                y++;
            }
        } else {
            n /= 2;
            int x = n / 2, y = -n / 2;
            for (int i = 0; i < n; i++) {
                for (int j = 1, x1 = x, y1 = y; j <= n; j++, x1--, y1++) {
                    a[(x1 + n) % n][(y1 + n) % n] = i * n + j;
                }
                x++;
                y++;
            }
            n *= 2;
            for (int i = n / 2; i < n; i++)
                for (int j = n / 2; j < n; j++)
                    a[i][j] = a[i - n / 2][j - n / 2] + (n / 2) * (n / 2);
            for (int i = 0; i < n / 2; i++)
                for (int j = n / 2; j < n; j++)
                    a[i][j] = a[i][j - n / 2] + 2 * (n / 2) * (n / 2);
            for (int i = n / 2; i < n; i++)
                for (int j = 0; j < n / 2; j++)
                    a[i][j] = a[i - n / 2][j] + 3 * (n / 2) * (n / 2);
            int c;
            for (int i = 0; i < n / 2; i++)
                for (int j = n / 2 - n / 4 + 1; j <= n / 2 + n / 4 - 2; j++) {
                    c = a[i][j];
                    a[i][j] = a[i + n / 2][j];
                    a[i + n / 2][j] = c;
                }
            c = a[0][0];
            a[0][0] = a[n / 2][0];
            a[n / 2][0] = c;
            c = a[n / 2 - 1][0];
            a[n / 2 - 1][0] = a[n - 1][0];
            a[n - 1][0] = c;
            for (int i = 1; i < n / 2 - 1; i++) {
                c = a[i][1];
                a[i][1] = a[i + n / 2][1];
                a[i + n / 2][1] = c;
            }
        }
        if (n == 2)
            printf("Магического квадрата размера 2 не существует\n");
        else {
            printf("Магический квадрат размера: %d\n", n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    printf("%d ", a[i][j]);
                printf("\n");
            }
        }
        for (int i = 0; i < n; i++)
            free(a[i]);
        free(a);
        printf("\n");
    }
    return 0;
}
/*
1  15 14 4
12  6  7 9
8  10 11 5
13 3  2  16
 */