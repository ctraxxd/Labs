#include "functions.h"

#define fopen_s(pFile, filename, mode) ((*(pFile))=fopen((filename),  (mode)))==NULL

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <fstream>

std::fstream file;
bool isDataEntered = false;
const int mod = 1e9 + 7;

void inputData(Data **workshops, int *count, int *max_count) {
    int num_workshops;
    std::cin >> num_workshops;
    for (int i = 0; i < num_workshops; i++) {
        if (*count >= *max_count) {
            *max_count *= 2;
            Data *temp = (Data *) realloc(*workshops, (*max_count) * sizeof(Data));
            if (!temp) {
                std::cout << "Ошибка выделения памяти.\n";
                return;
            }
            *workshops = temp;
        }
        std::cout << "Введите наименование продукции: ";
        std::cin >> (*workshops)[*count].nameOfProduct;
        std::cout << "Введите номер цеха: ";
        std::cin >> (*workshops)[*count].numberOfWorkshop;
        std::cout << "Введите количество изготовленных единиц продукции: ";
        std::cin >> (*workshops)[*count].numberOfProduct;
        std::cout << "Введите массу одного изделия: ";
        std::cin >> (*workshops)[*count].weightOfOneProduct;
        (*workshops)[*count].weightOfAllProducts =
                (*workshops)[*count].weightOfOneProduct * (*workshops)[*count].numberOfProduct;
        (*workshops)[*count].idOfProduct = ((*count + 2) * (*max_count + 2)) % mod;
        std::cout << "id изделия: " << (*workshops)[*count].idOfProduct << "\n\n";
        (*count)++;
    }

}

void inputWorkshopData(Data **workshops, int &workshopCount) {
    int maxCount = 5;
    if (isDataEntered) {
        std::cout << "Ошибка: Данные об изделиях уже введены, повторный ввод недоступен.\n";
        return;
    }
    std::cout << "Введите количество различных изделий: ";
    inputData(workshops, &workshopCount, &maxCount);
    isDataEntered = true;
}

void addWorkshop(Data **workshops, int &count) {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
    std::cout << "Введите количество изделий для добавления: ";
    int maxCount = 5;
    inputData(workshops, &count, &maxCount);
}

void initWorkshops(Data *&workshops, int &count) {
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
    workshops = (Data *) malloc(size * sizeof(Data));
    file.open("workshops.bin", std::ios_base::binary | std::ios_base::in);
    Data Data;
    for (int i = 0; i < size; i++) {
        file.read((char *) &Data, sizeof(Data));
        workshops[i] = Data;
        std::cout << Data.nameOfProduct << '\n';
    }
    isDataEntered = true;
    count = size;
    file.close();
    std::cout << "Загружено " << size << " изделия из файла";
    count = size;
    file.close();
}

int choiceTasks() {
    int choice;
    std::cout << "\n=====================================================================================\n"
              << "                                       Меню"
              << "\n=====================================================================================\n\n"
              << "1. Ввести данные об изделиях\n"
              << "2. Показать данные об изделиях\n"
              << "3. Добавить новые изделия\n"
              << "4. Найти изделие по id\n"
              << "5. Удалить изделие по id\n"
              << "6. Изменить данные изделия по id\n"
              << "7. Сортировать изделия по номеру цеху\n"
              << "8. Найти все изделия по номеру цеха\n"
              << "9. Запись данных в двоичный файл\n"
              << "10. Чтение данных из двоичного файла\n"
              << "11. Корректировка данных двоичного файла\n"
              << "0. Выход из программы\n\n"
              << "Ваш выбор: ";
    while (!(std::cin >> choice) || std::cin.peek() != '\n' || (choice < 0 || choice > 11)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка ввода.\nПожалуйста, выберите значение от 0 до 11: ";
    }
    return choice;
}

void displayWorkshopArray(Data *workshops, int count) {
    if (!isDataEntered) {
        std::cout << ("Введите сначала данные...\n");
        return;
    }
    std::cout
            << ("Данные о продукции:\n=====================================================================================\n");
    for (int i = 0; i < count; i++) {
        std::cout << "Название: " << workshops[i].nameOfProduct << '\n' << "Номер цеха: "
                  << workshops[i].numberOfWorkshop << '\n'
                  << "Количество: "
                  << workshops[i].numberOfProduct << '\n'
                  << "Масса одного изделия: " << workshops[i].weightOfOneProduct << '\n' << "Масса всех изделий: "
                  << workshops[i].weightOfAllProducts << "\nid изделия: "
                  << workshops[i].idOfProduct << "\n---------------------------------------------\n";
    }
}

void findWorkshopByIdOfProduct(Data *workshops, int count) {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
    int id;
    std::cout << "Введите id продукции для поиска: ";
    std::cin >> id;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (workshops[i].idOfProduct == id) {
            std::cout << "Название: " << workshops[i].nameOfProduct << '\n' << "Номер цеха: "
                      << workshops[i].numberOfWorkshop << '\n'
                      << "Количество: "
                      << workshops[i].numberOfProduct << '\n'
                      << "Масса одного изделия: " << workshops[i].weightOfOneProduct << '\n' << "Масса всех изделий: "
                      << workshops[i].weightOfAllProducts << "\nid изделия: "
                      << workshops[i].idOfProduct << "\n---------------------------------------------\n";
            found = 1;
            break;
        }
    }
    if (!found) {
        std::cout << "Продукция с id " << id << " не найдена.\n";
    }
}

