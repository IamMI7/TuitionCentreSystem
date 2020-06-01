#include "Tutor.h"
TutorList * tutorList = new TutorList();

/**Tutor Class**/

// Constructors
Tutor::Tutor(int tutorId, std::string tutorName, std::string tutorPhone, std::string tutorAddress, std::tm tutorDateJoined, 
	TuitionCentre *tutorTuitionCentre, Subject *tutorSubject, Rating tutorRating)
{
	std::tm tutorDateTerminated;
	tutorDateTerminated.tm_year = 0;
	tutorDateTerminated.tm_mon = 0;
	tutorDateTerminated.tm_mday = 0;
	tutorDateTerminated.tm_hour = 0;
	tutorDateTerminated.tm_min = 0;
	tutorDateTerminated.tm_sec = 0;

	Tutor::tutorId = tutorId;
	Tutor::tutorTuitionCentre = tutorTuitionCentre;
	Tutor::tutorSubject = tutorSubject;
	Tutor::tutorName = tutorName;
	Tutor::tutorDateJoined = tutorDateJoined;
	Tutor::tutorDateTerminated = tutorDateTerminated;
	Tutor::tutorPhone = tutorPhone;
	Tutor::tutorAddress = tutorAddress;
	Tutor::tutorRating = tutorRating;
}

Tutor::Tutor(std::string tutorName, std::string tutorPhone, std::string tutorAddress, std::tm tutorDateJoined, 
	TuitionCentre *tutorTuitionCentre, Subject *tutorSubject, Rating tutorRating)
{
	std::tm tutorDateTerminated;
	tutorDateTerminated.tm_year = 0;
	tutorDateTerminated.tm_mon = 0;
	tutorDateTerminated.tm_mday = 0;
	tutorDateTerminated.tm_hour = 0;
	tutorDateTerminated.tm_min = 0;
	tutorDateTerminated.tm_sec = 0;

	Tutor::tutorId = generateId();
	Tutor::tutorTuitionCentre = tutorTuitionCentre;
	Tutor::tutorSubject = tutorSubject;
	Tutor::tutorName = tutorName;
	Tutor::tutorDateJoined = tutorDateJoined;
	Tutor::tutorDateTerminated = tutorDateTerminated;
	Tutor::tutorPhone = tutorPhone;
	Tutor::tutorAddress = tutorAddress;
	Tutor::tutorRating = tutorRating;
}

// Methods
bool Tutor::isExpired(std::time_t currentDateTimeT) 
{
	//Checks if tutor has been terminated for more than or equal to 6 months
	std::tm dateTerminated = Tutor::tutorDateTerminated;
	std::time_t dateTerminatedTimeT = std::mktime(&dateTerminated);
 	if (dateTerminatedTimeT == -1) {
		return false;
	}
	else if (std::difftime(currentDateTimeT, dateTerminatedTimeT) >= 15552000) {
		return true;
	}
	else {
		return false;
	}
}

void Tutor::toString()
{
	std::cout << std::setw(3) << std::left << Tutor::getTutorId() << "|";
	std::cout << std::setw(10) << std::left << Tutor::getTutorName() << "|";
	std::cout << std::setw(10) << std::left << Tutor::getTutorPhone() << "|";
	std::cout << std::setw(15) << std::left << Tutor::getTutorAddress() << "|";
	std::cout << std::setw(15) << std::left << Tutor::getTutorTuitionCentre()->getTuitionCentreName() << "|";
	std::cout << std::setw(10) << std::left << Tutor::getTutorSubject()->getSubjectName() << "|";
	std::cout << std::setw(10) << std::left << Tutor::getTutorSubject()->getSubjectHR() << "|";
	std::cout << std::setw(6) << std::left << Tutor::getTutorRating().getRatingAverage() << "|";
	std::cout << std::endl;
}

