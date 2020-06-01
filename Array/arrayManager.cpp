#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "arrayManager.h"
#include "View.h"
#include "Controller.h"


using namespace std;

int ArrayManager::getArrSize() {
	return arrSize;
}
Tutor* ArrayManager::getTutorArray() {
	return tutorArray;
}

TuitionCentre* ArrayManager::getTuitionCentreArray() {
	return tuitionCentreArray;
}

Subject* ArrayManager::getSubjectArray() {
	return subjectArray;
}
//Database Preset
void ArrayManager::presetSubjectArray() {
	subjectArray[0] = Subject(1,"English",40.00);
	subjectArray[1] = Subject(2, "History", 50.00);
	subjectArray[2] = Subject(3, "Math", 65.00);
	subjectArray[3] = Subject(4, "Physics", 80.00);
	subjectArray[4] = Subject(5, "Biology",80.00);
}
void ArrayManager::presetTuitionCentreArray() {
	tuitionCentreArray[0] = TuitionCentre(1, "Bukit Jalil");
	tuitionCentreArray[1] = TuitionCentre(2, "Petaling Jaya");
	tuitionCentreArray[2] = TuitionCentre(3, "Puchong");
	tuitionCentreArray[3] = TuitionCentre(4, "Bukit Bintang");
	tuitionCentreArray[4] = TuitionCentre(5, "Kepong");
}

void ArrayManager::presetTutorArray() {
	tutorArray[0] = Tutor(4, "David", "0136089026","Petaling Jaya",toTm(2019,3,5),&tuitionCentreArray[1],
		&subjectArray[1],Rating(16,4));
	tutorArray[1] = Tutor(3, "Bryen", "0145579905", "Bukit Jalil", toTm(2017, 11, 7), &tuitionCentreArray[0],
		&subjectArray[0], Rating(20,5));
	tutorArray[2] = Tutor(2, "Chester", "0129087885", "Sri Petaling", toTm(2019, 1, 6), &tuitionCentreArray[0],
		&subjectArray[0], Rating(12,6));
	tutorArray[3] = Tutor(6, "Fanny", "0167278826", "Bukit Bintang", toTm(2019, 6, 30), &tuitionCentreArray[3],
		&subjectArray[4], Rating(9,3));
	tutorArray[4] = Tutor(5, "Eddie", "0178890231", "Puchong", toTm(2018, 2, 24), &tuitionCentreArray[2],
		&subjectArray[1], Rating(12,4));
	tutorArray[5] = Tutor(7, "Gary", "0192443566", "Kepong", toTm(2017, 12, 13), &tuitionCentreArray[4],
		&subjectArray[2], Rating(8,2));
	tutorArray[6] = Tutor(1, "Andy", "0167889054", "Bukit Jalil", toTm(2018,11,1), &tuitionCentreArray[0],
		&subjectArray[1], Rating(24,8));
	tutorArray[7] = Tutor(8, "Harry", "0174453667", "Kinrara", toTm(2019, 11, 11), &tuitionCentreArray[2],
		&subjectArray[0], Rating(9,3));
	tutorArray[8] = Tutor(9, "Ian", "0123345579", "Kepong", toTm(2019, 3, 11), &tuitionCentreArray[4],
		&subjectArray[1], Rating(21,7));
	tutorArray[9] = Tutor(10, "Joshua", "0137756809", "Shah Alam", toTm(2017, 11, 7), &tuitionCentreArray[2],
		&subjectArray[4], Rating(100,25));
	tutorArray[10] = Tutor(11, "Jaydon", "0123434678", "Bukit Jalil", toTm(2017,11,7), &tuitionCentreArray[1],
		&subjectArray[2], Rating(25,5));
	tutorArray[11] = Tutor(12, "Kylie", "0198976514", "Bukit Bintang", toTm(2018, 2, 3), &tuitionCentreArray[3],
		&subjectArray[0], Rating(10,5));
	tutorArray[12] = Tutor(13, "Liam", "0115897567", "Bukit Jalil", toTm(2019, 8, 20), &tuitionCentreArray[0],
		&subjectArray[4], Rating(36,9));
	tutorArray[13] = Tutor(14, "Marcus", "0169874476", "Petaling Jaya", toTm(2020, 5, 19), &tuitionCentreArray[1],
		&subjectArray[3], Rating(30,10));
	tutorArray[14] = Tutor(15, "Nidus", "0167895564", "Sri Petaling", toTm(2020, 3, 2), &tuitionCentreArray[0],
		&subjectArray[4], Rating(20,4));


	tutorArray[0].setTutorDateTerminated(toTm(2019, 8, 18));
	tutorArray[2].setTutorDateTerminated(toTm(2020, 5, 5));
	tutorArray[11].setTutorDateTerminated(toTm(2020, 4, 23));

}

