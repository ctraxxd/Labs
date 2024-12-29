#ifndef TASK2_FUNCTIONS_H
#define TASK2_FUNCTIONS_H

typedef struct {
    int regNumber;
    char author[1000];
    char name[1000];
    char publishHouse[1000];
    int year;
    union {
        int numberOfBooks;
        int sizeOfBooks;
    } u;
} Data;

void input(char *);

void inputData(Data **, int *, int *);

void inputBookData(Data **, int &);

void addBook(Data **, int &);

int choiceTasks();

void displayBookArray(Data *, int);

void findBookByRegNumber(Data *, int);

void deleteBookByRegNumber(Data **, int *);

void updateBookByRegNumber(Data *, int);

void sortByAuthor(Data *, int);

void findBooksByYear(Data *, int);

void addNewBook();

void deleteBook();

void updateBook();

void displayBooks();

#endif //TASK2_FUNCTIONS_H
