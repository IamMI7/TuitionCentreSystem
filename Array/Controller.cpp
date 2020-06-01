#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include "Controller.h"
#include "View.h"
#include "Tutor.h"
#include "ArrayManager.h"


using namespace std;
void mainController(int *n,ArrayManager *arrMan){
	mainMenu();
	*n = userChoice(1, 6, "Choice: ");
		switch (*n) {
		case 1:
			//Display All Tutor
			displayAllTutorHeader();
			arrMan->displayTutor();
			//calls displayTutorController
			displayAllTutorC(n, arrMan);
			break;
		case 2:
			//Search Tutor
			//calls searchTutorController
			searchTutorC(n, arrMan);
			break;
		case 3:
			//Add Tutor
			//Calls addTutor Function
			arrMan->addTutor();
			break;
		case 4:
			//Generate Weekly Report
			arrMan->generateWeeklyReport();
			//returns to Main Menu after report is shown
			mainController(n, arrMan);
			break;
		case 5:
			// Remove User from record
			//Calls destroyTutorController
			destroyTutorC(n, arrMan);
			break;
		case 6:
			//Exit
			exit(0);
			break;

		}
}

void displayAllTutorC(int *n, ArrayManager *arrMan) {
	Tutor* sortedArray=arrMan->getTutorArray();
	bool asc=true;
	while (true) {
		int count = 1;
		displayMenu();
		*n = userChoice(1, 9, "Choice: ");
		switch (*n) {
		case 1:
			//Sort by ID (asc)
			sortedArray = arrMan->sortById(true);
			break;
		case 2:
			//Sort by ID (des)
			sortedArray = arrMan->sortById(false);
			break;
		case 3:
			//Sort by Hourly Rate (asc)
			sortedArray = arrMan->sortByHR(true);
			break;
		case 4:
			//Sort by Hourly Rate (desc)
			sortedArray = arrMan->sortByHR(false);
			break;
		case 5:
			// Sort by Average Rating(asc)
			sortedArray = arrMan->sortByRating(true);
			break;
		case 6:
			//Sort by Average Rating (desc)
			sortedArray = arrMan->sortByRating(false);
			break;
		case 7:
			//Modify Tutor
			*n = userChoice(1, arrMan->getArrSize(), "Choose Tutor to modify: ");
			//Display selected Tutor Card
			//Calls modifyTutorController with selected Tutor
			if (asc == true) {
				cout << board(30);
				sortedArray[*n - 1].toStringCard();
				modifyTutorC(n, arrMan, &sortedArray[*n - 1]);
			}
			//Display Descending
			else {
				cout << board(30);
				sortedArray[arrMan->getArrSize() - *n].toStringCard();
				//*n from the back of the array
				modifyTutorC(n, arrMan, &sortedArray[arrMan->getArrSize()-*n]);
			}
			break;
		case 8:
			//View Tutor in card format
			cardViewC(n, arrMan, sortedArray);
			break;
		case 9:
			//Return to Main Menu
			mainController(n, arrMan);
			break;
		}
		//Display in ascending
		tutorTableHead();
		if ((*n == 1 || *n == 3) || *n == 5) {
			for (int i = 0; i < arrMan->getArrSize(); i++) {
				cout << setw(3) << left << count << "|";
				sortedArray[i].toString();
				cout << board(90);
				count++;
			}
			asc = true;
		}
		//Display in descending
		else if ((*n == 2 || *n == 4) || *n == 6) {
			for (int i = arrMan->getArrSize() - 1; i >= 0; i--) {
				cout << setw(3) << left << count << "|";
				sortedArray[i].toString();
				cout << board(90);
				count++;
			}
			asc = false;
		}
	}
	
}

