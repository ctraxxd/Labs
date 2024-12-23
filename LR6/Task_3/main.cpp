#include <iostream>

bool isPal(char *a, int size) {
    int i = 0, j = size - 1;
    while (i < j) {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    char **c = new char *[n];
    char C = getchar();
    while (C != '\n')
        C = getchar();
    for (int i = 0; i < n; i++) {
        c[i] = new char[80];
        char C = getchar();
        int I = 0;
        while (C != '\n') {
            c[i][I] = C;
            C = getchar();
            I++;
        }
        for (int j = 0; j < I; j++)
            std::cout << c[i][j];
        std::cout << (isPal(c[i], I) ? " - палиндром" : " - не палиндром") << '\n';
    }
    return 0;
}
