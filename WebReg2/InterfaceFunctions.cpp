#include "InterfaceFunctions.h"

//User creation
Student createStudent()
{
	//Variables
	string name;
	int idNum;

	//Get Student Name
	cout << "Enter student name: \n";
	getline(cin, name);

	//Get Id Number
	cout << "Enter 8-digit student id number: \n";
	cin >> idNum;
    
    //Create student object
    Student x(name, idNum);

	//Return student object
	return x;
}

//Startup menu
char startUpMenu()
{
    //Variable
    char opt;
    
    //Startup Menu
	cout << "Please select an option below" << endl;
	cout << "A. Create Student" << endl;
	cout << "E. Exit Program" << endl;
	cin >> opt;
    
    return opt;
}

//Student Creation Menu
void studentCreationMenu()
{
	//Variable
    bool quitProgram = true;
    
    //Create student
    while (quitProgram)
    {
        char option = startUpMenu();    //Get user choice
        cin.ignore();

		//Switch statement
        switch (option)
		{
		case 'A':
		case 'a':
        {
            Student x = createStudent();
            menuLoop(x);
            break;
        }
		case 'E':
		case 'e': quitProgram = false;
                  break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}
}

//Main menu
char menu()
{
	//Variable
    char opt;

	//Menu
    cout << "\n---------- Main Menu ----------" << endl;
	cout << "Please select an option below" << endl;
	cout << "A. Display Available Courses" << endl;
	cout << "B. Enroll in Course" << endl;
	cout << "C. Drop a Course" << endl;
	cout << "D. View current course load" << endl;
	cout << "E. Exit" << endl;
	cout << "Enter either A, B, C, D, or E " << endl;
	cin >> opt;

	return opt;
}

//MenuLoop
void menuLoop(Student& x)
{
	//Variables
    char option;
	bool exit = true;

	//While loop for menu
    while (exit)
	{
		//Get choice from welcome menu
		option = menu();

		//Switch statement for each option
		switch (option)
		{
		case 'A':
		case 'a': x.displayAll();       //Display All
			break;
		case 'B':
		case 'b': x.enroll();           //enroll in course
			break;
		case 'C':
		case 'c': x.dropCourse();       //drop course
			break;
		case 'D':
		case 'd': x.displayLoad();      //display student course load
			break;
		case 'E':
		case 'e': cout << "Logging out, Goodbye!\n\n";
			exit = false;
			break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}
}
