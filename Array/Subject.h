#pragma once
#include <string>

using namespace std;

struct Subject {
private:
	int subjectId;
	std::string subjectName;
	double subjectHR;
public:
	//Constructor
	Subject();
	Subject(int id, string name, double HR);
	//Getter and Setter
	int getSubjectId();
	std::string getSubjectName();
	double getSubjectHR();
	void setSubjectId(int n);
	void setSubjectName(std::string name);
	void setSubjectHR(double subjectHR);
	//Method
	//toString
	void toString();
};