void ArrayManager::presetDatabase() {
	presetSubjectArray();
	presetTuitionCentreArray();
	presetTutorArray();
}

void ArrayManager::displayTutor() {
	tutorTableHead();
	for (int i = 0; i < arrSize; i++) {
		cout << setw(3)<<left<< i+1 <<"|";
		tutorArray[i].toString();
		cout << board(90);
	}
};
void ArrayManager::displayTuitionCentre() {
	centreTableHead();
	for (int i = 0; i < 5; i++) {
		cout << setw(3) << left << i + 1 << "|";
		tuitionCentreArray[i].toString();
		cout << board(30);
	}
}
void ArrayManager::displaySubject() {
	subjectTableHead();
	for (int i = 0; i < 5; i++) {
		cout << setw(3)<<left<< i+1 << "|";
		subjectArray[i].toString();
		cout << board(30);
	}
}

Tutor* ArrayManager::getTerminatedTutor(int* arrSizeVar) {
	Tutor* terminatedTutor;
	int hit=0,j=0;
	for (int i = 0; i < arrSize; i++) {
		if (tutorArray[i].getTutorDateTerminated().tm_mday != 0) {
			hit++;
		}
	}
	terminatedTutor = new Tutor[hit];
	*arrSizeVar = hit;
	for (int i = 0; i < arrSize; i++) {
		if (tutorArray[i].getTutorDateTerminated().tm_mday != 0) {
			terminatedTutor[j] = tutorArray[i];
			j++;
		}
	}
	return terminatedTutor;
}


void ArrayManager::addTutor() {
	string name, phone, address;
	Subject* subject;
	TuitionCentre *centre;
	cout << "Input Name: ";
	cin >> name;
	cout << "Input Phone: ";
	cin >> phone;
	cout << "Input Address: ";
	cin >> address;
	displaySubject();
	int choice = userChoice(1, 5, "Choose Subject: ");
	subject = &(subjectArray[choice - 1]);
	displayTuitionCentre();
	choice = userChoice(1, 5,"Choose Centres: ");
	centre = &(tuitionCentreArray[choice - 1]);
	// Constructor to create new instance
	Tutor newTutor = Tutor(generateId(), name, phone, address, centre, subject, Rating(1,1));
	newTutor.setTutorDateJoined(getCurrentDate());
	newTutor.setTutorDateTerminated(toTm(0, 0, 0));
	// Increaase tutor Array size by 1
	increaseArrSize(1);
	// Set the last element (new element) as newTutor
	tutorArray[arrSize - 1] = newTutor;
	// Display Tutor Card
	newTutor.toStringCard();
	cout << "Tutor Succesfully Added!" << endl;
}

int ArrayManager::generateId() {
	// Sort Array by Id then return last index id using random access
	Tutor* t = sortById(true);
	return (t[arrSize - 1].getTutorId())+1;
}

