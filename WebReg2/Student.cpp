#include "Student.h"
#include <fstream>


//int Student::classList = null_ptr;


//Constructor
Student::Student(string n, int i) : name(n), idNum(i)
{
	populateList();
}

Student::Student() 
{
	populateList();
}

//setters
void Student::setName(string input) {
	name = input;
}

void Student::setID(int input) {
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

//populate instance variables linked list... consider making linked list a static variable
void Student::populateList() {
	string
		courseName, courseNum, type, section,
		units, professor, time, location,
		finalDateTime, maxCapacity, currentEnrollment,
		waitListed, status, emptySpace, name;

	ifstream inputFile("ICS_Classes.txt");      //Input file

	while (!inputFile.eof())
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
	}

	//Close file after populating linked list
	inputFile.close();
}

void Student::writeLinkedList() {
	classList.writeListToFile();
}

void Student::displayAll() {

	this->classList.displayAll();
}

//Enroll
void Student::enroll()
{
	bool enroll = true;

	//Loop to enroll in classes
	while (enroll)
	{
		string num;
		char choice;

		cout << "\nPlease sign up for a course using a the 5 digit course number" << endl;
		cin >> num;

		//Sign student up for class
		classList.searchCoursetoEnroll(num);

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

		cout << "\nEnter the course number you wish to drop:" << endl;
		cin >> num;

		//Sign student up for class
		classList.searchCoursetoDisenroll(num);

		cout << "Would you like to drop  another course? (Y/N)" << endl;
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