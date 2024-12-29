#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
    int bookCount = 0;
    Data *books = nullptr;
    initBooks(books, bookCount);
    if (books == nullptr) {
        books = (Data *) malloc(5 * sizeof(Data));
    }
    while (true) {
        int choice = choiceTasks();
        switch (choice) {
            case 1:
                std::cout << "=====================================================================================\n";
                inputBookData(&books, bookCount);
                break;
            case 2:
                std::cout << "=====================================================================================\n";
                displayBookArray(books, bookCount);
                break;
            case 3:
                std::cout << "=====================================================================================\n";
                addBook(&books, bookCount);
                break;
            case 4:
                std::cout << "=====================================================================================\n";
                findBookByRegNumber(books, bookCount);
                break;
            case 5:
                std::cout << "=====================================================================================\n";
                deleteBookByRegNumber(&books, &bookCount);
                break;
            case 6:
                std::cout << ("====================================================================================\n");
                updateBookByRegNumber(books, bookCount);
                break;
            case 7:
                std::cout << "=====================================================================================\n";
                sortByAuthor(books, bookCount);
                break;
            case 8:
                std::cout << "=====================================================================================\n";
                findBooksByNumberOfBook(books, bookCount);
                break;
            case 9:
                std::cout << "=====================================================================================\n";
                saveToFile(books, bookCount);
                break;
            case 10:
                std::cout << "=====================================================================================\n";
                printFromFile();
                break;
            case 11: {
                std::cout << "=====================================================================================\n";
                std::fstream file;
                int size;
                file.open("size.txt", std::ios::in);
                if (file.peek() != EOF) { //В файле что, то есть
                    file >> size;
                    file.close();
                } else {
                    std::cout << "Нечего выводить...\n";
                    file.close();
                    break;
                }
                if (size == 0) {
                    std::cout << "Нечего выводить...\n";
                    file.close();
                    break;
                }
                changeFile();
                break;
            }
            case 0:
                std::cout << "Выход из программы\n";
                return 0;
            default:
                std::cerr << "Некорректный выбор. Попробуйте снова.\n";
                break;
        }
    }
}
