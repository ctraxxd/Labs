#ifndef TASK2_FUNCTIONS_H
#define TASK2_FUNCTIONS_H

typedef struct {
    int regNumber;
    char author[1000];
    char name[1000];
    int year;
    char publishHouse[1000];
    int numberOfBooks;
} Data;

void input(char *);

void inputData(Data **, int *, int *);

void inputBookData(Data **, int &);

void addBook(Data **, int &);

void initBooks(Data *&, int &);

int choiceTasks();

void displayBookArray(Data *, int);

void findBookByRegNumber(Data *, int);

void deleteBookByRegNumber(Data **, int *);

void updateBookByRegNumber(Data *, int);

void sortByAuthor(Data *, int);

void findBooksByNumberOfBook(Data *, int);

void printFromFile();

void changeFile();

void saveToFile(Data *, int);

#endif //TASK2_FUNCTIONS_H
