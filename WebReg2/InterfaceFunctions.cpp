#include "InterfaceFunctions.h"
#include <fstream>

//Startup menu
char startUpMenu()
{
	//Variable
	char opt;

	//Startup Menu
	cout << "Please select an option below" << endl;
	cout << "A. Login" << endl;
	cout << "E. Exit Program" << endl;
	cin >> opt;

	return opt;
}

//Main menu
char menu()
{
	//Variable
	char opt;

	//Menu
	cout << "\n---------- Main Menu ----------" << endl;
	cout << "Please select an option below" << endl;
	cout << "A. Display Available Courses" << endl;
	cout << "B. Enroll in Course" << endl;
	cout << "C. Drop a Course" << endl;
	cout << "D. View current course load" << endl;
	cout << "E. Logout" << endl;
	cout << "Enter either A, B, C, D, or E " << endl;
	cin >> opt;

	return opt;
}

void menuLoop(Student* x)
{
	//Variables
	char option;
	bool exit = true;

	//While loop for menu
	while (exit)
	{
		//Get choice from welcome menu
		option = menu();

		//Switch statement for each option
		switch (option)
		{
		case 'A':
		case 'a': x->displayAll();       //Display All
			break;
		case 'B':
		case 'b': x->enroll();           //enroll in course
										 /*
										 /CAUSES BUG
										 //WHEN YOU TRY TO DROP A COURSE RIGHT AFTER ENROLLING
										 */

			break;
		case 'C':
		case 'c': x->dropCourse();       //drop course
			break;
		case 'D':
		case 'd': x->displayLoad();      //display student course load
			break;
		case 'E':
		case 'e': 
				{
				cout << "Logging out, Goodbye!\n\n";
				exit = false;
				}
			break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}
}

void setUpUserVector(vector<string>& userNameList) {
	ifstream inputFile("users.txt");      //Input file

	while (true) {

		string test;
		inputFile >> test;
		userNameList.push_back(test);

		if (inputFile.eof()) {
			break;
		}
	}

	inputFile.close();
}

map<string, Student*> setUpMap(vector<string>& userNameList, map<string, Student*> testMap) {
	
	for (auto i : userNameList) {				// access by value, the type of i is int

		ifstream inputFile(i + ".txt");			//Input file

		//variables to construct object
		string userLogin, userPW, userName, userMaxUnits, userCU, userID;

		//variables to construct schedule
		string
			courseName, courseNum, type, section,
			units, professor, time, location,
			finalDateTime, maxCapacity, currentEnrollment,
			waitListed, status, emptySpace, name;

		Student* x = new Student;	// <--- make sure to check for mem leaks & deallocate

		while (inputFile) {
			bool gotMemberData = false;

			if (!gotMemberData) {
				getline(inputFile, userLogin);
				getline(inputFile, userPW);
				getline(inputFile, userName);
				getline(inputFile, userID);
				getline(inputFile, userMaxUnits);
				getline(inputFile, userCU);

				gotMemberData = true;
			}

			addValuesToObject(x, userLogin, userPW, userName, userMaxUnits, userCU, userID);

			//add student schedule write loop here
			while (true && !inputFile.eof())
			{
				getline(inputFile, courseName);
				getline(inputFile, courseNum);
				getline(inputFile, type);
				getline(inputFile, section);
				getline(inputFile, units);
				getline(inputFile, professor);
				getline(inputFile, time);
				getline(inputFile, location);
				getline(inputFile, finalDateTime);
				getline(inputFile, maxCapacity);
				getline(inputFile, currentEnrollment);
				getline(inputFile, waitListed);
				getline(inputFile, status);

				//this mitigates the condition where a course does not have a final
				//in that case, we backwards initialize string values to match
				//the order in which they were read from the file
				if (finalDateTime.size() < 6)
				{
					status = waitListed;
					waitListed = currentEnrollment;
					currentEnrollment = maxCapacity;
					maxCapacity = finalDateTime;
					finalDateTime = "";
				}
				else
				{
					getline(inputFile, emptySpace);	//To skip the extra line in txt file (find a better method maybe?)
				}

				DeptCourse d(
					professor, courseNum, courseName, type, section,
					units, time, location, finalDateTime, maxCapacity,
					currentEnrollment, waitListed, status);				//Create DeptCourse object

				x->studentSchedule.add(&d);	                                //Add DeptCourse to the CourseList

				if (inputFile.eof()) break; // if the file is the last line

			}
		}

		testMap[userPW] = x;				//map object 
		inputFile.close();
	}

	return testMap;
}

void addValuesToObject(Student* x, string& userLogin, string& userPW, string& userName, string& userMaxUnits, string& userCU, string& userID) {

	x->setUserLogin(userLogin);
	x->setPassCode(userPW);
	x->setName(userName);
	x->setID(atoi(userID.c_str()));
}

void getLogin(vector<string>& userNameList, map<string, Student*> testMap) {
	//Variables
	string loginName, passWord;
	cout << "Enter username: ";
	getline(cin, loginName);
	cout << "Enter password: ";
	getline(cin, passWord);

	for (auto vectorIterator : userNameList) {

		/*
		check if loginName is part of the student accounts txt file
		if yes
		check if the password inputed is mapped to an object
		if yes
		check if that object matches the login name
		if yes we found the right account
		*/
		if ((vectorIterator == loginName) && testMap.find(passWord) != testMap.end()) {
			if (testMap[passWord]->getLogin() == loginName) {
				cout << "\nWelcome back: " << testMap[passWord]->getName() << endl;
				menuLoop(testMap[passWord]);
				break;
			}
		}
		else {
			//not found
			cout << "Not Found" << endl;
			//add return statement to exit for loop
		}
	}
}
