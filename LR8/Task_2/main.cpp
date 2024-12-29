#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
    int bookCount = 0;
    Data *books = (Data *) malloc(5 * sizeof(Data));
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
                findBooksByYear(books, bookCount);
                break;
            case 9:
                std::cout << "=====================================================================================\n";
                addNewBook();
                break;
            case 10:
                std::cout << "=====================================================================================\n";
                deleteBook();
                break;
            case 11: {
                std::cout << "=====================================================================================\n";
                updateBook();
                break;
            }
            case 12: {
                std::cout << "=====================================================================================\n";
                displayBooks();
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
