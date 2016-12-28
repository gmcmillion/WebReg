#ifndef INTERFACEFUNCTIONS_HPP 
#define INTERFACEFUNCTIONS_HPP 

#include "Student.h"
#include <vector>
#include <map>

//display user menu after they login
char menu();

//display login menu
char startUpMenu();

//Validate for more than one char in input
char validateNumOfChar(string str);

//Validate for more than one char in input for main menu
char validateMenuNumChar(string str);

//Validate input
char validateStartUp(string str);

//Validate menu input
char validateMenu(string str);

//loop that handles menu switch statement
void menuLoop(Student* x);

//load all file names into vector
void setUpUserVector(vector<string>& userNameList);

//load all key value pairs into map
map<string, Student*> setUpMap(vector<string>& userNameList, map<string, Student*> testMap);

//Calls the student's setters
void addValuesToObject(Student* x, string& userLogin, string& userPW, string& userName, string& userMaxUnits, string& userCU, string& userID);

//Gets user login and password and verifies authentication
void getLogin(vector<string>& userNameList, map<string, Student*> testMap);
#endif