void Tutor::toStringCard()
{
	std::ostringstream stringStream, dateJoinedStream, dateTerminatedStream;
	dateJoinedStream << Tutor::tutorDateJoined.tm_mday << "/" << Tutor::tutorDateJoined.tm_mon + 1 << "/" << Tutor::tutorDateJoined.tm_year + 1900;
	dateTerminatedStream << Tutor::tutorDateTerminated.tm_mday << "/" << Tutor::tutorDateTerminated.tm_mon + 1 << "/" << Tutor::tutorDateTerminated.tm_year + 1900;
	std::cout << std::setw(5) << std::left << "|Id: ";
	std::cout << std::setw(25) << std::left << Tutor::getTutorId() << "|" << std::endl;
	std::cout << std::setw(7) << std::left << "|Name: ";
	std::cout << std::setw(23) << std::left << Tutor::getTutorName() << "|" << std::endl;
	std::cout << std::setw(8) << std::left << "|Phone: ";
	std::cout << std::setw(22) << std::left << Tutor::getTutorPhone() << "|" << std::endl;
	std::cout << std::setw(10) << std::left << "|Address: ";
	std::cout << std::setw(20) << std::left << Tutor::getTutorAddress() << "|" << std::endl;
	std::cout << std::setw(9) << std::left << "|Centre: ";
	std::cout << std::setw(21) << std::left << Tutor::getTutorTuitionCentre()->getTuitionCentreName() << "|" << std::endl;
	std::cout << std::setw(10) << std::left << "|Subject: ";
	std::cout << std::setw(20) << std::left << Tutor::getTutorSubject()->getSubjectName() << "|" << std::endl;
	std::cout << std::setw(13) << std::left << "|HourlyRate: ";
	std::cout << std::setw(17) << std::left << Tutor::getTutorSubject()->getSubjectHR() << "|" << std::endl;
	std::cout << std::setw(9) << std::left << "|Rating: ";
	std::cout << std::setw(21) << std::left << Tutor::getTutorRating().getRatingAverage() << "|" << std::endl;
	std::cout << std::setw(9) << std::left << "|Joined: ";
	std::cout << std::setw(21) << std::left << dateJoinedStream.str() << "|" << std::endl;
	std::cout << std::setw(13) << std::left << "|Terminated: ";
	if (Tutor::tutorDateTerminated.tm_mday == 0) {
		std::cout << std::setw(17) << std::left << "Not terminated" << "|";
		std::cout << std::endl << std::endl;
	}
	else {
		std::cout << std::setw(17) << std::left << dateTerminatedStream.str() << "|";
		std::cout << std::endl << std::endl;
	}
}

void Tutor::terminate()
{
	Tutor::setTutorDateTerminated(getCurrentDate());
}

// Getters and Setters
int Tutor::getTutorId()
{
	return Tutor::tutorId;
}

TuitionCentre * Tutor::getTutorTuitionCentre()
{
	return Tutor::tutorTuitionCentre;
}

void Tutor::setTutorTuitionCentre(TuitionCentre * tutorTuitionCentre)
{
	Tutor::tutorTuitionCentre = tutorTuitionCentre;
}

Subject * Tutor::getTutorSubject()
{
	return Tutor::tutorSubject;
}

void Tutor::setTutorSubject(Subject * tutorSubject)
{
	Tutor::tutorSubject = tutorSubject;
}

std::string Tutor::getTutorName()
{
	return Tutor::tutorName;
}

void Tutor::setTutorName(std::string tutorName)
{
	Tutor::tutorName = tutorName;
}

std::tm Tutor::getTutorDateJoined()
{
	return Tutor::tutorDateJoined;
}

void Tutor::setTutorDateJoined(std::tm tutorDateJoined)
{
	Tutor::tutorDateJoined = tutorDateJoined;
}

std::tm Tutor::getTutorDateTerminated()
{
	return Tutor::tutorDateTerminated;
}

void Tutor::setTutorDateTerminated(std::tm tutorDateTerminated)
{
	Tutor::tutorDateTerminated = tutorDateTerminated;
}

std::string Tutor::getTutorPhone()
{
	return Tutor::tutorPhone;
}

void Tutor::setTutorPhone(std::string tutorPhone)
{
	Tutor::tutorPhone = tutorPhone;
}

std::string Tutor::getTutorAddress()
{
	return Tutor::tutorAddress;
}

void Tutor::setTutorAddress(std::string tutorAddress)
{
	Tutor::tutorAddress = tutorAddress;
}

Rating Tutor::getTutorRating()
{
	return Tutor::tutorRating;
}

void Tutor::setTutorRating(Rating tutorRating)
{
	Tutor::tutorRating = tutorRating;
}

/**TutorList Class**/

// Constructors
TutorList::TutorList() {}

