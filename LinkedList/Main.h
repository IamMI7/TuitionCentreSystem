#ifndef MAIN_H // To make sure you don't declare the function more than once by including the header multiple times.
#define MAIN_H

#include "Tutor.h"

// Shared functions
int generateId();
tm getCurrentDate();
tm toTm(int year, int month, int day);
void presetSubjectList();
void presetTuitionCentreList();
void presetTutorList();

#endif