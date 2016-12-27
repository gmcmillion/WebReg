#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include "Course.h"
#include "CourseList.h"
#include "DeptCourse.h"
#include "Student.h"
#include "InterfaceFunctions.h"

using namespace std;


int main()
{
	char studentOption;
	bool quitProgram = false;

	map<string, Student*> testMap;
	vector<string> userNameList;


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

	for (auto i : userNameList){				// access by value, the type of i is int

		cout << "Vector file is: " << i << endl;

		ifstream inputFile(i + ".txt");			//Input file
		string userLogin, userPW, userName, userMaxUnits, userCU, userID;

		string
			courseName, courseNum, type, section,
			units, professor, time, location,
			finalDateTime, maxCapacity, currentEnrollment,
			waitListed, status, emptySpace, name;

		Student* x = new Student;			// <--- make sure to check for mem leaks & deallocate

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
			cout << userLogin << userPW << userName << userID << userMaxUnits << userCU << endl;

			x->setUserLogin(userLogin);
			x->setPassCode(userPW);
			x->setName(userName);
			x->setID(atoi(userID.c_str()));

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

			if (inputFile.eof()) {
				break;
			}
		}

		testMap[userPW] = x;				//map object 
		inputFile.close();

	}

	//Get choice from welcome menu
	cout << "\nWelcome to UCI WebReg\n" << endl;

	while (!quitProgram) {

		studentOption = studentCreationMenu();
		cin.ignore();

		switch (studentOption)
		{
		case 'A':
		case 'a': {

			//Variables
			string loginName, passWord;
			cout << "Enter username: ";
			getline(cin, loginName);
			cout << "Enter password: ";
			getline(cin, passWord);

			for (auto vectorIterator: userNameList) {
				
				cout << vectorIterator << endl;

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
						cout << "Welcome back: " << testMap[passWord]->getName() << endl;
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
				  break;
		case 'E':
		case 'e': {
			quitProgram = true;
			return 0;
		}
				  break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}


	/*

	//Get choice from welcome menu
	cout << "\nWelcome to UCI WebReg\n" << endl;

	while (!quitProgram) {
		
		studentOption = studentCreationMenu();
		cin.ignore();

		switch (studentOption)
		{
		case 'A':
		case 'a': {
			//Student x = createStudent(x); <--------- fix this

			//Variables
			string name;
			int idNum;

			//Get Student Name
			cout << "Enter student name: \n";
			getline(cin, name);

			//Get Id Number
			cout << "Enter 8-digit student id number: \n";
			cin >> idNum;
			Student x(name, idNum);
			menuLoop(x);
		}
				  break;
		case 'E':
		case 'e': {
			quitProgram = true;
			return 0;
		}
				  break;
		default: cout << "\nThat is an invalid option, try again\n\n";
		}
	}

	*/

	for (auto itr = testMap.begin(); itr != testMap.end(); itr++)
	{
		delete itr->second;
	}


	return 0;
}