// Methods
void TutorList::addTutor()
{
	std::string name, phone, address;
	Subject* subject;
	TuitionCentre *centre;
	std::cout << "Input Name: ";
	std::cin >> name;
	std::cout << "Input Phone: ";
	std::cin >> phone;
	std::cout << "Input Address: ";
	std::cin >> address;

	subjectTableHead();
	subjectList->display();
	int choice = userChoice(1, 5, "Choose Subject: ");
	subject = subjectList->getIndex(choice - 1);

	centreTableHead();
	tuitionCentreList->display();
	choice = userChoice(1, 5, "Choose Centre: ");
	centre = tuitionCentreList->getIndex(choice - 1);

	Tutor * newTutor = new Tutor(name, phone, address, getCurrentDate(), centre, subject, Rating(0, 0));
	tutorList->addTutor(newTutor);

	// ---------DISPLAY TUTOR CARD
	std::cout << "Tutor Succesfully Added!" << std::endl;
	newTutor->toStringCard();
}

void TutorList::addTutor(Tutor * newTutor)
{
	if (tutorListHead == NULL && tutorListTail == NULL) {
		tutorListHead = newTutor;
		tutorListTail = newTutor;
	}
	else {
		tutorListTail->tutorNextTutor = newTutor;
		newTutor->tutorPreviousTutor = tutorListTail;
		tutorListTail = newTutor;
	}
}

void TutorList::checkTerminatedDuration()
{
	//Checks for expired tutors in the list and deletes them
	tm currentDate = getCurrentDate();
	std::time_t currentDateTimeT = mktime(&currentDate);
	std::cout << "Checking Tutors for termination expiry..." << std::endl;

	Tutor * removedTutor;
	tutorListTracer = tutorListHead;
	while (tutorListTracer != NULL) {
		if (tutorListTracer->isExpired(currentDateTimeT)) {
			std::cout << tutorListTracer->getTutorName() << 
				" has been removed from the database because they have been terminated for more than or equal to 6 months" 
				<< std::endl << std::endl;
			removedTutor = tutorListTracer;
			tutorListTracer = tutorListTracer->tutorNextTutor;
			destroy(removedTutor);
		}
		else {
			tutorListTracer = tutorListTracer->tutorNextTutor;
		}
	}
}

TutorList * TutorList::duplicateList()
{
	//Duplicates the current linked list into a new one
	tutorListTracer = tutorListHead;
	TutorList * newTutorList = new TutorList;
	while (tutorListTracer != NULL) {
		Tutor * newTutor = new Tutor(tutorListTracer->getTutorId(), tutorListTracer->getTutorName(), 
			tutorListTracer->getTutorPhone(), tutorListTracer->getTutorAddress(), 
			tutorListTracer->getTutorDateJoined(), tutorListTracer->getTutorTuitionCentre(), 
			tutorListTracer->getTutorSubject(), tutorListTracer->getTutorRating());
		newTutorList->addTutor(newTutor);
		tutorListTracer = tutorListTracer->tutorNextTutor;
	}
	return newTutorList;
}

TutorList * TutorList::duplicateTerminatedList()
{
	//Duplicates only terminated tutors in the linked list into a new one
	tutorListTracer = tutorListHead;
	TutorList * newTutorList = new TutorList;
	while (tutorListTracer != NULL) {
		if (tutorListTracer->getTutorDateTerminated().tm_mday != 0) {
			Tutor * newTutor = new Tutor(tutorListTracer->getTutorId(), tutorListTracer->getTutorName(), 
				tutorListTracer->getTutorPhone(), tutorListTracer->getTutorAddress(),
				tutorListTracer->getTutorDateJoined(), tutorListTracer->getTutorTuitionCentre(), 
				tutorListTracer->getTutorSubject(), tutorListTracer->getTutorRating());
			newTutorList->addTutor(newTutor);
		}
		tutorListTracer = tutorListTracer->tutorNextTutor;
	}
	return newTutorList;
}

void TutorList::destroy(Tutor *tutor)
{
	//Removes a tutor from the list and deconstructs it
	if (tutor->tutorNextTutor == NULL && tutor->tutorPreviousTutor == NULL) {}
	else if (tutor->tutorNextTutor == NULL) {
		tutor->tutorPreviousTutor->tutorNextTutor = tutor->tutorNextTutor;
	}
	else if (tutor->tutorPreviousTutor == NULL) {
		tutor->tutorNextTutor->tutorPreviousTutor = tutor->tutorPreviousTutor;
	}
	else {
		tutor->tutorNextTutor->tutorPreviousTutor = tutor->tutorPreviousTutor;
		tutor->tutorPreviousTutor->tutorNextTutor = tutor->tutorNextTutor;
	}

	if (tutor == tutorListHead) {
		tutorListHead = tutorListHead->tutorNextTutor;
	}
	else if (tutor == tutorListTail) {
		tutorListTail = tutorListTail->tutorPreviousTutor;
	}

	delete tutor;
}

