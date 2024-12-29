#include "functions.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

void input(char *str) {
    char c;
    int i = 0;
    while (true) {
        if (std::cin.peek() == ' ')
            str[i] = ' ', i++;
        std::cin >> c;
        str[i] = c, i++;
        if (std::cin.peek() == '\n')
            break;
    }
    str[i] = '\0';
}

void inputF(char *str, std::fstream &file) {
    char c;
    int i = 0;
    while (true) {
        if (file.peek() == ' ')
            str[i] = ' ', i++;
        file >> c;
        str[i] = c, i++;
        if (file.peek() == '\n')
            break;
    }
    str[i] = '\0';
}

void inputData(Data **books, int *count, int *max_count) {
    int num_books;
    std::cin >> num_books;
    for (int i = 0; i < num_books; i++) {
        if (*count >= *max_count) {
            *max_count *= 2;
            Data *temp = (Data *) realloc(*books, (*max_count) * sizeof(Data));
            if (!temp) {
                std::cout << "Ошибка выделения памяти.\n";
                return;
            }
            *books = temp;
        }
        std::cout << "Введите регистрационный номер: ";
        std::cin >> (*books)[*count].regNumber;
        std::cout << "Введите автора: ";
        input((*books)[*count].author);
        std::cout << "Введите название книги: ";
        input((*books)[*count].name);
        std::cout << "Введите год издания: ";
        std::cin >> (*books)[*count].year;
        std::cout << "Введите издательство: ";
        input((*books)[*count].publishHouse);
        std::cout << "Введите количество страниц: ";
        std::cin >> (*books)[*count].u.numberOfBooks;
        (*count)++;
    }
}

void inputBookData(Data **books, int &bookCount) {
    int maxCount = 5;
    std::cout << "Введите количество различных книг: ";
    inputData(books, &bookCount, &maxCount);
}

void addBook(Data **books, int &count) {
    std::cout << "Введите количество книг для добавления: ";
    int maxCount = 5;
    inputData(books, &count, &maxCount);
}

int choiceTasks() {
    int choice;
    std::cout << "\n=====================================================================================\n"
              << "                                       Меню"
              << "\n=====================================================================================\n\n"
              << "1. Ввести данные о книгах\n"
              << "2. Показать данные о книгах\n"
              << "3. Добавить новые книги\n"
              << "4. Найти книгу по рег. номеру\n"
              << "5. Удалить книгу по рег. номеру\n"
              << "6. Изменить данные книги по рег. номеру\n"
              << "7. Сортировать книги по автору\n"
              << "8. Найти все книги после заданного года\n"
              << "9. Добавить книгу в файл\n"
              << "10. Удалить книгу из файла\n"
              << "11. Корректировка книги в файле\n"
              << "12. Просмотр книг из файла\n"
              << "0. Выход из программы\n\n"
              << "Ваш выбор: ";
    std::cin >> choice;
    return choice;
}

void displayBookArray(Data *books, int count) {
    std::cout
            << ("Данные о книгах:\n=====================================================================================\n");
    for (int i = 0; i < count; i++) {
        std::cout << "Рег. номер: " << books[i].regNumber << '\n' << "Автор: "
                  << books[i].author << '\n'
                  << "Название: "
                  << books[i].name << '\n'
                  << "Год издания: " << books[i].year << '\n' << "Издательство: "
                  << books[i].publishHouse << "\nКол-во книг: "
                  << books[i].u.numberOfBooks << "\n---------------------------------------------\n";
    }
}

void findBookByRegNumber(Data *books, int count) {
    int id;
    std::cout << "Введите рег. номер для поиска: ";
    std::cin >> id;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (books[i].regNumber == id) {
            std::cout << "Рег. номер: " << books[i].regNumber << '\n' << "Автор: "
                      << books[i].author << '\n'
                      << "Название: "
                      << books[i].name << '\n'
                      << "Год издания: " << books[i].year << '\n' << "Издательство: "
                      << books[i].publishHouse << "\nКол-во книг: "
                      << books[i].u.numberOfBooks << "\n---------------------------------------------\n";
            found = 1;
            break;
        }
    }
    if (!found) {
        std::cout << "Книга с рег. номером " << id << " не найдена.\n";
    }
}

void deleteBookByRegNumber(Data **books, int *count) {
    int id;
    std::cout << "Введите рег. номер для удаления: ";
    std::cin >> id;
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if ((*books)[i].regNumber == id) {
            for (int j = i; j < *count - 1; ++j) {
                (*books)[j] = (*books)[j + 1];
            }
            found = 1;
            break;
        }
    }
    if (found) {
        (*count)--;
        Data *temp = (Data *) realloc(*books, (*count) * sizeof(Data));
        if (temp) {
            *books = temp;
        }
        std::cout << "Книга с номером " << id << " удалена.\n";
    } else {
        std::cout << "Книга с номером " << id << " не найдена, т.к. её нет в данных.\n";
    }
}

