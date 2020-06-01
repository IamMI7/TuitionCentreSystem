#include "TuitionCentre.h"
TuitionCentreList * tuitionCentreList = new TuitionCentreList();

/**TuitionCentre Class**/

// Constructors
TuitionCentre::TuitionCentre(int tuitionCentreId, std::string tuitionCentreName)
{
	TuitionCentre::tuitionCentreId = tuitionCentreId;
	TuitionCentre::tuitionCentreName = tuitionCentreName;
}

// Methods
std::string TuitionCentre::toString() {
	std::cout << std::setw(3) << std::left << TuitionCentre::tuitionCentreId << "|";
	std::cout << std::setw(21) << std::left << TuitionCentre::tuitionCentreName << "|";
	std::cout << std::endl;
	return "";
}

// Getters and Setters
int TuitionCentre::getId()
{
	return TuitionCentre::tuitionCentreId;
}

std::string TuitionCentre::getTuitionCentreName()
{
	return TuitionCentre::tuitionCentreName;
}

void TuitionCentre::setTuitionCentreName(std::string tuitionCentreName)
{
	TuitionCentre::tuitionCentreName = tuitionCentreName;
}

/**TuitionCentreList Class**/

// Constructors
TuitionCentreList::TuitionCentreList()
{
}

// Methods
void TuitionCentreList::add(TuitionCentre *newTuitionCentre)
{
	if (tuitionCentreListHead == NULL && tuitionCentreListTail == NULL) {
		tuitionCentreListHead = newTuitionCentre;
		tuitionCentreListTail = newTuitionCentre;
	}
	else {
		tuitionCentreListTail->tuitionCentreNextTuitionCentre = newTuitionCentre;
		newTuitionCentre->tuitionCentrePreviousTuitionCentre = tuitionCentreListTail;
		tuitionCentreListTail = newTuitionCentre;
	}
}

void TuitionCentreList::display()
{
	int count = 1;
	tuitionCentreListTracer = tuitionCentreListHead;
	while (tuitionCentreListTracer != NULL) {
		std::cout << std::setw(3) << std::left << count << "|";
		std::cout << tuitionCentreListTracer->toString();
		tuitionCentreListTracer = tuitionCentreListTracer->tuitionCentreNextTuitionCentre;
		count++;
	}
	std::cout << std::endl << std::endl;
}

TuitionCentre *TuitionCentreList::getIndex(int index)
{
	//Gets tuition centre in the list based on index
	tuitionCentreListTracer = tuitionCentreListHead;
	for (int count = 0; count < index; count++) {
		tuitionCentreListTracer = tuitionCentreListTracer->tuitionCentreNextTuitionCentre;
	}
	return tuitionCentreListTracer;
}