void TutorList::display()
{
	int count = 1;
	tutorListTracer = tutorListHead;
	while (tutorListTracer != NULL) {
		std::cout << std::setw(3) << std::left << count << "|";
		tutorListTracer->toString();
		std::cout << board(91);
		tutorListTracer = tutorListTracer->tutorNextTutor;
		count++;
	}
	std::cout << std::endl << std::endl;
}

void TutorList::displayCard()
{
	int count = 1;
	tutorListTracer = tutorListHead;
	tutorTableHead();
	while (tutorListTracer != NULL) {
		std::cout << std::setw(3) << std::left << count << "|";
		tutorListTracer->toStringCard();
		std::cout << board(91);
		tutorListTracer = tutorListTracer->tutorNextTutor;
		count++;
	}
	std::cout << std::endl << std::endl;
}

Tutor * TutorList::getIndex(int index)
{
	//Gets tutor in the list based on index
	if (index >= TutorList::getSize()) {
		return NULL;
	}

	tutorListTracer = tutorListHead;
	for (int count = 0; count < index; count++) {
		if (tutorListTracer != NULL) {
			tutorListTracer = tutorListTracer->tutorNextTutor;
		}
	}
	return tutorListTracer;
}

int TutorList::getSize()
{
	//Gets the amount of tutors in the list
	int size = 0;
	tutorListTracer = tutorListHead;
	while (tutorListTracer != NULL) {
		size++;
		tutorListTracer = tutorListTracer->tutorNextTutor;
	}
	return size;
}

Tutor * TutorList::searchById(int tutorId, int type)
{
	//Gets a tutor based on its ID
	tutorListTracer = tutorListHead;
	if (type == 0) {
		// Jump search
		int jump = 4;
		while (tutorListTracer != NULL) {
			if (tutorListTracer->getTutorId() == tutorId) {
				return tutorListTracer;
			}
			else if (tutorListTracer->getTutorId() > tutorId) {
				while (tutorListTracer->getTutorId() != tutorId) {
					tutorListTracer = tutorListTracer->tutorPreviousTutor;
					if (tutorListTracer == NULL) {
						return NULL;
					}
				}
				return tutorListTracer;
			}
			for (int count = 0; count < jump; count++) {
				if (tutorListTracer != NULL) {
					tutorListTracer = tutorListTracer->tutorNextTutor;
				}
			}
		}
		return NULL;
	}
	else {
		while (tutorListTracer != NULL) {
			if (tutorListTracer->getTutorId() == tutorId) {
				return tutorListTracer;
			}
			tutorListTracer = tutorListTracer->tutorNextTutor;
		}
		return NULL;
	}
}

void TutorList::searchByRating(int lowerBoundary, int upperBoundary)
{
	//Creates a new TutorList based on the specifiec rating range
	tutorListSearched = new TutorList();
	tutorListTracer = tutorListHead;
	while (tutorListTracer != NULL) {
		int ratingAverage = tutorListTracer->getTutorRating().getRatingAverage();
		if (ratingAverage >= lowerBoundary && ratingAverage <= upperBoundary) {
			Tutor * newTutor = new Tutor(tutorListTracer->getTutorId(), tutorListTracer->getTutorName(), 
				tutorListTracer->getTutorPhone(), tutorListTracer->getTutorAddress(),
				tutorListTracer->getTutorDateJoined(), tutorListTracer->getTutorTuitionCentre(), 
				tutorListTracer->getTutorSubject(), tutorListTracer->getTutorRating());
			tutorListSearched->addTutor(newTutor);
		}
		tutorListTracer = tutorListTracer->tutorNextTutor;
	}
}

