#pragma once
#include <ctime>
#include "ArrayManager.h"

using namespace std;

//Controller
void mainController(int *n,ArrayManager *arrMan);
// Display Menu Controller
void displayAllTutorC(int *n, ArrayManager *arrMan);
// Search Menu Controller
void searchTutorC(int *n, ArrayManager *arrMan);
// Modify Tutor Controller
void modifyTutorC(int *n, ArrayManager *arrMan, Tutor* tutor);
// destroy Tutor Controller
void destroyTutorC(int *n, ArrayManager *arrMan);
// Tutor Card View Navigation Controller
void cardViewC(int *n, ArrayManager *arrMan, Tutor* tutor);



//tm manipulation
//get Current Date in tm format
std::tm getCurrentDate();
// Covert parameter into tm
std::tm toTm(int year, int month, int day);
//Automatic process to remove any tutor terminated past 6 month
void checkTerminatedDuration(ArrayManager* arrMan);






