#pragma once
#include "TuitionCentre.h"
#include "Tutor.h"
#include "Rating.h"
#include "Subject.h"
#include "iostream"

using namespace std;

struct ArrayManager {
private:
	int arrSize = 15;
	//Dynamic Array
	Tutor* tutorArray = new Tutor[15]; 
	//Static Array
	TuitionCentre tuitionCentreArray[5];
	Subject subjectArray[5];
public:
	//Getter and Setter
	int getArrSize();
	Tutor* getTutorArray();
	TuitionCentre* getTuitionCentreArray();
	Subject* getSubjectArray();


	//Database Preset
	void presetTutorArray();
	void presetTuitionCentreArray();
	void presetSubjectArray();
	// Calls above 3 methods
	void presetDatabase();

	//Display Array Content
	//Display All Tutor
	void displayTutor();
	//Display ALl Tuition Centre
	void displayTuitionCentre();
	//Display All Subject
	void displaySubject();
	// Returns an array with terminated Tutor
	Tutor* getTerminatedTutor(int* arrSizeVar);

	//Add Tutor
	void addTutor();
	//Returns Id in last spot
	int generateId();

	//Sort by ID
	Tutor* sortById(bool asc);
	////BinaryInsertionSortbyId
	int binarySearchLocId(Tutor* sortArray, int id, int low, int high);
	void binaryInsertionSortId(Tutor* sortedArray);
	//Sort by Hourly Rate
	Tutor* sortByHR(bool asc);
	int binarySearchLocHR(Tutor* sortedArray, double HR, int low, int high);
	void binaryInsertionSortHR(Tutor* sortedArray);
	////
	//Sort by Rating
	Tutor* sortByRating(bool asc);
	int binarySearchLocRating(Tutor* sortedArray, double rating, int low, int high);
	void binaryInsertionSortRating(Tutor* sortedArray);


	//Search
	//Binary Search by Id
	Tutor* searchById(int tutorId);
	int binarySearchId(Tutor* sortArray, int Id, int low, int high);
	//Front and Back search for Rating
	Tutor* searchByRating(int lowerBoundary, int upperBoundary, int* arrSizeVar);
	//Front and Back search for Multiple Criteria
	Tutor* pagination(Tutor* tutor ,int* arrSizeVar);
	Tutor* searchByHR(Tutor* tutor,double lowerBoundary,double upperBoundary ,int* arrSizeVar);
	Tutor* searchBySubject(Tutor* tutor, Subject* subject,int* arrSizeVar);
	Tutor* searchByTuitionCentre(Tutor* t, TuitionCentre* tuitionCentre, int* arrSizeVar);
	//Generate Weekly Report
	void generateWeeklyReport();

	//Terminate Tutor
	void destroyTutor(Tutor* target);


	//Array Manipulation
	void increaseArrSize(int n);
	void decreaseArrSize(int n);


};

