#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include "Tutor.h"
#include "Controller.h"


using namespace std;

//Constructor
Tutor::Tutor(){
};
Tutor::Tutor(int id, std::string name, std::string phone, std::string address,
	 TuitionCentre* tc, Subject* subject, Rating rating) {

	this->tutorId = id;
	this->tutorName = name;
	this->tutorPhone = phone;
	this->tutorAddress = address;
	this->tutorTuitionCentre = tc;
	this->tutorSubject = subject;
	this->tutorRating = rating;

}
Tutor::Tutor(int id, std::string name, std::string phone, std::string address,
	std::tm join, TuitionCentre* tc, Subject* subject, Rating rating) {
	
	this->tutorId = id;
	this->tutorName = name;
	this->tutorPhone = phone;
	this->tutorAddress = address;
	this->tutorDateJoined = join;
	this->tutorDateTerminated.tm_mday = 0;
	this->tutorTuitionCentre = tc;
	this->tutorSubject = subject;
	this->tutorRating = rating;
	
}

//Getter and Setter
int Tutor::getTutorId() {
	return tutorId;
}
std::string Tutor::getTutorName() {
	return tutorName;
}
std::string Tutor::getTutorPhone() {
	return tutorPhone;
}
std::string Tutor::getTutorAddress() {
	return tutorAddress;
}
std::tm Tutor::getTutorDateJoined() {
	return tutorDateJoined;
}
std::tm Tutor::getTutorDateTerminated() {
	return tutorDateTerminated;
}
TuitionCentre *Tutor::getTutorTuitionCentre() {
	return tutorTuitionCentre;
}
Subject *Tutor::getTutorSubject() {
	return tutorSubject;
}
Rating Tutor::getTutorRating() {
	return tutorRating;
}

void Tutor::setTutorId(int n) {
	this->tutorId = n;
}
void Tutor::setTutorName(std::string name) {
	this->tutorName = name;
}
void Tutor::setTutorPhone(std::string phone) {
	this->tutorPhone = phone;
}
void Tutor::setTutorAddress(std::string address) {
	this->tutorAddress = address;
}
void Tutor::setTutorDateJoined(std::tm date) {
	this->tutorDateJoined = date;
}
void Tutor::setTutorDateTerminated(std::tm date) {
	this->tutorDateTerminated = date;
}
void Tutor::setTuitionCentre(TuitionCentre* tuitionCentre) {
	this->tutorTuitionCentre = tuitionCentre;
}
void Tutor::setSubject(Subject* subject) {
	this->tutorSubject = subject;
}
void Tutor::setRating(Rating rating) {
	this->tutorRating = rating;
}

void Tutor::terminate() {
	this->setTutorDateTerminated(getCurrentDate());
}

bool Tutor::isExpired(std::time_t currentDateTimeT) {
	std::tm dateTerminated = tutorDateTerminated;
	std::time_t dateTerminatedTimeT = std::mktime(&dateTerminated);
	if (dateTerminatedTimeT == -1) {
		return false;
	}
	else if(std::difftime(currentDateTimeT,dateTerminatedTimeT)>= 15552000){
		return true;
	}
	else {
		return false;
	}

}

