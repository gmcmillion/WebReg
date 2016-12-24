#ifndef INTERFACEFUNCTIONS_HPP 
#define INTERFACEFUNCTIONS_HPP 

#include "Student.h"

//Function Prototypes
char menu();
char studentCreationMenu();

Student createStudent(Student& x);
void menuLoop(Student& x);

#endif // !