void searchTutorC(int *n, ArrayManager *arrMan) {
	searchMenu();
	Tutor* tutor = NULL;
	int arrSizeVar=0, lowerB, upperB;
	*n = userChoice(1, 4, "Choice: ");
	switch (*n) {
	case 1:
		//Search by ID
		int id;
		id = userChoice(1, arrMan->generateId(), "Input Id: ");
		tutor = arrMan->searchById(id);
		//-------------DISPLAY TUTOR CARD
		if (tutor != NULL) {
			tutor->toStringCard();
			modifyTutorC(n, arrMan, tutor);
		}
		else {
			cout << "Tutor does not exist" << endl;
			mainController(n, arrMan);
		}
		break;
	case 2:
		//Search by Rating
		lowerB = userChoice(1, 5, "Input Lower Boundary of Range(1 - 5): ");
		upperB = userChoice(lowerB, 6, "Input Upper Boundary of Range(lower boundary - 5): ");
		tutor = arrMan->searchByRating(lowerB, upperB, &arrSizeVar);
		//---------------DISPLAY TUTOR WITH RATING
		if (arrSizeVar == 0) {
			cout << "No Tutor fit criteria" << endl;
		}
		else {
			tutorTableHead();
			for (int i = 0; i < arrSizeVar; i++) {
				cout << setw(3) << left << i + 1 << "|";
				tutor[i].toString();
				cout << board(80);
			}
		}
		break;
	case 3:
		//Search by MultipleCriteria
		lowerB = userChoice(1, 5, "Input Lower Boundary of Range(1 - 5): ");
		upperB = userChoice(lowerB, 5, "Input Upper Boundary of Range(lower boundary - 5): ");
		tutor = arrMan->searchByRating(lowerB, upperB, &arrSizeVar);
		if (arrSizeVar == 0) {
			cout << "No Tutor fit criteria" << endl;
			break;
		}
		else {
			//Pagination
			tutor = arrMan->pagination(tutor, &arrSizeVar);
			if (arrSizeVar == 0) {
				cout << "No Tutor fit criteria" << endl;
				break;
			}
			//T
			else {
				paginationPageSize();
				int compare = userChoice(1, 4, "Page Size: ");
				if (compare != 4) {
					if (arrSizeVar > (compare * 10 + 1))
						arrSizeVar = compare * 10;
				}
				for (int i = 0; i < arrSizeVar; i++) {
					cout << setw(3) << left << i+1 << "|";
					tutor[i].toString();
				}
			}
		}

		break;
	case 4:
		//Return to Main Menu
		mainController(n, arrMan);
		break;
	}

	modifyPreMenu();
	*n = userChoice(1, 2, "Input Choice: ");
	if (arrSizeVar != 0) {
		if (*n == 1) {
			int i = userChoice(1, arrSizeVar, "Input Tutor Number to modify/terminate: ");
			tutor[i-1].toStringCard();
			// Call Modify Controller
			modifyTutorC(n, arrMan, &(tutor[i - 1]));
		}
		else if (*n == 2) {
			//Return to Main Menu
			mainController(n, arrMan);
		}
	}
}

