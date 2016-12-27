#include "DeptCourse.h"
#include <iomanip>

//Constructor
DeptCourse::DeptCourse(string profName, string courseNum, string courseName,
    string cType, string cSection, string courseUnits, string cTime,
    string cLocation, string cFinalDateTime,string cMaxEnr,
    string cCurEnro, string cWaitlisted, string cStatus) : Course(profName,
    courseNum, courseName)
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
void DeptCourse::display() //override
{
    cout << getClassName() << endl;

    //Heading
    cout << "Crs Code | " << "Type | " << "Sect | "
    << "Units | " << "Professor  | " << "      Time         | "
    << " Location  | " << "          Final            | "
    << "Max Enr. | " << "Curr. Enr. | "
    << "WaitList | " << "Status" << endl;

    cout
    << setw(10) << left << getCourseNum() << " "
    << setw(6) << left << getType() << " "
    << setw(6) << left << getSection()<< " "
    << setw(7) << left << getUnits() << " "
    << setw(13) << left << getProf() << " "
    << setw(20) << left << getTime() << " "
    << setw(12) << left << getLocation() << " "
    << setw(27) << left << getFinalDateTime() << " "
    << setw(10) << left << getmaxEnrollment() << " "
    << setw(12) << left << getcurrentEnrollment() << " "
    << setw(10) << left << getWaitListed() << " "
    << setw(7) << left << getStatus() << endl;
}

//Display
void DeptCourse::display(string courseTitle)
{
    cout
    << setw(10) << left << getCourseNum() << " "
    << setw(6) << left << getType() << " "
    << setw(6) << left << getSection()<< " "
    << setw(7) << left << getUnits() << " "
    << setw(13) << left << getProf() << " "
    << setw(20) << left << getTime() << " "
    << setw(12) << left << getLocation() << " "
    << setw(27) << left << getFinalDateTime() << " "
    << setw(10) << left << getmaxEnrollment() << " "
    << setw(12) << left << getcurrentEnrollment() << " "
    << setw(10) << left << getWaitListed() << " "
    << setw(7) << left << getStatus() << endl;
}

//Displays students enrolled classes
void DeptCourse::displaySchedule()
{

    cout
    << setw(25) << left << getClassName() << " "
    << setw(10) << left << getCourseNum() << " "
    << setw(6) << left << getType() << " "
    << setw(6) << left << getSection()<< " "
    << setw(8) << left << getUnits() << " "
    << setw(13) << left << getProf() << " "
    << setw(21) << left << getTime() << " "
    << setw(11) << left << getLocation();
}

//Increment current enrollment by 1
void DeptCourse::enrollStudentInCourse()
{
    int numEnrolled = stoi(currentEnrollment); 		//use stoi to convert string to int
    numEnrolled++;

    currentEnrollment = to_string(numEnrolled);		//set currentEnrollment
}

//Decrement current enrollment by 1
void DeptCourse::disenrollStudent()
{
    int numEnrolled = stoi(currentEnrollment); 		//use stoi to convert string to int
    numEnrolled--;

    currentEnrollment = to_string(numEnrolled);		//set currentEnrollment
}

//Get Type
string DeptCourse::getType()
{
    return type;
}

//Get Section
string DeptCourse::getSection()
{
    return section;
}

//Get Units
string DeptCourse::getUnits()
{
    return units;
}

//Get Time
string DeptCourse::getTime()
{
    return time;
}
		
//Get Location
string DeptCourse::getLocation()
{
    return location;
}

//Get Final Date Time
string DeptCourse::getFinalDateTime()
{
    return finalDateTime;
}

//Get Max Enrollment
string DeptCourse::getmaxEnrollment()
{
    return maxEnrollment;
}

//Get Current Enrollment
string DeptCourse::getcurrentEnrollment()
{
    return currentEnrollment;
}

//Get Waitlisted
string DeptCourse::getWaitListed()
{
    return waitListed;
}

//Get Status
string DeptCourse::getStatus()
{
    return status;
}