void deleteWorkshopByIdOfProduct(Data **workshops, int *count) {
    if (!isDataEntered) {
        std::cout << "Введите сначала данные...\n";
        return;
    }
    int id;
    std::cout << "Введите id продукции для удаления: ";
    std::cin >> id;
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if ((*workshops)[i].idOfProduct == id) {
            for (int j = i; j < *count - 1; ++j) {
                (*workshops)[j] = (*workshops)[j + 1];
            }
            found = 1;
            break;
        }
    }
    if (found) {
        (*count)--;
        Data *temp = (Data *) realloc(*workshops, (*count) * sizeof(Data));
        if (temp) {
            *workshops = temp;
        }
        std::cout << "Изделие с номером " << id << " удалено.\n";
    } else {
        std::cout << "Изделие с номером " << id << " не найдено, т.к. его нет в данных.\n";
    }
}

void updateWorkshopByIdOfProduct(Data *workshops, int count) {
    if (!isDataEntered) {
        std::cout << ("Введите сначала данные...\n");
        return;
    }
    int id;
    std::cout << "Введите id продукции для изменения: ";
    std::cin >> id;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (workshops[i].idOfProduct == id) {
            std::cout << "Введите новые данные для изделия с id: " << id << '\n';
            std::cout << "Введите наименование продукции: ";
            std::cin >> workshops[i].nameOfProduct;
            std::cout << "Введите номер цеха: ";
            std::cin >> workshops[i].numberOfWorkshop;
            std::cout << "Введите количество изготовленных единиц продукции: ";
            std::cin >> workshops[i].numberOfProduct;
            std::cout << "Введите массу одного изделия: ";
            std::cin >> workshops[i].weightOfOneProduct;
            workshops[i].weightOfAllProducts =
                    workshops[i].weightOfOneProduct * workshops[i].numberOfProduct;
            found = 1;
            break;
        }
    }
    if (!found) {
        std::cout << "Изделие с id " << id << " не найдена.\n";
    }
}

void sortWorkshopsByNumber(Data *workshops, int count) {
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
            if (workshops[i].numberOfProduct < workshops[i + 1].numberOfProduct) {
                Data temp = workshops[i];
                workshops[i] = workshops[i + 1];
                workshops[i + 1] = temp;
                isSorted = false;
            }
        }
        right--;
        for (int i = right - 1; i >= start; i--) {
            if (workshops[i].numberOfProduct < workshops[i + 1].numberOfProduct) {
                Data temp = workshops[i];
                workshops[i] = workshops[i + 1];
                workshops[i + 1] = temp;
                isSorted = false;
            }
        }
        start++;
    }
    std::cout << "Массив продукций отсортирован по номеру цеха в убывающем порядке.\n";
}

void findWorkshopsByNumberOfWorkshop(Data *workshops, int count) {
    if (!isDataEntered) {
        std::cout << ("Введите сначала данные...\n");
        return;
    }
    int id;
    std::cout << "Введите номер цеха для поиска изделий: ";
    std::cin >> id;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (workshops[i].numberOfWorkshop == id) {
            std::cout << "Название: " << workshops[i].nameOfProduct << '\n' << "Номер цеха: "
                      << workshops[i].numberOfWorkshop << '\n'
                      << "Количество: "
                      << workshops[i].numberOfProduct << '\n'
                      << "Масса одного изделия: " << workshops[i].weightOfOneProduct << '\n' << "Масса всех изделий: "
                      << workshops[i].weightOfAllProducts << "\nid изделия: "
                      << workshops[i].idOfProduct << "\n---------------------------------------------\n";
            found = 1;
        }
    }
    if (!found) {
        std::cout << "Продукция на цехе с номером " << id << " не найдена.\n";
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
    file.open("workshops.bin", std::ios_base::binary | std::ios_base::in);
    Data data;
    for (int i = 0; i < size; i++) {
        file.read((char *) &data, sizeof(Data));
        std::cout << "Название: " << data.nameOfProduct << '\n' << "Номер цеха: "
                  << data.numberOfWorkshop << '\n'
                  << "Количество: "
                  << data.numberOfProduct << '\n'
                  << "Масса одного изделия: " << data.weightOfOneProduct << '\n' << "Масса всех изделий: "
                  << data.weightOfAllProducts << "\nid изделия: "
                  << data.idOfProduct << "\n---------------------------------------------\n";

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
    std::cout << "Выберите изделие для изменения: ";
    std::cin >> idx;
    idx--;
    Data Data;
    file.open("workshops.bin", std::ios_base::binary | std::ios_base::in);
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
        std::cin >> Data.nameOfProduct;
        std::cout << "Обновление успешно";
    } else if (cc == 2) {
        std::cout << "\nВведите новый номер цеха: ";
        std::cin >> Data.numberOfWorkshop;
        std::cout << "Обновление успешно";
    } else if (cc == 3) {
        std::cout << "\nВведите новое количество изделия: ";
        std::cin >> Data.numberOfProduct;
        std::cout << "Обновление успешно";
    } else if (cc == 4) {
        std::cout << "\nВведите новую массу изделия: ";
        std::cin >> Data.weightOfOneProduct;
        std::cout << "Обновление успешно";
    }
    Data.weightOfAllProducts = Data.weightOfOneProduct * Data.numberOfProduct;
    FILE *f1;
    fopen_s(&f1, "workshops.bin", "rb+");
    fseek(f1, sizeof(Data) * idx, 0);
    fwrite((char *) &Data, sizeof(Data), 1, f1);
    fclose(f1);
}

void saveToFile(Data *workshops, int count) {
    file.open("workshops.bin", std::ios::binary | std::ios::out);
    file.close();
    for (int i = 0; i < count; i++) {
        file.open("workshops.bin", std::ios::binary | std::ios::app);
        file.write((char *) &workshops[i], sizeof(Data));
        file.close();
    }
    file.open("size.txt", std::ios::out);
    file << count;
    file.close();
    std::cout << "Запись прошла успешно\n";
}
