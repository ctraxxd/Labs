#include <iostream>

const int N = 100;

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

void swap(int i, int j, char **a) {
    auto c = a[i];
    auto d = a[j];
    a[j] = c;
    a[i] = d;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void Parse(char **a, int *sizes, const char *c) {
    int lst = -1;
    int I = 0;
    for (int i = 0; i < N; i++) {
        if (c[i] == ' ') {
            int sz = (i - (lst + 1));
            sizes[I] = sz;
            a[I] = new char[sz + 1];
            for (int j = lst + 1; j < i; j++)
                a[I][j - lst - 1] = c[j];
            a[I][sz] = '\0';
            lst = i;
            I++;
        }
    }
}

void Sort(char **a, int *sizes, int size) {
    for (int l = 0; l < size; l++) {
        for (int i = 0; i < size - 1; i++) {
            if (sizes[i] > sizes[i + 1])
                swap(i, i + 1, a), swap(sizes[i], sizes[i + 1]);
            else if (sizes[i] == sizes[i + 1]) {
                for (int j = 0; j < sizes[i]; j++)
                    if (a[i][j] > a[i + 1][j])
                        swap(i, i + 1, a);
                    else if (a[i][j] < a[i + 1][j])
                        break;
            }
        }
    }
}

void Task() {
    char *c = new char[N];
    char C = (char) getchar();
    int I = 0;
    while (C != '\n') {
        if(I < N)
            c[I] = C;
        C = (char) getchar();
        I++;
    }
    if(I >= N)
    {
        std::cout << "Неправильный формат строки. Введите данные заново.\n";
        delete[]c;
        return;
    }
    bool b = true;
    for (int j = 0; j < I; j++)
        if (c[j] == 0 || c[j] == ' ' || (c[j] >= '0' && c[j] <= '9'))
            continue;
        else b = false;
    for (int i = N - 1; i >= 0; i--)
        if (c[i] == ' ')
            c[i] = 0;
        else if (c[i] == 0)
            continue;
        else {
            c[i + 1] = ' ';
            break;
        }
    if (b) {
        int size = 0;
        for (int i = 0; i < N; i++)
            size += (c[i] == ' ');
        char **a = new char *[size];
        int *sizes = new int[size];
        Parse(a, sizes, c);
        Sort(a, sizes, size);
        std::cout << "Числа в порядке возрастания: ";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < sizes[i]; j++)
                std::cout << a[i][j];
            std::cout << " ";
        }
        std::cout << "\n\n";
        for (int i = 0; i < size; i++)
            delete[]a[i];
        delete[]a;
        delete[]sizes;
        delete[]c;
    } else {
        std::cout << "Неправильный формат строки. Введите данные заново.\n";
        delete[]c;
    }

}