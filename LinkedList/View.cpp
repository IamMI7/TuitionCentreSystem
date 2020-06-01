#include "View.h"

// Print Welcome header
void programHeader() {
	std::cout << div(40);
	std::cout << "\t      Welcome to	    " << std::endl;
	std::cout << " \t eXcel Tuition Centre " << std::endl;
	std::cout << " \tTutor Management System" << std::endl;
	std::cout << div(40);
}

void mainMenu() {
	std::cout << board(40);
	std::cout << "1. Display all Tutor" << std::endl;
	std::cout << "2. Search Tutor" << std::endl;
	std::cout << "3. Add Tutor" << std::endl;
	std::cout << "4. Generate Weekly Report" << std::endl;
	std::cout << "5. Remove User from Record" << std::endl;
	std::cout << "6. Exit" << std::endl;
	std::cout << board(40); 
}

void searchMenu() {
	std::cout << board(40);
	std::cout << "1. Search by ID" << std::endl;
	std::cout << "2. Search by Rating" << std::endl;
	std::cout << "3. Search by Multiple Criteria" << std::endl;
	std::cout << "4. Return to Main Menu" << std::endl;
	std::cout << board(40);
}

void paginationSubMenu() {
	std::cout << board(40);
	std::cout << "Search by: " << std::endl;
	std::cout << "1. Subject" << std::endl;
	std::cout << "2. Hourly Rate" << std::endl;
	std::cout << board(40);
}

void paginationPageSize() {
	std::cout << board(40);
	std::cout << "Display: " << std::endl;
	std::cout << "1. First 10 results" << std::endl;
	std::cout << "2. First 20 results" << std::endl;
	std::cout << "3. First 30 results" << std::endl;
	std::cout << "4. Display all" << std::endl;
	std::cout << board(40);
}

void displayMenu() {
	std::cout << board(40);
	std::cout << "1. Sort by ID (ascending)" << std::endl;
	std::cout << "2. Sort by ID (descending)" << std::endl;
	std::cout << "3. Sort by Hourly Rate (ascending)" << std::endl;
	std::cout << "4. Sort by Hourly Rate (descending)" << std::endl;
	std::cout << "5. Sort by Average Rating(ascending)" << std::endl;
	std::cout << "6. Sort by Average Rating (descending)" << std::endl;
	std::cout << "7. Modify Tutor" << std::endl;
	std::cout << "8. View in Card Format" << std::endl;
	std::cout << "9. Return to Main Menu" << std::endl;
	std::cout << board(40);
}

void cardMenu() {
	std::cout << div(40);
	std::cout << "1. Next" << std::endl;
	std::cout << "2. Back" << std::endl;
	std::cout << "3. Return to Main Menu" << std::endl;
	std::cout << div(40);
}

void displayAllTutorHeader() {
	std::cout << div(91);
	std::cout << std::setw(35) << " " << "eXcel Tuition Centre" << std::endl;
	std::cout << std::setw(41) << " " << "Tutor" << std::endl;
	std::cout << div(91);
}

//Table Head
void tutorTableHead() {
	std::cout << std::setw(3) << std::left << "No." << "|";
	std::cout << std::setw(3) << std::left << "Id" << "|";
	std::cout << std::setw(10) << std::left << "Name" << "|";
	std::cout << std::setw(10) << std::left << "Phone No." << "|";
	std::cout << std::setw(15) << std::left << "Address" << "|";
	std::cout << std::setw(15) << std::left << "Centre" << "|";
	std::cout << std::setw(10) << std::left << "Subject" << "|";
	std::cout << std::setw(10) << std::left << "HourlyRate" << "|";
	std::cout << std::setw(6) << std::left << "Rating" << "|";
	std::cout << std::endl;
	std::cout << board(91);
}

void subjectTableHead() {
	std::cout << board(30);
	std::cout << std::setw(3) << std::left << "No." << "|";
	std::cout << std::setw(3) << std::left << "Id" << "|";
	std::cout << std::setw(10) << std::left << "Subject" << "|";
	std::cout << std::setw(10) << std::left << "HourlyRate" << "|";
	std::cout << std::endl;
	std::cout << board(30);

}

void centreTableHead() {
	std::cout << board(30);
	std::cout << std::setw(3) << std::left << "No." << "|";
	std::cout << std::setw(3) << std::left << "Id" << "|";
	std::cout << std::setw(21) << std::left << "Tuition Centre Name" << "|";
	std::cout << std::endl;
	std::cout << board(30);

}

//Modify menu
void modifyMenu() {
	std::cout << board(40);
	std::cout << "1. Modify Tutor Record" << std::endl;
	std::cout << "2. Terminate Tutor" << std::endl;
	std::cout << "3. Return to Main Menu" << std::endl;
	std::cout << board(40);
}

void modifyFieldMenu() {
	std::cout << board(30);
	std::cout << "1. Modify Phone Number" << std::endl;
	std::cout << "2. Modify Address" << std::endl;
	std::cout << board(30);
}

void modifyPreMenu() {
	std::cout << board(30);
	std::cout << "1. Select Tutor for Modification / Termination" << std::endl;
	std::cout << "2. Return to main menu" << std::endl;
	std::cout << board(30);
}

//Report
void reportHeader() {
	std::cout << div(47);
	std::cout << std::setw(10) << "" << "eXcel Weekly Vacancy Report" << std::endl;
	std::cout << div(47);
}

void vacancyHeader() {
	std::cout << board(47);
	std::cout << std::setw(3) << std::left << "No." << "|";
	std::cout << std::setw(10) << std::left << "Subject" << "|";
	std::cout << std::setw(15) << std::left << "HourlyRate" << "|";
	std::cout << std::setw(15) << std::left << "TuitionCentre" << "|";
	std::cout << std::endl;
	std::cout << board(47);
}

//View Checking
int userChoice(int lower, int higher, std::string phrase) {
	int choice;
	std::cin.clear(); //clears error flag
	while (true) {
		std::cout << phrase;
		std::cin >> choice;
		//Checks if int is within range
		if (choice >= lower && choice <= higher) {
			break;
		}
		else {
			//int out of range
			std::cout << "Invalid input, try again !\n";
			//make sure entering char does not turn into infinite loop
			std::cin.clear(); //clears error flag
			std::cin.ignore(100, '\n'); // skip buffer
		}
	}
	std::cout << std::endl;
	return choice;
}

bool verifyChoice() {
	int choice = userChoice(0, 1, "Confirm Decision (Yes = 1, No = 0): ");
	if (choice == 1)
		return true;
	else
		return false;
}

//Divider
std::string div(int n) {
	return (std::string(n, '=')) + "\n";
}

std::string board(int n) {
	return (std::string(n, '-')) + "\n";
}