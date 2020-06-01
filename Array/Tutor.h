#pragma once
#include <string>
#include "Subject.h"
#include "Rating.h"
#include "TuitionCentre.h"

using namespace std;

struct Tutor {
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
	//Constructor
	Tutor();
	Tutor(int id, std::string name, std::string tutorPhone, std::string tutorAddress,
		 TuitionCentre* tc, Subject* subject, Rating rating);
	Tutor(int id, std::string name, std::string tutorPhone,std::string tutorAddress,
		std::tm join, TuitionCentre* tc, Subject* subject, Rating rating);
	//Getter and Setter
	int getTutorId();
	std::string getTutorName();
	std::string getTutorPhone();
	std::string getTutorAddress();
	std::tm getTutorDateJoined();
	std::tm getTutorDateTerminated();
	TuitionCentre *getTutorTuitionCentre();
	Subject *getTutorSubject();
	Rating getTutorRating();

	void setTutorId(int n);
	void setTutorName(std::string name);
	void setTutorPhone(std::string phone);
	void setTutorAddress(std::string address);
	void setTutorDateJoined(std::tm date);
	void setTutorDateTerminated(std::tm date);
	void setTuitionCentre(TuitionCentre* tuitionCentre);
	void setSubject(Subject* subject);
	void setRating(Rating rating);
	//Methods
	//Set tutor terminated date to now 
	void terminate();
	//checks if tutor have been terminated for more than 6 month
	bool isExpired(std::time_t currentDateTimeT);
	
	//toString
	//Display tutor information in card format including dates
	void toStringCard();
	// Display tutor Information in table format excluding dates
	void toString();
};