void modifyTutorC(int *n, ArrayManager *arrMan, Tutor* tutor) {
	modifyMenu();
	*n = userChoice(1, 3, "Input Choice: ");
	string newField, oldField;
	switch (*n) {
	case 1:
		//Modify Tutor Record
		modifyFieldMenu();
		*n = userChoice(1,2,"Input Field to modify:");
		switch (*n) {
		case 1:
			//Modify Phone Number
			oldField = tutor->getTutorPhone();
			cout << "Enter New Phone No.: ";
			cin >> newField;
			for (int i = 0; i < arrMan->getArrSize(); i++) {
				if (tutor->getTutorId() == arrMan->getTutorArray()[i].getTutorId()) {
					arrMan->getTutorArray()[i].setTutorPhone(newField);
					cout << "Tutor Phone No. successfully changed from " << oldField << " to "
						<< arrMan->getTutorArray()[i].getTutorPhone() << endl;
					tutor = &(arrMan->getTutorArray()[i]);
				}
			}
			break;
		case 2:
			//Modify Name
		{
			oldField = tutor->getTutorAddress();
			cout << "Enter New Address : ";
			cin >> newField;
			for (int i = 0; i < arrMan->getArrSize(); i++) {
				if (tutor->getTutorId() == arrMan->getTutorArray()[i].getTutorId()) {
					arrMan->getTutorArray()[i].setTutorAddress(newField);
					cout << "Tutor Address successfully changed from " << oldField << " to "
						<< arrMan->getTutorArray()[i].getTutorAddress() << endl;
					tutor = &(arrMan->getTutorArray()[i]);
				}
			}

		}
		break;
		}
		*n = 1;
		break;
	case 2:
		//Terminate 
		for (int i = 0; i < arrMan->getArrSize(); i++) {
			if (tutor->getTutorId() == arrMan->getTutorArray()[i].getTutorId()) {
				if (verifyChoice()) {
					arrMan->getTutorArray()[i].setTutorDateTerminated(getCurrentDate());
				}
				tutor = &(arrMan->getTutorArray()[i]);
			}
		}
		*n = 1;
		break;
	case 3:
		//Return to Main Menu
		*n = 2;
		break;

	}
	if (*n == 1) {
		tutor->toStringCard();
		modifyTutorC(n, arrMan, tutor);
	}
	else{
	mainController(n, arrMan);
	}
}

void destroyTutorC(int* n, ArrayManager *arrMan) {
	int arrSizeVar;
	Tutor* t =arrMan->getTerminatedTutor(&arrSizeVar);
	tutorTableHead();
	if (arrSizeVar != 0) {
		for (int i = 0; i < arrSizeVar; i++) {
			cout << setw(3) << left << i + 1 << "|";
			t[i].toString();
		}
	}
	else {
		cout << "There are no terminated Tutor available to be removed";
	}
	Tutor* target=NULL;
	bool flag = true;
	destroyMenu();
	*n = userChoice(1, 2, "Input Choice: ");
	switch (*n){
	case 1:
		while (flag) {
			cout << "Input User Id to delete: ";
			cin >> *n;
			for (int i = 0; i < arrSizeVar; i++) {
				if (t[i].getTutorId() == *n) {
					target = &t[i];
					flag = false;
					break;
				}
			}
		}
		arrMan->destroyTutor(target);
		break;
	case 2:
		mainController(n, arrMan);
		break;
	}
	mainController(n, arrMan);
}

void cardViewC(int *n, ArrayManager *arrMan, Tutor* tutor) {
	int i = 0;
	while (i < arrMan->getArrSize() && i >= 0) {
		tutor[i].toStringCard();
		cardMenu();
		*n = userChoice(1, 3, "Choose Input: ");
		switch (*n) {
		case 1:
			i++;
			break;
		case 2:
			i--;
			break;
		case 3:
			mainController(n, arrMan);
			break;
		}
	}
	cout << "End of array reached" << endl;
	mainController(n, arrMan);
}


std::tm getCurrentDate() {
	std::tm currentDate;
	std::time_t now = std::time(NULL);
	gmtime_s(&currentDate, &now);
	return currentDate;
}

std::tm toTm(int year, int month, int day) {
	std::tm date;
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;
	return date;
}

void checkTerminatedDuration(ArrayManager* arrMan) {
	//Checks for expired tutors in the list and deletes them
	tm currentDate = getCurrentDate();
	std::time_t currentDateTimeT = mktime(&currentDate);
	for(int i =0; i < arrMan->getArrSize(); i++) {
		if (arrMan->getTutorArray()[i].isExpired(currentDateTimeT)) {
			std::cout << arrMan->getTutorArray()[i].getTutorName() 
				<< " has been removed from the database because they have been terminated for more than or equal to 6 months" << std::endl;
			arrMan->destroyTutor(&(arrMan->getTutorArray()[i]));
		}
	}

}

