//Student.h
#ifndef Student_h
#define Student_h

#include <string>
#include "CourseList.h"

class Student
{
    private:
        string name;
        int idNum;
		int maxUnitsAllowed;
		int currentUnitsEnrolled;
		CourseList classList;
		CourseList studentSchedule; // <--- this should hold student class

		//static CourseList masterSchedule;

		//write linked list to text file (after student enrolls or drops)
		void writeLinkedList();
		void populateList();


    public:
        //Constructor
		Student(string n, int i);
		Student();
		//setters
		void setName(string name);

		void setID(int id);
    
        //Getters
		string getName();
    
		int getIdNum();

		//enroll student in course
		void enroll();

		//drop student from course
		void dropCourse();

		//display all courses from file to student
		void displayAll();

		//Display each course the student has signed up for
		void displayLoad();


};
#endif
