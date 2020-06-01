#pragma once
#include <string>

using namespace std;

struct TuitionCentre {
private:
	int tuitionCentreId;
	std::string tuitionCentreName;

public:
	//Constructor
	TuitionCentre();
	TuitionCentre(int n,string name);
	//Getters and Setters
	int getTuitionCentreId();
	std::string getTuitionCentreName();
	void setTuitionCentreId(int id);
	void setTuitionCentreName(std::string name);
	//toString
	void toString();
};