#include <iostream>
#include <iomanip>
#include <string>
#include "Controller.h"
#include "View.h"
#include "Tutor.h"

void mainController(int choice)
{
	mainMenu();
	int count = 1;
	std::string tutorName;
	TutorList * terminatedTutors;
	choice = userChoice(1, 6, "Choice: ");
	switch (choice) {
	case 1:
		//Display All Tutor
		displayAllTutorHeader();
		tutorTableHead();
		tutorList->display();
		displayAllTutorC(choice);
		break;
	case 2:
		//Search Tutor
		searchTutorC(choice);
		break;
	case 3:
		//Add Tutor
		tutorList->addTutor();
		break;
	case 4:
		//Generate Weekly Report
		reportHeader();
		terminatedTutors = tutorList->duplicateTerminatedList();
		vacancyHeader();
		if (terminatedTutors->getSize() == 0) {
			std::cout << "No Vacancy Available" << std::endl;
		}
		else {
			terminatedTutors->tutorListTracer = terminatedTutors->tutorListHead;
			while (terminatedTutors->tutorListTracer != NULL) {
				board(47);
				std::cout << std::setw(3) << std::left << count << "|";
				std::cout << std::setw(10) << std::left << terminatedTutors->tutorListTracer->getTutorSubject()->getSubjectName() << "|";
				std::cout << std::setw(15) << std::left << std::setprecision(2) << std::fixed << terminatedTutors->tutorListTracer->getTutorSubject()->getSubjectHR() << "|";
				std::cout << std::setw(15) << std::left << terminatedTutors->tutorListTracer->getTutorTuitionCentre()->getTuitionCentreName() << "|";
				std::cout << std::endl;
				std::cout << board(47);
				terminatedTutors->tutorListTracer = terminatedTutors->tutorListTracer->tutorNextTutor;
				count++;
			}
		}
		mainController(choice);
		break;
	case 5:
		// Remove User from record
		tutorTableHead();
		terminatedTutors = tutorList->duplicateTerminatedList(); //Show only terminated users
		terminatedTutors->display();
		choice = userChoice(1, terminatedTutors->getSize(), "Choose Tutor to remove: ");
		tutorName = terminatedTutors->getIndex(choice - 1)->getTutorName();
		terminatedTutors->getIndex(choice - 1)->toStringCard();
		if (verifyChoice()) {
			tutorList->destroy(tutorList->searchById(terminatedTutors->getIndex(choice - 1)->getTutorId(), 1));
			std::cout << tutorName << " has been removed from the database" << std::endl;
		}
		else {
			std::cout << "Returning back to main menu" << std::endl;
		}
		std::cout << board(80);
		choice = 5;
		break;
	case 6:
		//Exit
		exit(0);
		break;
	}
	if (choice == 3 || choice == 5) {
		mainController(0);
	}
}

void displayAllTutorC(int choice) {
	displayMenu();
	choice = userChoice(1, 8, "Choice: ");
	Tutor * tutor;
	switch (choice) {
	case 1:
		//Sort by ID (asc)
		tutorList->sortById(true);
		displayAllTutorHeader();
		tutorTableHead();
		tutorList->tutorListSorted->display();
		break;
	case 2:
		//Sort by ID (desc)
		tutorList->sortById(false);
		displayAllTutorHeader();
		tutorTableHead();
		tutorList->tutorListSorted->display();
		break;
	case 3:
		//Sort by Hourly Rate (asc)
		tutorList->sortByHR(true);
		displayAllTutorHeader();
		tutorTableHead();
		tutorList->tutorListSorted->display();
		break;
	case 4:
		//Sort by Hourly Rate (desc)
		tutorList->sortByHR(false);
		displayAllTutorHeader();
		tutorTableHead();
		tutorList->tutorListSorted->display();
		break;
	case 5:
		//Sort by Average Rating(asc)
		tutorList->sortByRating(true);
		displayAllTutorHeader();
		tutorTableHead();
		tutorList->tutorListSorted->display();
		break;
	case 6:
		//Sort by Average Rating (desc)
		tutorList->sortByRating(false);
		displayAllTutorHeader();
		tutorTableHead();
		tutorList->tutorListSorted->display();
		break;
	case 7:
		//Modify Tutor
		choice = userChoice(1, tutorList->getSize(), "Choose Tutor to modify: ");
		tutor = tutorList->getIndex(choice - 1);
		modifyTutorC(choice, tutor);
		std::cout << board(80);
		break;
	case 8:
		//View in Card Format
		cardViewC(choice);
		break;
	case 9:
		//Return to Main Menu
		break;
	}
	mainController(0);
}

