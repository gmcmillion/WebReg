#ifndef DEPTCOURSE_H
#define DEPTCOURSE_H
#include "Course.h"
#include <iostream>

class DeptCourse : public Course
{
    protected:
		string type;			    //course type like lab, lecture, dis
		string section;       		//A, A1, A2, etc. We might not need this
		string units;				//course units
		string time;				//course meeting times and days
		string location;			//course room location
        string finalDateTime;		//course final date and time
        string maxEnrollment;		//enrollment capacity
		string currentEnrollment;	//number of students currently enrolled
        string waitListed;			//waitlisted capacity, labs are often N/A due to students not being able to waitlist
        //string restrictions;		//sometimes class are restricted to	ics students and not open to students of other majors
        string status;				//open, full, etc.
    
    public:
        //Constructor
        DeptCourse(string profName, string courseNum, string courseName,
			string cType,    string cSection,  string courseUnits,
			string cTime,    string cLocation, string cFinalDateTime,
			string cMaxEnr,  string cCurEnro,  string cWaitlisted,
			string cStatus);
    
        //Overrides the display function defined in Course.h
        void display() override;
        
		//Display
        void display(string courseTitle);

		//Displays students enrolled classes
		void displaySchedule();

		//increment current enrollment by 1
		void enrollStudentInCourse();
        
		//decrement current enrollment by 1
		void disenrollStudent();
    
        //Getters
        string getType();
		string getSection();
		string getUnits();
		string getTime();
		string getLocation();
		string getFinalDateTime();
		string getmaxEnrollment();
		string getcurrentEnrollment();
		string getWaitListed();
		string getStatus();
};
#endif
