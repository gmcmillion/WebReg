#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "CourseList.h"
#include "DeptCourse.h"
#include "Student.h"
using namespace std;

//Function Prototypes
char menu();
char studentCreationMenu();
//Student createStudent(Student& x);      //Commented out since we will use later
void menuLoop(Student& x);

int main()
{
	//Variables
    char studentOption;
	bool quitProgram = false;

	//Welcome
	cout << "--- Welcome to UCI WebReg ---\n" << endl;

	//While loop to start program
    while (!quitProgram)
    {
		studentOption = studentCreationMenu();
		switch (studentOption)
		{
		case 'A':
		case 'a':   //Will make the code below into its own function eventually
        {
			cin.ignore();
			//Student x; = createStudent(x); <--------- fix this

			//Variables
			string name;
			int idNum;

			//Get Student Name
			cout << "Enter student name: \n";
			getline(cin, name);

			//Get Id Number
			cout << "Enter 8-digit student id number: \n";
			cin >> idNum;
			Student x(name, idNum);     //Create a student object
			menuLoop(x);                //Send object into menuLoop
		}
				  break;
		case 'E':
		case 'e': cout << "Goodbye!" << endl;
            quitProgram = true;
            break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}

	//system pause is the visual studio way of pausing a program before exiting
	system("Pause");
}

/*
//prompt user creation
Student createStudent(Student& x) {
	//Variables
	string name;
	int idNum;

	//Get Student Name
	cout << "Enter student name: \n";
	getline(cin, name);
	x.setName(name);

	//Get Id Number
	cout << "Enter 8-digit student id number: \n";
	cin >> idNum;
	x.setID(idNum);

	//Create a student object
	return x;
}
*/

//Creation Menu
char studentCreationMenu()
{
	char opt;

	//Menu
	cout << "Please select an option below" << endl;
	cout << "A. Create Student" << endl;
	cout << "E. Exit Program" << endl;
	cin >> opt;

	return opt;
}

//Welcome menu
char menu()
{
	char opt;

	//Menu
	cout << "\nPlease select an option below" << endl;
	cout << "A. Display Available Courses" << endl;
	cout << "B. Enroll in Course" << endl;
	cout << "C. Drop a Course" << endl;
	cout << "D. View current course load" << endl;
	cout << "E. Exit to login screen" << endl;
	cout << "Enter either A, B, C, D, or E " << endl;
	cin >> opt;

	return opt;
}

//Menu Loop
void menuLoop(Student& x)
{
	char option;
	bool exit = true;
    CourseList studentSchedule;

	while (exit)
	{
		//Get choice from welcome menu
		option = menu();
        
		//Switch statement for each option
		switch (option)
		{
		case 'A':
		case 'a': x.displayAll();                   //Display All
			break;
		case 'B':
		case 'b': x.enroll(studentSchedule);        //Enroll in a course
			break;
		case 'C':
		case 'c': x.dropCourse();                   //Drop course
			break;
		case 'D':
		case 'd': studentSchedule.displayLoad();    //View students current course load
			break;
		case 'E':
		case 'e': cout << "Logging out, Goodbye!" << endl;
			exit = false;
			break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}
}