void searchTutorC(int choice) {
	searchMenu();
	Tutor* tutor = NULL;
	choice = userChoice(1, 4, "Choice: ");
	int id, lowerB = 0, upperB = 0;
	switch (choice) {
	case 1:
		//Search by ID
		id = userChoice(1, 999, "Input Id: ");
		tutorList->sortById(true);
		tutor = tutorList->tutorListSorted->searchById(id, 0);
		if (tutor == NULL) {
			std::cout << "No tutor with ID " << id << std::endl;
		}
		else {
			tutor->toStringCard();
			modifyTutorC(choice, tutor);
		}
		
		break;
	case 2:
		//Search by Rating
		lowerB = userChoice(1, 5, "Input Lower Boundary of Range: ");
		upperB = userChoice(lowerB, 5, "Input Upper Boundary of Range: ");
		tutorList->searchByRating(lowerB, upperB);

		if (tutorList->tutorListSearched->getSize() == 0) {
			std::cout << "No Tutor fit the criteria" << std::endl;
		}
		else {
			tutorList->tutorListSearched->display();
			choice = userChoice(1, tutorList->tutorListSearched->getSize(), "Choose Tutor to modify: ");
			id = tutorList->tutorListSearched->getIndex(choice - 1)->getTutorId();
			Tutor * tutor = tutorList->duplicateList()->searchById(id, 0);
			tutor->toStringCard();
			modifyTutorC(choice, tutor);
		}
		std::cout << board(80);
		break;
	case 3:
		//Search by Multiple Criteria
		paginationSubMenu();

		int subOrHR, sub, tuitionCentre;
		subOrHR = userChoice(1, 2, "Input Choice: ");
		if (subOrHR == 1) {
			subjectTableHead();
			std::cout << std::setw(3) << std::left << 0 << "|" << std::setw(25) << "  Select all subjects" << "|"<< std::endl;
			subjectList->display();
			sub = userChoice(0, 5, "Choose Subject: ");
		}
		else {
			lowerB = userChoice(1, 30, "Input Lower Boundary of Range(1 - 30): ");
			upperB = userChoice(lowerB, 30, "Input Upper Boundary of Range(lower boundary - 30): ");
		}
		centreTableHead();
		std::cout << std::setw(3) << std::left << 0 << "|" << std::setw(25) << "  Select all centres" << "|" << std::endl;
		tuitionCentreList->display();
		tuitionCentre = userChoice(0, 5, "Choose Tuition Centre: ");
		
		tutorList->pagination(subOrHR, sub, lowerB, upperB, tuitionCentre);

		if (tutorList->tutorListSearched->getSize() == 0) {
			std::cout << "No Tutor fit criteria" << std::endl;
		}
		else {
			paginationPageSize();
			int pageSize = userChoice(1, 4, "Page Size: ");
			tutorTableHead();
			if (pageSize == 4) {
				tutorList->tutorListSearched->display();
			}
			else {
				pageSize *= 10;
				for (int count = 1; count <= pageSize; count++) {
					if (tutorList->tutorListSearched->getIndex(count - 1) != NULL) {
						std::cout << std::setw(3) << std::left << count << "|";
						tutorList->tutorListSearched->getIndex(count - 1)->toString();
					}
					else {
						break;
					}	
				}
			}
			choice = userChoice(1, pageSize, "Choose Tutor to modify: ");
			Tutor * tutor = tutorList->searchById(tutorList->tutorListSearched->getIndex(choice - 1)->getTutorId(), 0);
			tutor->toStringCard();
			modifyTutorC(choice, tutor);
		}
		std::cout << board(80);
		break;
	case 4:
		//Return to main menu
		break;
	}
	mainController(0);
}

void modifyTutorC(int choice, Tutor* duplicatedTutor) {
	Tutor * tutor = tutorList->searchById(duplicatedTutor->getTutorId(), 1);  //Get Tutor from original list //1 = linear search 0 = jump search
	tutor->toStringCard();
	modifyMenu();
	choice = userChoice(1, 3, "Input Choice: ");
	std::string newField, oldField;
	switch (choice) {
	case 1:
		//Modify Tutor Record
		modifyFieldMenu();
		choice = userChoice(1, 3, "Input Field to modify:");
		switch (choice) {
		case 1:
			//Modify Phone Number
			oldField = tutor->getTutorPhone();
			std::cout << "Enter New Phone No.: ";
			std::cin >> newField;
			tutor->setTutorPhone(newField);
			std::cout << "Tutor Phone No. successfully changed from " << oldField << " to " << tutor->getTutorPhone() << std::endl;
			break;
		case 2:
			//Modify Address
			oldField = tutor->getTutorAddress();
			std::cout << "Enter New Address: ";
			std::cin >> newField;
			tutor->setTutorAddress(newField);
			std::cout << "Tutor address successfully changed from " << oldField << " to " << tutor->getTutorAddress() << std::endl;
			break;
		}
		choice = 1;
		break;
	case 2:
		//Terminate 
		tutor->terminate();
		std::cout << "Tutor has been successfully terminated" << std::endl;
		choice = 1;
		break;
	case 3:
		//Return to Main Menu
		choice = 2;
		break;

	}
	if (choice == 1) {
		modifyTutorC(choice, tutor);
	}
	else {
		mainController(choice);
	}
}

void cardViewC(int choice) {
	int index = 0;
	while (index < tutorList->getSize() && index >= 0) {
		tutorList->getIndex(index)->toStringCard();
		cardMenu();
		choice = userChoice(1, 3, "Choose Input: ");
		switch (choice) {
		case 1:
			index++;
			break;
		case 2:
			index--;
			break;
		case 3:
			mainController(choice);
			break;
		}
	}
	std::cout << "End of array reached" << std::endl;
	mainController(choice);
}