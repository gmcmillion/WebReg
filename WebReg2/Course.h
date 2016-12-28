//Course.h
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course
{
    protected:
        //Member Variables
        string prof;
        string courseNumber;
        string className;

    public:
        //Constructor
        Course(string profName, string courseNum, string courseName) 
			: prof(profName), courseNumber(courseNum), className(courseName)
        {}

        //Virtual Functions for display
        virtual void display() = 0;   
    
        //Get prof
        string getProf()
        {
            return prof;
        }
    
        //Get Course Number
        string getCourseNum()
        {
            return courseNumber;
        }
    
        //Get Class name
        string getClassName()
        {
            return className;
        }
};
#endif
