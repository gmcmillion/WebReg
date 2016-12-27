//Student.h
#ifndef Student_h
#define Student_h

#include <string>
#include "CourseList.h"

class Student
{
    private:
		string userLoginName; // <--- used to compare to map's string value
		string passCode; // <--- consider using this for map
		//map would look like map<string, Student> where string is username and student is the student's record
		// if map<string, string> is true, then proceed to check map<string, Student>

		//Variables
        string name;
        int idNum;
		int maxUnitsAllowed;
		int currentUnitsEnrolled;
		CourseList classList;

		//static CourseList masterSchedule;

		//write linked list to text file (after student enrolls or drops)
		void writeLinkedList();

    public:
		CourseList studentSchedule; // <--- this should hold student class

        //Constructor
		Student(string n, int i);
		Student();

		//destructor
		~Student();
		
		//setters
		void setName(const string& name);
		void setID(const int& id);
		void setUserLogin(const string& input);
		void setPassCode(const string& input);


        //Getters
		string getName();
    
		int getIdNum();

		string getLogin();

		//Enroll student in course
		void enroll();

		void populateList(string fileName);


		//Drop student from course
		void dropCourse();

		//Display all courses from file to student
		void displayAll();

		//Display each course the student has signed up for
		void displayLoad();


};
#endif
