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

//setters
void Student::setName(const string& input) {
	name = input;
}

void Student::setUserLogin(const string& input) {
	userLoginName = input;
}

void Student::setPassCode(const string& input) {
	passCode = input;
}

void Student::setID(const int& input) {
	idNum = input;
}

//Getters
string Student::getName()
{
	return name;
}

int Student::getIdNum()
{
	return idNum;
}

string Student::getLogin() {
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

//Enroll
void Student::enroll()
{
	bool enroll = true;
	bool validCourse = false;

	//Loop to enroll in classes
	while (enroll)
	{
		string num;
		char choice;

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

		cout << "Would you like to enroll in another course? (Y/N)" << endl;
		cin >> choice;

		//Input verification
		while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
		{
			cout << "Invalid input: Please enter either Y or N\n";
			cin >> choice;
		}

		//Break while loop if user chooses N or n
		if (choice == 'N' || choice == 'n')
			enroll = false;
	}
	//write linked list to text file when done enrolling
	classList.writeListToFile();
}

//Drop Course
void Student::dropCourse()
{
	bool drop = true;

	//Loop to enroll in classes
	while (drop)
	{
		string num;
		char choice;
		bool validCourse = false;

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

		cout << "Would you like to drop another course? (Y/N)" << endl;
		cin >> choice;

		//Input verification
		while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
		{
			cout << "Invalid input: Please enter either Y or N\n";
			cin >> choice;
		}

		//Break while loop if user chooses N or n
		if (choice == 'N' || choice == 'n')
			drop = false;
	}

	//write linked list to text file when done dropping
	classList.writeListToFile();
}
