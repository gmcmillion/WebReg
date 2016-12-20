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
        //No arg Constructor
		CourseList();
    
        //Add Course to linked list
		void add(DeptCourse * co);

		//for now, search couse by the course code
		void searchCoursetoEnroll(string courseCode);

		void searchCoursetoDisenroll(string courseCode);

        //Display each course in the linked list
		void displayAll();

		//this rewrites the file essentially "modifying it".
		void writeListToFile();
    
        //Destructor
		~CourseList();
};
#endif
