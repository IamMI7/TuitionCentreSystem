#ifndef SUBJECT_H // To make sure you don't declare the function more than once by including the header multiple times.
#define SUBJECT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "View.h"

struct Subject
{
private:
	int subjectId;
	std::string subjectName;
	double subjectHR;
public:
	// Properties
	Subject *subjectNextSubject = NULL;
	Subject *subjectPreviousSubject = NULL;

	// Constructors
	Subject(int subjectId, std::string subjectName, double subjectHR);
	
	// Methods
	std::string toString();

	// Getters and Setters
	int getSubjectId();
	std::string getSubjectName();
	void setSubjectName(std::string subjectName);
	double getSubjectHR();
	void setSubjectHR(double subjectHR);
};

struct SubjectList
{
	// Properties
	Subject *subjectListHead = NULL;
	Subject *subjectListTail = NULL;
	Subject *subjectListTracer = NULL;

	// Constructors
	SubjectList();

	// Methods
	void add(Subject *newSubject);
	void display();
	Subject * getIndex(int index);
};

extern SubjectList * subjectList;

#endif