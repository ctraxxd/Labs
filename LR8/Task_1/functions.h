#ifndef TASK1_FUNCTIONS_H
#define TASK1_FUNCTIONS_H

typedef struct {
    char nameOfProduct[1000]{};
    int numberOfWorkshop;
    int numberOfProduct;
    long double weightOfOneProduct;
    long double weightOfAllProducts;
    int idOfProduct;
} Data;

void inputData(Data **, int *, int *);

void inputWorkshopData(Data **, int &);

void addWorkshop(Data **, int &);

void initWorkshops(Data *&, int &);

int choiceTasks();

void displayWorkshopArray(Data *, int);

void findWorkshopByIdOfProduct(Data *, int);

void deleteWorkshopByIdOfProduct(Data **, int *);

void updateWorkshopByIdOfProduct(Data *, int);

void sortWorkshopsByNumber(Data *, int);

void findWorkshopsByNumberOfWorkshop(Data *, int);

void printFromFile();

void changeFile();

void saveToFile(Data *, int);

#endif //TASK1_FUNCTIONS_H
