#include <stdio.h>

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
    printf("Программа, для дополнения поля для игры в сапёр\n");
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
        printf("Введите количество рядов n: ");
        int n = readInt();
        while (n < 1) {
            printf("Введите количество рядов n заново: ");
            n = readInt();
        }
        printf("Введите количество столбцов m: ");
        int m = readInt();
        while (m < 1) {
            printf("Введите количество столбцов m заново: ");
            m = readInt();
        }
        int c[n][m];
        int try = 0;
        int lst = '\n';
        while (true) {
            try++;
            if (try == 1)
                printf("Введите поле для игры в сапёр размером %d * %d:\n", n, m);
            else printf("Введите поле для игры в сапёр размером %d * %d заново:\n", n, m);
            bool b = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    c[i][j] = getchar();
                    lst = c[i][j];
                    if (c[i][j] != '.' && c[i][j] != '*') {
                        b = false;
                        break;
                    }
                }
                if (!b)
                    break;
                lst = getchar();
                if (lst != '\n') {
                    b = false;
                    break;
                }
            }
            if (!b) {
                while (lst != '\n')
                    lst = getchar();
                continue;
            } else break;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (c[i][j] != '*') {
                    int cnt = 0;
                    for (int di = -1; di <= 1; di++)
                        for (int dj = -1; dj <= 1; dj++) {
                            int I = i + di, J = j + dj;
                            if (I >= 0 && J >= 0 && I < n && J < m)
                                cnt += (c[I][J] == '*');
                        }
                    if (cnt == 0)
                        c[i][j] = ' ';
                    else c[i][j] = '0' + cnt;
                }
            }
        printf("Дополненное поле для игры в сапёр:\n");
        for (int i = 0; i <= 4 * m; i++)
            printf("-");
        printf("\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("| %c ", c[i][j]);
            printf("|\n");
            for (int j = 0; j <= 4 * m; j++)
                printf("-");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}