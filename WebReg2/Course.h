//Course.h
#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
    protected:
        //course needs to change
        //students enroll with courseCodes, not course names
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
    
        //setters
        
        //getters
        string getProf()
        {
            return prof;
        }
    
        string getCourseNum()
        {
            return courseNumber;
        }
    
        string getClassName()
        {
            return className;
        }
};
#endif
