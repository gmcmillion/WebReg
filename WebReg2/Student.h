//Student.h
#ifndef Student_h
#define Student_h
#include "CourseList.h"

class Student
{
    private:
		//Member Variables
        string name;
        int idNum;
		int maxUnitsAllowed;
		int currentUnitsEnrolled;
		CourseList classList;
		string userLoginName; //Compare to value in vector
		string passCode; //Used as key in map

		//write linked list to text file (after student enrolls or drops)
		void writeLinkedList();

    public:
		CourseList studentSchedule; //Holds student class

        //Constructor
		Student(string n, int i);
		Student();
		
		//Setters
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

		//Populate list
        void populateList(string fileName);

		//Drop student from course
		void dropCourse();

		//Display all courses from file to student
		void displayAll();

		//Display each course the student has signed up for
		void displayLoad();
    
        //Input validation
        char validateYesOrNo(string str);
};
#endif
