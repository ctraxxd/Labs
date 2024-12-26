#include <iostream>
#include <string>

int readInt() {
    int input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -2147483648;
    }
    return input;
}

int* transfer(std::string s, int n, int &sz)
{
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        a[i] = s[n - i - 1] - '0';
    int *b = new int[4 * n];
    int *c = new int[n];
    int I = 0;
    while(true)
    {
        b[I] = a[0] & 1;
        I++;
        int J = n - 1;
        a[0] -= (a[0] & 1);
        for(int i = n - 1; i >= 0; i--)
        {
            c[J] = a[i] / 2;
            a[i - 1] += (a[i] % 2) * 10;
            J--;
        }
        J++;
        bool B = true;
        for(int j = J; j < n; j++) {
            a[j - J] = c[j];
            if(c[j])
                B = false;
        }
        for(int j = n - J; j < n; j++)
            a[j] = 0;
        if(B)
            break;
    }
    while(I % 8 != 7)
        I++;
    sz = I;
    delete[]a;
    delete[]c;
    return b;
}

void Task() {
    std::cout << "Введите число в естественной форме: ";
    std::string s;
    std::cin >> s;
    int sign = 0;
    if(s[0] == '-')
        sign = 1, s.erase(s.begin());
    int n = s.size();
    for(int i = 0; i < n; i++)
        if(s[i] < '0' || s[i] > '9')
        {
            std::cout << "Неверный формат ввода. ";
            Task();
            return;
        }
    int I;
    auto a = transfer(s, n, I);
    a[I - 1] = sign;
    for(int i = I - 1; i >= 0; i--)
        std::cout << a[i];
}