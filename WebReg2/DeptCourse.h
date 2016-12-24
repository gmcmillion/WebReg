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
        DeptCourse(
			string profName, string courseNum, string courseName,
			string cType,    string cSection,  string courseUnits,
			string cTime,    string cLocation, string cFinalDateTime,
			string cMaxEnr,  string cCurEnro,  string cWaitlisted,
			string cStatus) 
			: Course(profName, courseNum, courseName)
        {
			type = cType;			    
			section = cSection;       		
			units = courseUnits;
			time = cTime;
			location= cLocation;		
			
			finalDateTime = cFinalDateTime;		
			
			maxEnrollment = cMaxEnr;
			currentEnrollment = cCurEnro;	
			waitListed = cWaitlisted;
			status = cStatus;
        }

        //Overrides the display function defined in Course.h
        void display() override
        {
			cout << getClassName() << endl;

			cout 
			<< getCourseNum()		<< " " << getType()				 << " "
			<< getSection()			<< " " << getUnits()			 << " "
			<< getProf()			<< " " << getTime()				 << " "
			<< getLocation()		<< " " << getFinalDateTime()	 << " " 
			<< getmaxEnrollment()	<< " " << getcurrentEnrollment() << " "
			<< getWaitListed()		<< " " << getStatus()
			<< endl;
        }
		void display(string courseTitle)
		{

			cout
				<< getCourseNum() << " " << getType() << " "
				<< getSection() << " " << getUnits() << " "
				<< getProf() << " " << getTime() << " "
				<< getLocation() << " " << getFinalDateTime() << " "
				<< getmaxEnrollment() << " " << getcurrentEnrollment() << " "
				<< getWaitListed() << " " << getStatus()
				<< endl;
		}

		//Displays students enrolled classes
		void displaySchedule()
		{
			cout
				<< getClassName() << " " << getCourseNum() << " "
				<< getType() << " " << getSection() << " "
				<< getUnits() << " " << getProf() << " "
				<< getTime() << " " << getLocation();
		}

		//increment current enrollment by 1
		void enrollStudentInCourse() 
		{
			int numEnrolled = stoi(currentEnrollment); 		//use stoi to convert string to int
			numEnrolled++;

			currentEnrollment = to_string(numEnrolled);		//set currentEnrollment
		}

		//decrement current enrollment by 1
		void disenrollStudent()
		{
			int numEnrolled = stoi(currentEnrollment); 		//use stoi to convert string to int
			numEnrolled--;

			currentEnrollment = to_string(numEnrolled);		//set currentEnrollment		
		}
    
        string getType()
        {
            return type;
        }
		
		string getSection()
		{
			return section;
		}        

		string getUnits()
		{
			return units;
		}        
		
		string getTime()
		{
			return time;
		}        
		
		string getLocation()
		{
			return location;
		}        
		
		string getFinalDateTime()
		{
			return finalDateTime;
		}

		string getmaxEnrollment()
		{
			return maxEnrollment;
		}

		string getcurrentEnrollment()
		{
			return currentEnrollment;
		}

		string getWaitListed()
		{
			return waitListed;
		}

		string getStatus()
		{
			return status;
		}
};
#endif
