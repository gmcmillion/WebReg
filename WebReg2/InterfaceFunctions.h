#ifndef INTERFACEFUNCTIONS_HPP 
#define INTERFACEFUNCTIONS_HPP 

#include "Student.h"

//Function Prototypes
char menu();
char studentCreationMenu(); //<-- change this function
char startUpMenu();			//<--- add this function

Student createStudent(Student& x); //<-- change this function
void menuLoop(Student* x);

//Student createStudent();

#endif // !
