//CourseList.h
#ifndef COURSELIST_H
#define COURSELIST_H
#include "DeptCourse.h"

class CourseList
{
    private:
        //Node to hold each instance of Course
        struct ListNode
        {
			DeptCourse* course;         //Pointer to a Course
            ListNode* next;				//Pointer to the next ListNode
        };

		string title;
        ListNode * head;
    
    public:
        //Constructor
		CourseList();
    
        //Add Course to linked list
		void add(DeptCourse * co);
		
        DeptCourse courseToAdd(string courseCode);

		//Remove course from the list
        bool removeCourseFromLoad(string courseCode);

		//Search Course to enroll in
		bool searchCoursetoEnroll(string courseCode);

		//Search Course to drop
        void searchCoursetoDisenroll(string courseCode);

        //Display each course in the linked list
		void displayAll();

		//Display each course the student has signed up for
		void displayLoad();

		//Updates the ICS_Classes.txt with any changes
		void writeListToFile();

		//Writes the students schedule to file
		void writeListToFile(string, string, string, int, int, int);
    
        //Destructor
		~CourseList();
};
#endif
