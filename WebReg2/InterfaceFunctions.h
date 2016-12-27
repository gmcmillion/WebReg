#ifndef INTERFACEFUNCTIONS_HPP 
#define INTERFACEFUNCTIONS_HPP 

#include "Student.h"

//Function Prototypes
char menu();
char studentCreationMenu();
char startUpMenu();

Student createStudent(Student& x);
void menuLoop(Student* x);

//Student createStudent();

#endif // !