void TutorList::pagination(int subOrHR, int sub, int lowerB, int upperB, int tuitionCentre)
{
	//Creates a new TutorList based on multiple criterias
	tutorListSearched = new TutorList();
	TutorList * tutorListTemp = new TutorList();
	tutorListTracer = tutorListHead;
	
	if (subOrHR == 1) {
		//filtered by subject
		if (sub == 0) {
			tutorListTemp = tutorList->duplicateList();
		}
		else {
			while (tutorListTracer != NULL) {
				if (tutorListTracer->getTutorSubject() == subjectList->getIndex(sub - 1)) {
					Tutor * newTutor = new Tutor(tutorListTracer->getTutorId(), tutorListTracer->getTutorName(), 
						tutorListTracer->getTutorPhone(), tutorListTracer->getTutorAddress(),
						tutorListTracer->getTutorDateJoined(), tutorListTracer->getTutorTuitionCentre(), 
						tutorListTracer->getTutorSubject(), tutorListTracer->getTutorRating());
					tutorListTemp->addTutor(newTutor);
				}
				tutorListTracer = tutorListTracer->tutorNextTutor;
			}
		}
	}
	else {
		//filtered by hourly rate
		while (tutorListTracer != NULL) {
			double tutorHR = tutorListTracer->getTutorSubject()->getSubjectHR();
			if (tutorHR >= lowerB && tutorHR <= upperB) {
				Tutor * newTutor = new Tutor(tutorListTracer->getTutorId(), tutorListTracer->getTutorName(), 
					tutorListTracer->getTutorPhone(), tutorListTracer->getTutorAddress(),
					tutorListTracer->getTutorDateJoined(), tutorListTracer->getTutorTuitionCentre(), 
					tutorListTracer->getTutorSubject(), tutorListTracer->getTutorRating());
				tutorListTemp->addTutor(newTutor);
			}
			tutorListTracer = tutorListTracer->tutorNextTutor;
		}
	}

	tutorListTracer = tutorListTemp->tutorListHead;
	//filtered by tuition centre
	if (tuitionCentre == 0) {
		tutorListSearched = tutorListTemp->duplicateList();
	}
	else {
		while (tutorListTracer != NULL) {
			if (tutorListTracer->getTutorTuitionCentre() == tuitionCentreList->getIndex(tuitionCentre - 1)) {
				Tutor * newTutor = new Tutor(tutorListTracer->getTutorId(), tutorListTracer->getTutorName(), 
					tutorListTracer->getTutorPhone(), tutorListTracer->getTutorAddress(),
					tutorListTracer->getTutorDateJoined(), tutorListTracer->getTutorTuitionCentre(), 
					tutorListTracer->getTutorSubject(), tutorListTracer->getTutorRating());
				tutorListSearched->addTutor(newTutor);
			}
			tutorListTracer = tutorListTracer->tutorNextTutor;
		}
	}
}

void TutorList::sortById(bool order)
{
	tutorListSorted = duplicateList();
	mergeSortById(&tutorListSorted->tutorListHead, order);
}

void TutorList::sortByHR(bool order)
{
	tutorListSorted = duplicateList();
	mergeSortByHR(&tutorListSorted->tutorListHead, order);
}

void TutorList::sortByRating(bool order)
{
	tutorListSorted = duplicateList();
	mergeSortByRating(&tutorListSorted->tutorListHead, order);
}

void mergeSortById(Tutor **headRef, bool order) 
{
	Tutor * head = *headRef;
	Tutor * frontHalf;
	Tutor * backHalf;

	if ((head == NULL) || (head->tutorNextTutor == NULL)) {
		return;
	}

	/* Split head into 'fronthalf' and 'backhalf' sublists */
	frontBackSplit(head, &frontHalf, &backHalf);

	/* Recursively sort the sublists */
	mergeSortById(&frontHalf, order);
	mergeSortById(&backHalf, order);

	/* merge the two sorted lists together */
	std::function<Tutor * (Tutor *, Tutor *)> sortedMerge;
	sortedMerge = [head, &sortedMerge, &order](Tutor *frontHalf, Tutor * backHalf) -> Tutor * {
		Tutor * result = NULL;

		if (frontHalf == NULL)
			return (backHalf);
		else if (backHalf == NULL)
			return (frontHalf);

		/* Pick either frontHalf or backHalf, and recur */
		// if ascending order
		if (order == true) {
			if (frontHalf->getTutorId() < backHalf->getTutorId()) {
				result = frontHalf;
				result->tutorNextTutor = sortedMerge(frontHalf->tutorNextTutor, backHalf);
			}
			else {
				result = backHalf;
				result->tutorNextTutor = sortedMerge(frontHalf, backHalf->tutorNextTutor);
			}
			return result;
		}
		// if descending order
		else {
			if (frontHalf->getTutorId() > backHalf->getTutorId()) {
				result = frontHalf;
				result->tutorNextTutor = sortedMerge(frontHalf->tutorNextTutor, backHalf);
			}
			else {
				result = backHalf;
				result->tutorNextTutor = sortedMerge(frontHalf, backHalf->tutorNextTutor);
			}
			return result;
		}
	};
	*headRef = sortedMerge(frontHalf, backHalf);
}

