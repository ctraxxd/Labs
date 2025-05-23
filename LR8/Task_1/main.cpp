#include <iostream>
#include <fstream>
#include "functions.h"

int main() {
    int workshopCount = 0;
    Data *workshops = nullptr;
    initWorkshops(workshops, workshopCount);
    if (workshops == nullptr) {
        workshops = (Data *) malloc(5 * sizeof(Data));
    }
    while (true) {
        int choice = choiceTasks();
        switch (choice) {
            case 1:
                std::cout << "=====================================================================================\n";
                inputWorkshopData(&workshops, workshopCount);
                break;
            case 2:
                std::cout << "=====================================================================================\n";
                displayWorkshopArray(workshops, workshopCount);
                break;
            case 3:
                std::cout << "=====================================================================================\n";
                addWorkshop(&workshops, workshopCount);
                break;
            case 4:
                std::cout << "=====================================================================================\n";
                findWorkshopByIdOfProduct(workshops, workshopCount);
                break;
            case 5:
                std::cout << "=====================================================================================\n";
                deleteWorkshopByIdOfProduct(&workshops, &workshopCount);
                break;
            case 6:
                std::cout << ("====================================================================================\n");
                updateWorkshopByIdOfProduct(workshops, workshopCount);
                break;
            case 7:
                std::cout << "=====================================================================================\n";
                sortWorkshopsByNumber(workshops, workshopCount);
                break;
            case 8:
                std::cout << "=====================================================================================\n";
                findWorkshopsByNumberOfWorkshop(workshops, workshopCount);
                break;
            case 9:
                std::cout << "=====================================================================================\n";
                saveToFile(workshops, workshopCount);
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