void Tutor::toStringCard() {
		std::ostringstream stringStream, dateJoinedStream, dateTerminatedStream;
	dateJoinedStream << Tutor::tutorDateJoined.tm_mday << "/" << Tutor::tutorDateJoined.tm_mon + 1 << "/" << Tutor::tutorDateJoined.tm_year + 1900;
	dateTerminatedStream << Tutor::tutorDateTerminated.tm_mday << "/" << Tutor::tutorDateTerminated.tm_mon + 1 << "/" << Tutor::tutorDateTerminated.tm_year + 1900;
	if (Tutor::tutorDateTerminated.tm_mday == 0) {
		std::cout << std::setw(5) << std::left<< "|Id: ";
		std::cout << std::setw(25) << std::left << Tutor::getTutorId() << "|"<<endl;
		std::cout << std::setw(7) << std::left<< "|Name: ";
		std::cout << std::setw(23) << std::left << Tutor::getTutorName() << "|"<<endl;
		std::cout << std::setw(8) << std::left << "|Phone: ";
		std::cout << std::setw(22) << std::left << Tutor::getTutorPhone() << "|" <<endl;
		std::cout << std::setw(10) << std::left << "|Address: ";
		std::cout << std::setw(20) << std::left << Tutor::getTutorAddress() << "|"<<endl;
		std::cout << std::setw(9) << std::left <<"|Centre: ";
		std::cout << std::setw(21) << std::left << Tutor::getTutorTuitionCentre()->getTuitionCentreName() << "|" <<endl;
		std::cout << std:: setw(10) <<std::left << "|Subject: ";
		std::cout << std::setw(20) << std::left << Tutor::getTutorSubject()->getSubjectName() << "|"<<endl;
		std::cout << std:: setw(13) <<std::left << "|HourlyRate: ";
		std::cout << std::setw(17) << std::left << setprecision(2) << fixed <<Tutor::getTutorSubject()->getSubjectHR() << "|" <<endl;
		std::cout << std::setw(9) << std::left << "|Rating: ";
		std::cout << std::setw(21) << std::left << Tutor::getTutorRating().getRatingAverage() << "|"<<endl;
		std::cout << std:: setw(9) <<std::left << "|Joined: ";
		std::cout << std::setw(21) << std::left << dateJoinedStream.str() << "|"<<endl;
		std::cout << std::setw(13) << std::left << "|Terminated: ";
		std::cout << std::setw(17) << std::left << "Not terminated" << "|";
		std::cout << std::endl;
	}
	else {
		std::cout << std::setw(5) << std::left<< "|Id: ";
		std::cout << std::setw(25) << std::left << Tutor::getTutorId() << "|"<<endl;
		std::cout << std::setw(7) << std::left<< "|Name: ";
		std::cout << std::setw(23) << std::left << Tutor::getTutorName() << "|"<<endl;
		std::cout << std::setw(8) << std::left << "|Phone: ";
		std::cout << std::setw(22) << std::left << Tutor::getTutorPhone() << "|" <<endl;
		std::cout << std::setw(10) << std::left << "|Address: ";
		std::cout << std::setw(20) << std::left << Tutor::getTutorAddress() << "|"<<endl;
		std::cout << std::setw(9) << std::left <<"|Centre: ";
		std::cout << std::setw(21) << std::left << Tutor::getTutorTuitionCentre()->getTuitionCentreName() << "|" <<endl;
		std::cout << std:: setw(10) <<std::left << "|Subject: ";
		std::cout << std::setw(20) << std::left << Tutor::getTutorSubject()->getSubjectName() << "|"<<endl;
		std::cout << std::setw(13) << std::left << "|HourlyRate: ";
		std::cout << std::setw(17) << std::left << setprecision(2) << fixed << Tutor::getTutorSubject()->getSubjectHR() << "|" << endl;
		std::cout << std::setw(9) << std::left << "|Rating: ";
		std::cout << std::setw(21) << std::left << Tutor::getTutorRating().getRatingAverage() << "|"<<endl;
		std::cout << std::setw(9) << std::left << "|Joined: ";
		std::cout << std::setw(21) << std::left << dateJoinedStream.str() << "|"<<endl;
		std::cout << std::setw(13) << std::left << "|Terminated: ";
		std::cout << std::setw(17) << std::left << dateTerminatedStream.str() << "|";
		std::cout << std::endl;
	}
}

void Tutor::toString() {
	cout << setw(3) << left << this->getTutorId() <<"|";
	cout << setw(10) << left << this->getTutorName() << "|";
	cout << setw(10) << left << this->getTutorPhone() << "|"; 
	cout << setw(15) << left << this->getTutorAddress() << "|";
	cout << setw(15) << left << this->getTutorTuitionCentre()->getTuitionCentreName() << "|";
	cout << setw(10) << left << this->getTutorSubject()->getSubjectName()<< "|";
	cout << setw(10) << left << setprecision(2) << fixed << this->getTutorSubject()->getSubjectHR()<< "|";
	cout << setw(6) << left << this->getTutorRating().getRatingAverage() <<"|";
	cout << endl;
}