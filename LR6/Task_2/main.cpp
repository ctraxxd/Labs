#include <iostream>

int isLet(char x) {
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
        if (x == 'a' || x == 'o' || x == 'u' || x == 'i' || x == 'e' || x == 'y' ||
            x == 'A' || x == 'O' || x == 'U' || x == 'I' || x == 'E' || x == 'Y') {
            return 1;
        } else return -1;
    }
    return 0;
}

int main() {
    char *c = new char[80];
    char C = getchar();
    int I = 0;
    while (C != '\n') {
        c[I] = C;
        C = getchar();
        I++;
    }
    int delta = 0;
    for (int i = 0; i < 80; i++)
        delta += isLet(c[i]);
    if (delta > 0)
        std::cout << "Гласных";
    else if (delta == 0)
        std::cout << "Поровну";
    else std::cout << "Согласных";
    delete[]c;
    return 0;
}
