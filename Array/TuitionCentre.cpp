#include <string>
#include <iostream>
#include <iomanip>
#include "TuitionCentre.h"
using namespace std;

TuitionCentre::TuitionCentre() {};
TuitionCentre::TuitionCentre(int n, string name) {
	this->tuitionCentreId = n;
	this->tuitionCentreName = name;
}
int TuitionCentre::getTuitionCentreId() {
	return tuitionCentreId;
}
std::string TuitionCentre::getTuitionCentreName() {
	return tuitionCentreName;
}
void TuitionCentre::setTuitionCentreId(int id) {
	this->tuitionCentreId = id;
}
void TuitionCentre::setTuitionCentreName(std::string name) {
	this->tuitionCentreName = name;
}
void TuitionCentre::toString() {
	cout << setw(3) << left << this->tuitionCentreId << "|";
	cout << setw(20) << left << this->tuitionCentreName << "|";
	cout << endl;
}