//main.cpp
#include <iostream>
#include "Course.h"
#include "CourseList.h"
#include "DeptCourse.h"
#include "Student.h"
#include "InterfaceFunctions.h"
using namespace std;

int main()
{
	//Welcome
	cout << "--- Welcome to UCI WebReg ---\n" << endl;
    
    //Show student creation menu
    studentCreationMenu();

	return 0;
}