//Sort Tutor by Id
Tutor* ArrayManager::sortById(bool asc) {
	int count = 1;
	Tutor* sortedArray = new Tutor[arrSize];
	binaryInsertionSortId(sortedArray);
	return sortedArray;
}
//use BinarySearch to find location of insertion
int ArrayManager::binarySearchLocId(Tutor* sortedArray, int id, int low, int high) {
	//empty list or list with 1 item
	if (high <= low) {
		//if selected is larger than first item, return index after
		// else return current index
		if (low != NULL) {
			return (id > sortedArray[low].getTutorId()) ? (low + 1) : low;
		}
		//empty list
		else {
			return 0;
		}
	}
	//Binary Search for insert index location
	int mid = (low + high) / 2;
	//If selected has the same value as the middle
	if (id == sortedArray[mid].getTutorId()) {
		return mid+1;
	}
	//Else, recursively calls this function in a narrower half
	//upper half or lower half of the divided array
	if (id > sortedArray[mid].getTutorId()) {
		return binarySearchLocId(sortedArray, id, mid + 1, high);
	}
	return binarySearchLocId(sortedArray, id, low, mid - 1);
}
//Binary Insertion Sort Using Id
void ArrayManager::binaryInsertionSortId(Tutor* sortedArray) {
	int loc, j, i;

	sortedArray[0] = tutorArray[0];

	for (i = 0; i < arrSize; i++) {
		j = i - 1;
		Tutor selected = tutorArray[i];
		// find location of where to insert
		loc = binarySearchLocId(sortedArray, selected.getTutorId(), 0, j);

		//Move all elements after location to create space
		while (j >= loc) {
			sortedArray[j + 1] = sortedArray[j];
			j--;
		}
		sortedArray[j + 1] = selected;

	}
}

//Sort Tutor by HourlyRate
Tutor* ArrayManager::sortByHR(bool asc) {
	int count = 1;
	Tutor* sortedArray = new Tutor[arrSize];
	binaryInsertionSortHR(sortedArray);
	return sortedArray;
}
//use BinarySearch to find location of insertion
int ArrayManager::binarySearchLocHR(Tutor* sortedArray, double HR, int low, int high) {
	//empty list or list with 1 item
	if (high <= low) {
		//if selected is larger than first item, return index after
		// else return current index
		if (low != NULL) {
			return (HR > sortedArray[low].getTutorSubject()->getSubjectHR()) ? (low + 1) : low;
		}
		//empty list
		else {
			return 0;
		}
	}
	//Binary Search for insert index location
	int mid = (low + high) / 2;
	//If selected has the same value as the middle
	if (HR == sortedArray[mid].getTutorSubject()->getSubjectHR()) {
		return mid + 1;
	}
	//Else, recursively calls this function in a narrower half
	//upper half or lower half of the divided array
	if (HR > sortedArray[mid].getTutorSubject()->getSubjectHR()) {
		return binarySearchLocHR(sortedArray, HR, mid + 1, high);
	}
	return binarySearchLocHR(sortedArray, HR, low, mid - 1);
}
//Binary Insertion Sort Using HR
void ArrayManager::binaryInsertionSortHR(Tutor* sortedArray) {
	int loc, j, i;

	sortedArray[0] = tutorArray[0];

	for (i = 0; i < arrSize; i++) {
		j = i - 1;
		Tutor selected = tutorArray[i];
		// find location of where to insert
		loc = binarySearchLocHR(sortedArray, selected.getTutorSubject()->getSubjectHR(), 0, j);

		//Move all elements after location to create space
		while (j >= loc) {
			sortedArray[j + 1] = sortedArray[j];
			j--;
		}
		sortedArray[j + 1] = selected;

	}
}

