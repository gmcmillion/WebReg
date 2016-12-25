#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Course.h"
#include "CourseList.h"
#include "DeptCourse.h"
#include "Student.h"
#include "InterfaceFunctions.h"

using namespace std;


int main()
{
	char studentOption;
	bool quitProgram = false;

	//Get choice from welcome menu
	cout << "\nWelcome to UCI WebReg\n" << endl;

	while (!quitProgram) {
		
		studentOption = studentCreationMenu();
		cin.ignore();

		switch (studentOption)
		{
		case 'A':
		case 'a': {
			//Student x = createStudent(x); <--------- fix this

			//Variables
			string name;
			int idNum;

			//Get Student Name
			cout << "Enter student name: \n";
			getline(cin, name);

			//Get Id Number
			cout << "Enter 8-digit student id number: \n";
			cin >> idNum;
			Student x(name, idNum);
			menuLoop(x);
		}
				  break;
		case 'E':
		case 'e': {
			quitProgram = true;
			return 0;
		}
				  break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}

	return 0;
}
