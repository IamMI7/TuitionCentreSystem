#ifndef TUTOR_H // To make sure you don't declare the function more than once by including the header multiple times.
#define TUTOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <functional>
#include "Main.h"
#include "View.h"
#include "TuitionCentre.h"
#include "Subject.h"
#include "Rating.h"

struct Tutor
{
private:
	int tutorId;
	TuitionCentre *tutorTuitionCentre;
	Subject *tutorSubject;
	std::string tutorName;
	std::tm tutorDateJoined;
	std::tm tutorDateTerminated;
	std::string tutorPhone;
	std::string tutorAddress;
	Rating tutorRating;
public:
	// Properties
	Tutor *tutorNextTutor = NULL;
	Tutor *tutorPreviousTutor = NULL;

	// Constructors
	Tutor(int tutorId, std::string tutorName, std::string tutorPhone, std::string tutorAddress, std::tm tutorDateJoined, TuitionCentre * tutorTuitionCentre, Subject * tutorSubject, Rating tutorRating);
	Tutor(std::string tutorName, std::string tutorPhone, std::string tutorAddress, std::tm tutorDateJoined, TuitionCentre * tutorTuitionCentre, Subject * tutorSubject, Rating tutorRating);
	
	// Methods
	bool isExpired(std::time_t currentDateTimeT);
	void toString();
	void toStringCard();
	void terminate();

	//Getters and Setters
	int getTutorId();
	TuitionCentre *getTutorTuitionCentre();
	void setTutorTuitionCentre(TuitionCentre *tutorTuitionCentre);
	Subject *getTutorSubject();
	void setTutorSubject(Subject *tutorSubject);
	std::string getTutorName();
	void setTutorName(std::string tutorName);
	std::tm getTutorDateJoined();
	void setTutorDateJoined(std::tm tutorDateJoined);
	std::tm getTutorDateTerminated();
	void setTutorDateTerminated(std::tm tutorDateTerminated);
	std::string getTutorPhone();
	void setTutorPhone(std::string tutorPhone);
	std::string getTutorAddress();
	void setTutorAddress(std::string tutorAddress);
	Rating getTutorRating();
	void setTutorRating(Rating tutorRating);
};

struct TutorList
{
	// Properties
	Tutor *tutorListHead = NULL;
	Tutor *tutorListTail = NULL;
	Tutor *tutorListTracer = NULL;
	TutorList *tutorListSorted = NULL;
	TutorList *tutorListSearched = NULL;

	// Constructors
	TutorList();

	// Methods
	void addTutor();
	void addTutor(Tutor * newTutor);
	void checkTerminatedDuration();
	TutorList * duplicateList();
	TutorList * duplicateTerminatedList();
	void destroy(Tutor *tutor);
	void display();
	void displayCard();
	Tutor * getIndex(int index);
	int getSize();
	Tutor * searchById(int tutorId, int type);
	void searchByRating(int lowerBoundary, int upperBoundary);
	void pagination(int subOrHR, int sub, int lowerB, int upperB, int tuitionCentre);
	void sortById(bool order);
	void sortByHR(bool order);
	void sortByRating(bool order);
};

extern TutorList * tutorList;

/** Helper Functions **/

void mergeSortById(Tutor ** headRef, bool order);
void mergeSortByHR(Tutor ** headRef, bool order);
void mergeSortByRating(Tutor ** headRef, bool order);
void frontBackSplit(Tutor * head, Tutor ** frontHalf, Tutor ** backHalf);

#endif