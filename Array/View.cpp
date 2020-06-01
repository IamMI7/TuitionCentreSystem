#include <iostream>
#include <iomanip>
#include "View.h"

using namespace std;

void programHeader() {
	cout << div(40);
	cout << "\t      Welcome to	    " << endl;
	cout << " \t eXcel Tuition Centre " << endl;
	cout << " \tTutor Management System" << endl;
	cout << div(40);
}

void mainMenu() {
	cout << board(40);
	cout << "1. Display all Tutor" <<endl;
	cout << "2. Search Tutor" << endl;
	cout << "3. Add Tutor" << endl;
	cout << "4. Generate Weekly Report" << endl;
	cout << "5. Remove User from Record" << endl;
	cout << "6. Exit" << endl;
	cout << board(40);
}

void searchMenu() {
	cout << board(40);
	cout << "1. Search by ID" << endl;
	cout << "2. Search by Rating" << endl;
	cout << "3. Search by Multiple Criteria" << endl;
	cout << "4. Return to Main Menu" << endl;
	cout << board(40);
}

void paginationSubMenu() {
	cout << board(40);
	cout << "Search by: " << endl;
	cout << "1. Subject" << endl;
	cout << "2. Hourly Rate" << endl;
	cout << board(40);
}

void paginationPageSize() {
	cout << board(40);
	cout << "Display: " << endl;
	cout << "1. First 10 results" <<endl;
	cout << "2. First 20 results" << endl;
	cout << "3. First 30 results" << endl;
	cout << "4. Display All" << endl;
	cout << board(40);

}

void displayMenu() {
	cout << board(40);
	cout << "1. Sort by ID (ascending)" << endl;
	cout << "2. Sort by ID (descending)" << endl;
	cout << "3. Sort by Hourly Rate (ascending)" << endl;
	cout << "4. Sort by Hourly Rate (descending)" << endl;
	cout << "5. Sort by Average Rating(ascending)" << endl;
	cout << "6. Sort by Average Rating (descending)" << endl;
	cout << "7. Modify Tutor" << endl;
	cout << "8. View in Card Format" << endl;
	cout << "9. Return to Main Menu" << endl;
	cout << board(40);
}

void displayAllTutorHeader() {
	cout << div(90);
	cout << setw(26) << " " << "eXcel Tuition Centre" << endl;
	cout << setw(32) << " " <<"Tutor" <<endl;
	cout << div(90);
}

void cardMenu() {
	cout << div(40);
	cout << "1. Next"<<endl;
	cout << "2. Back"<<endl;
	cout << "3. Return to Main Menu" << endl;
	cout << div(40);
}

void tutorTableHead() {
	cout << board(90);
	cout << setw(3) << left << "No." << "|";
	cout << setw(3) << left << "Id"<< "|";
	cout << setw(10) << left << "Name" << "|";
	cout << setw(10) << left << "Phone No." << "|";
	cout << setw(15) << left << "Address" << "|";
	cout << setw(15) << left << "Centre" << "|";
	cout << setw(10) << left << "Subject" << "|";
	cout << setw(10) << left << "HourlyRate" << "|";
	cout << setw(4) << left << "Rating" << "|";
	cout << endl;
	cout << board(90);


}

void subjectTableHead() {
	cout << board(30);
	cout << setw(3) << left << "No." << "|";
	cout << setw(3) << left << "Id" << "|";
	cout << setw(10) << left << "Subject" << "|";
	cout << setw(10) << left << "HourlyRate" << "|";
	cout << endl;
	cout << board(30);

}

void centreTableHead() {
	cout << board(30);
	cout << setw(3) << left << "No." << "|";
	cout << setw(3) << left << "Id" << "|";
	cout << setw(20) << left << "Tuition Centre Name" << "|";
	cout << endl;
	cout << board(30);

}

void modifyMenu() {
	cout << board(30);
	cout << "Modify Menu" << endl;
	cout << "1. Modify Tutor Record" << endl;
	cout << "2. Terminate Tutor" << endl;
	cout << "3. Return to Main Menu" << endl;
	cout << board(30);
}

void modifyFieldMenu() {
	cout << board(30);
	cout << "1. Modify Phone Number" << endl;
	cout << "2. Modify Address" << endl;
	cout << board(30);
}

void modifyPreMenu() {
	cout << board(30);
	cout << "1. Select Tutor for Modification / Termination" << endl;
	cout << "2. Return to main menu" << endl;
	cout << board(30);
}

//Remove User from Record
void destroyMenu() {
	cout << board(30);
	cout << "1. Input User ID to destroy" << endl;
	cout << "2. Cancel" << endl;
	cout << board(30);
}

//Weekly Report Header
void reportHeader() {
	std::cout << div(47);
	std::cout << std::setw(10) << "" << "eXcel Weekly Vacancy Report" << std::endl;
	std::cout << div(47);
}

void vacancyHeader() {
	cout << board(47);
	cout << setw(3) << left << "No." << "|";
	cout << setw(10) << left << "Subject" << "|";
	cout << setw(15) << left << "HourlyRate" << "|";
	cout << setw(15) << left << "TuitionCentre"<<"|";
	cout << endl;
	cout << board(47);
}

//View Checking
int userChoice(int lower, int higher,std::string phrase) {
	int choice;
	while (true) {
		cout << phrase;
		cin >> choice;
		//Checks if int is within range
		if (choice >= lower && choice <= higher) {
			break;
		}
		else {
		//int out of range
			cout << "Invalid input, try again !\n";
		//make sure entering char does not turn into infinite loop
			cin.clear(); //clears error flag
			cin.ignore(100, '\n'); // skip buffer
		}
	}
	cout << endl;
	return choice;
}

bool verifyChoice() {
	int i = userChoice(0,1, "Confirm Decision Yes == 1, No == 0?: ");
	if (i == 1)
		return true;
	else
		return false;
}

//Divider
std::string div(int n) {
	return (std::string(n, '='))+"\n";
}

std::string board(int n) {
	return (std::string(n, '-')) + "\n";
}