//Sort Tutor by Rating
Tutor* ArrayManager::sortByRating(bool asc) {
	int count = 1;
	Tutor* sortedArray = new Tutor[arrSize];
	binaryInsertionSortRating(sortedArray);
	return sortedArray;
}
//use BinarySearch to find location of insertion
int ArrayManager::binarySearchLocRating(Tutor* sortedArray, double Rating, int low, int high) {
	//empty list or list with 1 item
	if (high <= low) {
		//if selected is larger than first item, return index after
		// else return current index
		if (low != NULL) {
			return (Rating > sortedArray[low].getTutorRating().getRatingAverage()) ? (low + 1) : low;
		}
		//empty list
		else {
			return 0;
		}
	}
	//Binary Search for insert index location
	int mid = (low + high) / 2;
	//If selected has the same value as the middle
	if (Rating == sortedArray[mid].getTutorRating().getRatingAverage()) {
		return mid + 1;
	}
	//Else, recursively calls this function in a narrower half
	//upper half or lower half of the divided array
	if (Rating > sortedArray[mid].getTutorRating().getRatingAverage()) {
		return binarySearchLocRating(sortedArray, Rating, mid + 1, high);
	}
	return binarySearchLocRating(sortedArray, Rating, low, mid - 1);
}
//Binary Insertion Sort Using Rating
void ArrayManager::binaryInsertionSortRating(Tutor* sortedArray) {
	int loc, j, i;

	sortedArray[0] = tutorArray[0];

	for (i = 0; i < arrSize; i++) {
		j = i - 1;
		Tutor selected = tutorArray[i];
		// find location of where to insert
		loc = binarySearchLocRating(sortedArray, selected.getTutorRating().getRatingAverage(), 0, j);

		//Move all elements after location to create space
		while (j >= loc) {
			sortedArray[j + 1] = sortedArray[j];
			j--;
		}
		sortedArray[j + 1] = selected;

	}
}


//Search
//Binary Search by Id
// Returns Pointer to tutor with hat Id
Tutor* ArrayManager::searchById(int tutorId) {
	Tutor* tutor = NULL,*sortedArray = new Tutor[arrSize];
	binaryInsertionSortId(sortedArray);
	int loc = binarySearchId(sortedArray, tutorId, 0 ,arrSize-1);
	
	if(loc != -1)
		tutor = &(sortedArray[loc]);
	else {
		tutor = NULL;
	}
	return tutor;
}

