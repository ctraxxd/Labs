#include <iostream>
#include "func.h"

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, для перевода числа из естественной формы в прямой код\n";
    std::cout << "Выполнил Ефременко Валерий, группа 453502, вариант 9\n";
    while (true) {
        std::cout << "\nВведите 1, чтобы выполнить программу, или введите 2, чтобы закончить работу программы: ";
        int type = readInt();
        if (type != 1 && type != 2) {
            std::cout << "Неправильный формат ввода.\n\n";
            continue;
        }
        if (type == 2) {
            std::cout << "Выполнение программы завершено.\n";
            break;
        }
        Task();
    }
    return 0;
}