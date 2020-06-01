#ifndef	VIEW_H // To make sure you don't declare the function more than once by including the header multiple times.
#define VIEW_H

#include <iostream>
#include <iomanip>
#include <string>

void programHeader();
void mainMenu();
void searchMenu();
void paginationSubMenu();
void paginationPageSize();
void displayMenu();
void cardMenu();
void modifyMenu();
void modifyFieldMenu();
void modifyPreMenu();
void reportHeader();
void vacancyHeader();
void displayAllTutorHeader();
void tutorTableHead();
void subjectTableHead();
void centreTableHead();
int userChoice(int lower, int higher, std::string phrase);
bool verifyChoice();
std::string div(int n);
std::string board(int n);

#endif