void updateBookByRegNumber(Data *books, int count) {
    int id;
    std::cout << "Введите рег. номер для изменения: ";
    std::cin >> id;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (books[i].regNumber == id) {
            std::cout << "Введите новые данные для книги с рег. номером: " << id << '\n';
            std::cout << "Введите автора: ";
            input(books[i].author);
            std::cout << "Введите навзание: ";
            input(books[i].name);
            std::cout << "Введите год издания: ";
            std::cin >> books[i].year;
            std::cout << "Введите издательство: ";
            input(books[i].publishHouse);
            std::cout << "Введите количество книг: ";
            std::cin >> books[i].u.numberOfBooks;
            break;
        }
    }
    if (!found) {
        std::cout << "Книги с рег. номером " << id << " не найдено.\n";
    }
}

bool Is_Bigger(char *a, char *b) {
    for (int i = 0; i < 1000; i++)
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    return false;
}

void sortByAuthor(Data *books, int count) {
    bool isSorted = false;
    int right = count - 1;
    int start = 0;
    while (!isSorted) {
        isSorted = true;
        for (int i = start; i < right; i++) {
            if (Is_Bigger(books[i].author, books[i + 1].author)) {
                Data temp = books[i];
                books[i] = books[i + 1];
                books[i + 1] = temp;
                isSorted = false;
            }
        }
        right--;
        for (int i = right - 1; i >= start; i--) {
            if (Is_Bigger(books[i].author, books[i + 1].author)) {
                Data temp = books[i];
                books[i] = books[i + 1];
                books[i + 1] = temp;
                isSorted = false;
            }
        }
        start++;
    }
    std::cout << "Массив отсортирован в алфавитном порядке относительно авторов.\n";
}

void findBooksByYear(Data *books, int count) {
    sortByAuthor(books, count);
    int year;
    std::cout << "Введите год издания: ";
    std::cin >> year;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (books[i].year >= year) {
            std::cout << "Рег. номер: " << books[i].regNumber << '\n' << "Автор: "
                      << books[i].author << '\n'
                      << "Название: "
                      << books[i].name << '\n'
                      << "Год издания: " << books[i].year << '\n' << "Издательство: "
                      << books[i].publishHouse << "\nКол-во книг: "
                      << books[i].u.numberOfBooks << "\n---------------------------------------------\n";
            found = 1;
        }
    }
    if (!found) {
        std::cout << "Нет книг изданных после " << year << '\n';
    }
}

void strcp(std::string s, char *c) {
    for (int i = 0; i < s.size(); i++)
        c[i] = s[i];
    c[s.size()] = '\0';
}

void addNewBook() {
    std::fstream file;
    file.open("data.txt", std::ios::in);
    int cnt = 0;
    if (file.peek() != EOF)
        file >> cnt;
    Data books[cnt + 1];
    for (int i = 0; i < cnt; i++) {
        char str[4000];
        inputF(str, file);
        int j = 0, c = 0;
        std::string s;
        while (str[j] != '\0') {
            if (str[j] == '|') {
                if (c == 0)
                    books[i].regNumber = stoi(s);
                else if (c == 1)
                    strcp(s, books[i].author);
                else if (c == 2)
                    strcp(s, books[i].name);
                else if (c == 3)
                    books[i].year = stoi(s);
                else if (c == 4)
                    strcp(s, books[i].publishHouse);
                c++;
                s = "";
                j++;
            }
            s += str[j];
            j++;
        }
        books[i].u.numberOfBooks = stoi(s);
    }
    file.close();
    std::cout << "Введите регистрационный номер: ";
    std::cin >> books[cnt].regNumber;
    std::cout << "Введите автора: ";
    input(books[cnt].author);
    std::cout << "Введите название книги: ";
    input(books[cnt].name);
    std::cout << "Введите год издания: ";
    std::cin >> books[cnt].year;
    std::cout << "Введите издательство: ";
    input(books[cnt].publishHouse);
    std::cout << "Введите количество страниц: ";
    std::cin >> books[cnt].u.numberOfBooks;
    file.open("data.txt", std::ios::out);
    file << cnt + 1 << '\n';
    for (int i = 0; i <= cnt; i++)
        file << books[i].regNumber << '|' << books[i].author << '|' << books[i].name << '|' << books[i].year << '|'
             << books[i].publishHouse << '|' << books[i].u.numberOfBooks << '\n';
    file.close();
}

