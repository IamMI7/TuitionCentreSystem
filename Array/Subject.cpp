#include <string>
#include <iostream>
#include <iomanip>
#include "Subject.h"

using namespace std;

Subject::Subject() {};
Subject::Subject(int id,string name, double HR) {
	this->subjectId = id;
	this->subjectName = name;
	this->subjectHR = HR;
}

int Subject::getSubjectId() {
	return subjectId;
}
std::string Subject::getSubjectName() {
	return subjectName;
}
double Subject::getSubjectHR() {
	return subjectHR;
}
void Subject::setSubjectId(int n) {
	this->subjectId = n;
}
void Subject::setSubjectName(std::string name) {
	this->subjectName = name;
}
void Subject::setSubjectHR(double subjectHR) {
	this->subjectHR = subjectHR;
}

void Subject::toString() {
	cout << setw(3) << left << this->subjectId << "|"; 
	cout << setw(10) << left << this->subjectName << "|";
	cout << setw(10) << left <<setprecision(2) << fixed << this->subjectHR << "|";
	cout << endl;
}