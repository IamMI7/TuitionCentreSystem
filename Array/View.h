#pragma once
#include <iostream>
#include <string>

using namespace std;

// Print Welcome header
void programHeader();
//MENU's
//1. Main Menu of the progran
void mainMenu();
//2. Search Menu 
void searchMenu();
//Pagination Options
//Choose to narrow down by Subject or HR
void paginationSubMenu();
void paginationPageSize();
//3. Display Meny 
void displayMenu();
void displayAllTutorHeader();
// Navigate displaying Tutor in Card
void cardMenu();
//Table Header to display Fields
void tutorTableHead();
void subjectTableHead();
void centreTableHead();
//4. Modify Menu 3 option
void modifyMenu();
void modifyFieldMenu();
void modifyPreMenu();

//Manually Remove User from Record
void destroyMenu();

//weeklyReport Header
void reportHeader();
//Table Header to display Field
void vacancyHeader();


//View Checking
//Make sure user input is >= lower and <= higher
//Phrase is repeated if invalid input
int userChoice(int lower, int higher,std::string phrase);
//Prompts confirmation message
bool verifyChoice();

//Print = or -- to separate section of program
std::string div(int n);
std::string board(int n);