void deleteBook() {
    std::fstream file;
    file.open("data.txt", std::ios::in);
    int cnt = 0;
    if (file.peek() != EOF)
        file >> cnt;
    Data books[cnt];
    for (int i = 0; i < cnt; i++) {
        char str[4000];
        inputF(str, file);
        int j = 0, c = 0;
        std::string s;
        while (str[j] != '\0') {
            if (str[j] == '|') {
                if (c == 0)
                    books[i].regNumber = stoi(s);
                else if (c == 1)
                    strcp(s, books[i].author);
                else if (c == 2)
                    strcp(s, books[i].name);
                else if (c == 3)
                    books[i].year = stoi(s);
                else if (c == 4)
                    strcp(s, books[i].publishHouse);
                c++;
                s = "";
                j++;
            }
            s += str[j];
            j++;
        }
        books[i].u.numberOfBooks = stoi(s);
    }
    file.close();
    int id;
    std::cout << "Введите регистрационный номер книги, которую хотим удалить: ";
    std::cin >> id;
    file.open("data.txt", std::ios::out);
    int c = 0;
    for (int i = 0; i < cnt; i++)
        if (books[i].regNumber == id)
            c++;
    file << cnt - c << '\n';
    for (int i = 0; i < cnt; i++)
        if (books[i].regNumber != id)
            file << books[i].regNumber << '|' << books[i].author << '|' << books[i].name << '|' << books[i].year
                 << '|' << books[i].publishHouse << '|' << books[i].u.numberOfBooks << '\n';
    file.close();
}

void updateBook() {
    std::fstream file;
    file.open("data.txt", std::ios::in);
    int cnt = 0;
    if (file.peek() != EOF)
        file >> cnt;
    Data books[cnt];
    for (int i = 0; i < cnt; i++) {
        char str[4000];
        inputF(str, file);
        int j = 0, c = 0;
        std::string s;
        while (str[j] != '\0') {
            if (str[j] == '|') {
                if (c == 0)
                    books[i].regNumber = stoi(s);
                else if (c == 1)
                    strcp(s, books[i].author);
                else if (c == 2)
                    strcp(s, books[i].name);
                else if (c == 3)
                    books[i].year = stoi(s);
                else if (c == 4)
                    strcp(s, books[i].publishHouse);
                c++;
                s = "";
                j++;
            }
            s += str[j];
            j++;
        }
        books[i].u.numberOfBooks = stoi(s);
    }
    file.close();
    int id;
    std::cout << "Введите регистрационный номер книги, которую хотим изменить: ";
    std::cin >> id;
    file.open("data.txt", std::ios::out);
    for (int i = 0; i < cnt; i++)
        if (books[i].regNumber == id) {
            std::cout << "Введите автора: ";
            input(books[i].author);
            std::cout << "Введите название книги: ";
            input(books[i].name);
            std::cout << "Введите год издания: ";
            std::cin >> books[i].year;
            std::cout << "Введите издательство: ";
            input(books[i].publishHouse);
            std::cout << "Введите количество страниц: ";
            std::cin >> books[i].u.numberOfBooks;
            break;
        }
    file << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        file << books[i].regNumber << '|' << books[i].author << '|' << books[i].name << '|' << books[i].year << '|'
             << books[i].publishHouse << '|' << books[i].u.numberOfBooks << '\n';
    file.close();
}

void displayBooks() {
    std::fstream file;
    file.open("data.txt", std::ios::in);
    int cnt = 0;
    if (file.peek() != EOF)
        file >> cnt;
    Data books[cnt];
    for (int i = 0; i < cnt; i++) {
        char str[4000];
        inputF(str, file);
        int j = 0, c = 0;
        std::string s;
        while (str[j] != '\0') {
            if (str[j] == '|') {
                if (c == 0)
                    books[i].regNumber = stoi(s);
                else if (c == 1)
                    strcp(s, books[i].author);
                else if (c == 2)
                    strcp(s, books[i].name);
                else if (c == 3)
                    books[i].year = stoi(s);
                else if (c == 4)
                    strcp(s, books[i].publishHouse);
                c++;
                s = "";
                j++;
            }
            s += str[j];
            j++;
        }
        books[i].u.numberOfBooks = stoi(s);
    }
    file.close();
    for (int i = 0; i < cnt; i++) {
        std::cout << "Рег. номер: " << books[i].regNumber << '\n' << "Автор: "
                  << books[i].author << '\n'
                  << "Название: "
                  << books[i].name << '\n'
                  << "Год издания: " << books[i].year << '\n' << "Издательство: "
                  << books[i].publishHouse << "\nКол-во книг: "
                  << books[i].u.numberOfBooks << "\n---------------------------------------------\n";
    }
}