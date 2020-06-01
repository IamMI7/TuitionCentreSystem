#include "Tutor.h"
#include "Controller.h"

using namespace std;

int main() {
	presetSubjectList();
	presetTuitionCentreList();
	presetTutorList();

	tutorList->checkTerminatedDuration();

	programHeader();
	mainController(0);

	return 0;
}

int generateId()
{
	//Generates ID for new tutors based on highest ID + 1
	Tutor * current = tutorList->tutorListHead;
	int highestId = 0;
	if (current == NULL) {
		return 1;
	}
	while (current != NULL) {
		if (highestId < current->getTutorId()) {
			highestId = current->getTutorId();
		}
		current = current->tutorNextTutor;
	}
	highestId++;
	return highestId;
}

tm getCurrentDate() 
{
	std::tm currentDate;
	std::time_t now = std::time(NULL);
	gmtime_s(&currentDate, &now);
	return currentDate;
}

tm toTm(int year, int month, int day) {
	std::tm date;
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;
	return date;
}

//Database Preset
void presetSubjectList() {
	subjectList->add(new Subject(1, "English", 40.00));
	subjectList->add(new Subject(2, "History", 50.00));
	subjectList->add(new Subject(3, "Math", 65.00));
	subjectList->add(new Subject(4, "Physics", 80.00));
	subjectList->add(new Subject(5, "Biology", 80.00));
}

void presetTuitionCentreList() {
	tuitionCentreList->add(new TuitionCentre(1, "Bukit Jalil"));
	tuitionCentreList->add(new TuitionCentre(2, "Petaling Jaya"));
	tuitionCentreList->add(new TuitionCentre(3, "Puchong"));
	tuitionCentreList->add(new TuitionCentre(4, "Bukit Bintang"));
	tuitionCentreList->add(new TuitionCentre(5, "Kepong"));
}

void presetTutorList() {
	tutorList->addTutor(new Tutor(4, "David", "0136089026", "Petaling Jaya", toTm(2019, 3, 5), tuitionCentreList->getIndex(1),
		subjectList->getIndex(1), Rating(16, 4)));
	tutorList->addTutor(new Tutor(3, "Bryen", "0145579905", "Bukit Jalil", toTm(2017, 11, 7), tuitionCentreList->getIndex(0),
		subjectList->getIndex(0), Rating(20, 5)));
	tutorList->addTutor(new Tutor(2, "Chester", "0129087885", "Sri Petaling", toTm(2019, 1, 6), tuitionCentreList->getIndex(0),
		subjectList->getIndex(2), Rating(12, 6)));
	tutorList->addTutor(new Tutor(6, "Fanny", "0167278826", "Bukit Bintang", toTm(2019, 6, 30), tuitionCentreList->getIndex(3),
		subjectList->getIndex(4), Rating(9, 3)));
	tutorList->addTutor(new Tutor(5, "Eddie", "0178890231", "Puchong", toTm(2018, 2, 24), tuitionCentreList->getIndex(2),
		subjectList->getIndex(1), Rating(12, 4)));
	tutorList->addTutor(new Tutor(7, "Gary", "0192443566", "Kepong", toTm(2017, 12, 13), tuitionCentreList->getIndex(4),
		subjectList->getIndex(2), Rating(8, 2)));
	tutorList->addTutor(new Tutor(1, "Andy", "0167889054", "Bukit Jalil", toTm(2018, 11, 1), tuitionCentreList->getIndex(0),
		subjectList->getIndex(1), Rating(24, 8)));
	tutorList->addTutor(new Tutor(8, "Harry", "0174453667", "Kinrara", toTm(2019, 11, 11), tuitionCentreList->getIndex(2),
		subjectList->getIndex(0), Rating(9, 3)));
	tutorList->addTutor(new Tutor(9, "Ian", "0123345579", "Kepong", toTm(2019, 3, 11), tuitionCentreList->getIndex(4),
		subjectList->getIndex(1), Rating(21, 7)));
	tutorList->addTutor(new Tutor(10, "Joshua", "0137756809", "Shah Alam", toTm(2017, 11, 7), tuitionCentreList->getIndex(2),
		subjectList->getIndex(4), Rating(100, 25)));
	tutorList->addTutor(new Tutor(11, "Jaydon", "0123434678", "Bukit Jalil", toTm(2017, 11, 7), tuitionCentreList->getIndex(1),
		subjectList->getIndex(2), Rating(25, 5)));
	tutorList->addTutor(new Tutor(12, "Kylie", "0198976514", "Bukit Bintang", toTm(2018, 2, 3), tuitionCentreList->getIndex(3),
		subjectList->getIndex(0), Rating(10, 5)));
	tutorList->addTutor(new Tutor(13, "Liam", "0115897567", "Bukit Jalil", toTm(2019, 8, 20), tuitionCentreList->getIndex(0),
		subjectList->getIndex(4), Rating(36, 9)));
	tutorList->addTutor(new Tutor(14, "Marcus", "0169874476", "Petaling Jaya", toTm(2020, 5, 19), tuitionCentreList->getIndex(1),
		subjectList->getIndex(3), Rating(30, 10)));
	tutorList->addTutor(new Tutor(15, "Nidus", "0167895564", "Sri Petaling", toTm(2020, 3, 2), tuitionCentreList->getIndex(0),
		subjectList->getIndex(4), Rating(20, 4)));
	
	tutorList->getIndex(0)->setTutorDateTerminated(toTm(2019, 8, 18));
	tutorList->getIndex(2)->setTutorDateTerminated(toTm(2020, 5, 5));
	tutorList->getIndex(11)->setTutorDateTerminated(toTm(2020, 4, 23));
}
