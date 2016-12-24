#include "InterfaceFunctions.h"

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

char studentCreationMenu() {
	char opt;

	//menu
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

	//menu
	cout << "\n\nPlease select an option below" << endl;
	cout << "A. Display Available Courses" << endl;
	cout << "B. Enroll in Course" << endl;
	cout << "C. Drop a Course" << endl;
	cout << "D. View current course load" << endl;
	cout << "E. Exit" << endl;
	cout << "Enter either A, B, C, D, or E " << endl;
	cin >> opt;

	return opt;
}

void menuLoop(Student& x) {
	char option;
	bool exit = true;

	while (exit)
	{
		//Get choice from welcome menu
		option = menu();
		//Switch statement for each option
		switch (option)
		{
		case 'A':
		case 'a': x.displayAll();     //Display All
			break;
		case 'B':
		case 'b': x.enroll();
			break;
		case 'C':
		case 'c': //drop course
			x.dropCourse();
			break;
		case 'D':
		case 'd': //view students current course load
				  //need to create a student member function for this
			x.displayLoad();
			break;
		case 'E':
		case 'e': cout << "Logging out, Goodbye!" << endl;
			exit = false;
			break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}
}