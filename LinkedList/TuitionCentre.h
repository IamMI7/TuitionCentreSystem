#ifndef TUITIONCENTRE_H // To make sure you don't declare the function more than once by including the header multiple times.
#define TUITIONCENTRE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "View.h"

struct TuitionCentre 
{
private:
	int tuitionCentreId;
	std::string tuitionCentreName;
public:
	// Properties
	TuitionCentre *tuitionCentreNextTuitionCentre = NULL;
	TuitionCentre *tuitionCentrePreviousTuitionCentre = NULL;

	// Constructors
	TuitionCentre(int tuitionCentreId, std::string tuitionCentreName);
	
	// Methods
	std::string toString();
	
	//Getters and Setters
	int getId();
	std::string getTuitionCentreName();
	void setTuitionCentreName(std::string tuitionCentreName);
};

struct TuitionCentreList
{
	// Properties
	TuitionCentre *tuitionCentreListHead = NULL;
	TuitionCentre *tuitionCentreListTail = NULL;
	TuitionCentre *tuitionCentreListTracer = NULL;

	// Constructors
	TuitionCentreList();

	// Methods
	void add(TuitionCentre *newTuitionCentre);
	void display();
	TuitionCentre * getIndex(int index);
};

extern TuitionCentreList * tuitionCentreList;

#endif