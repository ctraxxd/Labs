#include "functions.h"

#define fopen_s(pFile, filename, mode) ((*(pFile))=fopen((filename),  (mode)))==NULL

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <fstream>

std::fstream file;
bool isDataEntered = false;

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
        std::cin >> (*books)[*count].numberOfBooks;
        (*count)++;
    }

}

void inputBookData(Data **books, int &bookCount) {
    int maxCount = 5;
    if (isDataEntered) {
        std::cout << "Ошибка: Данные о книгах уже введены, повторный ввод недоступен.\n";
        return;
    }
    std::cout << "Введите количество различных книг: ";
    inputData(books, &bookCount, &maxCount);
    isDataEntered = true;
}

void addBook(Data **books, int &count) {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
    std::cout << "Введите количество книг для добавления: ";
    int maxCount = 5;
    inputData(books, &count, &maxCount);
}

void initBooks(Data *&books, int &count) {
    int size;
    file.open("size.txt", std::ios::in);
    if (file.peek() != EOF) {
        file >> size;
        file.close();
    } else {
        std::cout << "Файл пуст...\n";
        file.close();
        return;
    }
    if (size == 0) {
        std::cout << "Файл пуст...\n";
        file.close();
        return;
    }
    books = (Data *) malloc(size * sizeof(Data));
    file.open("books.bin", std::ios_base::binary | std::ios_base::in);
    Data Data;
    for (int i = 0; i < size; i++) {
        file.read((char *) &Data, sizeof(Data));
        books[i] = Data;
        std::cout << Data.regNumber << '\n';
    }
    isDataEntered = true;
    count = size;
    file.close();
    std::cout << "Загружено " << size << " книг из файла";
    count = size;
    file.close();
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
              << "5. Удалить изделие по рег. номеру\n"
              << "6. Изменить данные изделия по рег. номеру\n"
              << "7. Сортировать изделия по автору\n"
              << "8. Найти все книги после заданного года\n"
              << "9. Запись данных в файл\n"
              << "10. Чтение данных из файла\n"
              << "11. Корректировка данных файла\n"
              << "0. Выход из программы\n\n"
              << "Ваш выбор: ";
    while (!(std::cin >> choice) || std::cin.peek() != '\n' || (choice < 0 || choice > 11)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка ввода.\nПожалуйста, выберите значение от 0 до 11: ";
    }
    return choice;
}

void displayBookArray(Data *books, int count) {
    if (!isDataEntered) {
        std::cout << ("Введите сначала данные...\n");
        return;
    }
    std::cout
            << ("Данные о книгах:\n=====================================================================================\n");
    for (int i = 0; i < count; i++) {
        std::cout << "Рег. номер: " << books[i].regNumber << '\n' << "Автор: "
                  << books[i].author << '\n'
                  << "Название: "
                  << books[i].name << '\n'
                  << "Год издания: " << books[i].year << '\n' << "Издательство: "
                  << books[i].publishHouse << "\nКол-во книг: "
                  << books[i].numberOfBooks << "\n---------------------------------------------\n";
    }
}

void findBookByRegNumber(Data *books, int count) {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
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
                      << books[i].numberOfBooks << "\n---------------------------------------------\n";
            found = 1;
            break;
        }
    }
    if (!found) {
        std::cout << "Продукция с рег. номером " << id << " не найдена.\n";
    }
}

void deleteBookByRegNumber(Data **books, int *count) {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
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
    if (!isDataEntered) {
        std::cout << ("Введите сначала данные...\n");
        return;
    }
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
            std::cin >> books[i].numberOfBooks;
            break;
        }
    }
    if (!found) {
        std::cout << "Книг изданных после " << id << " не найдено.\n";
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
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
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
    std::cout << "Массив отсортирован в алфавитном порядке авторов.\n";
}

void findBooksByNumberOfBook(Data *books, int count) {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
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
                      << books[i].numberOfBooks << "\n---------------------------------------------\n";
            found = 1;
        }
    }

}

void printFromFile() {
    int size;
    file.open("size.txt", std::ios::in);
    if (file.peek() != EOF) { //В файле что, то есть
        file >> size;
        file.close();
    } else {
        std::cout << "Нечего выводить...\n";
        file.close();
        return;
    }
    if (size == 0) {
        std::cout << "Нечего выводить...\n";
        file.close();
        return;
    }
    file.open("books.bin", std::ios_base::binary | std::ios_base::in);
    Data data;
    for (int i = 0; i < size; i++) {
        file.read((char *) &data, sizeof(Data));
        std::cout << "Рег. номер: " << data.regNumber << '\n' << "Автор: "
                  << data.author << '\n'
                  << "Название: "
                  << data.name << '\n'
                  << "Год издания: " << data.year << '\n' << "Издательство: "
                  << data.publishHouse << "\nКол-во книг: "
                  << data.numberOfBooks << "\n---------------------------------------------\n";

    }
    file.close();
}

void changeFile() {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
    printFromFile();
    int idx;
    std::cout << "Выберите книгу для изменения: ";
    std::cin >> idx;
    idx--;
    Data Data;
    file.open("books.bin", std::ios_base::binary | std::ios_base::in);
    file.seekg(idx * sizeof(Data), std::ios::beg);
    file.read((char *) &Data, sizeof(Data));
    file.close();
    int cc;
    std::cout << "1) Название изделия\n2) Номер цеха\n3) Количество сделанных изделий\n4) Масса одного изделия";
    std::cout << "\n\nВведите параметр для изменения: ";
    while (!(std::cin >> cc) || std::cin.peek() != '\n' || (cc < 1 || cc > 4)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка ввода.\nПожалуйста, выберите значение от 1 до 4: ";
    }
    std::cin.ignore();
    if (cc == 1) {
        std::cout << "\nВведите новое название изделия: ";
        input(Data.author);
        std::cout << "Обновление успешно";
    } else if (cc == 2) {
        std::cout << "\nВведите новый номер цеха: ";
        input(Data.name);
        std::cout << "Обновление успешно";
    } else if (cc == 3) {
        std::cout << "\nВведите новое количество изделия: ";
        std::cin >> Data.year;
        std::cout << "Обновление успешно";
    } else if (cc == 4) {
        std::cout << "\nВведите новую массу изделия: ";
        input(Data.publishHouse);
        std::cout << "Обновление успешно";
    } else if (cc == 5) {
        std::cout << "\nВведите новую массу изделия: ";
        std::cin >> Data.numberOfBooks;
        std::cout << "Обновление успешно";
    }
    FILE *f1;
    fopen_s(&f1, "books.bin", "rb+");
    fseek(f1, sizeof(Data) * idx, 0);
    fwrite((char *) &Data, sizeof(Data), 1, f1);
    fclose(f1);
}

void saveToFile(Data *books, int count) {
    file.open("books.bin", std::ios::binary | std::ios::out);
    file.close();
    for (int i = 0; i < count; i++) {
        file.open("books.bin", std::ios::binary | std::ios::app);
        file.write((char *) &books[i], sizeof(Data));
        file.close();
    }
    file.open("size.txt", std::ios::out);
    file << count;
    file.close();
    std::cout << "Запись прошла успешно\n";
}
