#include "Subject.h"
SubjectList * subjectList = new SubjectList();

/**Subject Class**/

// Constructors
Subject::Subject(int subjectId, std::string subjectName, double subjectHR)
{
	Subject::subjectId = subjectId;
	Subject::subjectName = subjectName;
	Subject::subjectHR = subjectHR;
}

// Methods
std::string Subject::toString() {
	std::cout << std::setw(3) << std::left << Subject::subjectId << "|";
	std::cout << std::setw(10) << std::left << Subject::subjectName << "|";
	std::cout << std::setw(10) << std::left << std::setprecision(2) << std::fixed << Subject::subjectHR << "|";
	std::cout << std::endl;
	return "";
}

// Getters and Setters
int Subject::getSubjectId()
{
	return Subject::subjectId;
}

std::string Subject::getSubjectName()
{
	return Subject::subjectName;
}

void Subject::setSubjectName(std::string subjectName)
{
	Subject::subjectName = subjectName;
}

double Subject::getSubjectHR()
{
	return Subject::subjectHR;
}

void Subject::setSubjectHR(double subjectHR)
{
	Subject::subjectHR = subjectHR;
}

/**SubjectList Class**/

// Constructors
SubjectList::SubjectList()
{
}

// Methods
void SubjectList::add(Subject *newSubject)
{
	if (subjectListHead == NULL && subjectListTail == NULL) {
		subjectListHead = newSubject;
		subjectListTail = newSubject;
	}
	else {
		subjectListTail->subjectNextSubject = newSubject;
		newSubject->subjectPreviousSubject = subjectListTail;
		subjectListTail = newSubject;
	}
}

void SubjectList::display()
{
	int count = 1;
	subjectListTracer = subjectListHead;
	while (subjectListTracer != NULL) {
		std::cout << std::setw(3) << std::left << count << "|";
		std::cout << subjectListTracer->toString();
		subjectListTracer = subjectListTracer->subjectNextSubject;
		count++;
	}
	std::cout << std::endl << std::endl;
}

Subject *SubjectList::getIndex(int index)
{
	//Gets subject in the list based on index
	subjectListTracer = subjectListHead;
	for (int count = 0; count < index; count++) {
		subjectListTracer = subjectListTracer->subjectNextSubject;
	}
	return subjectListTracer;
}