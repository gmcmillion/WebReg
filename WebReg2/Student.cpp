#include "Student.h"
#include <fstream>

//Constructor
Student::Student(string n, int i) : name(n), idNum(i), maxUnitsAllowed(16), currentUnitsEnrolled(0)
{
	populateList("ICS_Classes.txt");
}
//Default Constructor
Student::Student() : name(""), idNum(0), maxUnitsAllowed(16), currentUnitsEnrolled(0)
{
	populateList("ICS_Classes.txt");
}

//Set name
void Student::setName(const string& input)
{
	name = input;
}

//Set User Login
void Student::setUserLogin(const string& input)
{
	userLoginName = input;
}

//Set passcode
void Student::setPassCode(const string& input)
{
	passCode = input;
}

//Set ID
void Student::setID(const int& input)
{
	idNum = input;
}

//Get name
string Student::getName()
{
	return name;
}

//Get Id Num
int Student::getIdNum()
{
	return idNum;
}

//Get Login
string Student::getLogin()
{
	return userLoginName;
}

//populate instance variables linked list... consider making linked list a static variable
void Student::populateList(string fileName)
{
	string
		courseName, courseNum, type, section,
		units, professor, time, location,
		finalDateTime, maxCapacity, currentEnrollment,
		waitListed, status, emptySpace, name;

	ifstream inputFile(fileName);      //Input file

	while (true)
	{
		getline(inputFile, courseName);
		getline(inputFile, courseNum);
		getline(inputFile, type);
		getline(inputFile, section);
		getline(inputFile, units);
		getline(inputFile, professor);
		getline(inputFile, time);
		getline(inputFile, location);
		getline(inputFile, finalDateTime);
		getline(inputFile, maxCapacity);
		getline(inputFile, currentEnrollment);
		getline(inputFile, waitListed);
		getline(inputFile, status);

		//this mitigates the condition where a course does not have a final
		//in that case, we backwards initialize string values to match
		//the order in which they were read from the file
		if (finalDateTime.size() < 6)
		{
			status = waitListed;
			waitListed = currentEnrollment;
			currentEnrollment = maxCapacity;
			maxCapacity = finalDateTime;
			finalDateTime = "";
		}
		else
		{
			getline(inputFile, emptySpace);	//To skip the extra line in txt file (find a better method maybe?)
		}

		DeptCourse d(
			professor, courseNum, courseName, type, section,
			units, time, location, finalDateTime, maxCapacity,
			currentEnrollment, waitListed, status);				//Create DeptCourse object

		classList.add(&d);	                                //Add DeptCourse to the CourseList

		if (inputFile.eof()) break; // if the file is the last line

	}

	//Close file after populating linked list
	inputFile.close();
}

void Student::writeLinkedList()
{
	classList.writeListToFile();
}

void Student::displayAll()
{

	this->classList.displayAll();
}

void Student::displayLoad()
{
	this->studentSchedule.displayLoad();
}

//Input validation
char Student::validateYesOrNo(string str)
{
    //Variable
    char option;
    
    //Check number of char entered
    while (str.length() > 1)
    {
        cout << "INVALID INPUT: Enter one character, Y or N\n";
        getline(cin, str);
    }
    
    //Initialize our char (string to char)
    option = str[0];
    
    //Loop for input validation
    while (option != 'Y' && option != 'N' && option != 'y' && option != 'n' )
    {
        cout << "INVALID INPUT: Enter either Y or N\n";
        getline(cin, str);
    
        //Check number of char entered
        while (str.length() > 1)
        {
            cout << "INVALID INPUT: Enter one character, Y or N\n";
            getline(cin, str);
        }
    
        //Initialize our char (string to char)
        option = str[0];
    }
    
    return toupper(option);
}

//Enroll
void Student::enroll()
{
	bool enroll = true;
	bool validCourse = false;
    string input;
    char choice;

	//Loop to enroll in classes
	while (enroll)
	{
		string num;

		cout << "\nPlease sign up for a course using a the 5 digit course number" << endl;
		cin >> num;

		//Sign student up for class
		validCourse = classList.searchCoursetoEnroll(num);
		if (validCourse) {
			//get class matching that course code, and add it into the student schedule
			DeptCourse x = classList.courseToAdd(num);
			studentSchedule.add(&x);
			//now rewrite students file to reflect newly added course
			studentSchedule.writeListToFile(userLoginName, passCode, name, idNum, maxUnitsAllowed, currentUnitsEnrolled);
		}
        cin.ignore();
		cout << "Would you like to enroll in another course? (Y/N)" << endl;
		getline(cin, input);
        
        //Input Validation
        choice = validateYesOrNo(input);
        
		//Break while loop if user chooses N or n
		if (choice == 'N')
			enroll = false;
	}
	//write linked list to text file when done enrolling
	classList.writeListToFile();
}

//Drop Course
void Student::dropCourse()
{
	bool drop = true;
    bool validCourse = false;
    string input;
    char choice;

	//Loop to enroll in classes
	while (drop)
	{
		string num;

		cout << "\nEnter the course number you wish to drop:" << endl;
		cin >> num;

        //Drop course, and return true(dropped) or false(didnt drop)
        validCourse = studentSchedule.removeCourseFromLoad(num);
		
		//If validCourse is true, decrement the list
        if (validCourse)
        {
			//drop class from list
			classList.searchCoursetoDisenroll(num);

			//rewrite students file to reflect dropped course
			studentSchedule.writeListToFile(userLoginName, passCode, name, idNum, maxUnitsAllowed, currentUnitsEnrolled);
		}
        
        cin.ignore();   //Clear buffer
        cout << "Would you like to drop another course? (Y/N)" << endl;
		getline(cin, input);

        //Input Validation
        choice = validateYesOrNo(input);

		//Break while loop if user chooses N or n
		if (choice == 'N')
			drop = false;
	}

	//write linked list to text file when done dropping
	classList.writeListToFile();
}
