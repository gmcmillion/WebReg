#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Course.h"
#include "CourseList.h"
#include "DeptCourse.h"
#include "Student.h"
using namespace std;

int main()
{
	//Variables
    string 
		courseName, courseNum, type, section,
		units, professor, time, location,
		finalDateTime, maxCapacity, currentEnrollment, 
		waitListed, status, emptySpace, name;
    int idNum;
    bool enroll = true;

	ifstream inputFile("ICS_Classes.txt");      //Input file
    
    CourseList icsCourseList;					//Define a CourseList object of ICS courses

	//While not end of file
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

		icsCourseList.add(&d);	                                //Add DeptCourse to the CourseList
	}
    
	//enroll in some courses to text write to file
	//icsCourseList.searchCoursetoEnroll("36500");
	//icsCourseList.searchCoursetoEnroll("36521");

    //Display All
	icsCourseList.displayAll();
    
    //Get Student Name
    cout << "\nEnter student name: \n";
    getline(cin, name);
    
    //Get Id Number
    cout << "Enter 8-digit student id number: \n";
    cin >> idNum;

    //Create a student object
    Student x(name, idNum);
    
    //Loop to enroll in classes
    while (enroll)
    {
        string num;
        char choice;
        
        cout << "\nPlease sign up for a course using a the 5 digit course number" << endl;
        cin >> num;
        
        //Sign student up for class
        icsCourseList.searchCoursetoEnroll(num);
        //d.enrollStudentInCourse() ?????
        
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
    
    //Close file
    inputFile.close();

	//rewrite file before closing
	//icsCourseList.writeListToFile();
    
	//system pause is the visual studio way of pausing a program before exiting
    system("Pause");
}
