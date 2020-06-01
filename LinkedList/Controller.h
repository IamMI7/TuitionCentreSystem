#ifndef CONTROLLER_H // To make sure you don't declare the function more than once by including the header multiple times.
#define CONTROLLER_H

#include "Tutor.h"

void mainController(int choice);
void displayAllTutorC(int choice);
void searchTutorC(int choice);

void modifyTutorC(int choice, Tutor * tutor);

void cardViewC(int choice);

#endif