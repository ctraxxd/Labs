#include <iostream>

const int N = 100;

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

int main() {
    char *c = new char[N];
    char C = (char) getchar();
    int I = 0;
    while (C != '\n') {
        c[I] = C;
        C = (char) getchar();
        I++;
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
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < sizes[i]; j++)
                std::cout << a[i][j];
            std::cout << " ";
        }
        for (int i = 0; i < size; i++)
            delete[]a[i];
        delete[]a;
        delete[]sizes;
    }
    delete[]c;
    return 0;
}
