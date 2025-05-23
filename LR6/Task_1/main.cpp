#include <iostream>
#include "func.h"

const int N = 100;

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, для вывода чисел строки в порядке возрастания значений\n";
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
        std::cout << "Введите строку из цифр и пробелов:\n";
        Task();
    }
    return 0;
}
