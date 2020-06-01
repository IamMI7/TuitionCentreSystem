#include <iostream>
#include "View.h"
#include "Controller.h"
#include "ArrayManager.h"

using namespace std;

int main() {
	//=============Database Setup=======================
	int choice=NULL;
	ArrayManager *arrMan = new ArrayManager();
	arrMan->presetDatabase();

	checkTerminatedDuration(arrMan);
	//Program Start
	programHeader();
	//Delete any tutor that is terminated 6 month before
	
	while (true) {
		mainController(&choice, arrMan);
	}

	//Ending
	system("pause");
	return 0;
}