void mergeSortByHR(Tutor **headRef, bool order)
{
	Tutor * head = *headRef;
	Tutor * frontHalf;
	Tutor * backHalf;

	if ((head == NULL) || (head->tutorNextTutor == NULL)) {
		return;
	}

	/* Split head into 'frontHalf' and 'backHalf' sublists */
	frontBackSplit(head, &frontHalf, &backHalf);

	/* Recursively sort the sublists */
	mergeSortByHR(&frontHalf, order);
	mergeSortByHR(&backHalf, order);

	/* merge the two sorted lists together */
	std::function<Tutor * (Tutor *, Tutor *)> sortedMerge;
	sortedMerge = [head, &sortedMerge, &order](Tutor *frontHalf, Tutor * backHalf) -> Tutor * {
		Tutor * result = NULL;

		if (frontHalf == NULL)
			return (backHalf);
		else if (backHalf == NULL)
			return (frontHalf);

		/* Pick either frontHalf or backHalf, and recur */
		// if ascending order
		if (order == true) {
			if (frontHalf->getTutorSubject()->getSubjectHR() < backHalf->getTutorSubject()->getSubjectHR()) {
				result = frontHalf;
				result->tutorNextTutor = sortedMerge(frontHalf->tutorNextTutor, backHalf);
			}
			else {
				result = backHalf;
				result->tutorNextTutor = sortedMerge(frontHalf, backHalf->tutorNextTutor);
			}
			return result;
		}
		// if descending order
		else {
			if (frontHalf->getTutorSubject()->getSubjectHR() > backHalf->getTutorSubject()->getSubjectHR()) {
				result = frontHalf;
				result->tutorNextTutor = sortedMerge(frontHalf->tutorNextTutor, backHalf);
			}
			else {
				result = backHalf;
				result->tutorNextTutor = sortedMerge(frontHalf, backHalf->tutorNextTutor);
			}
			return result;
		}
	};
	*headRef = sortedMerge(frontHalf, backHalf);
}

void mergeSortByRating(Tutor **headRef, bool order)
{
	Tutor * head = *headRef;
	Tutor * frontHalf;
	Tutor * backHalf;

	if ((head == NULL) || (head->tutorNextTutor == NULL)) {
		return;
	}

	/* Split head into 'frontHalf' and 'backHalf' sublists */
	frontBackSplit(head, &frontHalf, &backHalf);

	/* Recursively sort the sublists */
	mergeSortByRating(&frontHalf, order);
	mergeSortByRating(&backHalf, order);

	/* merge the two sorted lists together */
	std::function<Tutor * (Tutor *, Tutor *)> sortedMerge;
	sortedMerge = [head, &sortedMerge, &order](Tutor *frontHalf, Tutor * backHalf) -> Tutor * {
		Tutor * result = NULL;

		if (frontHalf == NULL)
			return (backHalf);
		else if (backHalf == NULL)
			return (frontHalf);

		/* Pick either frontHalf or backHalf, and recur */
		// if ascending order
		if (order == true) {
			if (frontHalf->getTutorRating().getRatingAverage() < backHalf->getTutorRating().getRatingAverage()) {
				result = frontHalf;
				result->tutorNextTutor = sortedMerge(frontHalf->tutorNextTutor, backHalf);
			}
			else {
				result = backHalf;
				result->tutorNextTutor = sortedMerge(frontHalf, backHalf->tutorNextTutor);
			}
			return result;
		}
		// if descending order
		else {
			if (frontHalf->getTutorRating().getRatingAverage() > backHalf->getTutorRating().getRatingAverage()) {
				result = frontHalf;
				result->tutorNextTutor = sortedMerge(frontHalf->tutorNextTutor, backHalf);
			}
			else {
				result = backHalf;
				result->tutorNextTutor = sortedMerge(frontHalf, backHalf->tutorNextTutor);
			}
			return result;
		}
	};
	*headRef = sortedMerge(frontHalf, backHalf);
}


void frontBackSplit(Tutor * head, Tutor ** frontHalf, Tutor ** backHalf)
{
	Tutor * fast;
	Tutor * slow;
	slow = head;
	fast = head->tutorNextTutor;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->tutorNextTutor;
		if (fast != NULL) {
			slow = slow->tutorNextTutor;
			fast = fast->tutorNextTutor;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two at that point. */
	*frontHalf = head;
	*backHalf = slow->tutorNextTutor;
	slow->tutorNextTutor = NULL;
}