int ArrayManager::binarySearchId(Tutor* sortArray, int id, int low, int high) {
	low = 0;
	high = arrSize - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (sortArray[mid].getTutorId() == id) {
			return mid;
		}
		else if (sortArray[mid].getTutorId() <= id) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

// Front and Back Search for Rating
Tutor* ArrayManager::searchByRating(int lowerBoundary, int upperBoundary, int* arrSizeVar)
{
	int hit = 0;
	Tutor* tutor = NULL;
	//front and back algo
	int front = 0, back = arrSize-1;
	while (front <= back) {
		if (tutorArray[front].getTutorRating().getRatingAverage() >= lowerBoundary &&
			tutorArray[front].getTutorRating().getRatingAverage() <= upperBoundary)
			hit++;
		if (front != back) {
			if (tutorArray[back].getTutorRating().getRatingAverage() >= lowerBoundary &&
				tutorArray[back].getTutorRating().getRatingAverage() <= upperBoundary)
				hit++;
		}
		front++;
		back--;
	}
	//reset
	front = 0;
	back = arrSize - 1;
	tutor = new Tutor[hit];
	*arrSizeVar = hit;
	int j = 0;
	while (front <= back) {
		if (tutorArray[front].getTutorRating().getRatingAverage() >= lowerBoundary &&
			tutorArray[front].getTutorRating().getRatingAverage() <= upperBoundary) {
			tutor[j] = tutorArray[front];
			hit--;
			j++;
			
		}
		if (front != back) {
			if (tutorArray[back].getTutorRating().getRatingAverage() >= lowerBoundary &&
				tutorArray[back].getTutorRating().getRatingAverage() <= upperBoundary) {
				tutor[j] = tutorArray[back];
				hit--;
				j++;
			}
		}
		front++;
		back--;
	}

	return tutor;
}
// Search by Multiple Criteria

Tutor* ArrayManager:: pagination(Tutor* ratingSortedArr, int* arrSizeVar) {
	Tutor* t = NULL;
	paginationSubMenu();

	if (userChoice(1, 2, "Input Choice: ") == 1) {
		int sub;
		displaySubject();
		//All Subject Option
		cout << setw(3) << left << "0" << "|";
		cout << setw(3) << left << "" << "|";
		cout << setw(21) << left << "All Subject" << "|";
		board(30);
		cout << endl;
		// Choose Subject
		sub =userChoice(0, 5, "Choose Subject: ");
		if(sub != 0)
			t=searchBySubject(ratingSortedArr,&subjectArray[sub - 1], arrSizeVar);
		else t = ratingSortedArr;
	}
	else {
		double lowerB, upperB;
		lowerB = userChoice(40, 80, "Input Lower Boundary of Range(40-80): ");
		upperB = userChoice(lowerB, 80, "Input Upper Boundary of Range(lower boundary - 80): ");
		t=searchByHR(ratingSortedArr, lowerB, upperB, arrSizeVar);
	}
	displayTuitionCentre();
	//All Centre Option
	cout << setw(3) << left << "0" << "|" ;
	cout << setw(3) << left << "" << "|";
	cout << setw(20) << left << "All Tuition Centre" << "|";
	board(30);
	cout << endl;
	//Choose TUition Centre
	int n = userChoice(0, 5, "Choose Tuition Centre: ");
	if (n != 0)
		t = searchByTuitionCentre(t, &tuitionCentreArray[n - 1], arrSizeVar);
	return t;
}

Tutor* ArrayManager::searchByHR(Tutor* ratingSortedArr,double lowerBoundary,double upperBoundary,int* arrSizeVar) {
	int hit = 0;
	Tutor* tutor = NULL;
	//front and back algo
	int front = 0, back = *arrSizeVar - 1;
	while (front <= back) {
		if (ratingSortedArr[front].getTutorSubject()->getSubjectHR() >= lowerBoundary &&
			ratingSortedArr[front].getTutorSubject()->getSubjectHR() <= upperBoundary)
			hit++;
		if (front != back) {
			if (ratingSortedArr[back].getTutorSubject()->getSubjectHR() >= lowerBoundary &&
				ratingSortedArr[back].getTutorSubject()->getSubjectHR() <= upperBoundary)
				hit++;
		}
		front++;
		back--;
	}
	//reset
	front = 0;
	back = *arrSizeVar - 1;
	tutor = new Tutor[hit];
	*arrSizeVar = hit;
	int j = 0;
	while (front <= back) {
		if (ratingSortedArr[front].getTutorSubject()->getSubjectHR() >= lowerBoundary &&
			ratingSortedArr[front].getTutorSubject()->getSubjectHR() <= upperBoundary) {
			tutor[j] = ratingSortedArr[front];
			hit--;
			j++;

		}
		if (front != back) {
			if (ratingSortedArr[back].getTutorSubject()->getSubjectHR() >= lowerBoundary &&
				ratingSortedArr[back].getTutorSubject()->getSubjectHR() <= upperBoundary) {
				tutor[j] = ratingSortedArr[back];
				hit--;
				j++;
			}
		}
		front++;
		back--;
	}
	return tutor;
}

Tutor* ArrayManager::searchBySubject(Tutor* ratingSortedArr,Subject* subject , int* arrSizeVar) {
	int hit = 0;
	Tutor* tutor = NULL;
	//front and back algo
	int front = 0, back = *arrSizeVar - 1;
	while (front <= back) {
		if (ratingSortedArr[front].getTutorSubject()->getSubjectName() == subject->getSubjectName())
			hit++;
		if (front != back) {
			if (ratingSortedArr[back].getTutorSubject()->getSubjectName() == subject->getSubjectName())
				hit++;
		}
		front++;
		back--;
	}
	//reset
	front = 0;
	back = *arrSizeVar - 1;
	tutor = new Tutor[hit];
	*arrSizeVar = hit;
	int j = 0;
	while (front <= back) {
		if (ratingSortedArr[front].getTutorSubject()->getSubjectName() == subject->getSubjectName()) {
			tutor[j] = ratingSortedArr[front];
			j++;
		}
		if (front != back) {
			if (ratingSortedArr[back].getTutorSubject()->getSubjectName() == subject->getSubjectName()) {
				tutor[j] = ratingSortedArr[back];
				j++;
			}
		}
		front++;
		back--;
	}
	return tutor;
}

Tutor* ArrayManager::searchByTuitionCentre(Tutor* ratingSortedArr, TuitionCentre* tuitionCentre, int* arrSizeVar) {
	int hit = 0;
	Tutor* tutor = NULL;
	//front and back algo
	int front = 0, back = *arrSizeVar - 1;
	while (front <= back) {
		if (ratingSortedArr[front].getTutorTuitionCentre()->getTuitionCentreName() == tuitionCentre->getTuitionCentreName())
			hit++;
		if (front != back) {
			if (ratingSortedArr[back].getTutorTuitionCentre()->getTuitionCentreName() == tuitionCentre->getTuitionCentreName())
				hit++;
		}
		front++;
		back--;
	}
	//reset
	front = 0;
	back = *arrSizeVar - 1;
	tutor = new Tutor[hit];
	*arrSizeVar = hit;
	int j = 0;
	while (front <= back) {
		if (ratingSortedArr[front].getTutorTuitionCentre()->getTuitionCentreName() == tuitionCentre->getTuitionCentreName()) {
			tutor[j] = ratingSortedArr[front];
			j++;
		}
		if (front != back) {
			if (ratingSortedArr[back].getTutorTuitionCentre()->getTuitionCentreName() == tuitionCentre->getTuitionCentreName()) {
				tutor[j] = ratingSortedArr[back];
				j++;
			}
		}
		front++;
		back--;
	}
	return tutor;
}

//Provide vacancy Report
void ArrayManager::generateWeeklyReport() {
	reportHeader();
	int arrSizeVar;
	Tutor* t = getTerminatedTutor(&arrSizeVar);
	vacancyHeader();
	if (arrSizeVar != 0) {
		for (int i = 0; i < arrSizeVar; i++) {
			board(47);
			cout << setw(3) << left << i+1 << "|";
			cout << setw(10) << left << t[i].getTutorSubject()->getSubjectName() << "|";
			cout << setw(15) << left << setprecision(2) << fixed <<t[i].getTutorSubject()->getSubjectHR()<< "|";
			cout << setw(15) << left << t[i].getTutorTuitionCentre()->getTuitionCentreName() << "|";
			cout << endl;
			cout<<board(47);
		}
	}
	else {
		cout << "No Vacancy Available"<<endl;
	}
}

//Permanently Remove USer from Record
void ArrayManager::destroyTutor(Tutor* target) {
	for (int i = 0; i < arrSize; i++) {
		if (tutorArray[i].getTutorId() == target->getTutorId()) {
			cout << "Tutor " + tutorArray[i].getTutorName() + " is deleted" << endl;
			for (int j = i; j < (arrSize - 1); j++)
			{
				tutorArray[j] = tutorArray[j + 1];
			}
			break;
		}
	}
	decreaseArrSize(1);
}

//Method
void ArrayManager::increaseArrSize(int n) {
	//Create new Array
	Tutor* newArray = new Tutor[arrSize + n];
	//Copy old array content into new array
	for (int i = 0; i < arrSize; i++) {
		newArray[i] = tutorArray[i];
	}
	arrSize = arrSize + n;
	//Delete previous array
	delete[] tutorArray;
	tutorArray = newArray;
}

void ArrayManager::decreaseArrSize(int n) {
	//Create new Array
	Tutor* newArray = new Tutor[arrSize - n];
	//Copy old array content into new array
	for (int i = 0; i < arrSize - n; i++) {
		newArray[i] = tutorArray[i];
	}
	arrSize = arrSize - n;
	//Delete previous array
	delete[] tutorArray;
	tutorArray = newArray;
}
